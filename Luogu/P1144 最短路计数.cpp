//知识点:BFS/图论
/*
欲求得到达每个点的 最短路 的条数
显然,
每个点的最短路条数 = 所有父亲点的最短路条数 之和 
所有边权值都为1
所以可以通过BFS来解决 
 
当访问到这个节点时，
如果是第一次访问，
由于是从起点1 开始BFS,
所以之前访问的时候,路径长度不会比之后访问小 
将这个节点的答案+=他父节点的答案，
并将此节点入队；

如果是第二次访问
且当前的距离等于之前记录的距离，
说明这是第二条最短路，
同样，将这个节点的答案+=他父节点的答案，
但不需要入队了。
*/ 
#include<cstdio>
#include<ctype.h>
#include<queue>
#include<algorithm>
const int MARX = 1e6+10;
const int INF = 2147483647;
//=============================================================
struct edge
{
	int v,ne;
}a[MARX*2];
int head[MARX],dis[MARX],ans[MARX]={0,1};
bool vis[MARX];
int n,m,x,y,num;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)//建图 
{
	a[++num].ne=head[u],a[num].v=v,head[u]=num;
}
void bfs()//BFS 
{
	for(int i=2; i<=n; i++) dis[i]=INF;
	std::queue <int> s; s.push(1);
	while(!s.empty())
	{
	  int top=s.front();
	  s.pop();
	  for(int i=head[top]; i; i=a[i].ne)
	  {
	  	int v=a[i].v;
		if(dis[v] >= dis[top]+1)
		{
		  if(dis[v] == dis[top]+1)//更新答案 
			ans[v] = (ans[v]+ans[top])%100003;
		  if(dis[v] > dis[top]+1) //更新答案并入队 
		  {
			dis[v] = dis[top]+1,
			ans[v] = ans[top]%100003,
			s.push(v);
		  }
		}
	  }
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<=m; i++)//建图 
	{
	  x=read(),y=read();
	  add(x,y),add(y,x);
	}
	bfs();
	for(int i=1; i<=n; i++) 
	  printf("%d\n",ans[i]%100003);
}
