//算法: 数论,最大公约数,最小公倍数
/*
直接枚举b1的的因数， 
(时间复杂度为O(sqrt(b1)))
 
如果这个数是a1的整数倍并且满足:
	1. gcd(x/a1,a0/a1)==1
	2. gcd(b1/b0,b1/x)==1
则找到了一组合理的答案 
*/
#include<cstdio>
using namespace std;
int n,ans;
int a0,a1,b0,b1;
int gcd(int x,int y)//求最大公约数 
{
	return y==0?x:gcd(y,x%y);
}
signed main()
{
	scanf("%d",&n);
	while(n--)
	  {
	  	scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
	  	ans=0;
		for(int i=1;i*i<=b1;i++)//枚举因子 
		  if(b1%i==0) 
		    {
		      if(i%a1==0 && gcd(i/a1,(a0/a1))==1 && gcd((b1/b0),b1/i)==1) //满足条件 
			    ans++;
			    
			  int y=b1/i;
			  if(i!=y)
			    if(y%a1==0 && gcd(y/a1,(a0/a1))==1 && gcd((b1/b0),b1/y)==1) 
			       ans++;
		    }
		printf("%d\n",ans);
	  }
}
