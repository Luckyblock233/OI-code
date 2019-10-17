#include<cstdio>
using namespace std;
int a[100011];
int main()
{
	int n,m;
	int ans=0;
	int last=0,suml=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	suml+=a[i];
	  	if(suml>m)
	  	  {
	  	  	ans++;
	  	  	suml=a[i];
	  	  	last=i-1;
	  	  	if(suml>=m)
	  	  	  {
	  	  	  	ans++;
	  	  	  	suml=0;
	  	  	  	last++;
			  }
		  }
	  }
	if(last!=n) ans++;
	printf("%d",ans);
}
