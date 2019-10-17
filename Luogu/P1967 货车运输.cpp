//知识点:LCA,倍增,最小生成树 
/*
题目要求: 
经过边权的最大的最小值是多少

分析题意:
想到建立最小瓶颈生成树
并且重建树完成后 , 
原图会变成一个森林
为方便查询两点是否连通 
想到使用kruscal , 来重新建图 

重建图后 , 
对于要查询的两点 ,
先判断是否在一个连通块中
如果在一个联通块中 , 
那么求得他们的lca
答案 , 即两点到lca路径上的最小的边权 .

可以用倍增 , 
维护一个点 , 到它上方第 2^i个点
路径上的的最小边权 

则可以在求lca
循环上跳的过程中
将 答案 与 经过的路上的最小边权 取小 
维护答案 最小
最后输出即可 
*/ 
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
//====================================================================
const int MARX = 1e5+10;
const int INF = 2147483647;
struct edge
{
	int u,v,w,ne;//分存每一条边前,后坐标与权值 
}e1[5*MARX],e[10*MARX];
int q,n,m,root,num1,num2,head[MARX],pre[MARX];
int f[MARX][25],g[MARX][25];//上方第2^i个点 与 到它上方第 2^i个点路径上的的最小边权  
int dep[MARX];
bool vis[MARX];
//====================================================================
bool cmp(edge aa,edge bb){return aa.w>bb.w;}//结构体sort排序必须自定义排序函数 
inline void add1(int u,int v,int w){e1[++num1].u=u,e1[num1].v=v,e1[num1].w=w;}//原图 
inline void add2(int u,int v,int w) {e[++num2].u=u,e[num2].v=v,e[num2].w=w;e[num2].ne=head[u],head[u]=num2;}//重建图 
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}//查集 
void join(int x,int y)//并集 
{
	int r1=find(x),r2=find(y);
	if(r1 != r2) pre[r1]=r2;
}
int lca(int a,int b) //倍增法上跳 
{
	if(find(a)!=find(b)) return -1;//不连通 
	int ans=INF;
    if(dep[a] < dep[b]) std::swap(a,b);//保证被操作的a为较深的点 
    for(int i=20;i>=0;i--)			  //移到同一深度 
      if(dep[f[a][i]] >=dep[b])
	  {
      	ans=min(ans,g[a][i]);//答案取小 
      	a=f[a][i];
	  }
    if(a==b) return ans;
    for(int k=20;k>=0;k--)//同时上跳 
      if(f[a][k] != f[b][k])//不跳过lca 
        ans=min(ans,min(g[a][k],g[b][k])),a=f[a][k],b=f[b][k];//先更新答案,在将两点上跳 
    ans=min(ans,min(g[a][0],g[b][0])); 
	return ans;
}
void dfs(int u)  //dfs求深度,求向上2^n层的父亲 
{
    vis[u]=1;
    for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)//找能到达的点 
      if(!vis[v])
	  {
        dep[v]=dep[u]+1;//更新深度 
        f[v][0]=u , g[v][0]=e[i].w;//初始化 
        dfs(v);
	  }
}
//====================================================================
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int j=1;j<=m;j++)
	{
	  int u,v,w;
	  scanf("%lld%lld%lld",&u,&v,&w);//输入各边权值 
	  add1(u,v,w);
	}
	for(int i=1;i<=n;i++) pre[i]=i;//重置先祖 
	std::sort(e1+1,e1+num1+1,cmp);
	for(int i=1;i<=num1;i++)//kruscal重建图 
	{
	  if(find(e1[i].u) == find(e1[i].v)) continue;
	  join(e1[i].u,e1[i].v);
	  add2(e1[i].u,e1[i].v,e1[i].w);//建无向边 
	  add2(e1[i].v,e1[i].u,e1[i].w);
	}
	for(int i=1;i<=n;i++)//dfs收集各信息 
	  if(!vis[i])
	  {
	  	dep[i]=1; 
	  	dfs(i);
	  	f[i][0]=i , g[i][0]=INF;
	  }
	for(int i=1;i<=20;i++)//动态更新 上方第2^i个点 与 到它上方第 2^i个点路径上的的最小边权 
	  for(int j=1;j<=n;j++)
	    f[j][i]=f[f[j][i-1]][i-1],
	    g[j][i]=min(g[j][i-1],g[f[j][i-1]][i-1]);
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)//回答询问 
      {
      	int a,b;
      	scanf("%lld%lld",&a,&b);
      	printf("%lld\n",lca(a,b));
      }
}
