//知识点:Tarjan/强连通分量/缩点
/*
使用Tarjan 
求得最大的 强连通分量 

在得到强连通分量时
与之前的答案进行比较
取长度较长,且字典序较小的
作为答案

详见注释 
*/ 
#include<cstdio>
#include<algorithm>
#include<stack>
#include<string>
#include<ctype.h>
#define min(a,b) a<b?a:b  //懒得写algorithm库 
#define R register
using namespace std;
//=================================================
const int MARX = 5e3+10;
struct edge //列出了各变量的作用
{
	int u,v,ne;
}e[MARX*10];
int n,m,num ,  head[MARX];  //graph_building建图 
int dn,be,  dfn[MARX],low[MARX],bel[MARX];//Tarjan
int max_unicom,ans[MARX];//最大强连通分量大小 , 答案 
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
inline void check(int tmp[],int l)//比较函数,获得答案 
{
	std::sort(tmp,tmp+l);//对答案进行排序 
	if((l==max_unicom && tmp[0]<ans[0]) || (l>max_unicom))//取长度较长,且字典序较小的,作为答案 
	  for(int i=0;i<l;i++)//赋新的答案 
	    ans[i]=tmp[i];
	max_unicom=max(max_unicom,l);//更新大小 
}
void Tarjan(int u) 
{
	dfn[u]=low[u]= ++dn;//为 DFS序 与 low 赋值 
	st.push(u);	//入栈 
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
	  int sum=0;
	  int tmp[MARX];
	  for (R int r=u+1; r!=u; st.pop())//栈中的,在同一分量中的元素回弹,直到弹到源点 
	  {
		r=st.top(),tmp[sum++]=r;
		bel[r]=be; 		  //更新所在分量号 
	  }
	  check(tmp,sum);
	}
}
//=================================================
signed main() 
{
	n = read(),m = read();
	for(R int i=1;i<=m;i++) //建原始图 
	{
	  int u=read(),v=read(),t=read();
	  add(u,v);
	  if(t==2) add(v,u);
	}
	for(R int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);//循环进行tarjan,直到每个点都进入一个强连通分量 
	printf("%d\n",max_unicom);
	for(int i=0;i<max_unicom;i++) printf("%d ",ans[i]);
}
