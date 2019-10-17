//知识点:背包DP,并查集 
/*
By:Luckyblock
题目要求:
给定一些物品 ,有价值和质量.
一些物品必须一起购买,
求 给定容量的背包能到达的最大价值和 

分析题意:
考虑将 必须一起买的物品转化为 一个合成物品
合成物品 价值 = 内部物品价值之和,
合成物品 质量 = 内部物品质量之和, 
可以使用并查集进行维护 ,
并求得各合成物品的价值质量.

物品合成完毕后,
问题就转化为了一般的01背包问题. 
*/
#include<cstdio>
#include<ctype.h>
#define max(a,b) (a>b?a:b) 
const int MARX = 1e4+10;
//=============================================================
int n,m,w,c[MARX],d[MARX] , c1[MARX],d1[MARX]; 
int BEL,pre[MARX],group[MARX],bel[MARX];//并查集
int f[MARX];//背包DP 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int find(int x) { return (pre[x]==x)?(x):(pre[x]=find(pre[x])); }//查集 
void join(int x,int y)//并集 
{
	int r1=find(x),r2=find(y);
	if(r1!=r2) pre[r2]=r1;
}
//=============================================================
signed main()
{
	n=read(),m=read(),w=read();
	for(int i=1;i<=n;i++)//输入并初始化 
	{
	  pre[i]=i;
	  c[i]=read(),d[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
	  int u=read(),v=read();
	  
	  if(bel[u] || bel[v])//如果有一个 加入了一个合成物品 
	  {
	    if(bel[u]) c1[bel[u]]+=c[v] , d1[bel[u]]+=d[v],bel[v]=bel[u];//加入u的合成物品 
	    else c1[bel[v]]+=c[u] , d1[bel[v]]+=d[u],bel[u]=bel[v];//加入v的合成物品 
	  }
	  else
	  {
	    bel[u]=bel[v]= ++BEL;//新建一个合成物品 
	    c1[BEL]+=(c[u]+c[v]) , d1[BEL]+=(d[u]+d[v]);
	  }
	  join(u,v);//并集 
	}
	for(int i=1;i<=n;i++)//将单个,不需要合并购买的物品 , 转化为合成物品 
	  if(!bel[i]) c1[++BEL]+=c[i] , d1[BEL]+=d[i];
	for(int i=1;i<=BEL;i++)//01背包 
	  for(int j=w;j>=c1[i];j--)
	    f[j]=max(f[j],f[j-c1[i]]+d1[i]);
	printf("%d",f[w]);
}
