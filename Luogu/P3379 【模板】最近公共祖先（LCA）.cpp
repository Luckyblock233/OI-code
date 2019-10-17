//知识点:LCA/树链剖分 
/*
使用重链剖分进行LCA
详见注释 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
//========================================================
const int MARX = 5e5+10;
struct edge
{
		int u,v,ne;
}a[2*MARX];
int head[MARX];
int num,n,m,root;
int s[MARX],dep[MARX],fa[MARX],son[MARX],c[MARX];//Tree Chain Dxxxxx 
//========================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void add(int u,int v) 
{
		a[++num].u=u,a[num].v=v;
		a[num].ne=head[u],head[u]=num;
}
void dfs1(int u,int fat)//求得每个点的,子树大小 , 重儿子 , 父亲 , 深度 ; 
{
		s[u]=1 , dep[u]=dep[fat]+1 , fa[u]=fat;//更新 
		for(int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)
			if(v!=fat)
			{
				dfs1(v,u); 
				s[u]+=s[v];//回溯 
				if(s[son[u]] < s[v]) son[u]=v;
			}
}
void dfs2(int u,int fat)//求得每个点所在链,与链的顶端 
{
		c[u]=fat;
		if(son[u]) dfs2(son[u],fat);//重链 
		else return;
		for(int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)//轻链 
			if(v!=fa[u] && v!=son[u])
				dfs2(v,v);
}
int lca(int x,int y)//求得lca 
{
		for( ;c[x]!=c[y]; x=fa[c[x]])//循环将深度较大的点上移,直到两点在同一条链上 
		  if(dep[c[x]] < dep[c[y]])
		    std::swap(x,y);
		return dep[x]<dep[y]?x:y;//返回深度较小的点 
}
//========================================================
signed main()
{
		n=read(),m=read(),root=read();
		for(int i=1;i<n;i++)
		{
		  int u=read(),v=read();
		  add(u,v) , add(v,u);
		}
		dfs1(root,0);//初始化,进行剖分 
		dfs2(root,root);
		while(m--)
		{
			int u=read(),v=read();
			printf("%d\n",lca(u,v));
		}
}

//时间空间都不如树链剖分
//并且很难打,容易出锅的倍增LCA
//详见注释 
/* 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX = 5e5+10;
int f[MARX][25],g[MARX][25];
int dep[MARX],head[MARX],lg[MARX];
int num;
struct baka9  //存边 
{
    int v;
    int ne;
}a[2*MARX];
int lca(int a,int b) //倍增法上跳 
{
    if(dep[a] < dep[b]) swap(a,b);
    while(dep[a] > dep[b])				  //移到同一深度 
      a=f[a][ lg[dep[a]-dep[b]] -1];
    if(a==b) return a;
    for(int k=lg[dep[a]]-1;k>=0;k--)//同时上跳 
      if(f[a][k] != f[b][k])
        a=f[a][k],b=f[b][k];
    return f[a][0];
}
void dfs(int u,int fa)  //dfs求深度,求向上2^n层的父亲 
{
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=1;(1<<i)<=dep[u];i++)
      f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=a[i].ne)
      if(a[i].v != fa)
        dfs(a[i].v,u);
}
void add(int u,int v)//建图 
{
    a[++num].v=v;
    a[num].ne=head[u];
    head[u]=num;
}
int main()
{
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)//建图 
      {
      	int u,v;
      	scanf("%d%d",&u,&v);
      	add(u,v);add(v,u);
      }
    dfs(s,0);
    for(int i=1;i<=n;i++)//预处理log函数 
      lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=m;i++)
      {
      	int a,b;
      	scanf("%d%d",&a,&b);
      	printf("%d\n",lca(a,b));
      }
}
*/ 
