//知识点:组合数学/暴力枚举 
/*
题解链接: https://www.luogu.org/blog/koishikoishi/solution-p3799

题意: 
有n根木棒，现在从中选4根，
想要组成一个正三角形，问有几种选法？

由题意知,欲由4根木棒,组成一个正三角形,
则必然有两根的长度相同 , 
且另外两根的长度和,等于前两根的长度 

又发现各木棍的长度 a[i] <=5000
则可以直接用两层循环,
暴力枚举两种木棍的长度 
 
用桶 num[] ,记录各长度的木棒出现的次数

外层循环枚举两根相等的木棒的长度 i , 
当此长度的木棒数量 >= 2时,进入内层循环
内层循环,枚举一根用来 合成 的木棒长度 j 
另一根合成用的木棒长度即为 i-j.

如果 (i==j && num[j]>=1 && num[i-j]>=1) ,
  那么  ans+=  C2(num[i]) * C1(num[j]) * C1(num[i-j]);
如果(j==i-j && num[j]>=2) 
  那么 ans+=  C2(num[i]) * C1(num[j]);

内层循环:
    然后要从 剩下的木棒中 中取出两个  
  	  长度之和为 i 的木棒
      
      如果 j==i-j ,   
        那么要从长度为 j 的木棒中取出 2 个  
        那么方案数为:
        从 num[j] 个数中取出 2 个数的组合   
        即C(num[j],2) 
        
      如果j != i-j
        那么要从长度为 j 的木棒中取出 1 个  
        再从长度为 i-j 的木棒中取出 1 个  
        同理 , 那么方案数为:  
        C(num[j],1) \times C(num[i-j],1)
        
   根据乘法原理 ，  
   将所有方案数相乘 ,  
   即得 ans 的变化量 . 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
#define max(a,b) a>b?a:b
//======================================================= 
const int MARX = 1e6+10;
const int mod = 1e9+7;
int n,ans,maxa;
int a[MARX],num[MARX];
//=======================================================
inline int read()
{
	//isdigit函数,判断字符是否为数字字符,包含在<ctype.h>库中  
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline int C(int x,int k)//求得从n个数中取出k个数的组合 
{
	return k==1?x:x*(x-1)/2;
}
//=======================================================
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)//读入,并放入桶中 
	  a[i]=read(),
	  maxa=max(a[i],maxa),
	  num[a[i]]++;
	  
	for(int i=2;i<=maxa;i++)//枚举两根相等的边 
	  if(num[i]>=2)
	    {
	      int times = C(num[i],2)%mod;//求出组合数 
	      for(int j=1;j<=i/2;j++)//枚举被合成的边 
	        {
	          if(j!=i-j && num[j]>=1 && num[i-j]>=1)//当用来合成的木棒长度不等 
	            ans=(ans + times*C(num[j],1)%mod*C(num[i-j],1)%mod)%mod;
			  if(j==i-j && num[j]>=2)//当用来合成的木棒长度相等 
			    ans=(ans + times*C(num[j],2))%mod;
			}
		}
	
	printf("%lld",ans%mod);
}
