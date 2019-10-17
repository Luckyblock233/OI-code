//算法：DP，树状背包,依赖背包,DFS 

//先输入数据,建树
//没有先修课的课程的点的父亲结点为0 
//然后从0开始dfs
//向下找m层,即选择m门课程 

//对于第i个点,枚举他的儿子
//设f[i][j]表示选择以i为根的子树中j个节点。
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int v,ne;
}a[100010];
int n,m;
int num;
int va[310],head[310];
int f[2010][2010];
void add(int u,int v)//存边建树 
{
	a[++num].v=v;
	a[num].ne=head[u];
	head[u]=num;
}
void dfs(int u,int s)
{
	if(s<=0) return ;
	for(int j=head[u];j;j=a[j].ne)
	  {
	  	int v=a[j].v;
	  	for(int k=0;k<s;k++)//这里k从0开始到s-1，因为v的子树可以选择的节点是u的子树的节点数减一
	  	  f[v][k]=f[u][k]+va[v];//已经确定必须选v点，所以必须加上va[v] 
	  	dfs(v,s-1);
	  	for(int k=1;k<=s;k++)
	  	  f[u][k]=max(f[u][k],f[v][k-1]);//这里是把子树的值赋给了根节点，因为u选择k个点v只能选择k-1个点。 
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  {
	    int fa;
	   	scanf("%d%d",&fa,&va[i]);//建树 
	   	add(fa,i);
	  }
	dfs(0,m);
	printf("%d",f[0][m]);//直接输出以0为根,选择m个节点的值 
}
