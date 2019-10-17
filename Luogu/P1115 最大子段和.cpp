//算法：DP 
//对于第i个数要么接到前一个数后面,
//要么自己作为起点,再开一个新序列 
//则: 
//f[i]表示结尾为i的序列的最大和 , 
//转移方程式：f[i]=max(f[i-1]+a[i],a[i]);
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=-10010;
int a[200010];
int f[200010];//结尾为i的序列的最大和 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);//输入 
	for(int i=1;i<=n;i++)
	  {
	  	f[i]=max(f[i-1]+a[i],a[i]);
	  	ans=max(ans,f[i]);//找答案 
	  }
	printf("%d",ans);
}
