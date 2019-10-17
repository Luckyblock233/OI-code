#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int c[3500],w[3500];
int f[3500][3500];
int main()
{
	freopen("testdata.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&c[i],&w[i]);
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=m;j++)
	  	  {
	  	  	if(j>=c[i])
	  	  	  f[i][j]=max(f[i-1][j],f[i-1][j-c[i]]+w[i]);
	  	  	else
	  	  	  f[i][j]=f[i-1][j];
		  }
	  	for(int k=0;k<=n;k++)
	  	  {
	  	  	for(int j=0;j<=m;j++)
	  	  	  printf("%d ",f[k][j]);
	  	  	printf("\n");
		  }
		printf("\n");
	  }
	printf("%d",f[n][m]);
}
