#include<cstdio>
using namespace std;
int b[15000001];//储存各情况的数量 
int zz(int a)
{
	if(b[a]!=0)
	  return b[a];//返回数组内值 
	int s1=1;//赋初值,即它本身 
	s1+=a/2;
	for(int i=1;i<=a/2;i++)
	  s1+=zz(i)-1;//数量累加 ,累加时减去 它本身 
	b[a]=s1;//给数组赋值 
	return s1; 
}
int main()
{
	int a;
	scanf("%d",&a);
	int s=zz(a);  //输入输出 
	printf("%lld",s);
}
