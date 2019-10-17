//知识点:LCA/树链剖分 
/*
题意分析:
可以发现:
如果两条路径 a-b 与 c-d 有重合部分 , 
那么必然有: lca(a,b)在c-d上 , lca(c,d)在a-b上
	证明: 
	因为lca , 是一条路径的 "转折点" 或 较浅端点
	则: 如果两条路径有公共部分
	那么公共部分的 一端点 , 
	必然是上述两lca中的一个 

还可以发现 , 
如果满足:
  1.deep[x]>=deep[LCA(s,t)]
  2.LCA(s,x)=x或LCA(t,x)=x;
那么x是路径  s-t上的一点 

算法实现:
由上,可以通过树剖 , 来求得多个 lca
在进行判断 , 即可 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define R register
#define abs(a) a<0?-a:a
//========================================================
const int MARX = 5e5+10;
struct edge//建边 
{
		int u,v,ne;
}a[2*MARX];
int head[MARX];
int num,n,m,root;
int s[MARX],dep[MARX],fa[MARX],son[MARX],c[MARX];//树剖相关变量 
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
	for(R int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)
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
	for(R int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)//轻链 
	  if(v!=fa[u] && v!=son[u])
		dfs2(v,v);
}
inline int lca(int x,int y)//求得lca 
{
	for( ;c[x]!=c[y]; x=fa[c[x]])//循环将深度较大的点上移,直到两点在同一条链上 
	  if(dep[c[x]] < dep[c[y]])
		std::swap(x,y);
	return dep[x]<dep[y]?x:y;//返回深度较小的点 
}
//========================================================
signed main()
{
	n=read(),m=read(),root=1;
	for(R int i=1;i<n;i++)
	{
	  int u=read(),v=read();
	  add(u,v) , add(v,u);
	}
	dfs1(root,0);//初始化,进行剖分 
	dfs2(root,root);
	while(m--)
	{
	  int aa=read(),bb=read(),cc=read(),dd=read(); 
	  int lca1=lca(aa,bb) , lca2=lca(cc,dd);//求lca 
	  if(dep[lca1]<dep[lca2])//使lca1较深 
	  {
	  	std::swap(lca1,lca2);std::swap(aa,cc);std::swap(bb,dd);
	  }
	  if(lca(lca1,cc)==lca1 || lca(lca1,dd)==lca1) printf("Y\n");//如果满足条件 
	  else printf("N\n");
	}
}