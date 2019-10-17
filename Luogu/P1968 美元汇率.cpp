//算法：DP
//在某一天中,
//可以将所有马克转化为美元, 可以将所有美元转化为马克,
//或者这两种操作都不做

//则某一天的 马克/美元 数量,至于上一天的 美元/马克 数量有关
//则可以进行DP

//状态转移方程: fma[i]=max(fma[i-1],fdo[i-1]*100/a);
//	  			fdo[i]=max(fdo[i-1],fma[i-1]/100*a);
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a;
double fdo[110],fma[110]={100};//do为马克数，ma为美元数 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a);
	  	fma[i]=max(fma[i-1],fdo[i-1]*100/a);//转移 
	  	fdo[i]=max(fdo[i-1],fma[i-1]/100*a);
	  }
	printf("%.2lf",fma[n]);  
}
