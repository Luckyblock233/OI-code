//知识点:组合数学/Lucas定理 
/*
Lucas定理的模板
用来求得 C(n,m)%mod的结果
解决组合数取余的问题

内容: C(n,m)%p= C(n%p,m%p) ×C(n/p,m/p)%p 
即:	  Lucas(n,m)%p=Lucas(n/p,m/p)*C(n%p,m%p)%p 

又: C(n, m)%mod = n! / (m! * (n-m)!)%mod = n! * inv(m!*(n-m)! , mod) % mod

故:可以通过递归 , 并且用费马小定理求逆元进行辅助 , 来求得Lucas(n,m)的值
	递归边界条件即: m==0时,Lucas(n,0)=C(n,0)=1; 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//======================================
const int MARX = 1e5+10;
int fac[MARX]={1};//存阶乘 
//======================================
inline int read()
{
	//isdigit函数,判断字符是否为数字字符,包含在<ctype.h>库中 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int mul(int x,int y,int mod)//快速幂 
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
int c(int n,int m,int mod)//求C(n,m) 
{
	return m>n?0 : (fac[n] * mul(fac[m],mod-2,mod))%mod * mul(fac[n-m],mod-2,mod)%mod;
}
int lucas(int n,int m,int mod)//递归求得Lucas(n,m) 
{
	return !m?1 : c(n%mod,m%mod,mod) * lucas(n/mod,m/mod,mod)%mod;
}
//======================================
signed main()
{
	int T;
	T=read();
	while(T--)
	  {
	  	int n=read(),m=read(),mod=read();
	    for(int i=1;i<=mod;i++)//预处理 1~p 的阶乘(%p意义下,最多到p) 
	      fac[i]=(fac[i-1]*i)%mod;
	    printf("%lld\n",lucas(n+m,n,mod)); 
	  }
}
