#include<cstdio>
using namespace std;
int n;
int a[500010];
int b1[500010];
long long ans;
void b(int l1,int r1,int l2,int r2)
{
	int i=l1,j=l2,k=1;
	while(i<=r1 && j<=r2)
	  {
	  	if(a[i]<=a[j])
	  	  b1[k++]=a[i++];
	  	else
	  	  {
			b1[k++]=a[j++];
			ans=(ans+(r1-i+1))%10000007;
		  }
	  }
	while(i<=r1) 
	  b1[k++]=a[i++];
	while(j<=r2) 
	  b1[k++]=a[j++];
	for(int i=l1;i<=r2;i++)
	  a[i]=b1[i-l1+1];
}
void f(int l,int r)
{
	if(l>=r) return ;
	int mid=(l+r)/2;
	f(l,mid);
	f(mid+1,r);
	b(l,mid,mid+1,r);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	  {
	  	scanf("%d",&n);
	  	for(int i=1;i<=n;i++)
	  	  scanf("%d",&a[i]);
		f(1,n);
		printf("Case %d: %lld\n",k,ans%10000007);
		ans=0;
	  }
}
