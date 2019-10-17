//知识点:Tarjan,拓扑排序. 
/*
By:Luckyblock

分析题意:
按照给定的 举报揭发关系建立一张有向图后, 可以发现:
1. 对于一个强连通分量里的点,
   即一个举报关系形成了一个环 的间谍群 
   只需要 贿赂此强连通分量中的一个间谍 , 就可以摧毁整个间谍群
   显然 , 贿赂花费最少的间谍更优
   所以对于一个强连通分量,
   其权值为 强连通分量中最小的点权
   
2. 对于缩点后形成的DAG,
   只需要摧毁 入度为0的强连通分量
   那么整个DAG都会被摧毁. 
	
问题转化为:
先进行缩点 , 找到所有入度为0的强连通分量 
1.有解情况: 
  如果入度为 0的强连通分量都可以被摧毁,
  那么 答案为所有入度为0的 强连通分量 权值的和.
2.无解情况:
  如果入度为 0的强连通分量中,
  有些不能被摧毁
  那么枚举每一个不能被摧毁的强连通分量
  各强连通分量中编号最小的点 , 即为所求. 

代码很好写 , Tarjan + topsort
详见注释 
*/
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#define int long long
const int INF = 0x7f7f7f7f7f7f7f7f;//极大值 
const int MARX = 3010;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<2];
int n,p,m,num , head[MARX],we[MARX];//raw graph build
int we1[MARX],minn[MARX];//cooked graph build
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
void prepare()
{
	memset(we,0x7f,sizeof(we));//初始化权值为极大值 
	memset(we1,0x7f,sizeof(we1));
	memset(minn,0x7f,sizeof(minn));
	n=read(),p=read();
	for(int i=1;i<=p;i++) //读入原始点权 
	{
	  int now=read();
	  we[now]=read();
	}
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
	  	we1[BEL]=std::min(we1[BEL],we[i]);//更新强连通分量权值 
	  	minn[BEL]=std::min(minn[BEL],i);//更新强连通分量中编号最小的点. 
	  }
	}
}
void topsort()
{
	bool flag=0; int ans1=INF;
	for(int i=1;i<=BEL;i++) 
	  if(!in[i]) //找到所有入度为0的强连通分量 
	  {
	 	if(we1[i]>=INF) flag=1,ans1=std::min(ans1,minn[i]);//无解情况 
		else ans+=we1[i];//有解情况 
	  }
	if(flag) printf("NO\n");//按照有无解进行输出 
	else printf("YES\n");
	printf("%lld",flag?ans1:ans);
}
//=============================================================
signed main()
{
	prepare();
	for(int i=1;i<=n;i++) //循环进行tarjan 
	  if(!dfn[i]) tarjan(i);
	  
	for(int i=1;i<=num;i++)//更新各强连通分量的入度 
	  if(bel[e[i].u]!=bel[e[i].v])
	    in[bel[e[i].v]]++;
	topsort();
	
}
