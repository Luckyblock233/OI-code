//知识点:快速幂
/* 
简单数学题目, 可以将题目转化为: 
求解算式 (x+10^k*m)%n 的答案，
k<=10^9，很明显直接求乘方 会 变量爆破，
使用快速幂求余即可 
*/ 
#include<cstdio>
#include<ctype.h>
//=============================================================
int n,m,k,x;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int mul(int a,int b,int mod)//快速幂求余 模板 
{
	int ans=1;
	while(b)
	  {
	  	if(b&1) ans=ans*a%mod;
	  	a=(a*a)%mod;
	  	b>>=1;
	  }
	return ans%mod;
}
//=============================================================
signed main()
{
	n=read(),m=read(),k=read(),x=read();
	int y= ( x%n + m%n*mul(10,k,n)%n ) %n ;//求解算式 
	printf("%d",y);
}
