//与p1969，p5019一模一样
//注意开long long 
#include<cstdio>
using namespace std;
long long n,h;
long long lh;
int main()
{
    scanf("%ld",&n);
    long long ans=0;
    for(int i=1;i<=n;i++)
	  {
         scanf("%ld",&h);
         if(h>lh)
           ans=ans+(h-lh);
         lh=h;
      }
    printf("%ld",ans);
}
