//算法:二分答案
/*
由于弄干所有衣服需要的时间
是由最后一件烘干的衣服所需要的时间决定的，
所以每次都对剩余所需时间最长的那件衣服
使用烘衣机。
*/ 
#include<cstdio>
#define ll long long
using namespace std;
ll n,A,B;
ll a[5000100];
bool judge(ll x)
{
	int tot=0;
	for(int i=1;i<=n;i++)
	  {
	  	int y=a[i]-x*A;
	  	if(y<=0) continue;
		tot+=y/B+(y%B!=0?1:0);
	  	if(tot>x)return 0;
	  }
	return tot<=x;
}
int main()
{
	scanf("%lld%lld%lld",&n,&A,&B);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	ll l=1,r=5000100;
	while(l<=r)
	  {
	  	int mid=(l+r)>>1;
	  	if(judge(mid)) r=mid-1;
	  	else l=mid+1;
	  }
	printf("%lld",l);
} 
