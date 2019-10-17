//算法：DP/背包 
/*
既然说要都用素数，必须先筛出素数
如果是素数，就要判断是否取
每个素数可以无限取-->完全背包
*/ 
#include<cstdio>
#define max(a,b) a>b?a:b
using namespace std;
const int MARX = 10100;
int n,num;
int p[MARX];
bool vis[MARX]={1,1};//存是否为质数 
long long ans[MARX]={1};
void prime(int n)
{
	for(int i=2;i<=n;i++)//枚举数 
	  {
	  	if(!vis[i]) p[++num]=i;//为质数 
	  	for(int j=1;j<=num;j++)//打标记 
	  	  {
	  	  	if(i*p[j]>n) break;
	  	  	vis[i*p[j]]=1;
	  	  	if(i%p[j]==0) break;
		  }
	  }
}
int main()
{
	
	while(scanf("%d",&n)!=EOF)
	  {
	  	for(int i=1;i<=n;i++)
	  	  ans[i]=0;
	    prime(n);
	    for(int i=2;i<=n;i++)//完全背包 
	      if(!vis[i])//是素数,则可取 
	        for(int j=i;j<=n;j++) 
	          ans[j]+=ans[j-i];
	    printf("%lld\n",ans[n]);
	  }
}
