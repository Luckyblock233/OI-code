//算法:DP
//由题意知, 只能由小组I更换到小组I+1
//则在某一环节,选择某一小组的天数,
//只由 该小组上一环节的天数,与上一小组上一环节的天数有关

//就可以愉快的写出状态转移方程:
//f[j][i]=min(f[j][i-1],f[be[j]][i-1])+a[j][i];
//代表第i各环节选择第j个小组 的天数的最优解

//最后再循环m各小组,找到最小解即可 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[2010][2010];
int f[2010][2010];
int be[2010];
int main()
{
	scanf("%d%d",&n,&m);
	be[1]=m;
	for(int i=2;i<=m;i++) be[i]=i-1;//记录上一小组 
	
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%d",&a[i][j]); 
	    
	for(int i=1;i<=n;i++)//愉快的DP 
	  for(int j=1;j<=m;j++)
	    f[j][i]=min(f[j][i-1],f[be[j]][i-1])+a[j][i];
	    
	int ans=2147483640;
	for(int i=1;i<=m;i++)//找到最优解 
	  ans=min(ans,f[i][n]);
	printf("%d",ans);
}
