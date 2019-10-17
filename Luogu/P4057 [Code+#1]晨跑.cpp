//求三个数的最小公倍数
//详见注释 
#include<cstdio>
using namespace std;
long long gcd(long long x,long long y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}
int main()
{
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	a=a/gcd(a,b)*b;//求a与b的最小公倍数 
	printf("%lld",a/gcd(a,c)*c);//求 a与b的最小公倍数 与c的最小公倍数 ,输出 
}
