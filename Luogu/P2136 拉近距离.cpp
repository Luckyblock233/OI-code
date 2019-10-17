//知识点:SPFA,负权环,BFS 
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
#include<cctype>
#include<queue>
const int MARX = 2e6+10;
const int INF = 2147483647;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX];
bool vis[MARX];
int num,n,m,head[MARX],dis[MARX],cnt[MARX];;
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
	e[++num].ne=head[u]; head[u]=num;
	e[num].u=u; e[num].v=v; e[num].w=w;
}
bool spfa_bfs(int s)
{
	for(int i=1; i<=n; i++) dis[i]=INF, vis[i] = cnt[i] = 0; 
	std::queue <int> q;
	dis[s]=0, cnt[s]=1, vis[s]=1;
	q.push(s);
	for(;!q.empty();)//spfa 
	{
	  int top=q.front(); q.pop();
	  vis[top]=0;
	  for(int i=head[top]; i; i=e[i].ne)
	  {
	  	int v=e[i].v, w=e[i].w;
	  	if(dis[v] > dis[top]+w)
	  	{
	  	  dis[v] = dis[top]+w , cnt[v] = cnt[top] +1;//记录次序 
	  	  if(cnt[v] > n) return 0;//判断 
	  	  if(!vis[v]) q.push(v), vis[v]=1;
		}
	  }
	}
	return 1;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<=n; i++) dis[i]=INF;
	for(int i=1; i<=m; i++)
	{
	  int u=read(), v=read(), w=read();
	  add(u,v,-w);
	}
	//存在负权环 
	if(!spfa_bfs(1)) {printf("Forever love"); return 0;}
	
	int minn = dis[n]; 
	spfa_bfs(n);//以n为起点spfa 
	printf("%d", dis[1]>minn?minn:dis[1]); 
}

