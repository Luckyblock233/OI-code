//知识点 : 状压DP 
/*
By:Luckyblock
分析题意:
- 由于 每次只能花费一枚硬币, 且硬币数<=16
  则可以使用 一二进制串, 表示硬币的花费状况

- 为什么会导致 无法完成购买 ?
  可以发现, 若花费完所有硬币后, 还无法买到第n个物品
  则 导致无法完成购买. 
  
  则对于每一个 硬币花费状态,   
  都需要最大化其 能购买的物品编号 
  考虑 状压DP. 
 
- 设计状态: 
  设 f[i] : 花费状态i的硬币, 能买到的最远的物品 .
  显然有: f[0] = 0;
  
  设将第j个硬币, 价值为w[j], 添加到状态i中,  
  则有状态转移方程 为:
  f[i + 1<<j] = max(f[i + 1<<j] , f[i] + k) (sum[f[i] +1 ~ k] <= w[j])
  - sum[l,r] 为[l,r]内 物品的价值总和
  	可以使用前缀和进行维护, 并O(1)查询
    
	如何快速查询 最优的 k (sum[f[i] +1 ~ k] <= w[j]) ?
	由于前缀和 单调递增, 则可以进行二分查找
	在logn的时间内 求得最优的k 
  	 
  - 终止条件 
    若出现 f[i] == n, 花费说明状态i 的硬币, 已经可以完成购买
    统计其价值, 并取最大值为答案. 即可
*/
#include<cstdio>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define ll long long
const int MARX = 1e5+10;
const int MARXALL = 131080;
//=============================================================
int k, n, all, coin[20], c[MARX], f[MARXALL];;
ll ans = -1, sum[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int upper_search(int value, int l1, int r1)//找到区间[l1,r1] 大于value的第一个位置 
{
	int pos = r1 + 1;
	for(int l = l1, r = r1; l<=r;)
	{
	  int mid = (l + r) >> 1;
	  if(sum[mid] - sum[l1 -1] > value)  pos = mid,r = mid-1;
	  else l = mid + 1;
	}
	return pos;
}
//=============================================================
signed main()
{
	k = read(), n = read(); all = (1 << k) -1;//构造全集 
	for(int i = 1; i <= k; i ++) coin[i] = read();//读入并维护前缀和 
	for(int i = 1; i <= n; i ++) c[i] = read(), sum[i] = sum[i-1] + c[i];
	
	for(int i = 0; i <= all; i ++)
	{
	  if(f[i] == n)//状态满足条件, 统计答案 
	  {
	  	ll sum1 = 0;
	  	for(int j = 0; j < k; j ++) sum1 += (!(1 << j & i))*coin[j+1];//求得 未使用的硬币总和 
	  	ans = max(ans,sum1);//取最大值 
	  	continue;
	  }
	  
	  int l = f[i] + 1, r = n, now = 1;//构造二分查找边界, 与当前枚举到的硬币编号 
	  for(; ; )
	  {
		for(;(1 << (now-1) & i) && now <= k;) now++;//循环枚举 ,直到 一个未被使用的硬币 
		if(now > k) break;
		
		int pos = upper_search(coin[now],l,r) - 1;//查找 最大增量 
		f[i | (1 << (now-1))] = max(f[i | (1 << (now-1))], pos);//转移 
	    now ++;//编号++ 
	  }
	}
	printf("%lld",ans);
}
