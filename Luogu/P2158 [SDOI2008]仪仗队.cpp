//算法:数论/欧拉函数 
/*
沿着对角线
将这个正方形切开，
得到两个直角三角形。

发现，实际上要求的答案
大概就是在1到n的范围里
不同的gcd（i，j）的个数，

对于一个特定的i，
gcd（i，j）的个数
就是i-1的欧拉函数值。

那么这个问题
转化成为了欧拉函数的版子题。 
*/
#include<cstdio>
using namespace std;
int n,num;
int phi[100010]={0,1};
int p[100010];
bool vis[100010]={1,1};
void prime(int n)//欧拉筛求欧拉函数值 
{
	for(int i=2;i<=n;i++)
	  {
	  	if(!vis[i]) p[++num]=i,phi[i]=i-1;//质数的欧拉函数值 
	  	for(int j=1;j<=num;j++)
	  	  {
	  	  	if(i*p[j]>=n) break;
	  	  	vis[i*p[j]]=1;
	  	  	if(i%p[j]==0) 
			  {
			  	phi[i*p[j]]=phi[i]*p[j];//合数的欧拉函数值 
			    break;	
			  }
			else phi[i*p[j]]=phi[i]*phi[p[j]];//由最小公因子求得欧拉函数值 
		  }
	  }
}
signed main()
{
	scanf("%d",&n);
	if(n==1) //n==1时的特判 
	  {
		printf("0");
		return 0;
	  }
	prime(n);
	int ans=0;
	for(int i=1;i<=n-1;i++)//求和 
	  ans+=phi[i];
	printf("%d",ans*2+1);//获得答案 
}
