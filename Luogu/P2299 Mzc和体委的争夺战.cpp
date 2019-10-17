//经典dj求最短路算法例题,不再赘述 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxxx=2000000000;//超大极值 
int map[3000][3000];//邻接矩阵 
int dis[3000];
bool f[3000];
int n,m;
void dj(int);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    map[i][j]=maxxx;
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	  	scanf("%d%d%d",&x,&y,&z);
	  	if(map[x][y] > z)//注意此处路径有重复,需取最小的 
	  	  map[x][y]=map[y][x]=z;
	  }
	dj(1);//以1为起点 
	printf("%d",dis[n]);//到达n 
}
void dj(int s)//经典dj,不再赘述 
{
	for(int i=1;i<=n;i++)
	  dis[i]=map[s][i];
	dis[s]=0;
	f[s]=1;
	for(int i=1;i<=n;i++)
	  {
	  	int minn=maxxx;
	  	int bian=0;
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	if(dis[j]<minn && !f[j])
	  	  	  {
	  	  	  	minn=dis[j];
	  	  	  	bian=j;
			  }
		  }
		if(bian==0) break;
		f[bian]=1;
		for(int j=1;j<=n;j++)
		  {
		  	if(dis[bian]+map[bian][j]<dis[j])
		  	  dis[j]=dis[bian]+map[bian][j];
		  }
	  }
}
