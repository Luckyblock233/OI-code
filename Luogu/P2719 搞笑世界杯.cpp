//算法：DP
/*
设f[i][j]为 还剩i张A种票，j张B种票 时，
两人选到同一种票的概率

由此,可 初始化 f[i][0]=f[0][i]=1 , 因为这些情况绝对选到同一种票.

则: 
当 剩i张A种票，j张B种票 时， 
那么此时的排队的第一个人只有两种选择 
拿A类票或者B类票

抛硬币得到的可能性当然是二分之一，
所以说d[i-1][j]（当前第一人拿了A类票）
和d[i][j-1]（当前第一人拿了B类票）
各占二分之一
*/ 
#include<cstdio>
using namespace std;
int n;
double f[2000][2000];
int main()
{
	scanf("%d",&n);
	n>>=1;
	for(int i=2;i<=n;i++) 
	  f[i][0]=f[0][i]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    f[i][j]=(f[i-1][j] + f[i][j-1])*0.5;
	printf("%.4lf",f[n][n]);
}
