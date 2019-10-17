//基本思路:
//先以常规方法求出从a点到达b点的最短路
//在求最短路同时用path数组记录路径
//算法结束后,再看存的路径中有无损坏的路径
//有则累加最后输出 
#include<cstdio>
#include<cstring>
using namespace std;
int map[110][110];//存不损坏 
bool mapbreak[110][110];//存损坏 
int dis[110];
bool f[110];
int path[110];
int MA=21474830;//最大值 
int n,m,d,A,B;
int ans;
void dj(int);//用了裸dj 
int main()
{
	scanf("%d%d",&n,&m);//没有意思的输入 
	memset(map,MA,sizeof(map));//初始化 
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	  	scanf("%d%d%d",&x,&y,&z);
	    map[x][y]=map[y][x]=z;
	  }
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	    mapbreak[x][y]=mapbreak[y][x]=1;
      }	
	scanf("%d%d",&A,&B);
	dj(A);
	int k1=B;//用循环找路径 
	for(int i=k1;i;i=path[i])
	  {
	  	if(mapbreak[i][path[i]])//被损害则累加 
	  	  ans+=map[i][path[i]];
	  }
	printf("%d",ans);
}
void dj(int s)//裸dj,不赘述 
{
	for(int i=1;i<=n;i++)
	  {
	  	dis[i]=map[s][i];
	  	path[i]=s;
	  }
	f[s]=1;
	dis[s]=0;
	path[s]=0;
	for(int i=1;i<=n;i++)
	  {
	  	int minn=MA,k=-1;
	  	for(int j=1;j<=n;j++)
	  	  if(dis[j] < minn && !f[j])
	  	  	{
	  	  	  minn=dis[j];
	  	  	  k=j;
			}
		if(k==-1) break;
		f[k]=1;
		for(int j=1;j<=n;j++)
		  {
		  	if(dis[j] > dis[k] + map[k][j])
		  	  {
		  	  	dis[j] = dis[k] + map[k][j];
		  	  	path[j]=k;
			  }
		  }
	  }
}
