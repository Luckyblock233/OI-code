//算法：DP
//将体积当做他的价值,
//状态转移方程式:  
//f[j]=max(f[j],f[j-v[i]]+v[i]);
//因为最多可以装VM体积，如果f【j】==VM，直接输出即可
//因为没有更优的解了 
#include<cstdio>
#include<algorithm>
using namespace std;
int vm,n;
int v[5010];
int f[50010];
int main()
{
	scanf("%d%d",&vm,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
	  for(int j=vm;j>=v[i];j--)
	    {
	      f[j]=max(f[j],f[j-v[i]]+v[i]);
	      if(f[j]==vm)
	        {
	          printf("%d",f[vm]);
			  return 0;	
			}
		}
	printf("%d",f[vm]);
}
