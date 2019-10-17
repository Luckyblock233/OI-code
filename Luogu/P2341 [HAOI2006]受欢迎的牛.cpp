//知识点:Tarjan/强连通分量/缩点/topsort
/*
简略的题意:
求 被所有其他点直接/间接相连
	  的点的数量 

分析题意: 
可知: 
用Tarjan缩点 ,
求得各强连通分量后

如果仅存在一个
出度为0的强连通分量
那么该强连通分量的元素个数
即答案要求 

正确性证明: 
如果存在多个出度为0的分量
则这些分量
缺少它们之中其他分量的相连
故不能满足题目要求:
被所有其他分量直接/间接相连 
 
*/ 
#include<cstdio>
#include<stack>
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
int ans,in[MARX];  //topsort拓扑排序 
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
		e[++num].u=u,e[num].v = v;
		e[num].ne = head[u],head[u] = num;
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
		int in_num=0; 
		for(int i=1;i<=be;i++)//找到入度为0的点 
		  if(!in[i]) in_num++,ans=val[i];
		
		printf("%lld",in_num==1?ans:0);//输出 
}
//=================================================
signed main() 
{
		n = read(),m = read();
		for(R int i=1;i<=n;i++) we[i] = 1;
		for(R int i=1;i<=m;i++) add(read(),read());//建原始图 
		
		for(R int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);//循环进行tarjan,直到每个点都进入一个强连通分量 
		memset(head,0,sizeof head);//清空原图(重复利用原数组 
		num=0;
		for(R int i=1 ; e[i].v ; i++)//枚举所有的原边 
		{
			int u=e[i].u,v=e[i].v;
			if(bel[u]!=bel[v])//不在同一分量中 
		    in[bel[v]]++ , add(bel[v],bel[u]);
		}
		
		topsort();
}
