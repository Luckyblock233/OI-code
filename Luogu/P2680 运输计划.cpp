//知识点:图论,lca 
/*
By:Luckyblock
题目要求:
可选择树上任意一边,将其权值置零
求树上多条路径权值和的最小值 

m=1,20分:
只有一条树上路径
显然,将此路径上 权值最大边 的权值置零最优
暴力上跳至lca , 求得路径权值和 和 最大边权值
输出 权值和 - 最大边权 即可 
 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define max(a,b) a>b?a:b
#define ll long long
const int INF = 2147483647;
const int MARX = 3e5+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<1];
int n,m,num , head[MARX],fa[MARX],dis[MARX],dep[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)
{
	e[++num].u=u,e[num].v=v,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
void dfs(int u, int fat)
{
	fa[u]=fat,dep[u]=dep[fat]+1;
	for(int i=head[u];i;i=e[i].ne)
	  if(e[i].v!=fat)
	  {
	    dis[e[i].v]=e[i].w;
	    dfs(e[i].v,u);
	  }
}
ll lca(int a, int b)
{
	ll marx=0,sum=0;
	if(dep[a]<dep[b]) std::swap(a,b);
	for(;dep[a]>dep[b];a=fa[a]) 
	  sum+=dis[a],
	  marx=max(marx,dis[a]);
	
	for(;a!=b;a=fa[a],b=fa[b]) 
	  sum+=(dis[a]+dis[b]),
	  marx=max(marx,dis[a]), marx=max(marx,dis[b]);
	  
	return sum-marx;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w),add(v,u,w);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
	  int u=read(),v=read();
	  printf("%lld",lca(u,v));
	}
}
