//算法:贪心
/* 
要用 不一定等大的小正方形 覆盖 大矩形 
易证,每次添加一个边长为 min(x,y) 的正方形,其周长最小 
    证明:
	如果用更小的正方形覆盖原区域,会多出一些边
	故不可 
则:直至x,y中有一为0,不断添加边长为min(x,y)的正方形
对于等大的正方形,用乘法,来进行多次添加,以避免超时. 
*/ 
#include<cstdio>
#define ll long long//宏定义 
#define max(a,b) a>b?&a:&b//返回较大值的内存地址(因为要直接改变边长 
#define min(a,b) a>b?b:a 
using namespace std;
ll x,y,ans;
int main()
{
	scanf("%lld%lld",&x,&y);
	while(x && y)
	  {
	  	ll* maxx=max(x,y);//获得较大,较小值 
	  	ll minn=min(x,y);
	  	ans+=(*maxx/minn)*(4*minn);//增加答案 
	  	*maxx%=minn;//改变较大的边长 
	  }
	printf("%lld",ans);
}
