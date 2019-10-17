//知识点:组合数学 
/*
题意: 
求有多少种长度为 n 的序列 A,
满足以下条件：
1.  1 ~ n这n个数在序列中各出现了一次
2.  若第 i 个数A[i]的值为i，则称i是稳定的。
	序列恰好有 m 个数是稳定的

分析题意:
1. 当第 i个数在第 i个位置上时,称 i是稳定的
   看到 这种 数列顺序的关系
   自然就想到了 错排. 
   可以发现: 
   位置错误的数有 n-m个
   故错排的方案数为D[n-m] 

2. 除位置错误的人外
   还有 m 个人位置正确
   这 m 个人的组合
   需要从n个人中随意选择 
   方案数为：
   C(n,m) 
3. 由上,可知:
   位置错误的方案数为 D[n-m]
   位置正确的方案数为 C(n,m)
   故:总方案数为 
   D[n-m] * C(n,m) 
   
算法实现:
有了公式,就什么都好办了
1.首先预处理 错排方案数D[] 与 阶乘fac[]
2.使用Lucas定理 , 求得C(n,m) 
3.使用快速乘去余,求得 D[n-m] * C(n,m) 
*/ 

//思路写了之后 
//代码注释真的没什么好写的啊= = 
#include<cstdio>
#include<ctype.h>
#define int long long
//==========================================
const int MARX = 1e6+10;
const int mod = 1e9+7;
int T,n,m;
int fac[MARX]={1,1,2};//阶乘 
int D[MARX]={1,0,1};//错排 
//==========================================
inline int read()//快读 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline int mul(int x,int y)//快速幂 
{
	int ans=1;
	x%=mod;
	while(y)
	{
	  	if(y&1) ans=ans*x%mod;
	  	x=x*x%mod;
	  	y>>=1;
	}
	return ans;
}
int c(int n,int m)//求C(n,m) 
{
	return m>n?0 : (fac[n] * mul(fac[m],mod-2))%mod * mul(fac[n-m],mod-2)%mod;
}
int lucas(int n,int m)//递归求得Lucas(n,m) 
{
	return !m?1 : c(n%mod,m%mod) * lucas(n/mod,m/mod)%mod;
}
//==========================================
signed main()
{
	for(int i=3;i<MARX;i++)//预处理 错排方案数 与 阶乘 
	{
	    D[i]=((i-1)%mod*(D[i-1]%mod + D[i-2]%mod)%mod)%mod;
	    fac[i]=(fac[i-1]*i%mod)%mod;	
	}
	
	T = read();
	while(T--)
	{
	  	n=read(),m=read();
	  	printf("%lld\n",(lucas(n,m)%mod*D[n-m]%mod)%mod);
	}
}
