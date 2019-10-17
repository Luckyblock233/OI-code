//知识点:SPFA/负权环/BFS 
/*
spfa bfs版 判负权环

在进行spfa的同时,记录每个点 在其最短路径中的出现次序
其出现次序 = 其父亲点出现次序+1
可知,对于一个无负权环图,

每个点的出现次序<=n
则:如果有一个点的出现次序>n,
可证明出现了负权环 
*/ 
#include<cstdio>
#include<queue>
using namespace std;
const int MARX = 2e6+10;
const int INF = 2147483647;
struct line
{
	int u,v,w;
	int ne;
}a[MARX];
int head[MARX],dis[MARX],cnt[MARX];
bool vis[MARX];
int num,n1,n,m;
void add(int u,int v,int w)//建图 
{
	a[++num].u=u;a[num].v=v;a[num].w=w;
	a[num].ne=head[u];head[u]=num;
}
bool spfa_bfs(int);
int main()
{
	int u,v,w;
	scanf("%d",&n1);
	for(int p=1;p<=n1;p++)
	  {
	  	num=0;
	  	scanf("%d%d",&n,&m);
	  	for(int i=1;i<=n;i++)//初始化 
		  {
		  	dis[i]=INF;
			vis[i]=head[i]=0;
		  }
	  	for(int i=1;i<=m;i++) 
	  	  {
	  	  	scanf("%d%d%d",&u,&v,&w);
	  	  	add(u,v,w);
	  	  	if(w >= 0) add(v,u,w);
		  }
		if(spfa_bfs(1)) printf("N0\n");
		else printf("YE5\n");
	  }
}
bool spfa_bfs(int s)
{
	queue <int> q;
	dis[s]=0,cnt[s]=1,vis[s]=1;//初始化 
	q.push(s);
	while(!q.empty())
	  {
	  	int u=q.front();
	  	q.pop();
	  	vis[u]=0;
	  	for(int i=head[u];i;i=a[i].ne)//疏导 
	  	  {
	  	  	int v=a[i].v,w=a[i].w;
	  	  	if(dis[v]>dis[u]+w)
	  	  	  {
	  	  	  	dis[v]=dis[u]+w;
	  	  	  	cnt[v]=cnt[u]+1;//更新出现次序 
	  	  	  	if(cnt[v]>n) return 0;//出现了负权环 
	  	  	  	if(!vis[v])
	  	  	  	  {
	  	  	  	  	q.push(v);
	  	  	  	  	vis[v]=1;
				  }
			  }
		  }
	  }
	return 1;
}
//dfs版spfa判负权环
/*
spfa dfs判负权环

以一个点为起点,开始dfs
如果这个点,可以疏导其他点
那么进行疏导,vis[其他点]=1,
递归 以被疏导点 为起点,继续dfs

如果在递归dfs中,
可以疏导一个vis[]=1,即被疏导过的点 
证明存在负权环 
*/ 
/* 
#include<cstdio>
#include<cstring>
using namespace std;
struct line
{
	int be,af,we;
	int ne;
}a[200011];
int head[200011];
bool vis[200011];
int dis[200011];
int num,flag=1;
void add(int bee,int aff,int wee)
{
	a[++num].ne=head[bee];
	a[num].be=bee;
	a[num].af=aff;
	a[num].we=wee;
	head[bee]=num;
}
void spfa_dfs(int);
int main()
{
	int n1,n,m;
	int beee,afff,weee;
	scanf("%d",&n1);
	for(int p=1;p<=n1;p++)
	  {
	  	num=0;flag=1;
	  	scanf("%d%d",&n,&m);
	  	for(int i=1;i<=n;i++)
		  dis[i]=vis[i]=head[i]=0;
	  	for(int i=1;i<=m;i++)
	  	  {
	  	  	scanf("%d%d%d",&beee,&afff,&weee);
	  	  	add(beee,afff,weee);
	  	  	if(weee >= 0) add(afff,beee,weee);
		  }
		for(int i=1;i<=n;i++)
		  {
		  	spfa_dfs(i);
		  	if(!flag) break;
		  }
		if(!flag) printf("YE5\n");
		else printf("N0\n");
	  }
	return 0;
}
void spfa_dfs(int s)
{
	int to;
	vis[s]=1;
	for(int i=head[s];i;i=a[i].ne)
	  {
	  	to=a[i].af;
	  	if(dis[s] + a[i].we < dis[to])
	  	  {
	  	  	dis[to] = dis[s] + a[i].we;
	  	  	if(vis[to] || !flag)
	  	  	  {
	  	  	  	flag=0;
	  	  	  	break;
			  }
	  	  	spfa_dfs(to);
		  }
	  }
	vis[s]=0;
}
*/ 
