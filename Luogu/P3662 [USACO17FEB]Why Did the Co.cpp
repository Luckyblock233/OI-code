//算法:前缀和/枚举 
/*
区间的长度已经确定为k 
可以通过枚举区间的左端点
来确定一个区间

枚举每一个长度为k的区间，
判断哪一个区间中
损坏的灯的数目最少
输出最小灯数即可 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX = 1e5+10;
int n,b,k,tmp,ans=MARX;
bool a[MARX];
int f[MARX];//前缀和 
int main()
{
	scanf("%d%d%d",&n,&k,&b);
	for(int i=1;i<=b;i++)//记录坏灯 
	  {
	    scanf("%d",&tmp);
		a[tmp]=1;
	  }
	for(int i=1;i<=n;i++)//求前缀和 
	  f[i]=a[i]?f[i-1]+1:f[i-1];
	for(int i=1;i<=n-k;i++)//枚举每个区间 
	  ans=min(ans,f[i+k]-f[i]);
	printf("%d",ans);
}
