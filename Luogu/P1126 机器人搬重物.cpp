//知识点： bfs
/* 
注意走的是点,障碍是块;   点图与块图并存 

思路:存步数时不仅要存各点的秒数,还要考虑各个方向的秒数
所以就要用三维数组存答案
坐标变化量也要分面朝的方向来讨论 
另外,机器人占用四个格子的空间
行走时要注意判断一路上是否有障碍
*/ 
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MARX=21000000;//极值 
struct baka9
{
	int x,y;
	int c;
};
int ax[6][6]={{},{0,0,0,0},{0,1,2,3},{0,0,0,0},{0,-1,-2,-3}};//存各方向,各坐标的变化量 
int ay[6][6]={{},{0,1,2,3},{0,0,0,0},{0,-1,-2,-3},{0,0,0,0}};
bool map[60][60];//存图,是否有障碍 
int step[55][55][6];//存各点,各方向步数 
bool ju[55][55][6];//存某个点,某方向是否走过 
int n,m;
int sx,sy,ex,ey;
char c1;
queue <baka9> s;//队列 
void bfs();
bool judge(int,int,int,int,int);
int main()
{
	scanf("%d%d\n",&n,&m);
	memset(step,MARX,sizeof(step));//初始化step 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  	{
	  	  int x111;
	  	  scanf("%d",&x111);
	  	  map[i][j]=x111;//存图 
		}
	scanf("%d %d %d %d %c",&sx,&sy,&ex,&ey,&c1); 
	int c2;
	if(c1=='E')c2=1;//东南西北分别为1,2,3,4 
	if(c1=='S')c2=2;
	if(c1=='W')c2=3;
	if(c1=='N')c2=4;
	step[sx][sy][c2]=0; 
	baka9 tmp={sx,sy,c2};//压入队列 
	ju[sx][sy][c2]=1;
	s.push(tmp);
	bfs();
	int minn=MARX;//找到终点四个方向上的最小值 
	minn=MARX;
	for(int i=1;i<=4;i++)
	  minn=min(step[ex][ey][i],minn);
	if(minn==MARX) minn=-1;//最小值为极值,则不能到达 
	printf("%d",minn);
}
void bfs()//不标准的bfs 
{
	while(!s.empty())
	  {
	  	baka9 tmp=s.front(); 
	  	s.pop();
	  	int xx=tmp.x;
	  	int yy=tmp.y;
	  	int cc=tmp.c;
	  	for(int i=1;i<=3;i++)//前进的情况 
	  	  {
	  	  	int xxx=xx+ax[cc][i];
	  	  	int yyy=yy+ay[cc][i];
	  	  	if(ju[xx+ax[cc][i-1]][yy+ay[cc][i-1]][cc])//少前进一格能否行,用来判断路径上是否有障碍物 
	  	  	    if(judge(xx,yy,xxx,yyy,cc)) 
			      {
				    step[xxx][yyy][cc]=step[xx][yy][cc]+1;//秒数加一 
				    ju[xxx][yyy][cc]=1;
				    baka9 tmp1={xxx,yyy,cc};
				    s.push(tmp1);
			      }
	  	  }
	  	for(int i=1;i<=4;i++)//转向的情况 
	  	  {
	  	  	  int flag1=1; //转90秒数为1 
	  	  	  if(cc==i+2 || i==cc+2) flag1++;//如果转180,则秒数需加一 
			  if(step[xx][yy][i] > step[xx][yy][cc]+flag1)//如果在此点转向比之前省时 
	  	        {
	  	          step[xx][yy][i]=step[xx][yy][cc]+flag1;//压入队列 
	  	          ju[xx][yy][i]=1;
	  	      	  baka9 tmp1={xx,yy,i};
			  	  s.push(tmp1);
				}
			}
	  }
}
bool judge(int xx,int yy,int xxx,int yyy,int ccc)//判断 
{
	if(xxx>=1 && xxx<n)//不出界 
	  if(yyy>=1 && yyy<m)
	    if(step[xxx][yyy][ccc] > step[xx][yy][ccc]+1)//较优解 
		  {
		    int flag=1;
		    if(map[xxx][yyy]) flag=0;//判断是否有障碍 
		    if(map[xxx+1][yyy]) flag=0;
		    if(map[xxx][yyy+1]) flag=0;
		    if(map[xxx+1][yyy+1])flag=0;
		    return flag; 
		  }
	return 0;
}
