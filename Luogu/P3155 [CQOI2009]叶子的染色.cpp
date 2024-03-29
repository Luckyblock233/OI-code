//知识点:树形DP 
/*
分析题意:
易证,随意选择一个不为叶节点的点为根
对答案没有任何影响
	证明:由题,
	着色方案应该保证根结点到每个叶子的简单路径上
	都至少包含一个有色结点（哪怕是这个叶子本身）
	叶节点的着色方案
	只与其上方第一个有色节点有关  
	由此,得证.

可以进行树形DP: 
设f[i][j] ,为 第i个点,将其染成j颜色,所需要的代价
则可以初始化: 
	f[i][1]=1,f[i][0]=1,代表将每个点，染成某种颜色的代价均为1
	特别的,对于叶节点,f[i][!c[i]] = INF ,
	（c[i]为叶节点需要染的色)表示叶节点i不应被染成其他颜色,所以代价极大

然后随意选择一个非叶节点,作为根节点,开始dfs 
可以得知,
	如果某一个节点需要被染成 x 色
	并且他的父亲节点已经被染成了 x 色
	则,他不需要被染色,就可以继承父亲的颜色
	则,对于某一个节点,
	其被染成 x 色的代价,
	可以直接继承其父亲被染成 x 色的代价
	也可以保持父亲为 非x 色,并将此节点单独染成 x 色 
则可以得到:
	状态转移方程: 
	f[u][0]+=min(f[v][0]-1,f[v][1]); (u表示v的父亲节点) 
	f[u][1]+=min(f[v][1]-1,f[v][0]);

*/
#include<cstdio>
#include<queue>
#include<ctype.h>
#define int long long
#define min(a,b) a<b?a:b
//======================================================
const int MARX = 1e4+10;
const int INF = 2147483647;//极大值 
struct edge 
{
	int u,v,ne;
}e[2*MARX];
int m,n,c[MARX];//输入数据 
int root,num,head[MARX]; //建树 
int f[MARX][2]; // f[i][j]表示,第i个点,将其染成j颜色,所需要的代价
//======================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void add(int u,int v)
{
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
void dfs(int u,int fa)
{
	if(u<=n) return ;//叶节点,直接return ; 
	for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)//枚举所有非父节点 
	  if(v!=fa)
	  {
	    dfs(v,u);
		f[u][0]+=min(f[v][0]-1,f[v][1]);//用子节点,更新当前点的各值 
		f[u][1]+=min(f[v][1]-1,f[v][0]);
	  }
}
//======================================================
signed main()
{
	m=read(),n=read();
	root=n+1;//随意选择一个不为叶节点的节点 
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=m-1;i++)
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u);
	}
	for(int i=1;i<=m;i++)//初始化 
	{
	  f[i][0]=f[i][1]=1;
	  if(i<=n) f[i][(!c[i])]=INF;//叶节点特殊初始化 
	}
	dfs(root,root);
	printf("%lld",min(f[root][0],f[root][1]));//取较小的值 
}
