#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,k;
int main()
{
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	  {
	  	scanf("%d%d",&n,&m);
	  	printf("%d\n",2*(min(n,m)-1));
	  }
}
