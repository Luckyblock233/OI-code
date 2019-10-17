//知识点:Tarjan,缩点;
/*
By:Luckyblock

抽象化题意:
给定一n个点,m条边的有向图 , 点有点权 
要求在每个强连通分量中选择一个点,
使选择的点的点权之和最小
求最小点权和,和选择的方案数.

分析题意:
显然 , 选择每个强连通分量中点权最小的点 , 是最优的 
对于最小点权和 , 是唯一的

为什么会出现不同的 方案?
说明对于每个强连通分量中的最小点权,可能有多种选择 .  

算法实现: 
先进行Tarjan缩点,
对于每一个强连通分量 ,  
记录 每一个强连通分量中 的最小点权 和 最小点权的出现次数.

那么根据乘法原理, 方案数 = 最小点权出现次数 的 乘积. 
*/
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#define int long long
const int INF = 0x7f7f7f7f7f7f7f7f;//long long的极大值(8个字节 
const int MARX = 1e5+10;
const int mod = 1e9+7;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<2];
int n,p,m,num , head[MARX],we[MARX];//raw graph build
int we1[MARX],quan[MARX];//cooked graph build
int DFN,BEL , dfn[MARX],low[MARX],bel[MARX];//Tarjan
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
void prepare()
{
	memset(we1,0x7f,sizeof(we1));
	n=read();
	for(int i=1;i<=n;i++) we[i]=read();//读入原始点权 
	m=read();
	for(int i=1;i<=m;i++)//建图 
	{
	  int u=read(),v=read();
	  add(u,v);
	}
}
void tarjan(int u)
{
	dfn[u]=low[u]=++DFN;//u点的原始dfn值与low值 
	st.push(u);
	for(int i=head[u];i;i=e[i].ne)//dfs u点能到达的点 
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
	  for(int i=u+1;i!=u;st.pop())//将各点加入强连通分量中 
	  {
	  	i=st.top() , bel[i]=BEL;
	  	
	  	if(we1[BEL]==we[i]) quan[BEL]++;
	  	if(we1[BEL]>we[i]) we1[BEL]=we[i],quan[BEL]=1;//更新强连通分量权值 	
	  }
	}
}
//=============================================================
signed main()
{
	prepare();
	for(int i=1;i<=n;i++) //循环进行tarjan 
	  if(!dfn[i]) tarjan(i);
	
	int ans1=0,ans2=1;
	for(int i=1;i<=BEL;i++) ans1+=we1[i],ans2=(ans2*quan[i])%mod;//更新点权和和方案数 
	printf("%lld %lld",ans1,ans2);
}
