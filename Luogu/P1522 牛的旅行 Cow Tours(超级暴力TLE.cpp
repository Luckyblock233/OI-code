#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int n;
int po[161][3];
double map[161][161];
bool vis[161][161];
double ans;
int main()
{
	memset(map,127,sizeof(map));
	double lll=map[1][1];
	ans=lll;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&po[i][1],&po[i][2]);
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=n;j++)
	  	  {
			char a;
	  	  	cin>>a;
			if(a =='1')
			  {
			  	map[i][j]=map[j][i]=sqrt( ( (po[i][1]-po[j][1])*(po[i][1]-po[j][1]) )+( (po[i][2]-po[j][2])*(po[i][2]-po[j][2]) ) );
			  	vis[i][j]=vis[j][i]=1;
			  }
	  	  }
	  }
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      {
			if( map[i][j] > map[i][k] + map[k][j] )
	      	  map[i][j] = map[i][k] + map[k][j];
	      	if(map[i][j]!=lll)
	      	  vis[i][j]=1;
		  }
	for(int l=1;l<=n;l++)
	  for(int l1=l+1;l1<=n;l1++)
	  {
		if(vis[l][l1]==0)
		     {
		       double map1[161][161];
		       memset(map1,127,sizeof(map1));
		       for(int i=1; i<=n; i++)
		         for(int j=1; j<=n; j++)
		           map1[i][j]=map[i][j];
			   map1[l][l1]=map1[l1][l]=sqrt( ( (po[l][1]-po[l1][1])*(po[l][1]-po[l1][1]) )+( (po[l][2]-po[l1][2])*(po[l][2]-po[l1][2]) ) );
	     	   for(int k=1;k<=n;k++)
	       	     for(int i=1;i<=n;i++)
	         	   for(int j=1;j<=n;j++)
	           	     {
	      	     	    if( map1[i][j] > map1[i][k] + map1[k][j])
	      	       		  map1[i][j] = map1[i][k] + map1[k][j];
		       	     }
		  	   double maxx=0;
		  	   for(int i=1; i<=n; i++)
		         for(int j=i+1; j<=n; j++)
		      	   if(map1[i][j] > maxx)
				     maxx=map1[i][j];
		       if(maxx < ans)
			     ans=maxx;
			   vis[l][l1]=vis[l1][l]=1;
	  	     }
	  }
	printf("%.6lf\n",ans);
}
