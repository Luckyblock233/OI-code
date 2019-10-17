//算法：DP
//求最长不下降子序列的长度
//及最长不下降子序列的数量

//长度方程式: f[i] = max(f[j] +1,f[i]) (a[i]>a[j]) 

//数量可在求长度时一块求得:
//当f[i]<f[j]+1时,说明长度可以更长 , 数量需要被更新,此时 g[i] = g[j]
//当f[i]==f[j]+1时,说明 还有更多的满足长度最长,此时 g[i] += g[j]
#include<cstdio>
using namespace std;
int t,n;
int a[21];
int f[21],g[21];
int main()
{
	scanf("%d",&t);
	while(t--)
	  {
	  	scanf("%d",&n);
	  	for(int i=1;i<=n;i++)
	  	  {
	  	  	scanf("%d",&a[i]);
	  	  	f[i]=g[i]=1;
		  }
		int m1=1,m2=1;
	  	for(int i=1;i<=n;i++)//求长度与数量 
	  	  for(int j=1;j<i;j++)
	  	    if(a[j]<=a[i])
			  {
			  	if(f[j]+1>f[i]) f[i]=f[j]+1,g[i]=g[j]; 
			  	else if(f[j]+1 == f[i]) g[i]+=g[j];
			  }
		for(int i=1;i<=n;i++)//找最优解 
		  {
		  	if(f[i]>m1) m1=f[i];
		    if(g[i]>m2) m2=g[i];
		  }
		printf("%d %d\n",m1,m2);
	  }
}  
