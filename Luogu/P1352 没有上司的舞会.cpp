//知识点:树形DP 
/*
题目要求:
求一个树上点的点集 a, 
使 ai != father[aj] (i,j ∈ [1,n]) 
求此点集 的最大权值和 

分析题意:
对于一个点,
选择它 或 不选择它
只会对其 直接的儿子结点 产生影响 
也就是说,
如果其直系儿子节点的状态已经确定
就可以推出 该点的状态

算法实现:
设: f[i] 表示 选择第 i 个点后,其子树的最大权值和
    g[i]表示 , 不选择第i个点,其子树的最大权值和

那么对于一个子树的根节点 i,
及其 直系儿子结点 集合 son 
其状态转移方程为:
	f[i] = r[i] + ∑(g[v])  (v∈ son); 
	g[i] = ∑max(f[v],g[v]) (v∈ son);  

对于根节点最后的状态有两种情况
答案只需在 f[root] 与 g[root]取最大值即可 


注意的点:
由于可能出现负点权
所以有时选择此点 , 
比不选择此点更劣
要注意进行判断 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define int long long
const int MARX = 6e3+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX];
int n,num,root,head[MARX],in[MARX];//graph building
int r[MARX] , f[MARX],g[MARX];
//f[i]表示i参加的以i为根节点的子树的最大权值和,g[i]为不参加 
//=============================================================
inline int read() 
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)//建图 
{
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
void dfs(int u)
{
	int sum1=0,sum2=0; 
	for(int i=head[u];i;i=e[i].ne)
	{
	  dfs(e[i].v);//优先更新儿子结点 
	  sum1+=std::max(f[e[i].v],g[e[i].v]);//求得两和 
	  sum2+=g[e[i].v];
	}
	f[u]=sum2+r[u] , g[u]=sum1;//更新子树根节点的值 
//	printf("%lld %lld %lld\n",u,f[u],g[u]);
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1;i<=n;i++) r[i]=read();
	for(int i=1;i<n;i++)
	{
	  int v=read(),u=read();
	  add(u,v);
	  in[v]++;//入度++ 
	}
	for(int i=1;i<=n;i++)//寻找根节点 
	  if(!in[i]) {root=i;break;}
	dfs(root);
	printf("%lld",std::max(f[root],g[root]));//选择最终更优的状态 
}
