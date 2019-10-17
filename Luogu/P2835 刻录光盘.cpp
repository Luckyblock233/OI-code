#include<cstdio>
using namespace std;
int n,ans;
int pre[210];
bool fa[210];
//-----------------------------------------------
int find(int x)
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)
{
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2)
	  pre[r1]=r2;
}
//------------------------------------------------
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  pre[i]=i;
	for(int i=1;i<=n;i++)
	  {
	  	while(1)
	  	  {
	  	  	int x;
	  	  	scanf("%d",&x);
	  	  	if(x==0) break;
	  	  	fa[x]=1;
	  	  	join(x,i);
		  }
	  }
	for(int i=1;i<=n;i++)
	  if(pre[i]==i || fa[i]==0) ans++;
	printf("%d",ans);
}
