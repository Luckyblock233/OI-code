//知识点:约数个数, 唯一分解定理, 筛法求素 
/*
By:Luckyblock
数学推导公式较多 , 使用了latex进行渲染 
题目要求:

给定 $\large n$ , 求 $\large \dfrac{1}{x} + \dfrac{1}{y} = \dfrac{1}{n!}$ 的正整数解  的对数

分析题意:

- 首先对 求解式进行转化 :  

  $$\large \dfrac{1}{x} + \dfrac{1}{y} = \dfrac{1}{n!}$$   

  $$\large y\times n!+x\times n! = x\times y$$

  $$\large x\times y - \large y\times n!-x\times n! = 0$$

  $$\large x\times y - \large y\times n!-x\times n! + (n!)^2 = (n!)^2$$

- 根据 十字相乘法则 , 进行因式分解, 则有: 

   $$\large (x-n!)(y-n!) = n!$$

  由于 $x,y,n \in Z$  ,  则 $(x-n!) \text{与} (y-n!)$ 都为 $n!$ 的约数
  则 题目所求解的对数 ,  即为 $n!$ 的约数个数

-  根据 唯一分解定理 ,若设:
	
	$$\large n! = \prod\limits{p_i^{c_i}}(p_i\mid n)$$
	
	
	根据约数和定理 ,  则有:
	
	$$\large \alpha(n!) = \prod\limits{(c_i+1)}$$

	则题目所求 即为:  
	
	$$\large \alpha((n!)^2) = \prod\limits{(2\times c_i+1)}$$

- 由于 $\large n!$ 的质因子都 $\large\le n$ ,   
  则可以使用筛法直接预处理出所有 有贡献的素数

- 有一公式 :
	
	对于 $\large n!$ , $\large p_i$ 在 $\large n!$ 的质因数分解中 , 指数 的值 $\large c_i$ 
   $$\large c_i = \sum\limits_{k=1}^{\inf}{\lfloor\frac{n}{p_i^k}\rfloor} (p_i^k\le n)$$ 

	根据 此公式 , 即可可求得 指数 $c_i$ 的值
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
#define ll long long
const ll mod = 1e9+7;
const int MARX = 1e6+10;
//=============================================================
int n;
ll ans = 1;
bool flag[MARX];
std::vector <ll> prime;
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
	n = read();
	for(int i = 2; i <= n; i ++) //埃氏筛预处理所有 <=n的素数 
	{
	  if(!flag[i]) prime.push_back(i);
	  for(int j = 2; i * j <= n; j ++)
	    flag[i*j] = 1;
	}	
	
	for(int i = 0,size = prime.size(); i < size && prime[i] <= n; i ++)//枚举素数 
	{
	  ll tmp = 0, x = n, y = prime[i];
      for (; x; x /= prime[i]) tmp += x / y;//求得 x/y, x/(y^2), x/(y^3)... 
      ans = (ans * (tmp << 1 | 1) % mod) % mod;//累乘 计算贡献 
	}
	printf("%lld",ans);
}
