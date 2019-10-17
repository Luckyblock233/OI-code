//算法：dfs搜索
//数据很水 
//用dfs枚举所有情况即可 
#include<cstdio>
using namespace std;
int n,m,t;
int sx,sy,ex,ey;
int ax[5]={0,0,1,-1};
int ay[5]={1,-1,0,0};
bool map[6][6];
bool vis[6][6];
int ans;
void dfs(int x,int y)
{
	if(x==ex && y==ey)
	  ans++;
	for(int i=0;i<=3;i++)
	  {
	  	int xx=x+ax[i];
	  	int yy=y+ay[i];
	  	if(!map[xx][yy] && !vis[xx][yy])
	  	  if(xx>=1 && xx<=n && yy>=1 && yy<=m)
	  	    {
	  	  	  vis[xx][yy]=1;
	  	  	  dfs(xx,yy);
	  	  	  vis[xx][yy]=0;
		    }
	  }
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	for(int i=1;i<=t;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	map[x][y]=1;
	  }
	vis[sx][sy]=1;
	dfs(sx,sy);
	printf("%d",ans);
}
