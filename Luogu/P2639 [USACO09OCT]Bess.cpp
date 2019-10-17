//算法：DP
//将体积当做他的价值,
//状态转移方程式:  
//f[j]=max(f[j],f[j-v[i]]+v[i]);
#include<cstdio>
#include<algorithm>
using namespace std;
int vm,n;
int v[510];
int f[45010];
int main()
{
	scanf("%d%d",&vm,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
	  for(int j=vm;j>=v[i];j--)
	    f[j]=max(f[j],f[j-v[i]]+v[i]);
	printf("%d",f[vm]);
}
