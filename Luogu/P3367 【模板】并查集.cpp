#include<cstdio>
using namespace std;
int pre[30010];
int find(int x)
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)
{
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2)
	  pre[r1]=r2;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pre[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	int zi,xi,yi;
	  	scanf("%d%d%d",&zi,&xi,&yi);
	  	if(zi==1)
	  	  join(xi,yi);
	  	if(zi==2)
	  	  {
	  	  	if(find(xi)==find(yi))
	  	  	  printf("Y\n");
	  	  	else
	  	  	  printf("N\n");
		  }
	  }
}
