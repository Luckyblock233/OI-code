//算法:数论 
/*
题目用到一个性质: 
	  一个数字除以9的余数等于它的各位数字之和除以9的余数

所以只需要求得每一位数字的和即可 
由于题目给出了一个等差序列
所以可以用等差序列公式来求得数字之和,再讲和模9,即可得到答案 
公式为:
		 （l+r）*（r-l+1）/2//等差数列求和公式，l+r为首项加尾项，r-l+1为项数

但是题目数据范围太大,会爆long long
所以要再考虑缩小数据
观察求和公式,(l+r)与(r-l+1)中一个为奇,一个为偶
则可以先将除2移到算式前部. 
*/
#include<cstdio>
using namespace std;
long long q,l,r;
int main()
{
	scanf("%lld",&q);
	while(q--)
	  {
	  	scanf("%lld%lld",&l,&r);
	  	long long x=(l+r),y=(r-l+1);//计算各项 
	  	if(!(x%2))//先除掉二 
		  x=(x/2)%9;
		else 
		  y=(y/2)%9;  
		printf("%d\n",(x*y)%9);//输出答案 
	  }
}
/*
60分暴力模拟： 

#include<cstdio>
using namespace std;
long long q,l,r;
int main()
{
    scanf("%lld",&q);
    while(q--)
      {
      	int ans=0;
      	scanf("%lld%lld",&l,&r);
      	for(long long i=l;i<=r;i++)
      	  {
      	  	int now=i;
      	  	while(now)
      	  	  {
      	  	  	ans=(ans+now%10)%9;
      	  	  	now/=10;
              }
          }
        printf("%d\n",ans);
      }
}
*/
