//知识点:Tarjan缩点 
/*
By:Luckyblock
题意分析:
先将给定的有向图进行缩点 
可以发现 :
1.入度非0的点的信息, 都可以从别的点传输过来.
2.入度为0的点的信息不可从其他点传输,
  所以 必须在入度为0的点上 发布信息	
  
发现只在入度为0的点上传输信息是最优的 , 
所以答案 = 缩点后入度为0的点的个数 
*/
#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#define int long long
const int MARX = 1e5+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<3];
int n,p,m,num , head[MARX];//graph build
int DFN,BEL , dfn[MARX],low[MARX],bel[MARX];//Tarjan
int ans,in[MARX];//topsort
std::stack <int> st; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v)//建图 
{
	if(u==v) return ;
	e[++num].v = v,e[num].u=u;
	e[num].ne = head[u];head[u] = num;
}
void tarjan(int u)//tarjan缩点 
{
	dfn[u]=low[u]=++DFN;//初始值 
	st.push(u);
	for(int i=head[u];i;i=e[i].ne)
	{
	  int v=e[i].v;
	  if(!dfn[v]) tarjan(v),low[u]=std::min(low[v],low[u]); 
	  //如果新点未被到达过, 则在新点dfs, 并在回溯时更新原点的low值 
	  else if(!bel[v]) low[u]=std::min(low[u],dfn[v]);
	  //如果新点到达过 但不在一个强连通分量中, 则用新点的dfs序更新源点  
	}
	if(low[u]==dfn[u])//找到一个强连通分量 
	{
	  ++BEL;
	  for(int i=u+1;i!=u;st.pop())
	    i=st.top() , bel[i]=BEL;
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();//建图 
	for(int i=1;i<=m;i++)
	{
	  int u=read(),v=read();
	  add(u,v);
	}
	
	for(int i=1;i<=n;i++) 
	  if(!dfn[i]) tarjan(i);
	  
	for(int i=1;i<=num;i++)//更新入度 
	  if(bel[e[i].u]!=bel[e[i].v])
	    in[bel[e[i].v]]++;
	for(int i=1;i<=BEL;i++)  ans+=(!in[i]);//更新答案 
	printf("%lld",ans);
}
