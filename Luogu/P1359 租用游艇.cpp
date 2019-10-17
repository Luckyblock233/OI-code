//经典dj求最短路算法,不再赘述 
//此处注意:游艇只能从上游到下游，所以只能存单向通道
//存双向会出问题 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxxx=100000;//极值 
int map[1000][1000];//邻接矩阵 
int dis[1000];
bool f[1000];
int n;
void dj(int);
int main()
{
	scanf("%d",&n);//无趣输入 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    map[i][j]=maxxx;//初始化超大只 
	for(int i=1;i<=n-1;i++)//输入i点到他下游的点的距离 
	  {
	  	for(int j=i+1;j<=n;j++)
	  	{
	  	  int z;//输入距离 
	  	  scanf("%d",&z);
	  	  map[i][j]=z;//一定注意单向!!! 
		}
	  }
	dj(1);
	printf("%d",dis[n]);//输出 
}
void dj(int s)//经典dj板子,不再赘述 
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
