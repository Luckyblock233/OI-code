//����dj�����·�㷨����,����׸�� 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxxx=2000000000;//����ֵ 
int map[3000][3000];//�ڽӾ��� 
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
	  	if(map[x][y] > z)//ע��˴�·�����ظ�,��ȡ��С�� 
	  	  map[x][y]=map[y][x]=z;
	  }
	dj(1);//��1Ϊ��� 
	printf("%d",dis[n]);//����n 
}
void dj(int s)//����dj,����׸�� 
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
