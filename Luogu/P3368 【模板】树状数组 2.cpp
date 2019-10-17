#include<cstdio>
using namespace std;
int n,m;
int a[1000010];
int b[1000010];
int c[1000010];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y,int n)
{
	for(int i=x;i<=n;i+=lowbit(i))
	  c[i]+=y;
}
int find(int x)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	  sum+=c[i];
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	b[i]=a[i]-a[i-1];
	  	add(i,b[i],n);
	  }
	for(int i=1;i<=m;i++)
	  {
	  	int q,x,y,k;
	  	scanf("%d",&q);
	  	if(q==1)
		  {
		  	scanf("%d%d%d",&x,&y,&k);
		  	b[x]+=k , b[y+1]+=k;
		  	add(x,k,n);
		  	add(y+1,-k,n);
		  }
	  	else
	  	  {
	  	  	scanf("%d",&x);
	  	  	int ans=find(x);
	  	  	printf("%d\n",ans);
		  }
	  }
}
