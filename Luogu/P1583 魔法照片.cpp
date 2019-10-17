#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int e[11];
struct per
{
	int data;
	int bian;
}w[20100];
bool cmp(per x,per y)
{
	if(x.data==y.data)
	  return x.bian<y.bian;
	return x.data>y.data;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=10;i++)
	  scanf("%d",&e[i]);
	for(int j=1;j<=n;j++)
	  {
	  	w[j].bian=j;
	  	scanf("%d",&w[j].data);
	  }
	sort(w+1,w+n+1,cmp);
	for(int j=1;j<=n;j++)
	  w[w[j].bian].data+=e[(w[j].bian-1)%10+1];
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=k;i++)
	  printf("%d ",w[i].bian);
}
