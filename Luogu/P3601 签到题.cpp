//知识点:简单数论, 欧拉函数, 筛法求素 
/*
By:Luckyblock
题目要求:
给定 l,r, 求 ∑(i- Φ(i)) (l <= i <= r)
1<=l<=r<=1e12, r-l<=1e6

分析题意:
有下列性质 : 

1. 对于 $x \in Z$, 有:  
	
	$\large \phi(x) = x \times \prod\limits_{i=1}^{x}{\dfrac{p_i-1}{p_i}} (p_i \mid x)$
	
	$x$ 的一质因子 $p_i$ 对 $\phi (x)$ 的贡献为 $\dfrac{p_i-1}{p_i}$
	
2.  对于 一个合数$x$ , 至多存在一个 质因子 , $\ge \sqrt{x}$ 
	
	- 则可以筛出 $[1,\sqrt{1e12}]$ 内的质数
	  然后 用这些质数  对 $[l,r]$ 进行试除 ,   
	    
	    若可整除 $x$ , 则计算其对 $\phi(x)$ 的贡献
	 
	- 如何特判 $\ge \sqrt{x}$ 的 之多一个 质因子 $p_{max}$? 
	  显然 , $\large p_{max} = \dfrac{x}{\prod\limits p_i^{a_i}}$
	
	  则可 在试除时 , 对原数 $x$ 进行操作 , 
	  全部试除完毕后 , 原数 $x$ 变成 $1$ 或者 $p_{max}$
	  此时再计算 $p_{max}$ 的贡献即可 
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define ll long long
const int MARX = 1e6+10;
const ll mod = 666623333;
//=============================================================
ll L,R,ans,K[MARX],phi[MARX];
bool flag[MARX];
std::vector <ll> prime;
//=============================================================
inline ll read()
{
    ll s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	L = read(), R = read();
	for(int i = 2; i < MARX; i ++)//筛出[2,1e6]中的质数 
	{
	  if(!flag[i]) prime.push_back(i);
	  for(int j = 2; i * j < MARX; j ++)
	    flag[i*j] = 1;
	}
	
	for(ll i = L; i <= R; i ++) phi[i-L] = K[i-L] = i;//初始化 
	 
	for(int i = 0,size = prime.size(); i < size; i ++)//枚举质数 
	  for(ll j = max(2ll, (L-1) / prime[i] + 1); prime[i]*j <= R; j ++)//枚举质数的倍数 
	  {
	  	ll x = prime[i] * j - L; 
	  	phi[x] = phi[x] / prime[i] * (prime[i]-1);//计算 贡献 
	  	for(;K[x] % prime[i] == 0;) K[x] /= prime[i];//除去 pi 
	  }
	  
	for(ll i = L; i <= R; i ++)//枚举l~r中的数 
	{
	  if(K[i-L] != 1) phi[i-L] = phi[i-L] / K[i-L] * (K[i - L] - 1);//计算 >=sqrt(x)的质因子的贡献 
	  ans = (ans + (i - phi[i-L])) % mod;//累加答案 
	}
	
	printf("%lld", ans);
}
