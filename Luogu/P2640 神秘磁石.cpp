#include<cstdio>
using namespace std;
int n,k;
bool zhi[10010]={1,1};
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++)
	  for(int j=2;j<=n/i;j++)
	    zhi[i*j]=1;
	int flag=0;
	for(int i=2;i<=n-k;i++)
	  {
	  	int j=i+k;
	  	if(!zhi[i] && !zhi[j])
	  	  {
	  	  	printf("%d %d\n",i,j);
	  	  	flag=1;
		  }
	  }
	if(!flag) printf("empty");
}
