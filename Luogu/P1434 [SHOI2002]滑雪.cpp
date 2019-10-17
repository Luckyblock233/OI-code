//所用算法：DFS+回溯 ，记忆化搜索
//使用maxx数组存从当前点开始化的最大距离
//然后套dfs模板,并存以各点为起点的最长距离 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[110][110];//存图 
bool use[110][110];//是否用过 
int maxx[110][110];//记忆距离 
int ax[5]={1,-1,0,0};
int ay[5]={0,0,1,-1};
int ans=-1;
int dfs(int,int);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//输入 
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)//依次枚举各点作为起点 
	  for(int j=1;j<=n;j++)
	    if(!use[i][j])
	      {
	      	use[i][j]=1;
	      	int tot1=dfs(i,j);//计算以此点为起点的距离 
	      	maxx[i][j]=tot1;
	      	use[i][j]=0;
	      	if(tot1>ans) ans=tot1;//记录最大值 
		  }
	printf("%d",ans);
}
int dfs(int x,int y)
{
	if(maxx[x][y])//如果被记录,就直接返回 
	  return maxx[x][y];
	int tot2=0;
	for(int i=0;i<4;i++)
	  {
	  	int xx=x+ax[i];
	  	int yy=y+ay[i];
	  	if(!use[xx][yy] && xx>=1 && yy>=1 && xx<=n && yy<=m)
	  	  if(a[xx][yy] < a[x][y])
	  	    {
	  	  	  use[xx][yy]=1;
	  	  	  tot2=max( dfs(xx,yy),tot2 );//找到它能到达的点的最大距离 
	  	  	  use[xx][yy]=0;
		    }
	  }
	return tot2+1;//返回能到达的点+此点的和 
}
