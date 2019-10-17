//知识点:搜索 
/*
By:Luckyblock
题目中 , 棋子可以向空格子移动
那么可以进行转换 , 
将棋子移动,变为空格子移动.

使用记忆化dfs , 
记录 [空格子坐标],[目标棋子坐标] 状态 所需要的最小步数
使用dfs进行更新,
当目标棋子坐标 = 目标位置坐标时,记录最小答案即可.

可以拿到45分的好成绩(大雾 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
const int INF = 1e9+7;
const int cx[5] = {114514, 0,0,1,-1}; //change_x , change_y
const int cy[5] = {114514, 1,-1,0,0}; 
//=============================================================
int n,m,q , ans, ex,ey,sx,sy,tx,ty;
bool map[31][31];//棋盘 
int step[31][31][31][31];//记忆化, 记录 [空格子坐标],[目标棋子坐标] 状态 所需要的最小步数
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(;  isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void dfs(int wx,int wy,int nx,int ny,int sum) //white_x,white_y  and  now_x,now_y
{
	if(sum > step[wx][wy][nx][ny]) return ;//非较优解 
	step[wx][wy][nx][ny]=min(sum,step[wx][wy][nx][ny]);//更新 
	if(nx==tx && ny==ty)//到达目标位置 
	{
	  ans = min(ans,sum);
	  return ;
	}
	for(int i=1;i<=4;i++)//移动空格子 
	{
	  int nwx=wx+cx[i] , nwy=wy+cy[i]; //new_white_x,new_white_y
	  if(nwx<1 || nwx>n || nwy<1 || nwy>m || map[nwx][nwy]==0) continue;//越界 
	  if(nwx==nx && nwy==ny) dfs(nwx,nwy,wx,wy,sum+1);//空格子与目标棋子交换位置 
	  else dfs(nwx,nwy,nx,ny,sum+1);//空格子不与目标棋子交换位置 
	}
}
//=============================================================
signed main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    map[i][j]= read();
	
	while(q--)
	{
	  ans=INF; memset(step,INF,sizeof(step));//初始化 
	  ex=read(),ey=read(),sx=read(),sy=read(),tx=read(),ty=read();
	  dfs(ex,ey,sx,sy,0);//搜索 
	  printf("%d\n",ans==INF?-1:ans);
	}
}
