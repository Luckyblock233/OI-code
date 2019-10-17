//知识点:树的直径, 单调队列 
/*
By:Luckyblock
P1099 树网的核 的 数据加强版 

题目要求: 
给定一棵树, 边有边权
求一条 边长度和<=s 的路径, 
使其他所有点 到这条路径的距离的 最大值最小。

分析题意:

- 有一显然的 性质:
  对于 任意树上的节点, 距离其最远的点 一定为树的直径的端点 
  证明:
  1. 对于直径上一点x,  
     设 其与直径上两端点 的距离分别为: x1,x2, 且有x1 > x2
	 设 其与非直径上的点 中距离最远的 点的距离 为y
	 则必然有 x1 > y
	
	 可以反证: 
	 若 y > x1, 则  x1 + y > x1 + x2
	 则应选择 x1 与 y 作为 直径, 而非 x1 与 x2
	 反证 结论正确 
	 
  2.若P不在直径上，使用反证法，
    假设此时WQ不是直径，AB是直径

	若AB与PQ有交点C，由于P到Q最远，
	那么 PC+CQ>PC+CA，所以CQ>CA，易得 CQ+CB>CA+CB，即CQ+CB>AB，
	与AB是直径矛盾，不成立，如下图
	
  3.若AB与PQ没有交点，M为AB上任意一点，N为PQ上任意一点。
    首先还是NP+NQ>NQ+MN+MB，同时减掉NQ，得NP>MN+MB，
	易知NP+MN>MB，所以NP+MN+MA>MB+MA，即NP+MN+MA>AB，
	与AB是直径矛盾，所以这种情况也不成立
	
  - 则可 先求得树的直径, 并记录树的直径上的点
  	使用DFS处理较为容易
  	之后就可以 枚举树的直径上 长度<=s的合法区间 

- 可以发现 一些性质:
  若固定区间一端点, 并向另一侧寻找 合法的端点
  若 被固定端点 左移, 则另一端点 必然不右移
	 
  两端点的 位置变化量满足单调性
  则可以使用 双指针(尺取法) 来枚举每一个区间

- 对于每一个 合法区间, 
  如何求得 其他所有点 到这条路径的距离的最大值? 
  对路径外的点 进行分类讨论:
  1.对于在直径上的点,
  	显然, 直径的端点 距离此区间 比非端点远
	
	则只需考虑 直径两端点 到达区间对应两端点的 距离 
    可以对 直径上的点维护一前缀和 来做到O(1)查询
	
  2.对于在直径外的点,
  	显然, 当直径上 与其距离最近的点 在区间内时,
	才有可能 做出贡献
	否则 选择直径的端点 必然比选择 它更优
	
	则可以 维护 以每个直径上的点为起点, 不经过直径上其他点, 能到达的点的 最远距离
	在 枚举区间时 维护 距选择路径上的点 最远的直径外的点 
	显然是一个滑动窗口最值问题
	可以使用单调队列维护 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<queue>
#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int INF = 1e15+7;
const int MARX = 3e5+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<1];
int n,num, s,u,v,head[MARX];//建图变量
int dis[MARX], pre[MARX],map[MARX];//求树的直径, dis记录距离,  pre记录路径, map存直径上两相邻点的距离  
int ans = 1e15, sum[MARX], dis1[MARX];//sum记录直径上距离的前缀和, dis1记录直径上点i到 直径外点的最长距离 
int que[MARX]={INF},t=0, h=0;//单调队列- 
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
void dfs(int now,int fat,int sum,bool flag)//dfs求得 树的直径 
{
	if(flag) pre[now] = fat, map[now] = sum;//第二次dfs记录路径 (前驱 
	dis[now] = dis[fat] + sum;//更新距离 
	for(int i = head[now]; i; i = e[i].ne)
	  if(e[i].v != fat) dfs(e[i].v,now,e[i].w,flag);
}
void get_road()//求得 树的直径 
{
	dfs(1,0,0ll,0); //一次dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//选择 距离最远的点 
	  if(dis[i] > maxdis) u = i,maxdis = dis[i];
	dfs(u,0,0ll,1); //二次dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//选择 距离最远的点 
	  if(dis[i] > maxdis) v = i,maxdis = dis[i];
}
void bfs()//bfs处理 以每个直径上的点为起点, 不经过直径上其他点, 能到达的点的 最远距离
{
	memset(dis,63,sizeof(dis));
	std::queue <int> q,from;
	for(int i = v; i != 0; i = pre[i]) //将直径上的点加入 队列 
	  q.push(i), from.push(i), dis[i] = 0;
	  
	for(; !q.empty();)
	{
	  int now = q.front(),fr = from.front(); q.pop(),from.pop();
	  for(int i = head[now]; i ; i = e[i].ne)//枚举出边 
	    if(dis[e[i].v] >= INF)//未被更新过 
	    {
	      dis[e[i].v] = dis[now] + e[i].w;//更新最远距离 
	      dis1[fr] = max(dis1[fr],dis[e[i].v]);
		  q.push(e[i].v),from.push(fr);
		}
	}
}
void solve()
{
	pre[n+1] = v;
	for(int i = n + 1; i != 0; i = pre[i]) //预处理前缀和 
	  sum[pre[i]] = sum[i] + map[i];
	
	for(int l = v,r = v; l != 0 && r!=u; l = pre[l])//当r=u时停止枚举,之后枚举的区间都不合法 
	{
	  int last = r; ++h;
	  while(sum[r] - sum[l] <= s && r != 0) //枚举右端点 
	  {
	  	last = r, r = pre[r];
	  	if(r != 0 && sum[r] - sum[l] <= s)//单调队列更新 
	  	{
	  	  for(;dis1[r] >= que[t] && t >= h;) t--;
	  	  que[++t] = dis1[r];	
		}
	  }
	  if(r == 0 || sum[r] - sum[l] > s) r = last;//越界处理 
	  
	  int now = max(sum[l] , sum[u] - sum[r]);//更新答案 
	  now = max(now, que[h]);
	  ans = min(now, ans);
	}
}
//=============================================================
signed main()
{
	n = read(), s = read();
	for(int i = 1; i < n ;i ++)
	{
	  int u1 = read(), v1 = read(), w1 = read();
	  add(u1,v1,w1), add(v1,u1,w1);
	}
	get_road(); bfs(); solve();
	printf("%lld",ans);
}
/*
6 1000
1 2 999
2 3 100
3 4 1000
3 5 100
5 6 999
*/ 
