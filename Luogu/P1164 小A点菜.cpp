//算法:DP,01背包

//01背包变体
//由于要求方案数,
//初始化f[0]=1,即正好花费0元的方案为1. 
//状态转移方程为:f[j]=f[j]+f[j-a[i]]
//其中i为菜品编号,j为正好花的钱数 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
int f[10010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	f[0]=1;//初始化 
	for(int i=1;i<=n;i++)//DP 
	  if(a[i]<=m)//特判 
	    {
	  	  for(int j=m;j>=a[i];j--)
	  	    f[j]+=f[j-a[i]];
	    } 
	printf("%d",f[m]);
}
