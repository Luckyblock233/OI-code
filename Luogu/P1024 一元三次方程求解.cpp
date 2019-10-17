/*
算法：分治
原理：二分法求函数零点
先分别枚举-100~100之间的区间，区间长为一
然后按照二分法求函数零点，
若找到一个区间，两端的函数值不同号，
就找到了一个零点所在区间
之后通过二分法，求得要求精确度的零点即可 
*/
#include<cstdio>
using namespace std;
double a,b,c,d;
double f(double x)
{
	return x*x*x*a+x*x*b+x*c+d;
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(int x=-100;x<=100;x++)//枚举-100~100之间的区间 
	  {
	  	double x1=x,x2=x+1;
	  	if(f(x1)==0)
	  	printf("%.2lf ",x1); //在整数点 
		if(f(x1)*f(x2) >= 0) continue; 
		while(x2-x1>=0.001)//按照二分法求函数零点 
	  	  {
	  	  	double mid=(x1+x2)/2;
	  	  	if(f(x1)*f(mid)<0)
	  	  	  x2=mid;
	  	  	else
	  	  	  x1=mid;
		  }
		printf("%.2lf ",x1);//直接输出 
	  }
	return 0;
}
