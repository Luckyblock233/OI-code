//算法:二分答案
/*
答案满足单调性,则可以使用二分答案法
二分答案枚举最小速度
对枚举的数进行模拟检查 

此题对精度要求较高,故用long double 
*/ 
#include<cstdio>
#define double long double
using namespace std;
const int MARX = 2e6+10;
int n;
double x[MARX],y[MARX],s[MARX];
bool judge(double k)
{
	double t=0;
	for(int i=1;i<=n;i++)
	  {
	  	t+=s[i]/k;
	  	if(t>=y[i])return 0;// 若超出签收时间右端点（即来晚了），说明以此速度不可行，直接返回false 
	  	t=t<x[i]?x[i]:t;//如果小于签收时间左端点（即来早了），则等待至签收时间 
	  }
	return 1;
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%LF%LF%LF",&x[i],&y[i],&s[i]);
	double le=1,ri=1e9,mid;
	while(ri-le>=1e-6)//二分答案 
	  {
	  	mid=(le+ri)/2;
	  	if(judge(mid)) ri=mid;
	  	else le=mid;
	  }
	printf("%.2LF",mid);
}
