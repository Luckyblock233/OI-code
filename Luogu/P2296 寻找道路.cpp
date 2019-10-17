//知识点 :图论 
/*
By:Luckyblock
分析题意:
题意中指出: 路径上的所有点的出边 , 
所指向的点都直接或间接与终点联通 

所以要将不直接或间接与终点联通的点 , 
即不合法点都在图中删除.

直接寻找与终点不直接间接联通的点 比较麻烦
但是可以进行转换,
先寻找 直接间接与终点相连的点. 


算法实现:
要寻找直接间接与终点相连的点,
可以通过从终点反向BFS来实现.

先将 与终点直接连通的点加入队列,
之后 再将与队列中的点相连接的点 加入队列
给队列中的点打标记,表明暂时合法.

在暂时合法的 点中,还存在一些 与不合法的点直接相连的点
它们也是不合法的
所以还要枚举不合法的点, 即没有被打上暂时合法标记的点
将与他们直接相连的点的暂时合法标记去除.

最后对于仍然存在标记的点,
在它们中跑一遍 最短路即可. 
*/
#include<cstdio>
#include<queue>
#include<ctype.h>
#define int long long
const int INF = 2e9+7;
const int MARX = 1e4+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<5];
int n,m,st,to , head[MARX],dis[MARX];//存图 
bool vis[MARX],ju[MARX];//标记合法点 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void bfs()//bfs求得合法点 
{
    std::queue <int> qu; qu.push(to);
	while(!qu.empty())//以终点为起点 , 进行反向bfs 
	{
	  int top=qu.front();
	  qu.pop();
	  for(int i=head[top]; i; i=e[i].ne)//枚举出边 
	    if(!ju[e[i].v])
		{
	  	  ju[e[i].v]=1;//打上暂时合法标记 
	  	  qu.push(e[i].v);
	 	}
	}
	ju[to]=1;//出点合法 
	bool jud[MARX]={0};
	for(int i=1; i<=n; i++)
	  if(!ju[i])//剔除 与不合法的点相邻的暂时合法点 
	    for(int j=head[i]; j; j=e[j].ne)
		  jud[e[j].v]=1;//打不合法标记 
	for(int i=1; i<=n; i++)//去除合法标记 
	  ju[i]=( jud[i]?0:ju[i] );
}
void spfa()//最短路模板 
{
	for(int i=1; i<=n; i++) dis[i]=INF * ju[i];//初始化 
	std::queue <int> qu; qu.push(to);
	dis[to]=0 , vis[to]=1;
	while(!qu.empty())//spfa 
	{
	  int u=qu.front(); 
	  qu.pop();
	  vis[u]=0;
	  for(int i=head[u]; i; i=e[i].ne)
	  	if(ju[e[i].v] && dis[u]+1<dis[e[i].v])
	  	{
	  	  dis[e[i].v]=dis[u]+1;
	  	  if(!vis[e[i].v]) qu.push(e[i].v);
	  	  vis[e[i].v]=1;
		}
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)//建图 
	{
	  int u=read(),v=read();
	  e[i].u=v , e[i].v=u;
	  e[i].ne=head[e[i].u],head[e[i].u]=i;
	}
	st=read(),to=read();
	bfs();
	if(ju[st])//起点合法 
	{
	  spfa();
	  printf("%lld",dis[st]==INF?-1:dis[st]);
	  return 0;
	}
	printf("-1");
}
