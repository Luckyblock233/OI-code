#include<cstdio>
#include<algorithm>
using namespace std;
struct line
{
	int u,v,w;
}a[10010];
int pre[10100];
int n,m,k;
//--------------------------------------------------
bool cmp(line xx,line yy)
{
	return xx.w<yy.w;
}
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
//---------------------------------------------------
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(k > n)
	  {
	  	printf("No Answer");
	  	return 0;
	  }
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	  	scanf("%d%d%d",&x,&y,&z);
	  	a[i].u=x;a[i].v=y;a[i].w=z;
	  }
	int m1=1,k1=0,ans=0;
	for(int i=1;i<=n;i++)
	  pre[i]=i;
	sort(a+1,a+m+1,cmp);
	while(m1<=m)
	  {
	  	while(find(a[m1].u) == find(a[m1].v)  && m1<=m)
	  	  m1++;
	  	if(m1 > m)
		  {
		  	printf("No Answer");
		  	return 0;
		  }
	  	join(a[m1].u,a[m1].v);
	  	ans+=a[m1].w;
	  	k++;
	  	if(n-k1==k) break;
	  }
	printf("%d",ans);
}
