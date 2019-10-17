//算法：Floyd求多源最短路
//少有的Floyd的题
//输入数据,用邻接表存边
//然后初始化map[i][i]等于0,即i点到i点的距离为0
//因为可以选择的点包括想去的点,所以要提前初始化,不然Floyd跑一遍后会出错
//然后跑Floyd
//之后枚举每一个点,计算他们到达要求点的距离之和,
//选出其中和最小的点的编号
//输出即可 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MARX=0xf;
int p,f,c,ans;
double minn=999999999;
int map[510][510];
int want[510];
int main()
{
	memset(map,MARX,sizeof(map));//初始化极大值 
	scanf("%d%d%d",&p,&f,&c);
	for(int i=1;i<=f;i++)
	  scanf("%d",&want[i]);
	for(int i=1;i<=c;i++)//邻接矩阵存边 
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	map[u][v]=map[v][u]=w;
	  }
	for(int i=1;i<=p;i++)//初始化map 
	  map[i][i]=0;
	for(int i=1;i<=p;i++)//floyd 
	  for(int j=1;j<=p;j++)
	    for(int k=1;k<=p;k++)
	      if(map[j][k]>map[j][i]+map[i][k])
	        map[j][k]=map[j][i]+map[i][k];
	for(int i=1;i<=p;i++)//枚举每个点,计算最小和 
	  {
	  	int sum=0;
	  	for(int j=1;j<=f;j++)
	  	  sum+=map[i][want[j]];
	    if(minn>(1.0*sum/f))//注意平均值存double形 
	      {
	      	minn=1.0*sum/f;
	      	ans=i;
		  }
	  }
	printf("%d",ans);
}
