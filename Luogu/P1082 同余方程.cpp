//算法：数论/拓展欧几里得定理 
/*
求解不定方程a*x+b*y==gcd(a,b);
解法推导：
∵a=[a/b]*b+a%b;
又∵欧几里得知：gcd(a,b)==gcd(b,a%b);
∴([a/b]*b+a%b)*x+b*y=gcd(a,b);
∴[a/b]*b*x+(a%b)*x+b*y=gcd(a,b);
∴b*([a/b]*x+y)+(a%b)*x=gcd(b,a%b);
看到这里，不难发现：
令：a'=b,x'=[a/b]*x+y,b'=a%b,y'=x;
整理后原式又变成了：a'*x'+b'*y'==gcd(a',b');

当然解虽然最小，可能是负数，
加b/gcd(a,b)再模上b/gcd(a,b)即可
*/
#include<cstdio>
#include<algorithm>
int a,b,x,y;
void exgcd(int a,int b)
{
	if(b)
	{
	  exgcd(b,a%b);
	  int k=x;
	  x=y,y=k-a/b*y;
	}
	else x=1,y=0;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	exgcd(a,b);
	printf("%d",(x+b)%b);
}
