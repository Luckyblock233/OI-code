#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[100010],b[100010];
bool search(int k)
{
	int l=1,r=m;
	while(l<=r)
	  {
	    int mid=(l+r)/2;
		if(b[mid]>k) r=mid-1;
		if(b[mid]<k) l=mid+1;
		if(b[mid]==k) return 1;
	  }
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)
	  scanf("%d",&b[j]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
	  if(search(a[i]))
	  	printf("%d ",a[i]);
} 
