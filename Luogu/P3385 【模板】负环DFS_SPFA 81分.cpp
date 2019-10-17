#include<cstdio>
#include<cstring>
using namespace std;
struct line
{
	int be,af,we;
	int ne;
}a[200011];
int head[200011];
bool vis[200011];
int dis[200011];
int num,flag=1;
void add(int bee,int aff,int wee)
{
	a[++num].ne=head[bee];
	a[num].be=bee;
	a[num].af=aff;
	a[num].we=wee;
	head[bee]=num;
}
void spfa_dfs(int);
int main()
{
	int n1,n,m;
	int beee,afff,weee;
	scanf("%d",&n1);
	for(int p=1;p<=n1;p++)
	  {
	  	num=0;flag=1;
	  	scanf("%d%d",&n,&m);
	  	for(int i=1;i<=n;i++)
		  dis[i]=vis[i]=head[i]=0;
	  	for(int i=1;i<=m;i++)
	  	  {
	  	  	scanf("%d%d%d",&beee,&afff,&weee);
	  	  	add(beee,afff,weee);
	  	  	if(weee >= 0) add(afff,beee,weee);
		  }
		for(int i=1;i<=n;i++)
		  {
		  	spfa_dfs(i);
		  	if(!flag) break;
		  }
		if(!flag) printf("YE5\n");
		else printf("N0\n");
	  }
	return 0;
}
void spfa_dfs(int s)
{
	int to;
	vis[s]=1;
	for(int i=head[s];i;i=a[i].ne)
	  {
	  	to=a[i].af;
	  	if(dis[s] + a[i].we < dis[to])
	  	  {
	  	  	dis[to] = dis[s] + a[i].we;
	  	  	if(vis[to] || !flag)
	  	  	  {
	  	  	  	flag=0;
	  	  	  	break;
			  }
	  	  	spfa_dfs(to);
		  }
	  }
	vis[s]=0;
}
