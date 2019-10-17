//知识点:LCA/树链剖分 
/*
题目要求: 
在树上寻找一个节点
使给定三个点,
到达该点的总路程最短

分析题意:
易证,树上三个点,
他们的三对LCA,定有两对是相同的 
比较容易得到,不需证明 

可以证得,最优集合点,
即三个点的三对LCA 中 深度最深的一个 
	证明:
	假设求得一x,为a,b的LCA,
	且为三个LCA中深度最深的一个
	那么对于其他LCA x':
	    x'的深度 < x的深度 
	   可知:如果集合点设为x' , 
	    c点到达集合点的路程会增加w 
	   但a,b两点到达集合点的总路程会增加 2w

故,求得三个点三对LCA中,深度最深的,
在计算出他们之间的距离
就可得到答案 

由于数据范围较大,
使用时间复杂度较小的树剖完成 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define max_dep(a,b) dep[a]>dep[b]?a:b
#define R register
//========================================================
const int MARX = 5e5+10;
struct edge
{
		int u,v,ne;
}a[2*MARX];
int head[MARX];
int num,n,m,root,ans;
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
		  int ans1=0,ans2=0;
		  int tmp1=read(),tmp2=read(),tmp3=read();//求得三对lca 
		  int lca1=lca(tmp1,tmp2) ,lca2=lca(tmp1,tmp3) ,lca3=lca(tmp2,tmp3);
		  ans1=max_dep(lca1,max_dep(lca2,lca3));//求得三对lca中深度最大的 
		  ans2=dep[tmp1]+dep[tmp2]+dep[tmp3]-dep[lca1]-dep[lca2]-dep[lca3];//计算距离 
		  printf("%d %d\n",ans1,ans2);
		}
}
