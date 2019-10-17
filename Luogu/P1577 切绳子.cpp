//算法:二分答案
/*
答案满足单调性, 
是一道实数二分

二分枚举能够到达的最大长度
再进行检验,即检查 能切出的绳子数量 是否能到达k
如果能,则比此长度小的长度都可以,将左边界l=此长度
否则,将右边界r=此长度 
*/ 
#include<cstdio>
#include<cmath>
using namespace std;
const int MARX = 1e6+10;
int n,k;
double lth[MARX];
bool judge(double m)//检验 能切出的绳子数量 是否能到达k
{
	int tot=0;
	for(int i=1;i<=n;i++)
	  tot+=floor(lth[i]/m);
	return tot>=k;
}
signed main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%lf",&lth[i]);
	double l=0,r=1e6*1.0;
	while(r-l>1e-6 && l<=r)//二分枚举能够到达的最大长度 
	  {
	  	double m=(l+r)/2;
	  	if(judge(m)) l=m;
	  	else r=m;
	  }
	int ans=r*100;//控制精度 
	printf("%.2lf",ans/100.0);
} 
