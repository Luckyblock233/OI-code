//算法:二分答案
/*
直接套上二分答案，
区间l取0、r取树的最大高度，
关键的check判断
可以直接模拟一重循环加上树高a[i]-x。
*/ 
#include<cstdio>
#define int long long
using namespace std;
const int MARX = 1e6+10;
int n,m;
int a[MARX];
bool judge(int x)//判断 
{
	int tot=0;
	for(int i=1;i<=n;i++)
	  tot+=(a[i]>x?a[i]-x:0);
	return tot>=m;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	int l=1,r=1e9+10;
	while(l<=r)//二分 
	  {
	  	int mid=(l+r)>>1;
	  	if(judge(mid)) l=mid+1;
	  	else r=mid-1;
	  }
	printf("%lld",r);
} 
