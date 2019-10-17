//与p2678一模一样，只需增加一行sort 
#include<cstdio>
#include<algorithm>
using namespace std;
int l,n,m;
int a[50010];
bool judge(int mid)//贪心模拟 
{
	int m1=0;
	int pa=0;
	for(int i=1;i<=n+1;i++)
	  {
	  	if(a[i]-a[pa]<mid) m1++;
		else pa=i;
	  }
	if(m1>m) return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&l,&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	a[n+1]=l;
	sort(a+1,a+n+1); 
	int l=1,r=1000000000;
	while(l<=r)
	  {
	  	if(judge((l+r)/2))
		  l=(l+r)/2+1;
	  	else 
		  r=(l+r)/2-1;
	  }
	printf("%d",(l+r)/2);
}
