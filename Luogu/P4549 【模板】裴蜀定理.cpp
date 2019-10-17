//知识点:最大公约数gcd 
/*
直接求n个数的最大公约数即可
被裴蜀定理的名字骗了 
*/
#include<cstdio>
#include<cctype> 
int n,a,b,d;
//==========================================
int gcd(int a,int b)//欧几里得求最大公约数 
{
	return b?gcd(b,a%b):a;
}
//==========================================
signed main()
{
	scanf("%d%d%d",&n,&a,&b);
	a=a<0?-a:a , b=b<0?-b:b;//正负转换 
	d=gcd(a,b);
	for(int i=3;i<=n;i++)//循环求 
	{
	  scanf("%d",&a);
	  a=a<0?-a:a;//正负转换
	  d=gcd(d,a);
	}
	printf("%d",d);
} 
