//������������С������
//���ע�� 
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
	a=a/gcd(a,b)*b;//��a��b����С������ 
	printf("%lld",a/gcd(a,c)*c);//�� a��b����С������ ��c����С������ ,��� 
}
