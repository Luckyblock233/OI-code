//知识点:Tarjan/强连通分量/割点
/*
应用Tarjan求割点 

按照dfs的遍历顺序 , 
将图看成一棵树,
图便有了层次性. 
将dfs回溯的边当做回边 

用Tarjan,
dfn[]记录每一个点的dfs序,
low[]记录能连通的dfs序最小的点的编号

可以发现,初始时dfn[i]=low[i]
在不断dfs递归过程中进行更新

1.对于搜索树的根节点,
  如果它有两个或两个以上的子树
  去掉这个点后,这两个子树会不连通
  说明它是一个割点
2.对于其他的节点: 
  更新完成后,
  如果有一条边 ,满足low[v]>=dfn[u]
  说明v点,一定到达不了u点的祖先 (dfs树意义下的祖先) 
  那么u点是一个割点 
*/
#include<cstdio>
#include<stack>
#include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b 
#define max(a,b) a>b?a:b
#define int long long
#define R register
using namespace std;
//=================================================
const int MARX = 2e4+10;
struct edge //列出了各变量的作用
{
	int u,v,ne;
}e[MARX*10];
int n,m,num ,  head[MARX];  //graph_building建图 
int dn,sum, dfn[MARX],low[MARX];//Tarjan
bool cut[MARX];
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
void Tarjan(int u,int fa) 
{
	dfn[u]=low[u]= ++dn;//为 DFS序 与 low 赋值 
	int child=0;
	for(R int i=head[u];i;i=e[i].ne)//枚举可以到达的边 
	{
	  int v=e[i].v;
	  if(!dfn[v]) //如果新点未被到达过, 则在新点dfs, 并在回溯时更新原点的low值 
	  {
	  	Tarjan(v,fa);
		low[u]=min(low[u],low[v]);//更新能到达的dfs序最小的点的编号 
		if(low[v]>=dfn[u] && u!=fa)//u点不为搜索树的根节点,且v点到达不了u点的祖先
		{
		  if(!cut[u]) sum++;
		  cut[u]=1;//u点为割点
		}
		if(u==fa) child++;//子树数量++ 
	  }
	  low[u]=min(low[u],dfn[v]);//更新low值 
	}
	if(child>=2 && u==fa)//u为搜索树的根节点,并且至少有两个子树 
	{
	  if(!cut[u]) sum++;
	  cut[u]=1;
	}
}
//=================================================
signed main() 
{
	n = read(),m = read();
	for(R int i=1;i<=m;i++) 
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u); 
	}
	for(R int i=1;i<=n;i++)//循环进行tarjan,直到每个点都被到达过  
	  if(!dfn[i]) Tarjan(i,i);
	  
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++)
	  if(cut[i]) printf("%lld ",i);
}
