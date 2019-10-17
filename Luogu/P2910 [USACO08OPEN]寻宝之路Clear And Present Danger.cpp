//知识点:Floyd,最短路 
/*
模板题
详见注释 
*/
#include<cstdio>
#include<cstring> 
using namespace std;
//=========================================================== 
int road[10010];//存需要的路径 
int danger[105][105];//存危险度 
int n,m,minn;
//===========================================================
signed main()
{
	memset(danger,0xfffff,sizeof(danger));//初始化极大值
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&road[i]);//预定路径 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%d",&danger[i][j]);//输入每个点到其他点的危险度 
	
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)//Floyd求多源最短路 
	      if(danger[i][j] > danger[i][k] + danger[k][j])
	      	danger[i][j]=danger[i][k] + danger[k][j];
	      	
	for(int i=1;i<m;i++)//按照预定路径找最小值之和 
	  minn+=danger[road[i]][road[i+1]];
	
	printf("%d",minn);
}
