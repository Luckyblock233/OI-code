#include<cstdio>
#include<cstring>
using namespace std;
bool e[1048576];
int main()
{
	int n;
	scanf("%d",&n);
	while(1)
	  {
	    int d,i;
	    scanf("%d",&d);
	    if(d==-1)
	      break;
	    else
	      scanf("%d",&i);
	    int d1=d,ans=1;
	    while(i>0)
	      {
	      	while(d1>1)
	      	  {
	      	  	d1--;
	      	  	e[ans]=!e[ans];
	      	  	if(e[ans]==1)
	      	  	  ans=ans*2;
	      	  	else
	      	  	  ans=ans*2+1;
			  }
			i--;
			if(i==0)
			  printf("%d\n",ans);
			d1=d;
			ans=1;
		  }
		memset(e,0,sizeof(e));
	  }
	fclose(stdin);
	fclose(stdout);
}
