#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int h;
	int s1;
}c[5002];
bool cmp(baka9 a,baka9 b)
{
	if(a.s1<b.s1)
	  return true;
	return false;
}
int main()
{
	int n,s,a,b;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for(int i=0;i<n;i++)
	  {
	  	scanf("%d%d",&c[i].h,&c[i].s1);
	  	c[i].h-=(a+b);
	  }
	int i=0,ans=0;
	sort(c,c+n,cmp);
	while(s>0 && i<n)
	  {
	  	if(s>=c[i].s1)
	  	  {
			if(c[i].h<=0)
			  {
			    s-=c[i].s1;
	  	        ans++;
	  	      }
	  	  }
	  	else
		  break;
	  	i++;
	  }
	printf("%d",ans);
}
