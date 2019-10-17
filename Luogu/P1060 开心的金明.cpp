/*
本题为01背包模板题
完全套模板即可 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int w[30],v[30];
int f[30010];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=w[i];j--)
	  	f[j]=max(f[j],f[j-w[i]]+w[i]*v[i]);
	printf("%d",f[m]);
}

