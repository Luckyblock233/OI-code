//使用算法:BFS
//先将步数数组初始化为-1.
//输入各组数据,将马的初始点压入队列
//每次循环,取出队首的点,枚举它能到达的点
//如果新点在矩阵范围内,且没有被到达过(因为后到的步数一定比先到的步数多 
//则新点的步数为原点数+1
//当队列为空时结束
//输出各点步数 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int xm,ym;
int ax[10]={2,-2,2,-2,-1,1,-1,1};//存坐标变化量
int ay[10]={1,1,-1,-1,2,2,-2,-2};
int step[410][410];//存步数 
queue <int> x;
queue <int> y;
void bfs();
int main()
{
	memset(step,-1,sizeof(step));//初始化 
	scanf("%d%d%d%d",&n,&m,&xm,&ym);
	x.push(xm);//压入队列 
	y.push(ym);
	step[xm][ym]=0;//初始化 
	bfs();//搜 
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=m;j++)
	  	  printf("%-5d",step[i][j]);//输出步数 
	    printf("\n");
	  }
}
void bfs()
{
	while(!x.empty())
	  {
	  	int xx=x.front();
	  	int yy=y.front();
	  	x.pop(),y.pop();
	  	for(int i=0;i<8;i++)
	  	  {
	  	  	if(xx+ax[i]>=1 && xx+ax[i]<=n)//满足条件 
	  	  	  if(yy+ay[i]>=1 && yy+ay[i]<=m)
	  	  	    if(step[xx+ax[i]][yy+ay[i]] == -1)
	  	  	      {
	  	  	      	x.push(xx+ax[i]);//压入队列 
	  	  	      	y.push(yy+ay[i]);
	  	  	      	step[xx+ax[i]][yy+ay[i]]=step[xx][yy]+1;//计算步数 
				  }
		  }
	  }
}
