//知识点:差分 
/*
By:Luckyblock
题目要求:
给定一长度为n的 初始全0的数列, 给定m次修改操作

对于每次修改操作, 给定四个参数:l,r,s,e
表示 修改范围为[l,r], 对 l+=s, 对 r+=e
每次修改的 值为一个等差数列, 首项为s,尾项为e,长度为(r-l+1)

求数列中 所有修改完成后
所有元素的 异或和 与 最大值 
n <= 1e7, m <= 3e5 ,时间限制 500ms 

分析题意: 
- 这么鬼畜的 数据范围与时间限制, 
  无外部优化情况下, 只可使用 O(n) 算法 
  则对于单次 修改, 必须是O(1) 的

- 如何 进行区间加一 等差数列操作?
  由于 等差数列 的等差性质, 考虑进行差分:
  
  - 如下列等差数列:
    0   0   4   6   8   10   12   0   0
    进行一次差分后:
	0   0   4   2   2   2    2    0   0 
	发现 除了首元素外, 其他元素都相等, 相当于区间加操作
	则可再进行一次差分:
	0   0   4  -2   0   0    0   -2   2 
	发现 只有四个位置被操作, 值有所改变
	
  - 通过 手玩多组数据, 可以发现:
    若 将[l,r]内 加上一首项为s, 尾项为e的 等差数列 公差为 d 
    二次差分后 , 差分数组的变化为 :  
	a[l] += , a[l+1] += (d-s)   
	a[r+1] -=(d+e),a[r+2] += (d+e)	   
	
  则对于 一次修改操作, 可以通过 二次差分, 做到O(1)的复杂度    

- 虽然 修改次数较多, 
  但只需要最后进行一次查询,
  所以可以考虑 O(1)差分, 
  再通过 二次取前缀和 O(n)还原 
*/
#include<cstdio>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define int long long
const int MARX = 1e7+10;
//=============================================================
int n,m,ans1,ans2;
int diff[MARX];//差分数组 
int sum1[MARX],sum2[MARX];//两次前缀和 
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
	n = read(), m = read();
	for(int i = 1; i <= m; i ++)//处理修改操作 
	{
	  int l = read(), r = read(), s = read(), e = read();
	  int d = (e-s)/(r-l);//计算公差 
	  diff[l] += s, diff[l+1] += (d-s),//修改 
	  diff[r+1] -= (d+e), diff[r+2] += (d+e);
	}
	
	sum1[1] = sum2[1] = diff[1], ans1 = ans2 = diff[1];//初始化 
	for(int i = 2; i <= n; i ++)//取前缀和 
	{
	  sum1[i] = sum1[i-1] + diff[i];
	  sum2[i] = sum2[i-1] + sum1[i];
	  ans1 ^= sum2[i], ans2 = max(ans2,sum2[i]);
	}
	
	printf("%lld %lld",ans1,ans2);	
}
