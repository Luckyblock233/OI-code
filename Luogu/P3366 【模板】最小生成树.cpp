#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX=2147483646;
struct baka9
{
	int u,v,w,ne;
}a[401000];
int head[20010];
int minn[20010];
bool f[20010];
int n,m,ans,num;
void add(int x,int y,int z)
{
	a[++num].ne=head[x];
	a[num].u=x;
	a[num].v=y;
	a[num].w=z;
	head[x]=num;
}
bool prim();
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	    int x,y,z; 
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	  }
	if( prim() )
 	  printf("%d",ans);
 	else
 	  printf("orz");
}
bool prim()
{
	for(int i=2;i<=n;i++)
	  minn[i]=MARX;
	for(int i=head[1];i;i=a[i].ne)
	  minn[a[i].v]=min(minn[a[i].v],a[i].w);
	for(int i=1;i<n;i++)
	  {
	  	int minnn=MARX,k=-1;
	  	for(int j=1;j<=n;j++)
	  	  if(!f[j] && minn[j]<minnn)
	  	    {
	  	  	  minnn=minn[j];
	  	  	  k=j;
			}
		if(k==-1) break;
		f[k]=1;
		for(int l=head[k];l;l=a[l].ne)
		  {
		  	if(!f[a[l].v] && minn[a[l].v] > a[l].w)
		  	  minn[a[l].v]=a[l].w;
		  }
	  }
	for(int i=1;i<=n;i++)
	  {
	  	if(minn[i]==MARX)
	  	  return 0;
	  	ans+=minn[i];
	  }
	return 1;
}
