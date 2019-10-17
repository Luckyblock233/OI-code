//知识点: DP 
/*
By:Luckyblock
题目要求:
给定一棵树, 点有点权
求一棵 子树, 使其点权和最大

分析题意:
对于 以u点 为根的子树,
其 最大点权和为:
其 最大点权和>0的子树的 最大点权和 + 其自身权值
发现可以通过递归, 来进行更新
考虑树形dp

设f[i] 为以 u点 为根的子树, 的最大点权和:
则有状态转移方程为: 
f[u] = ∑(f[v] * (f[v]>0)) + w[u]
dfs进行树形dp
在进行dfs时, 取最大的点权和为答案 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
#define max(a,b) a>b?a:b
const int MARX = 1e4+6e3+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<1];
int n,num,ans, w[MARX],head[MARX];
int f[MARX]; // 以 u点 为根的子树, 的最大点权和
//============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)//建图 
{
	e[++num].u=u, e[num].v=v;
	e[num].ne=head[u], head[u]=num;
}
void dfs(int u,int fa)//dfs进行树形dp 
{
	f[u] = w[u];
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v != fa)
	  {
		dfs(e[i].v,u);//转移更新 
		f[u] += f[e[i].v]*(f[e[i].v]>0);
	  }
	ans = max(ans,f[u]);//取最大值 
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1; i<=n; i++) w[i]=read();
	for(int i=1; i<n; i++)
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%lld",ans);
}
