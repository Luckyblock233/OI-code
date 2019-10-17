//知识点:分层图,最短路 
/*
By:Luckyblock
分层图 ,顾名思义,
即建立 多层 相同或相似的 图, 并在图与图之间进行连边
可以实现 两种性质的图 之间的  转移,
或是 图与图 之间 有限制的转移 

不过 建多层图时间空间 消耗都巨大, 
因此适用的 数据范围 一般较小 

对于本题: 
按照 坐飞机次数进行分层, 层与层之间转移代表坐飞机
两层之间 建立边权为0的 单向边 
单层之间 建立边权为原值的 单向边 

之后即可 从第0层的s 跑单源最短路
其与 各层之间的 t, 路径的最小值
即为 答案所求 
*/
#include<cstdio>
#include<queue>
#include<ctype.h>
#define min(a,b) (a<b?a:b)
#define int long long
const int MARX = 2e6+10;
const int INF = 0x7ffffffff;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<2];
struct p//堆优化dj ,自定义优先级 
{
	int num,diss;
	bool operator < (const p &a) const {return diss > a.diss;}
}tmp;
int n,m,k,s,t,ans=INF, num,head[MARX],dis[MARX];
bool f[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v,int w)//建图 
{
	e[++num].u = u, e[num].v = v, e[num].w = w;
	e[num].ne = head[u], head[u] = num;
}
void djkstra(int start)//dj求 第0层s 到第k层t 的最短路 
{
	std::priority_queue <p> q;
	tmp.num = start, tmp.diss = 0; q.push(tmp);
	for(int i=0; i<=n*(k+1); i++) dis[i] = INF;//对所有层的所有点 赋极值 
	dis[start]=0;//初始化 
	
	while(!q.empty())//堆优化dj 
	{
	  int top=q.top().num; q.pop();
	  if(f[top]) continue;
	  f[top]=1;
	  for(int j=head[top]; j; j=e[j].ne)//找k点的临点, 并进行比较 
		if(dis[e[j].v] > dis[top] + e[j].w)//更新最短路 
		{
		  dis[e[j].v] = dis[top] + e[j].w;
		  tmp.num = e[j].v , tmp.diss = dis[e[j].v];
		  q.push(tmp);
		}
	}
}
//=============================================================
signed main()
{
	n = read(), m = read(), k = read();
	s = read(), t = read();
	for(int i = 1; i <= m; i ++)
	{
	  int u = read(), v = read(), w = read();
	  add(u,v,w), add(v,u,w);
	  for(int j = 1; j <= k; j ++)//按照 坐飞机次数进行分层
	  {
	    add(u + n*(j-1) , v + n*j , 0);//两层之间 建立边权为0的 单向边 
	    add(v + n*(j-1) , u + n*j , 0);
	    add(u + n*j , v + n*j , w);//单层之间 建立边权为原值的 单向边 
	    add(v + n*j , u + n*j , w);
	  }
	}
	djkstra(s);
	for(int i=0; i<=k ;i++) 
	  ans = min(ans,dis[t + i*n]);//求最小答案 
	printf("%lld",ans);
}
