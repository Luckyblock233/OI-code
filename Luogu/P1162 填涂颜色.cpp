//所用算法:bfs
//将正向填涂颜色,变为反向失去颜色
//先将所有的0变成2
//再依次从最外层的一圈点开始广度搜索
//遇到2,就把他变成0,并添加进队列
//遇到1,就直接进行下一层循环
//知道队列为空,则1外层的2全部变成了0
//输出即可 
#include<cstdio>
#include<queue>
using namespace std;
int map[35][35];
int xx[12]={1,-1,0,0};//各位置的增减量 
int yy[12]={0,0,1,-1};
queue <int> x;
queue <int> y;
int n;
void bfs();
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    {
	      scanf("%d",&map[i][j]);//存图,并初始化 
	      if(map[i][j]==0)
	        map[i][j]=2;
		}
	bfs(); 
	for(int i=1;i<=n;i++) 
	  {
	    for(int j=1;j<=n;j++)
	      printf("%d ",map[i][j]);
	    printf("\n");
	  }
}
void bfs()
{
	for(int i=1;i<=n;i++)//将最外层一圈的点添加进队列 
	  for(int j=1;j<=n;j++)
	    if(i==1 || j==1 || j==n || i==n)
	      {
	        x.push(i);
	        y.push(j);
		  }
	while(!x.empty())//标准广搜模板 
	  {
	  	int x1=x.front();
	  	int y1=y.front();
	  	x.pop();
	  	y.pop();
	  	if(map[x1][y1]==1)//遇到1直接下一层 
	  	  continue ;
	  	for(int i=0;i<=3;i++)
	  	  {
	  	  	int x2=x1+xx[i];
	  	  	int y2=y1+yy[i];
	  	  	if(x2>=1 && x2<=n)
	  	  	  if(y2>=1 && y2<=n)
	  	  	    if(map[x2][y2] == 2)
	  	  	      {
	  	  	      	map[x2][y2]=0;//置零 
	  	  	      	x.push(x2);//压入队列 
	  	  	      	y.push(y2);
				  }
		  }
	  }
}
