//知识点:枚举暴力,hash取模,瞎搞
/*
By:Luckyblock
题目要求: 
求方程: a0 + a1x + a2x^2 +...+ anx^n = 0 ,
在区间[1,m] 内的整数解. 

分析题意:
观察数据范围: 
0<n<=100 , m<1e6, 可以跑 O(nm)的算法 
|ai| <=10^(10000) 高精都会超时 的 神仙范围. 
考虑取模运算.

可以发现,假设对方程的 每个系数项进行取模, 
在 自变量取值相同的情况下 , 如果原方程右侧为0,
那么取模后 方程的右侧仍为0

另一个问题:
如何在较低 的 时间复杂度内求得 a0 + a1x + a2x^2 +...+ anx^n 的值? 
考虑对式子进行转化:
 a0+a1x+a2x^2+...+anx^n
=a0+ x(a1+a2x+...+anx^(n-1)) 
=a0+ x(a1 + x(a2+...+anx^(n-2)) ) )
=...
=a0+ x(a1+x(a2+x(a3+....an)))...)
明显可用递归求解 ,也可用循环求解. 
复杂度是线性的

算法实现:
那么可以跑 O(nm) 的算法,
直接暴力枚举自变量的取值
再求解方程,检查方程右侧是否为0 ,并记录合法解即可.

算法漏洞:
类似hash算法 ,此解法也存在碰撞的风险.
使用不同的取模质数,可以取得不等的分数
但是只使用1e9+7可以拿到满分(大雾 
为减少碰撞 概率,最好使用不同的大质数二次 取模. 
*/

//双模100分: 
#include<cstdio>
#include<ctype.h>
#define int long long
const int MARX = 1e6+10;
const int mod1 = 19260817;//两个大模数 
const int mod2 = 998244353;
//=============================================================
int n,m,num , a[110],b[110],ans[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void read1(int &a1 , int &b1)//快读 取模改进版 
{
    int s=1, w1=0,w2=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w1=(w1*10+ch-'0')%mod1,w2=(w2*10+ch-'0')%mod2;
    a1=s*w1,b1=s*w2;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=0; i<=n; i++) read1(a[i],b[i]);//读入并二次取模 
	
	for(int i=1,sum1=0,sum2=0; i<=m; i++,sum1=0,sum2=0)//暴力枚举答案 
	{
	  for(int j=n; j; j--) sum1=((a[j]+sum1)*i)%mod1,sum2=((a[j]+sum2)*i)%mod2;//求解 
	  sum1=(sum1+a[0])%mod1,sum2=(sum2+a[0])%mod2;
	   
	  if((!sum1) || (!sum2)) ans[++num]=i;//符合要求,加入答案 
	}
	printf("%lld\n",num);
	for(int i=1;i<=num;i++) printf("%lld\n",ans[i]);
}

//单模 1e9+7 卡过: 
/* 
#include<cstdio>
#include<ctype.h>
#define int long long
const int MARX = 1e6+10;
const int mod = 1e9+7;
//=============================================================
int n,m,num , a[110],ans[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = (w*10+ch-'0')%mod;
    return s*w;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=0; i<=n; i++) a[i]=read();
	for(int i=1,sum=0; i<=m; i++,sum=0)//暴力枚举答案 
	{
	  for(int j=n; j; j--) sum=((a[j]+sum)*i)%mod;//求解 
	  sum=(sum+a[0])%mod;
	  if(!sum) ans[++num]=i;//符合答案 
	}
	printf("%lld\n",num);
	for(int i=1;i<=num;i++) printf("%lld\n",ans[i]);
}
*/ 
