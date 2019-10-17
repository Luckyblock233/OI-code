//使用算法：dfs+回溯
//超级暴力做法,
//直接套模板,能走就走,找到鼠标就加血,并继续走
//试完所有情况后,求得最优解 
#include<cstdio>
using namespace std;
int map[15][15];//存图 
bool vis[15][15];//是否经过 
int n,m;
int sx,sy,ex,ey;//起点终点坐标 
bool flag;//判断minn是否被替换 
int minn=2100000000;//最小值 
int xx[5]={1,-1,0,0};//各位置的增减量 
int yy[5]={0,0,1,-1};
void dfs(int x,int y,int t,int hp);//分为当前点的横,纵坐标,当前时间,当前血量 
int main()
{
	scanf("%d%d",&n,&m);//输入并存图,并找到起点终点. 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    {
	      scanf("%d",&map[i][j]);
	      if(map[i][j]==2)
	        {
	          sx=i;sy=j;
			}
		  if(map[i][j]==3)
	        {
	          ex=i;ey=j;
			}
		}
	dfs(sx,sy,1,6);//从起点开始搜 
	if(flag)  printf("%d",minn);//如果,minn被替换 
	else  printf("-1");//未被替换 
}
void dfs(int x,int y,int t,int hp)
{
	if(hp <= 1) return ;//血量不能支撑继续走,就退出 
	for(int i=0;i<=3;i++)//枚举能到的点 
	  {
	  	int x1=x+xx[i];
	  	int y1=y+yy[i];
	  	if(x1>=1 && x1<=n)//冗长判断边界 
	  	  if(y1>=1 && y1<=m)
	  	    if(!vis[x1][y1])
	  	      if(map[x1][y1] != 0)
	  	        {
	  	          vis[x1][y1]=1;//记录 
	  	          if(x1==ex && y1==ey && t<=minn)//找最优解 
	  	            {
	  	              flag=1;
	  	              minn=t;
	  	            }
	  	          else
	  	            {
	  	              if( map[x1][y1]==4 )//如果能加血 
						dfs(x1,y1,t+1,6);
					  else//不能加血 
					    dfs(x1,y1,t+1,hp-1);
					}
				  vis[x1][y1]=0;//回溯` 
				}
	  }
}
