//知识点: 二分答案 
/*
By:Luckyblock
题目要求: 
给定 一个矩阵, 每个格点都有点权 
求 从矩阵第一行走到最后一行
经过格点点权最大值 的 最小值

分析题意:
首先观察 答案的性质
当 ans<=i时,满足条件
则 ans>i时也可满足条件
答案满足单调性, 可以使用二分答案 

二分答案枚举 经过的最大点权
之后 使用bfs进行检查
每次都将所在点 周边四个 格点中
点权 <=当前枚举量的 点加入队列
如果最后可以到达最后一行 , 那么此枚举量合法 
*/
#include<cstdio>
#include<queue> 
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int ex[4] = {1,-1,0,0};//坐标变化量 
const int ey[4] = {0,0,1,-1};
//=============================================================
struct node
{
	int x,y;
};
int n,m,ans,maxp , p[1010][1010]; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool check(int now)//bfs 检查 ans=now时的 合法性 
{
	bool vis[1010][1010]={0};
	std::queue <node> q;
	for(int i=1; i<=m; i++)//将 可以到达的初始点加入队列 
	  if(p[2][i] <= now)
	  {
	    q.push((node){2,i});
	    vis[2][i] = 1;
	  }
	for(;!q.empty();)
	{
	  node top = q.front();
	  q.pop();
	  for(int i=0; i<4; i++)//枚举可以转移到的点 
	  {
		int tx = top.x + ex[i], ty = top.y + ey[i];
		if(vis[tx][ty] || p[tx][ty]>now) continue;//答案合法 
		if(tx>n || tx<1 || ty>m || ty<1) continue;//越界 
		if(tx == n) return 1;//到达目标 
		
		q.push((node){tx,ty});//入队 
		vis[tx][ty]=1;
	  }
	}
	return 0;
}
//=============================================================
signed main()
{
	n = read(), m = read();
	for(int i=1; i<=n; i++)
	  for(int j=1; j<=m; j++)//初始矩阵 
	    p[i][j] = read(),
		maxp = max(maxp,p[i][j]);
	
	if(check(0)) {putchar('0'); return 0;}
	
	for(int l=1,r=maxp; l<=r;)//二分枚举 
	{
	  int mid = (l+r) >> 1;
	  if(check(mid)) ans=mid,r=mid-1;
	  else l=mid+1;
	}
	printf("%lld",ans);
}
