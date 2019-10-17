#include<cstdio>
#include<algorithm>
using namespace std;
struct ss
{
	int ch,ma,en;
	int data;
	int tot;
}a[500];
bool cmp(ss x,ss y)
{
	if(x.tot==y.tot)
	  {
	  	if(x.ch==y.ch)
	  	  {
	  	  	return x.data<y.data;
		  }
		return x.ch>y.ch;
	  }
	return x.tot>y.tot;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  {
	  	int x,y,z;
	  	scanf("%d%d%d",&x,&y,&z);
	  	a[i].ch=x;
		a[i].ma=y;
		a[i].en=z;
	  	a[i].tot=x+y+z;
	  	a[i].data=i+1;
	  }
	sort(a,a+n,cmp);
	for(int i=0;i<5;i++)
	  printf("%d %d\n",a[i].data,a[i].tot);
}
