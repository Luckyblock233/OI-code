#include<cstdio>
#include<algorithm>
using namespace std;
int n,marx,sum;
int a[70],num;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	int x;
	  	scanf("%d",&x);
	  	if(x<=50) 
		  {
		    a[++num]=x;
	   	    if(a[i]>marx) marx=a[i];
	  	    sum+=a[i];
	  	  }
	  }
	sort(a+1,a+num);
	for(int i=marx;i<=sum;i++)
	  if(!(sum%i))
	    {
	      
		}
}
