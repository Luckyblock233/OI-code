#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k,t;
int ans=-1;
double f(int x,int y,int a,int b)
{
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=k;i++)
	  {
	  	int x,y,sum=0;
	  	scanf("%d%d",&x,&y);
	  	for(int i=max(1,x-t);i<=min(x+t,n);i++)
	  	  for(int j=max(1,y-t);j<=min(y+t,m);j++)
	  	    {
	  	      if(f(i,j,x,y)<=t)
	  	        sum++;
			}
		ans=max(sum,ans);
	  }
	printf("%d",ans);
}
