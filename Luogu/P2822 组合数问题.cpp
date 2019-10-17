//知识点: 数论,思路题 
/*
题目要求:
先给定 k,
多次询问,每次询问给定n,m
求 有多少对(i,j) 满足C(i,j)是k的倍数
0<=i<=n && 0<=j<=min(i,m) 

分析题意:
发现 n,m<=2000, 但是查询次数t<=1e4;
要求一个 较低的查询复杂度.
则需要 考虑预处理. 

根据 杨辉三角 和组合数的性质:
杨辉三角第i行第j列 = 第i-1行第j列 + 第i-1行第j-1列 
= C(i-1,j-1) =从i-1个物品中 选择j-1个物品的方案数 
那么可以预处理出 给定范围内所有的组合数 

由于要求 满足C(i,j)%k 的对数,
可以在杨辉三角递推的过程中,同时进行取模运算
并记录 到达第C(i,j) 时, C(i1,j1)%k==0 的对数.

最后对于每次询问,
O(1)查询前缀和答案即可. 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//=============================================================
const int MARX = 2010;
int t,k,n,m;
int a[MARX][MARX];//存 C(i,j) % k 
int ans[MARX][MARX];//存 到C(i,j) 有多少对满足条件的答案 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	t=read(),k=read();
	a[0][0]=a[1][0]=a[1][1]=1;//初始化杨辉三角 
	for(int i=2;i<=2000;i++)
	{
	  a[i][0]=1;//首项 
	  for(int j=1;j<=i;j++)//递推 
	  {	
	  	a[i][j]=(a[i-1][j-1] + a[i-1][j])%k;//递推,求得C(i,j) 
	  	ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];//记录前缀答案 
	  	if(!a[i][j])ans[i][j]++;//C(i,j) 合法 
	  }
	  ans[i][i+1]=ans[i][i];//记录前缀答案 
	}
	while(t--)//O(1)回答询问 
	{
	  n=read(),m=read();
	  if(m>n) printf("%lld\n",ans[n][n]);
	  else printf("%lld\n",ans[n][m]);
	}
}
