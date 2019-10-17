//知识点:状压DP 
/*
By:Luckyblock
题目要求: 
给出一 n*m 的矩阵,有些方格可以生草 
不能有相邻的 , 生草的方格,
求填充矩阵的方案数 

分析题意: 
看到此题。 n<=12,m<=12 ,基本确定这是一个状压DP了
还可以发现,只有相邻的两行 , 才会互相影响. 
之后开始设计状态:
使用二进制数 , 表示每行 地皮的生草情况. 
设 f[i][j] 表示 ,当前到了第i行,第i行的状态为j,的方案数.

可以先进行初始化 , 获得每一行的合法状态,
即不存在 左右相邻 的 生草地皮的 状态.

然后 再将矩阵从上至下遍历,
每次枚举相邻的两行 ,
再枚举两行各自的合法状态.
1.如果这些合法状态可以 相邻并存 , 
  那么就更新下面一行 ,  此状态的答案,
  方程式为:
  f[i][j] =  ∑f[i-1][k] (j,k均为合法状态,且可以相邻并存)
2.否则,就不更新.

最后将最后一行,即第n行 , 
的所有合法状态的方案数求和,即为答案 

注:
观察方程式,发现可以使用滚动数组滚掉第 1 维
来进行空间复杂度的优化. 
*/
#include<cstdio>
#include<ctype.h>
#define lowbit(x) ((x)&-(x))
const int mod = 1e8;
const int MARX = 4100;
//=============================================================
int n,m,all , log_2[MARX];
bool map[20][20],plan[20][MARX];
long long ans,f[20][MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void prepare()//输入及预处理 
{
	for(int i=0,sum=1;i<=15;i++,sum<<=1) log_2[sum]=i; //预处理log函数 
	
	n=read(),m=read() ; all=(1<<m)-1;//全集 
	for(int i=1; i<=n; i++) 
	  for(int j=1; j<=m; j++)
	    map[i][j-1]=read();
	    
	for(int i=1; i<=n; i++)//获得各行的合法状态 
	  for(int j=0; j<=all; j++)
	  {
	  	bool flag=0;
		for(int k=j,last=-1; k; last=lowbit(k),k-=lowbit(k))//检查状态j的合法性 
	      if( map[i][log_2[lowbit(k)]]==0 || 2*last==lowbit(k) )//是否可以生草 及 是否存在连续的生草地皮 
		  {
		  	flag=1;break;//不合法,打标记 
		  }
	  	if(flag) continue;
	  	plan[i][j]=1 , f[i][j]=(i==1);//记录状态合法性 
	  }
}
void dp()
{
	for(int i=2; i<=n; i++)//枚举相邻的两行 
	  for(int j=0; j<=all; j++) //枚举两行的合法状态 
	    for(int k=0; k<=all; k++)
	      if( (plan[i-1][j] && plan[i][k]) && ((j&k)==0) )//两状态均合法 并且 可以相邻 
	        f[i][k]= (f[i][k]+f[i-1][j])%mod;//更新方案数 
}
//=============================================================
signed main()
{
	prepare();
	dp();
	for(int i=0; i<=all; i++)//更新答案 
	  if(plan[n][i]) 
	    ans=(ans+f[n][i])%mod;
	printf("%lld",ans);
}
