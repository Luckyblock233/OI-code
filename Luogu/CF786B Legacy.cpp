//知识点:线段树优化建图 
/*
线段树优化建图
用于解决 
类似 从 x 向区间[L,R]的 
区间连边问题 

原图:
1 2 3 4
向其中添加一系列虚点 ,
并将虚点与实点 , 虚点与虚点 连边,
将添加的边,的边权值设为0 之后:
		o 
      /   \ 
    o      o 
  / \     / \ 
 1   2   3   4

形成一棵满二叉树

对于这棵满二叉树,
可以将其当作一棵线段树,
来进行一系列的操作:

1. 对于 从 x 向区间[L,R]连边操作:
   由于新添加的边权全为0
   所以只需要将 x 与 
   "管辖" 着 [L,R] 区域的虚点连线即可
   可以类比线段树的区间查询,
   进行递归查询, 
   
   要连接的边数,
   由 R-L级别 ,转化为了log(R-L)级别 
   
2. 对于 从 区间[L,R] 向 x 连边操作:
   逆向操作
   考虑反向连边即可
   同时在初始化时,
   也要注意 初始化反向的边 
3. 对于 从x 向 y连边操作
   直接连接即可 
   
算法实现:
先进行两次 初始化建树操作
分别处理正向与反向的 ,
与虚点之间的连边, 
将其设置为0.

然后对于每种连边操作,
按照上述法则,
将x与实点/虚点 连边 

最后跑一遍最短路即可


注意的一些小点:
1.为了不影响实点之间的连边
  虚点,即线段树上的点 的编号,
  从n+1开始编号 
*/ 
#include<cstdio>
#include<queue>
#include<cstring>
#define ll long long
const int MARX = 3e5+10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
//============================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<4];//各边 
int n,q,start;//输入的初始变量 
std:: queue <int> qu;//spfa的队列 
int num,head[MARX];//建图变量 
int cnt,root1,root2,ls[MARX],rs[MARX];//线段树变量 (ls为左儿子,rs为右儿子) 
ll dis[MARX];//spfa 变量 
//============================================
inline void add(int u,int v,int w)
{
	e[++num].v=v,e[num].u=u,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
void build1(int &s,int l,int r)//初始化 从父亲向儿子的0边 
{
	if(l==r)//递归向下,直到 到达叶子部的 实点, 
	{
	  s=l;//实点的编号不变 
	  return;
	}
	s = ++cnt;//更新当前虚点的编号 
	int mid = (l+r)>>1;
	build1(ls[s],l,mid);//递归左右子树 
	build1(rs[s],mid+1,r);
	add(s,ls[s],0);//向下连0边 
	add(s,rs[s],0);
}
void build2(int &s,int l,int r)//类比build1,进行反向连0边 
{
	if(l==r)
	{
	  s=l;
	  return;
	}
	s = ++cnt;
	int mid = (l+r)>>1;
	build2(ls[s],l,mid);
	build2(rs[s],mid+1,r);
	add(ls[s],s,0);
	add(rs[s],s,0);
}
int L,R;//要操作的左右区间 
void updata(int s,int l,int r,int u,int w,int type)//s:当前点编号; l,r:当前点s管辖区间 ; type:操作的种类 
{
	if(L<=l && r<=R)//操作区间 包含 当前区间 
	{
	  if(type==2) add(u,s,w);//按照种类,进行连边操作. 
	  else add(s,u,w);
	  return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid) updata(ls[s],l,mid,u,w,type);//递归进行操作 
	if(mid<R) updata(rs[s],mid+1,r,u,w,type);
}
void spfa(int start)//他死了 
{
	memset(dis,0x3f,sizeof(dis));
	dis[start]=0;qu.push(start);
	while(!qu.empty())
	{
	  int u=qu.front(); qu.pop();
	  for(int i=head[u];i;i=e[i].ne)
	  {
	  	int v=e[i].v,w=e[i].w;
	  	if(dis[u]+w < dis[v])
	  	{
	  	  dis[v]=dis[u]+w ;
		  qu.push(v);	
		}
	  }
	}
}
//============================================
signed main()
{
	scanf("%d%d%d",&n,&q,&start);
	cnt=n;//为不影响实点之间的连边 , 虚点,从n+1开始编号 
	build1(root1,1,n),build2(root2,1,n);//初始化 
	for(int i=1;i<=q;i++)
	{
	  int opt,u,v,w;
	  scanf("%d",&opt);
	  if(opt==1)
	  {
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);//直接连接 
	  }
	  else
	  {
	  	scanf("%d%d%d%d",&u,&L,&R,&w);
	  	updata((opt==2?root1:root2),1,n,u,w,opt);//按照种类,进行操作 
	  }
	}
	
	spfa(start);
	/*
	for(int i=1;i<=n;i++)
	  for(int j=head[i];j;j=e[j].ne)
	    printf("%d %d %d\n",i,e[j].v,e[j].w);
	*/
	for(int i=1;i<=n;i++) printf("%lld ",dis[i]<INF?dis[i]:-1); 
}
