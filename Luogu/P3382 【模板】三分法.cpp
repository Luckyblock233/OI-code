//知识点:三分,求函数顶点 
/*
使用三分法求函数顶点
讲函数定义域三等分
比较两三等分点的函数值
并删去 左/右边界 ~ 左/右三等分点中 
不可能出现函数顶点的区域 
*/
#include<cstdio>
#include<cmath>
//==========================================
const double eps = 1e-7;//0的近似值 
int n;
double l,r , a[15];
//==========================================
double f(double x)//求得x=x时的函数值 
{
	double ans=0.0 , y=1;//y代表x^? 
	for(int i=n+1;i>=1;i--)
	  ans+=a[i]*y , //加值 
	  y*=x;//乘方 
	return ans;
}
//==========================================
signed main()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=1;i<=n+1;i++) 
	  scanf("%lf",&a[i]);
	  
	while(fabs(r-l)>eps)//进行三分 
	{
	  double mid1=(2*l+r)/3.0; //求三等分点 
	  double mid2=(l+2*r)/3.0;
	  if(f(mid1)<f(mid2)) l=mid1;//删去不可能出现函数顶点的部分 
	  else r=mid2;
	}
    printf("%.5lf",l);
}
