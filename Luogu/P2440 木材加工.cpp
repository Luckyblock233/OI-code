//算法：二分答案
//二分答案模板题
//枚举长度
//判断是否合法即可 
#include<cstdio>
#define ll long long
using namespace std;
ll n,k;
ll a[100010];
bool judge(ll x)
{
	int tot=0;
	for(int i=1;i<=n;i++)
	  tot+=a[i]/x;
	return tot>=k;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	ll l=1,r=1e9+10;
	while(l<=r)
	  {
	  	int mid=(l+r)>>1;
	  	if(judge(mid)) l=mid+1;
	  	else r=mid-1;
	  }
	printf("%lld",r);
}
