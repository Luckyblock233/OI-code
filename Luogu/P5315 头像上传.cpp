#include<cstdio>
using namespace std;
int n,L,G;
int main()
{
	scanf("%d%d%d",&n,&L,&G);
	for(int i=1;i<=n;i++)
	  {
	  	int w,h;
	  	scanf("%d%d",&w,&h);
	  	while(w>G || h>G)
	  	  w/=2,h/=2;
	  	if(w<L || h<L) printf("Too Young\n");
	  	if(w>=L && h>=L && w!=h) printf("Too Simple\n");
	  	if(w>=L && h>=L && w==h) printf("Sometimes Naive\n");
	  }
}
