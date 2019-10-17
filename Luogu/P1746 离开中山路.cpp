//使用算法：bfs
//模板题,见注释 
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int n;
char k;
int ax[5]={1,-1,0,0};//坐标变化量 
int ay[5]={0,0,1,-1};
bool map[1010][1010];//存是否能通过 
int step[1010][1010];//存步数 
int sx,sy,ex,ey;
queue <int> x;
queue <int> y;
void bfs()//标准bfs模板 
{
	while(!x.empty())
	  {
	  	int xx=x.front();
	  	int yy=y.front();
	  	x.pop(),y.pop();
	  	for(int i=0;i<4;i++)//枚举四个方向 
	  	  {
	  	  	int xxx=xx+ax[i];
	  	  	int yyy=yy+ay[i];
	  	  	if(xxx>=1 && xxx<=n && yyy>=1 && yyy<=n)
	  	  	  if(map[xxx][yyy] && step[xxx][yyy]==-1) 
	  	  	    {
	  	  	  	  step[xxx][yyy]=step[xx][yy]+1;
	  	  	  	  if(xxx==ex && yyy==ey) return ;
	  	  	  	  x.push(xxx);
	  	  	  	  y.push(yyy);
			    }
		  }
	  }
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)//输入 
	    {
	      cin>>k;
	      map[i][j]=!(k-'0');
	      step[i][j]=-1;//顺便初始化 
		}
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	x.push(sx);//压入队列 
	y.push(sy);
	step[sx][sy]=0;
	bfs(); 
	printf("%d",step[ex][ey]);
}
