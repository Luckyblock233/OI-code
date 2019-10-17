//知识点:Tarjan/强连通分量/缩点
/*
应用Tarjan实现的 缩点

求得各强连通分量后
将各强连通分量
作为新图的点
各强连通分量的权值 = 包含的点权值之和 
*/ 
#include<cstdio>
#include<stack>
#include<queue>
#include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b  //懒得写algorithm库 
#define max(a,b) a>b?a:b
#define int long long
#define R register
using namespace std;
//=================================================
const int MARX = 1e4+10;
struct edge //列出了各变量的作用
{
		int u,v,ne;
}e[MARX*10];
int n,m,num ,  head[MARX],we[MARX];  //graph_building建图 
int dn,be,  dfn[MARX],low[MARX],bel[MARX],val[MARX];//Tarjan
int ans,in[MARX],f[MARX];  //topsort拓扑排序 
stack <int> st;
//=================================================
inline int read()//快读 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void add(int u,int v)//建图 
{
	if(u==v) return ;
	e[++num].v = v,e[num].u=u;
	e[num].ne = head[u];head[u] = num;
}
void Tarjan(int u) 
{
	dfn[u]=low[u]= ++dn;//为 DFS序 与 low 赋值 
	st.push(u);					//入栈 
	for(R int i=head[u];i;i=e[i].ne)//枚举可以到达的边 
	{
	  int v=e[i].v;
	  if(!dfn[v]) Tarjan(v) , low[u]=min(low[u],low[v]);
	  //如果新点未被到达过, 则在新点dfs, 并在回溯时更新原点的low值 
	  else if(!bel[v]) low[u]=min(low[u],dfn[v]);
	  //如果新点到达过 但不在一个强连通分量中, 则用新点的dfs序更新源点 
	}
	if(low[u]==dfn[u])//回溯完成后,如果一个点的low值与dfs序相等,说明找到了一个环(即强连通分量) 
	{
	  ++be;//强连通分量数++ 
	  for (R int r=u+1; r!=u; st.pop())//栈中的,在同一分量中的元素回弹,知道弹到源点 
	  {
		r=st.top(); 
		bel[r]=be, 		  //更新所在分量号 
		val[be]+=we[r];	//此分量权值更新 
	  }
	}
}
void topsort()//拓扑排序 
{
	queue <int> q;
	for(int i=1;i<=be;i++)//找到入度为0的点 
	  if(!in[i]) q.push(i),f[i]=val[i], ans=max(ans,f[i]);
	while(!q.empty()) 
	{
	  int u=q.front();
	  q.pop();
	  for(R int i=head[u];i;i=e[i].ne)//更新能到达的点 
	  {
		int v=e[i].v;
		f[v]=max(f[v],f[u]+val[v]);
		if(!(--in[v])) q.push(v);
		ans=max(ans,f[v]);//更新答案 
	  }
	}
	printf("%lld",ans);//输出 
}
//=================================================
signed main() 
{
	n = read(),m = read();
	for(R int i=1;i<=n;i++) we[i] = read();//原始点权值 
	for(R int i=1;i<=m;i++) add(read(),read());//建原始图 
		
	for(R int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);//循环进行tarjan,直到每个点都进入一个强连通分量 
	memset(head,0,sizeof head);//清空原图(重复利用原数组 
	num=0;
	for(R int i=1 ; e[i].v ; i++)//枚举所有的原边 
	{
	  int u=e[i].u,v=e[i].v;
	  if(bel[u]!=bel[v])//不在同一分量中 
	  in[bel[v]]++ , add(bel[u],bel[v]);
	}
	topsort();
}
