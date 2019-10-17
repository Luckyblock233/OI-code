//知识点:二分答案,01最短路 
/*
By:Luckyblock
题目要求:
给定 一带权无向图,
可将 图中k条边 边权置零
要使: 从1 -->n 路径上 最长的边权值最小
求 最小的 最长的边权值.

分析题意:
显然, 答案满足单调性, 
可以对 最长的边权值进行 二分答案枚举 

若已枚举出 最长的边权值.
如何检查 枚举量的合法性?
- 对于 小于等于枚举量的 边权值不会影响 最长的边权值
  则 它们对答案正确性的判断 无贡献.

- 对于 大于枚举量的 边权值
  如果 必须要被经过, 就会影响 最长的边权值 
  则必须 消耗一次机会将其边权值置零
  
  显然, 若最后 使用边权置零的机会 > k,
  则证明 这种连接方案不合法
  
则需统计从1->n路径上, 比枚举量大的边 的 最少的个数
则可 将 大于枚举量的 边权值看做1, 其他看做0; 
进行最短路算法 , 求得的1-->n 的 "最短距离" 
即 1-->n 路径上 比枚举量大的边 的 最少的个数

通过 将求得的最少个数 与 k进行比较, 则可检查枚举量的合法性 

其他解法: 
由于此题 n,k较小, 也可以考虑建立分层图,并进行最短路 算法 
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<ctype.h>
#define int long long
const int MARX = 1e3+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[20*MARX];
int n,p,k,num,ans , head[MARX],dis[MARX];
bool vis[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v,int w)
{
	e[++num].u = u,e[num].v = v, e[num].w = w;
	e[num].ne = head[u], head[u] = num;
}
bool check(int maxx)//检查 最大边权为maxx时的合法性 
{
	std::priority_queue <std::pair<int,int> > q;//dij最短路预处理 
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1] = 0 ;//以1为起点 
	q.push(std::make_pair(0,1));
	
	for(; !q.empty(); )//dij 最短路 
	{
	  std::pair <int,int> top = q.top();  q.pop();
	  if(vis[top.second]) continue;
	  vis[top.second] = 1;
	  
	  for(int i=head[top.second]; i; i = e[i].ne)
	    if(dis[e[i].v] > dis[e[i].u] + (e[i].w>maxx))
	    {
	      //大于枚举量的 边权值看做1, 其他看做0; 
	      dis[e[i].v] = dis[e[i].u] + (e[i].w>maxx);
	      q.push(std::make_pair(-dis[e[i].v], e[i].v));
		}
	}
	
	return dis[n] <= k;//检查合法性 
}
//=============================================================
signed main()
{
	n = read(), p = read(), k = read();
	for(int i=1; i<=p; i++) 
	{
	  int u = read(), v = read(), w = read();
	  add(u,v,w), add(v,u,w);
	}
	
	if(check(0)) {printf("0"); return 0;}
	for(int l=1,r=1e6+10; l<=r;)//二分答案 
	{
	  int mid = (l+r) >> 1;
	  if(check(mid)) ans = mid, r = mid - 1; 
	  else l = mid + 1;
	}
	printf("%lld",ans==0?-1:ans);
}
