#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int x,y;
	int data;
}a[410];
int m,n,k,num,ans;
int map[25][25];
int flag=-1;
bool cmp(baka9 aa,baka9 bb)
{
	return aa.data>bb.data;
}
int far(int aa,int bb)
{
	if(flag==-1) return a[bb].x;
	int lx=max(a[aa].x,a[bb].x)-min(a[aa].x,a[bb].x);
	int ly=max(a[aa].y,a[bb].y)-min(a[aa].y,a[bb].y);
	return lx+ly;
}
int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	    {
	      scanf("%d",&map[i][j]);
	      if(map[i][j])
	        {
			  a[++num].x=i;
	          a[num].y=j;
	          a[num].data=map[i][j];
	        }
		}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++)
	  {
	  	if( far(flag,i)+a[i].x+1  <=k )
	  	  {
	  	  	k-=(far(flag,i)+1);
	  	  	flag=i;
	  	  	ans+=a[i].data;
		  }
		else
		  break;
	  }
	printf("%d",ans);
}
