//知识点:分层图,最短路 
/*
By:Luckyblock
题目给出操作:
可以使边权值变为 原边权的一半
点数<=50, 此 操作次数<=50 

很显然的 分层图问题 
按照 进行边权减半次数进行分层, 层与层之间转移代表边权减半操作 
两层之间 建立边权为0的 单向边 
单层之间 建立边权为原值的 单向边 

之后即可 从第0层的1 跑单源最短路
其与 各层之间的 n, 路径的最小值
即为 答案所求 
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<ctype.h>
#define min(a,b) (a<b?a:b)
const int MARX = 220010;
//=============================================================
struct edge
{
	int u,v,ne,w;
}e[20*MARX];
struct p//堆优化dj ,自定义优先级 
{
	int num,diss;
	bool operator < (const p &a) const {return diss > a.diss;}
}tmp;
int n,m,k,s,t, num,head[MARX];
int ans,dis[MARX];
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
	memset(dis,0x3f,sizeof(dis));
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
	s = 1, t = n;
	for(int i = 1; i <= m; i ++)
	{
	  int u = read(), v = read(),w = read();
	  add(u,v,w), add(v,u,w);
	  for(int j = 1; j <= k; j ++)//按照 坐飞机次数进行分层
	  {
	    add(u + n*(j-1) , v + n*j , w/2);//两层之间 建立边权为原边权1半的 单向边 
	    add(v + n*(j-1) , u + n*j , w/2);
	    add(u + n*j , v + n*j , w);//单层之间 建立边权为原值的 单向边 
	    add(v + n*j , u + n*j , w);
	  }
	}
	djkstra(s);
	ans = 2e9+7;
	for(int i=0; i<=k ;i++) ans = min(ans,dis[t + i*n]);//求最小答案 
	printf("%d",ans);
}
