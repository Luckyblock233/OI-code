#include<cstdio>
using namespace std;
int main()
{
	int n,n1;
	scanf("%d",&n);
	n1=n;
	int x;
	int juc1=0,jufu=0;
	while(n1>=0)
	  {
		scanf("%d",&x);
		if(x!=0)
		{
		  if(x<0) 
		    {
		  	   jufu=1;x=-x;
		    }
		  if(jufu==1) printf("-");
		  if(juc1==1 && jufu!=1) printf("+");
		  if(x!=1 && n1!=0) printf("%d",x);
		  if(juc1==1 && n1>=2) printf("x^%d",n1);
		  if(juc1==0 && n1>=2) 
		    {
		  	   juc1=1;
			   printf("x^%d",n1);
		    }
		  if(n1==1) printf("x");
		  if(n1==0) printf("%d",x);
	    }
		jufu=0;
		n1--;
	  }
	return 0;
}
