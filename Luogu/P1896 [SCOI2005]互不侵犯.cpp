//知识点: 状压DP 
/*
By:Luckyblock
发现 n,m <=9,又要求方案数 , 
就知道这必然是个状压了. 

分析题意:
一些性质:
1. 对于每一行 的棋子摆放情况, 
   只会被相邻的两行棋子所影响
2. 对于两行棋子能否相邻 , 处理方式较麻烦
   但是n,m<=9 , 状态数较少 , 
   可以预处理出所有状态 , 及他们能相邻的其他状态 
//=============================================================
算法实现:
先预处理出 单行的合法状态. (即没有左右相邻的国王的状态) 
并记录此单行状态 的 国王个数  .  
再预处理出 能相邻 的单行状态. (检查每个国王相邻8格内是否有其他国王) 

之后开始状压DP
设 f[i][j][k] 表示,第i行状态为j , 1~i行已经放置了k个国王的方案数
三层循环枚举 当前行数i , 第i-1行的状态,第i行的状态
然后 检查枚举的两行状态是否 能够相邻.

如果可以相邻 , 
继续枚举 第1~i行的国王数量, 
再用 i-1行的方案数 更新 第i行的方案数

转移方程式:
f[i][j][k] = ∑f[i-1][l][k-num[l]] 
(l与j是可以相邻的合法状态 , num记录每个单行状态的国王数量)  

//=============================================================
一些小技巧:
记录合法状态时 ,可以使用vector类.
直接将合法状态压入 vector中, 
枚举状态时 ,用状态在vector中的编号 映射 状态, 
以避免不必要的枚举 , 浪费时间空间 , 增长代码量. 
*/
#include<cstdio>
#include<ctype.h>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define lowbit(x) ((x)&(-x))
//=============================================================
int n,k , all,size ,quan[520];
std::vector <int> plan;//存单行合法状态 
bool map[520][520];//记录两状态能否相邻 
long long ans,f[15][100][520]; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool check(int x,int y)//检查x,y两状态能否相邻 
{
	while(x && y)
	{
	  //如果x相邻三位中 , 能与y的一位同为1 , 那么不合法 
	  if(((x>>1)&y) || ((x<<1)&y) || (x&y)) return 0;
	  x>>=1,y>>=1; 
	}
	return 1;
}
void prepare()
{
	n=read(),k=read(); all=(1<<n)-1;//全集 
	for(int i=0,sum=0; i<=all; sum=0,i++)//枚举所有状态 
	{
	  bool flag=0;
	  for(int l=i,last=-1;l;last=lowbit(l),l-=lowbit(l),sum++)//检查单行是否有相邻国王 
	    if(last == (lowbit(l)>>1)) {flag=1;break;}
	  if(flag || sum>k) continue;//有相邻国王,或者单行数量>总数量 , 不合法 
	  
	  plan.push_back(i);//加入vector中 
	  f[1][sum][plan.size()-1]=1;//初始化i=1时的答案 
	  quan[plan.size()-1]=sum;//记录数量 
	}
	
	size=plan.size();//检查各状态能否相邻 
	for(int i=0; i<size; i++)
	  for(int j=i; j<size; j++)
	    if( check(plan[i],plan[j]) )
	      map[i][j]=map[j][i]=1;
}
void dp()
{
	for(int i=2; i<=n; i++)
	  for(int j=0; j<size; j++)// i-1行的状态 
	    for(int l=0; l<size; l++)// i行的状态 
	      if(map[j][l])//可以相邻 
		    for(int r=quan[j]; r<=k-quan[l]; r++)// 1~i-1 行 的数量
			  f[i][r+quan[l]][l] += f[i-1][r][j];//更新 
}
//=============================================================
signed main()
{
	prepare();
	dp();
	for(int i=0; i<size; i++) ans+= f[n][k][i];//枚举最后一行的状态,并累加求和 
	printf("%lld",ans);
}
