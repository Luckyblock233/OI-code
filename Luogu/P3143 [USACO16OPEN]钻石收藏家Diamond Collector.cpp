//知识点: 双指针(尺取法) ,枚举.
/*
By:Luckyblock
题目要求:
给定一数列, 从其中选择 两组数
要求 每组中 各数相差<=K,
求 可以选择的数的 最多的数量 

分析题意:
- 首先对数列进行排序, 
  则选择的对象 则变成了 数的范围区间 
  以便于之后的处理
  
- 先只考虑 选出一个数组的情况:
  可以发现, 
  若固定了区间的左端点, 并向右寻找最优的右端点
  当 左端点右移时, 右端点也只单调右移 

  所以可以使用双指针(尺取法), 
  先令左端点 = 1, 并向右寻找 第一个满足条件的右端点
  之后 左端点右移, 右端点 继续右移, 直到满足条件
 
  在模拟的 过程中取最小的区间大小 
  按照 上述过程进行模拟,
  由于 左右端点 都只单调右移, 则 总复杂度为O(n) 

- 再考虑选择 两个区间
  可以枚举分界线, 把整个 序列分为两份, 
  并在两侧 分别选出 合法的最长的区间长度
  
  为满足上述要求, 可以取前缀最大值
  则 在枚举分界线后, 可以O(1)查询两侧的 最值 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
#define int long long
#define max(a,b) (a>b?a:b)
const int MARX = 5e4+10;
//=============================================================
int n,k,ans,a[MARX];
int pre[MARX],aft[MARX];
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
	n = read(), k = read();
	for(int i=1; i<=n; i++) a[i] = read();
	std::sort(a+1,a+n+1);//排序 
	
	int l = 1,r = 1; pre[1] = 1; 
	for(r=2; r<=n; r++)//预处理 1~i的最长区间长度 
	{
	  for(; a[r] - a[l] > k && l>0;) l++;//更新左端点 
	  pre[r] = max(pre[r-1], r-l+1);//取前缀最大值 
	}
	
	l = n,r = n; aft[n] = 1;
	for(l=n-1; l>=1; l--)//预处理 i~n的最长区间长度 
	{
	  for(; a[r] - a[l] > k && r<=n;) r--;//更新右端点 
	  aft[l] = max(aft[l+1], r-l+1);//取后缀最大值 
	}
	for(int i = 2; i < n; i ++)//枚举分界线, 取最大值作为答案 
	  ans = max(ans,pre[i]+aft[i+1]);
	printf("%lld",ans);
}
