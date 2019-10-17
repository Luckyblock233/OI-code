//知识点:二分答案,前缀和 
/*
By:Luckyblock
题目要求:
给定 一数列a, 给定m个区间[li,ri], 给定一参数S 
可任意选择 参数W的值
区间i的贡献 Yi = ∑(区间内>=W的数的数量) * ∑(区间内>=W的数的权值和)

总贡献 = abs(∑Yi - S);
求 令总贡献最小的 参数W的值 

分析题意:
- 对于所求的 W, 发现如下性质:
  当 W 单增时, wj大于等于W的 元素数量 单减, 总贡献Y单减 
  当 W 单减时, wj大于等于W的 元素数量 单增, 总贡献Y单增
  
  发现 W 的取值 与Y呈 负相关, 则可以通过二分答案 枚举W;

- 当 W 确定时, 考虑如何求得Y, 以检查答案的优劣性
  1.暴力枚举!
    对于 每一个所求区间, 暴力枚举其中合法元素, 并暴力计算
	复杂度 O(nm) , 必然会被卡掉 
	
  2.要求 区间内合法元素数 及 区间内合法元素的和
  	显然, 所求的 两量满足可减性 , 
	可以使用前缀和 O(n)维护 , 并可O(1) 求得每个区间内 两量
	就可 O(1)计算出 单个区间的贡献 
    复杂度 O(n) 
*/
#include<cstdio>
#include<ctype.h>
#include<cstdlib>
#define max(a,b) (a>b?a:b)
#define int long long
const int MARX = 2e5+10;
//=============================================================
int n, m, S, ans, maxw , w[MARX], v[MARX];
int l[MARX], r[MARX];//查询的m个区间 
int sum1[MARX], sum2[MARX];
//sum1,2为 两前缀和数组, 1为满足条件的 矿石个数, 2为满足条件的 矿石 价值和 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch); ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch); ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int abs(int x) {return (x<0?-x:x);}//绝对值 函数 
bool check(int W,int &sum)
{
	sum = 0;
	for(int i = 1; i <= n; i ++) //维护两前缀和 
	  sum1[i] = sum1[i-1] + (w[i] >= W),
	  sum2[i] = sum2[i-1] + v[i] * (w[i] >= W);
	
	for(int i = 1; i <= m; i ++)//枚举查询区间 
	{
	  int l1 = l[i], r1 = r[i];//计算 区间的贡献 
	  sum += (sum1[r1]-sum1[l1-1]) * (sum2[r1]-sum2[l1-1]);
	}
	return sum > S;//检查答案优劣性 
}
//=============================================================
signed main()
{
	n = read(),m = read(), S = read();
	for(int i = 1; i <= n; i ++)
	{
	   w[i] = read(), v[i] = read();
	   maxw = max(maxw,w[i]);
	}
	for(int i =1 ; i <= m; i ++) l[i] = read(), r[i] = read();
	
	for(int l = 1,r = maxw; l <= r;)//二分枚举 参数W 
	{
	  int mid = (l + r) >> 1, sum;
	  if(check(mid,sum)) l = mid + 1; 
	  else r = mid - 1;
	  if(abs(sum - S) < abs(ans - S)) ans = sum;//更新答案 
	}
	printf("%lld",abs(ans - S));
}
