//算法：DP/多维价值背包 
//除拿到资料数外,另增一维工资 
//只需要将一维数组转变为二维数组,
//并多加一层循环即可 
//状态转移方程式:f[j][k]=max(f[j][k],f[j-v[i]][k-w[i]]+c[i]);
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x;
int w[110];//伪装能力 
int c[110];//工资 
int v[110];//拿到资料 
int f[1010][1010];//前 伪装能力 ，后工资 
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&v[i],&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=w[i];j--)
	  	for(int k=x;k>=c[i];k--)
	  	  f[j][k]=max(f[j][k],f[j-w[i]][k-c[i]]+v[i]);
	printf("%d",f[m][x]);
}
