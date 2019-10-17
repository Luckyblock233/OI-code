#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int a;
int q[20][20];
int main()
{
    memset(q,-1,sizeof(q));
    scanf("%d%d%d",&n,&m,&a);
    for(int i=1;i<=n;i++) 
	  q[i][m]=1;
    for(int i=1;i<=m;i++) 
	  q[n][i]=1;
    for(int i=1;i<=a;i++)
      {
      	int xx,yy;
      	scanf("%d%d",&xx,&yy);
      	q[xx][yy]=0;
      	if(xx==n) 
		  for(int j=yy;j>=1;j--)
		    q[n][j]=0;
		if(yy==m)
		  for(int j=xx;j>=1;j--)
		    q[j][m]=0;
	  }
    for(int i=2;i<=m+n;i++)
      {
      	for(int j=1;j<=i-1;j++)
      	  {
      	    int k=i-j;
      	      if(q[n-j][m-k]==-1)
      	    	q[n-j][m-k]=q[n-j+1][m-k]+q[n-j][m-k+1];
          }
      }
    printf("%d",q[1][1]);
}
