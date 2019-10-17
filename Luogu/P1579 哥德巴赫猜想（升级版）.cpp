#include<cstdio>
#include<cmath>
using namespace std;
bool zhi[21000];
int ans[3];
int judge=0;
void zz(int a,int s)
{
	if(s==1)
	  {
	  	if(zhi[a]==0 && a>=2)
		  {
		  	ans[2]=a;
		  	judge=1;
		  	printf("%d %d %d",ans[0],ans[1],ans[2]);
		  }
	  	return ;
	  }
	for(int i=2;i<=a;i++)
	  {
	  	if(zhi[i]==0)
	  	  {
	  	  	ans[3-s]=i;
	  	  	zz(a-i,s-1);
	  	  	if(judge==1)
	  	  	  return ;
		  }
	  }
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	  {
	  	if(!zhi[i])
	  	for(int j=2*i;j<=a;j++)
	  	  if(j%i==0)
	  	    zhi[j]=1;
	  }
	zz(a,3);
}
