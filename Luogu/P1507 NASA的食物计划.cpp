//算法：DP/01背包
//本题为01背包变体,除体积外,另增一维质量
//只需要将一维数组转变为二维数组,
//并多加一层循环即可 
//状态转移方程式:f[j][k]=max(f[j][k],f[j-v[i]][k-w[i]]+c[i]);
#include<cstdio>
#include<algorithm>
using namespace std;
int vm,mm;
int n;
int v[51];//体积 
int w[51];//质量 
int c[51];//价值 
int f[410][410];//前体积，后质量 
int main()
{
	scanf("%d%d%d",&vm,&mm,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&v[i],&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	  for(int j=vm;j>=v[i];j--)
	  	for(int k=mm;k>=w[i];k--)
	  	  f[j][k]=max(f[j][k],f[j-v[i]][k-w[i]]+c[i]);
	printf("%d",f[vm][mm]);
}
