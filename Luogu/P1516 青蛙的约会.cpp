//算法：数论/扩展欧几里得 
/*
1.两只青蛙相遇，
会有[(x-y)+k(m-n)]%l=0;(k表示跳的次数

2.将(x-y)记为A,
(m-n)记为B,
即(A+kB)%l=0,
(A+kB)对l取余等于零可以等价为(A+kB)减去y个l等于零，
即(A+kB)-yl=0，
移项得kB-yl=-A

3.将k换为x，
得到xB-yl=A
(由于将-A变成了A，
在开始赋值时若B=m-n，
A就为y-x，
若B=n-m，
A就为x-y)，

然后判断是否有解：
令d为B与l的最大公约数gcd(B,l);
方程两边同时除以d，
得到了xB/d-yl/d=A/d,
由于d=gcd(B,l),所
以B/d、l/d为整数，
然后x、-y也是整数，
所以方程成立的条件就是A/d也为整数. 

4.这个方程就是扩展欧几里得exgcd(B,l,x,y)
（忽略y前的负号），
这样可以解出x，
此时的x不是最优解，
还要转换，
即((x*(A/d))%(l/d)+(l/d))%(l/d)。
*/

#include<cstdio>
#include<cmath>
using namespace std;
long long x,y,m,n,L;
long long xx,yy;
long long d;
void exgcd(long long a,long long b)//求解 
{
	if(b)
	  {
	  	exgcd(b,a%b);
	  	long long k=xx;
	  	xx=yy , yy=k-a/b*yy;
	  }
	else 
	  xx=1,yy=0,d=a;
	return ;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
	int a=n-m,b=L,c=x-y;
	if(a<0) a=-a,c=-c;//转换 
	exgcd(a,b);
	if(c%d)//判断 
	  {
	  	printf("Impossible");
		return 0;
	  }
	printf("%lld",( ( xx*(c/d) ) % (L/d) + (L/d) ) % (L/d) );
	
}
