//算法:DP/背包 
/* 
二维费用01背包
有分数维 与 人数维
要满足分数<=总分的一半 , 人数<=总人数的一半 
用分数替换价值 
*/
#include<cstdio>
#define max(a,b) a>b?a:b
const int MARX = 1e6+10;
//===============================================
int n,ans,sum,a[MARX],f[60][MARX];
//===============================================
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//输入 
	{
	  scanf("%d",&a[i]);
	  sum+=a[i];
	}
	sum>>=1,n>>=1;
	for(int i=1;i<=(n<<1);i++)
	  for(int j=sum;j>=a[i];j--)
	    for(int k=n;k>=1;k--)//分数即价值 
	      f[k][j]=max(f[k][j],f[k-1][j-a[i]]+a[i]);
	printf("%d",f[n][sum]);//输出 
}
