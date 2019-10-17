//算法：DP/01背包
//一道01背包的变体
//与普通01背包区别在于:
//不选某物时,也会得到一定的价值
//所以状态转移方程为:f[j]=max(f[j]+lose[i],f[j-use[i]]+win[i]);
//同时注意,当j<use[i]时,也需要加上不选第i件物品的价值
#include<cstdio>
#include<algorithm>
using namespace std;
int n,x;
int lose[1010],win[1010],use[1010];
long long f[1010];//注意long long 
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&lose[i],&win[i],&use[i]);//输入 
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=x;j>=0;j--) 
	  	  if(j>=use[i])//能够选 
			 f[j]=max(f[j]+lose[i],f[j-use[i]]+win[i]); 
	  	  else//不能够选 
		   f[j]=f[j]+lose[i];
	  }
	printf("%lld",5*f[x]);//最后乘⑤(题目要求) 
}
