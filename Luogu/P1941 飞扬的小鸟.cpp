//知识点: 完全背包,01背包 
/*
By:Luckyblock
//=============================================================
分析题意:
用 f[i][j] 表示横坐标为i , 纵坐标为j时的 最少花费 

先初始化 f[i][0] = INF (不可落地) ,
f[0][i]=0 (可以选择横坐标为0的任意一处为起点 

可以发现, 对于一个确定的横纵坐标的位置: 
1. 由 横坐标-1 处不上升,下落得到 
2. 由 横坐标-1 处经过 多次上升操作得到

那么可以简单的 得到状态转移方程式:
1. 当 j<m时 ,有: f[i][j] = min(f[i][j] , f[i-1][j - k*x[i]] + k) (k in Z)  
2. 当 j==m时 , 已经到达了 平面的顶部,
   不可继续上升,但是可以通过任意纵坐标处 的 多次上升来得到
   则有: f[i][m] = min(f[i][m] , f[i-1][j + k*x[i]] (j + k*x[i]>=m && j + k*x[i]<m+x[i])
3. 当横坐标为 i时,如果有柱子,
   则有: f[i][j] = INF (j in   [1,l[i]] , [h[i],m]) 
   表示柱子覆盖位置 不可到达 

对于每个横坐标 , 完成转移后,
都记录到达此横坐标的最小步数
如果最小步数 == INF , 则此横坐标不可到达
输出经过的柱子数即可
 
总复杂度为 O(n^2 * m)
可以拿到80分的好成绩(大雾 
//=============================================================
考虑优化: 
对于两种位置的转移,
1. 由 横坐标-1 处不上升,下落得到  --->  类似01背包 
2. 由 横坐标-1 处经过 多次上升操作得到 ---> 类似完全背包 

那么可以类比两种背包的写法 , 
来对状态转移进行优化

主要优化 第二种转移,
新的转移方程式为:
f[i][j] = min(f[i][j] , f[i][j-x[i-1]]+1 , f[i-1][j-x[i-1]]+1) 

对于每一个横坐标,先跑完全背包,再跑01背包
记录最小步数即可

总复杂度 O(n*m)  
//=============================================================
观察状态转移方程式,
还可以通过滚动数组,
来滚掉第1维 , 以优化空间复杂度 
*/
#include<cstdio>
#include<ctype.h>
#define ll long long
#define min1(a,b) ((a)<(b)?(a):(b))
#define min(a,b,c) (min1(a,min1(b,c)))
const ll INF = 0x7fffffffff;
const int MARX = 1e4+10;
//=============================================================
int n,m,k , x[MARX],y[MARX],h[MARX],l[MARX];//输入各数据 
ll ans=INF , f[MARX][1010];//表示横坐标为i , 纵坐标为j时的 最少花费  
bool jud[MARX];//jud[i]表示 横坐标为i时是否有柱子 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()//输入 + 初始化 
{
	n=read(),m=read(),k=read();
	for(int i=0; i<n; i++) x[i]=read(),y[i]=read();
	for(int i=1,tmp; i<=k; i++) tmp=read(),l[tmp]=read(),h[tmp]=read(),jud[tmp]=1;
	for(int i=1; i<=n; i++) f[i][0]=INF;
}
void dp()
{
	for(int i=1,num=0; i<=n; i++)
	{
	  ans = INF;
	  for(int j=1; j<=m; j++) f[i][j]=INF;//初始化极大值 
	  //由 横坐标-1 处经过 多次上升操作得到 ---> 类似完全背包  
	  for(int j=x[i-1]+1; j<m; j++) f[i][j] = min(f[i][j] , f[i-1][j-x[i-1]]+1 , f[i][j-x[i-1]]+1);
	  //纵坐标为 m的特殊情况  
	  for(int j=m-x[i-1]; j<=m; j++) f[i][m] = min(f[i][m] , f[i-1][j]+1 , f[i][j]+1);
	  //由 横坐标-1 处不上升,下落得到  --->  类似01背包 
	  for(int j=1; j+y[i-1]<=m; j++) f[i][j] = min1(f[i][j] , f[i-1][j+y[i-1]]);
	  //横坐标为i时有柱子 
	  if(jud[i])
	  {
	  	for(int j=1; j<=l[i]; j++) f[i][j]=INF;//赋极大值 
	  	for(int j=h[i]; j<=m; j++) f[i][j]=INF;
	  	num++;
	  }
	  
	  for(int j=1; j<=m; j++) ans=min1(ans,f[i][j]);//记录最小步数 
	  if(ans==INF) //此横坐标不可到达 
	  {
	  	printf("0\n%d",num-1);
	  	return ;
	  }
	}
	printf("1\n%lld",ans);
}
//=============================================================
signed main()
{
	prepare();
	dp();
}
//知识点:背包DP 
/* 
//By:Luckyblock
暴力10分代码
不考虑障碍物的情况 
直接进行背包DP. 
*/ 
/* 
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
const int MARX = 1100;
const int INF = 0x7f7f7f7f;
//=============================================================
int N,M,K,ans=INF;
int X[MARX],Y[MARX],L[MARX],H[MARX];
int f[MARX][MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()//输入 
{
	memset(f,0x7f,sizeof(f));
	N=read(),M=read(),K=read();
	H[0]=M+1;
	for(int i=1; i<=N; i++)  X[i]=read(),Y[i]=read() , H[i]=M+1;
	for(int i=1,tmp; i<=K; i++) tmp=read(),L[tmp]=read(),H[tmp]=read();
}
void dp()
{
	for(int i=1; i<=M; i++)f[0][i]=0;//初始值 
	for(int i=1,flag=1; i<=N; flag=1,i++)//进行DP 
	{	
	  for(int j=1; j<=M; j++)
	  {
	  	if(f[i-1][j-X[i]]+1 <f[i][j]) //状态转移 
	      f[i][j]=f[i-1][j-X[i]]+1,flag=0;
	    if(j+Y[i]<=M && f[i-1][j+Y[i]]<f[i][j]) 
		  f[i][j]=f[i-1][j+Y[i]],flag=0;
	  }
	  if(flag)//无解 
	  {
	  	printf("0\n%d",i);
	  	return ;
	  }
	}
	for(int i=1; i<=M; i++) ans=min(ans,f[N][i]);//有解 
	printf("1\n%d",ans);
}
//=============================================================
signed main()
{
	prepare();
	dp();
}
*/ 
