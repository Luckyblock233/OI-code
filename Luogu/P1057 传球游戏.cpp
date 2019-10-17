//知识点:DP 
/*
By:Luckyblock
题目要求:
有n个人 围成一个环形 
初始时 球在第一个人处 
每个单位时间内, 每个人都可以向左向右传球
求 经过m单位时间后 ,球回到第一个人手中 不同传球方案数 

分析题意:
很显然的sbDP
设 f[i] 为从1--i人的不同方案 
因为存在时间差异 , 所以存在后效性 
要进一步改进状态: f[i][j] 为从1-->i,经过j时间的 方案数

则有状态转移方程:
f[i+1][j] +=f[i][j-1] ,f[i-1][j] += f[i][j-1]
为避免时间的影响, 
枚举时要先枚举当前时间, 然后枚举当前位置
再进行转移求和 
*/
#include<cstdio>
#include<ctype.h>
#include<queue>
#define int long long
const int MARX = 40;
//=============================================================
int n,m,ans ,f[MARX][MARX];//i人j时间的方案 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	f[1][0] = 1;//初始值 
	for(int j=1; j<=m; j++)//枚举时间 
	  for(int i=1; i<=n; i++)//枚举 当前位置 
	  {
	    int pre = (i-1==0)?n:i-1, aft = (i+1==n+1)?1:i+1;//前驱后继 
	  	f[pre][j] += f[i][j-1],f[aft][j] += f[i][j-1];//转移 
	  }
	
	printf("%lld",f[1][m]);
}
