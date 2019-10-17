//知识点:搜索 
/*
By:Luckyblock
题目要求:
给定 n*n 个数, 和一个n*n的空矩阵 
求 一种 填数的方式, 使在不重复使用数字的情况下,
矩阵的每行,每列, 及两条对角线上的数 和相等
输出字典序 最小的方案 (将每行顺次相连之后，字典序最小) 
n<=4

分析题意:
看到 无比暴力的题目要求 和 无比暴力的 n<=4,
就知道这必然是个搜索了= =

为了使 字典序最小,
则需要使 靠右上的矩阵元素尽可能小 
则应先将 填涂数生序排序 
dfs时 , 应按照从左往右,从上往下的顺序枚举矩阵元素
填数时 按照 升序枚举填涂数字 
这样 第一个构成的合法矩阵 一定是字典序最小的矩阵 

80分:
爆搜爆搜!!!
直接枚举 每一个位置可以选择的数,
并暴力检查是否可以组成合法 的 矩阵 
复杂度O((n^2)!) 

100分: 
考虑一些优化:
由于爆搜 时, 各行,列,对角线 的和都不确定
所以要 将矩阵 添完后才可计算 是否合法
针对这方面进行优化:

先将 第一行进行填涂,
然后将第一行 的和作为标准和 ,用于和其他的和进行比较
之后每填涂完 某一行,或某一列,
就将 改行 或 该列的和与 标准和进行对比
相等时 , 才能继续进行 dfs. 
这样就可以通过本题 
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctype.h>
#define int long long
//=============================================================
int n,a[20] , map[5][5]; 
bool use[20];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void putout(int st)//输出 
{
	printf("%lld\n",st);
	for(int i=1; i<=n; putchar('\n'),i++)
	  for(int j=1; j<=n; j++)
	    printf("%lld ",map[i][j]);
	exit(0);
}
bool judge(int y,int st)//判断第y列,和对角线 是否合法 
{
	int sum1=0,sum2=0,sum3=0;//1为第y列,2为从右向左的对角线,3为从左向右的对角线 
	for(int i=1; i<=n; i++) //求和 
	  sum1+=map[i][y],sum2+=map[i][n-i+1],sum3+=map[i][i];
	if(y!=n) return (sum1==st && sum2==st);//比较 
	return (sum1==st && sum2==st && sum3==st);
}
void dfs(int x,int y,int st,int sum)//x为纵,y为横 
{
	if(x==n && y>1 && y<=n) //某一列填涂完毕 
	  if(!judge(y-1,st)) return;
	if(x==n+1 && y==1)//矩阵填涂完毕 
	{
	  if(judge(n,st)) putout(st);//合法且字典序最小的 矩阵 
	  else return ;
	}
	for(int i=1; i<=n*n; i++)
	  if(!use[i])//枚举填涂数字 
	  {
	  	use[i]=1, map[x][y] = a[i]; 
		if(y < n) dfs(x,y+1,st,sum+a[i]);
	  	else if(sum+a[i] == st) dfs(x+1,1,st,0);//某一行填涂完毕 
	  	use[i] = 0;
	  }
}
void start(int now,int sum)//填涂第1行,然后开始dfs 
{
	if(!now) {dfs(2,1,sum,0); return;} //第一行填涂完毕 
	for(int i=1; i<=n*n; i++)
	  if(!use[i])//填涂第一行 
	  {
	  	use[i] = 1 , map[1][n-now+1] = a[i];
	  	start(now-1,sum+a[i]);
	  	use[i] = 0;
	  }	
}
//=============================================================
signed main()
{
	n = read();
	for(int i=1; i<=n*n; i++) a[i] = read();
	std::sort(a+1,a+n*n+1);//升序排序  
	start(n,0);
}
