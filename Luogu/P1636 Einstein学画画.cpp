#include<cstdio>
using namespace std;
int oe[1010];
int main()
{
	int n,m;
	int x,y;
	int ji=0,ou=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	scanf("%d%d",&x,&y);
	  	oe[x]++;
	  	oe[y]++;
	  }
	for(int i=1;i<=n;i++)
	  {
	  	if(oe[i]%2==0)
	  	  ou++;
	  	else
	  	  ji++;
	  }
	if(ji==0 || ji==2)
	  printf("1");
	else
	  printf("%d",ji/2);
	
}
