#include<cstdio>
using namespace std;
int n,tot;
int ans[15],li[30],du1[30],du2[30];
void dfs(int);
void pr();
bool judge(int,int);
int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("%d",tot);
}
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	  if(judge(x,i))
	  	{
			ans[x]=i;
			li[i]=1;du1[x+i]=1;du2[x-i+n-1]=1;
			if(x==n && ++tot<=3) pr();
			else dfs(x+1);
			ans[x]=0;
			li[i]=0;du1[x+i]=0;du2[x-i+n-1]=0;
		}
}
bool judge(int x,int y)
{
	if(!li[y])
	  if(!du1[x+y])
	    if(!du2[x-y+n-1])
	      return 1;
	return 0;
}
void pr()
{
	for(int i=1;i<=n;i++)
	  printf("%d ",ans[i]);
	printf("\n");
}
