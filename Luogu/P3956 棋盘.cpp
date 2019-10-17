//知识点:记忆化,dfs 
/*
搜索 + 简单剪枝
比较简单 , 详见注释 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
const int INF = 0x3f3f3f;
const int ex[5] = {0,1,-1,0,0};//坐标变化量 
const int ey[5] = {0,0,0,1,-1};
//=============================================================
int m,n,ans=INF, map[110][110],step[110][110];//map存图的情况,step存到达各点的花费 
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//x,y存当前点坐标,sum 存到达当前点的花费,magci存转移到当前点是否使用了魔法 
void dfs(int x,int y,int sum,bool magic)
{
	if(sum>=step[x][y]) return ;//最优性剪枝 
	step[x][y]=sum;//赋值 
	if(x==m && y==m)//到达终点 
	{
	  ans=min(ans,step[x][y]);
	  return ;
	}
	for(int i=1,nx=x+ex[i],ny=y+ey[i];i<=4;i++,nx=x+ex[i],ny=y+ey[i])//枚举能到达的点 
	  if(nx>=1 && nx<=m && ny>=1 && ny<=m)//不越界 
	  {
	  	if(!map[nx][ny])//无色情况 
	  	{
	  	  if(!magic)//没有使用过魔法 
	  	  {
	  	    map[nx][ny]=map[x][y];//更改颜色,并进行转移 
	  	    dfs(nx,ny,sum+2,1);
		    map[nx][ny]=0;	
		  }
		  continue;	
		}
	  	dfs(nx,ny,sum+(map[x][y]!=map[nx][ny]),0);//有色情况,按照颜色同异情况进行转移 
	  }
}
//=============================================================
signed main()
{
	m=read(),n=read();
	for(int i=1;i<=n;i++)
	{
	  int x=read(),y=read(),c=read()+1;
	  map[x][y]=c;
	}
	memset(step,INF,sizeof(step));//初始化花费,为极大值 
	dfs(1,1,0,0);
	printf("%d",ans>=INF?-1:ans); 
}

