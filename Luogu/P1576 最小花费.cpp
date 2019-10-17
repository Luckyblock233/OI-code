//此题为dijkstra 的例题,思路即是dj算法的低即变式
//只需要将输入的减少百分比,转化为剩余百分比,
//此题就转化为了求最大路径乘积的问题 
#include<cstdio>
#include<cstring>
using namespace std;
double map[2005][2005]={0};//初始化 
double dis[2005]={0};
bool f[2005]={0};
int n,m,s,t;
int bian;
void dj();
int main()
{
	scanf("%d%d",&n,&m);//输入 
	for(int i=1;i<=m;i++)
	  {
	  	int x,y;
	  	double z;
	  	scanf("%d%d",&x,&y);
	  	scanf("%lf",&z);
	  	map[x][y]=map[y][x]=(100-z)/100;// 将输入的减少百分比,转化为剩余百分比,
	  }
	scanf("%d%d",&s,&t);//起点终点 
	dj();
	printf("%0.8lf",100/dis[t]);//再转化为需要的钱,输出即可 
}
void dj()//经典dj算法,不再赘述 
{
	for(int i=1;i<=n;i++)
	  dis[i]=map[s][i];
	f[s]=1;
	dis[s]=1;
	for(int i=1;i<n;i++)
	  {
	  	double minn=0;
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	if(dis[j] > minn && !f[j])
	  	  	  {
	  	  	  	minn=dis[j];
	  	  	  	bian=j;
			  }
		  }
		f[bian]=1;
		if(bian==t) break;//若t被确定,就可输出答案. 
		for(int j=1;j<=n;j++)
		  {
		  	if(dis[bian]*map[bian][j] > dis[j] && !f[j])//此处将最短路径和转化为最短路径乘积 
		  	  dis[j]=dis[bian]*map[bian][j];
		  }
	  }
}
