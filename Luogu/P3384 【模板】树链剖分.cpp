//知识点:LCA/树链剖分 /线段树 
/*
非常恶心的数据结构模板 

记录树链剖分的第二次dfs时的dfs序
可以发现 , 
每一条重链上的元素 , 在 dfs序中相邻
每一个根节点的子树上的元素 ,在dfs序中相邻

根据这种相邻关系 , 
则:可以使用线段树进行区间操作 
以实现树上操作
  
将 树链剖分 + 线段树 进行了融合 
详见注释 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define int long long
#define ls (s<<1)
#define rs (s<<1)+1
#define R register
//========================================================
const int MARX = 1e5+10;
struct edge
{
	int u,v,ne;
}e[2*MARX];
int head[MARX];//graph build建图变量 
struct node
{
	int w,l,r,tag;
}a[4*MARX];//线段树节点 
int num,n,m,root,mod; 
int raw[MARX] , cook[MARX];//原数列 , 与dfn序排列的数列 
int dep[MARX],fa[MARX],son[MARX],top[MARX],s[MARX];//树链剖分变量  s为(子树大小) 
int D,dfn[MARX];//dfs序变量 
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
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
void dfs1(int u,int fat)//求得每个点的,子树大小 , 重儿子 , 父亲 , 深度 ; 
{
	s[u]=1 , dep[u]=dep[fat]+1 , fa[u]=fat;//更新 
	for(R int i=head[u],v=e[i].v ;i; i=e[i].ne,v=e[i].v)
	  if(v!=fat)
	  {
		dfs1(v,u); 
		s[u]+=s[v];//回溯 , 更新子树大小 
		if(s[son[u]] < s[v]) son[u]=v;//更新重儿子 
	  }
}
void dfs2(int u,int fat)//求得每个点所在链,与链的顶端 , 与dfs序 
{
	dfn[u]=++D,cook[D]=raw[u],top[u]=fat;//更新dfs序 , 更新以dfs序为下标 的 原始权值数组 
	if(son[u]) dfs2(son[u],fat);//重链 
	else return;
	for(R int i=head[u],v=e[i].v ;i; i=e[i].ne,v=e[i].v)//轻链 
	  if(v!=fa[u] && v!=son[u])
		dfs2(v,v);
}
void build(int s , int l , int r)//递归建树 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) //叶子节点 
	{
	  a[s].w=cook[l];return ;
	}
	build (ls,l,mid);//左右子树 
	build (rs,mid+1,r);
	a[s].w=(a[ls].w+a[rs].w)%mod;
}
void pushdown(int s)//下放懒标记 
{
	a[ls].w=(a[ls].w+(a[ls].r-a[ls].l+1)*a[s].tag)%mod;//更新左右儿子的值 
	a[rs].w=(a[rs].w+(a[rs].r-a[rs].l+1)*a[s].tag)%mod;
	a[ls].tag=(a[ls].tag+a[s].tag)%mod; 
	a[rs].tag=(a[rs].tag+a[s].tag)%mod;//更新左右儿子的懒标记 
	a[s].tag=0;
}
void change(int s , int l , int r , int k)//区间更新 
{
	if(a[s].l>=l && a[s].r<=r)//在需要的区间内 
	{
	  a[s].w=(a[s].w+(a[s].r-a[s].l+1)*k)%mod;//更新 
	  a[s].tag=(a[s].tag+k)%mod;
	  return ;
	}
	if(a[s].tag) pushdown(s);//下放 
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//左右区间包括所需区间 
	if(r>mid)  change(rs,l,r,k);
	a[s].w=(a[ls].w+a[rs].w)%mod;
}
int search(int s , int l , int r)//区间查询 
{
	if(a[s].l>=l && a[s].r<=r)//在需要的区间内 
	  return a[s].w;
	if(a[s].tag) pushdown(s);
	int mid=(a[s].l+a[s].r)>>1,ans=0;
	if(l<=mid) ans=(ans+search(ls,l,r))%mod;//区间求和 
	if(r>mid)  ans=(ans+search(rs,l,r))%mod;
	return ans;
}
//========================================================
void change1(int x,int y,int z)// 将树从x到y结点最短路径上所有节点的值都加上z
{
	while(top[x]!=top[y])// 将x,y移到同一条链上 
	{
	  if(dep[top[x]] < dep[top[y]]) std::swap(x,y);//每次都操作较深的点 
	  change(1,dfn[top[x]],dfn[x],z);//改变经过的重链 
	  x=fa[top[x]];//转移位置 
	}
	if(dep[x]>dep[y]) std::swap(x,y);//操作较深的点 
	change(1,dfn[x],dfn[y],z);//改变x,y之间的区域 
}
void change3(int x,int z){change(1,dfn[x],dfn[x]+s[x]-1,z);}// 将以x为根节点的子树内所有节点值都加上z 
void search2(int x,int y)//求树从x到y结点最短路径上所有节点的值之和
{
	int ans=0;
	while(top[x]!=top[y])// 将x,y移到同一条链上 
	{
	  if(dep[top[x]] < dep[top[y]]) std::swap(x,y);//每次都操作较深的点 
	  ans=(ans+search(1,dfn[top[x]],dfn[x]))%mod;//答案+=经过的重链的所有点权值和 
	  x=fa[top[x]];
	}
	if(dep[x]>dep[y]) std::swap(x,y);
	ans=(ans+search(1,dfn[x],dfn[y]))%mod;//ans+=x,y之间区域的点权值和 
	printf("%lld\n",ans);
}
void search4(int x){printf("%lld\n",search(1,dfn[x],dfn[x]+s[x]-1));}//求以x为根节点的子树内所有节点值之和
//========================================================
signed main()
{
	n=read(),m=read(),root=read(),mod=read();
	for(R int i=1;i<=n;i++) raw[i]=read();
	for(R int i=1;i<n;i++)
	{
	  int u=read(),v=read();
	  add(u,v) , add(v,u);
	}
	dfs1(root,0);//初始化,进行剖分 
	dfs2(root,root);
	build(1,1,n);
	while(m--)
	{
	  int q=read(),x=read(),y,z;
	  switch (q)//四种操作 
	  {
	  	case 1:{y=read(),z=read()%mod;change1(x,y,z);break;}
	  	case 2:{y=read();search2(x,y);break;}
	  	case 3:{z=read()%mod;change3(x,z);break;}
	  	case 4:{search4(x);break;}
	  }
	}
}
