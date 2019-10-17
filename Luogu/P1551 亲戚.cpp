#include<cstdio>
using namespace std;
int pre[30000];
int find(int x)
{
	while( pre[x]!= x )
	  x=find(pre[x]);
	return pre[x];
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
	int n,m,q;
	scanf("%d%d",&n,&m);
	scanf("%d",&q);
	for(int i=1;i<=n;i++)
	  pre[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	join(x,y);
	  }
	for(int i=1;i<=q;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	if( find(x)==find(y) )
	  	  printf("Yes\n");
	  	else
	  	  printf("No\n");
	  }
}
