#include<cstdio>
#include<cmath>
using namespace std;
int n;
double po[25][2];
double l[20][20];
bool use[20];
double ans=10000000;
void dfs(int,double,int);
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	double x,y;
	  	scanf("%lf%lf",&x,&y);
	  	po[i][0]=x;
	  	po[i][1]=y;
	  }
	for(int i=1;i<=n+1;i++)
	  for(int t=1;t<=n+1;t++)
	    l[i][t]=sqrt((1.0*po[t][0]-po[i][0])*(1.0*po[t][0]-po[i][0])+(1.0*po[t][1]-po[i][1])*(1.0*po[t][1]-po[i][1]));
	dfs(1,0,n+1);
	printf("%.2lf",ans);
}
void dfs(int x,double s,int t)
{
	if(s > ans)
	  return ;
	if(x==n+1)
	  {
	  	if(s<ans)
		  ans=s;
	  	return ;
	  }
	for(int i=1;i<=n;i++)
	  if(!use[i])
	    {
	      use[i]=1;
		  dfs(x+1,s+l[t][i],i);
		  use[i]=0;
		}
}
