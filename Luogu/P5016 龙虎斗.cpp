//知识点:模拟
//先计算出初始状态的势力值,
//再分别枚举p2,找出最优解
//最后输出即可 
//注意开long long 
#include<cstdio>
using namespace std;
int n;
long long a[100010]; //存兵数 
long long m,p1,s1,s2;
long long l,h;
long long minn,ans;
long long jun(long long x)//求绝对值 
{
	if(x<0) return -x;
	return x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);//输入 
	a[p1]+=s1; 
	for(int i=1;i<m;i++)//计算 龙方 
	  l+=((m-i)*a[i]);
	for(int i=m+1;i<=n;i++)//计算 虎方 
	  h+=((i-m)*a[i]);
	minn=jun(l-h),ans=m; 
	for(int i=1;i<=n;i++)
	  {
	  	if(i<m)
	  	  {
	  	  	long long s=(m-i)*s2;//计算加入后的差距 
			if(jun((l+s)-h) < minn)//替换较优解 
	  	      {
	  	        minn=jun(l+s-h);
	  	        ans=i;
			  }
		  }
		else
	  	  {
	  	  	long long s=(i-m)*s2;//同上 
			if(jun((h+s)-l) < minn)
	  	      {
	  	        minn=jun(h+s-l);
	  	        ans=i;
			  }
	 	  }
	  }
	printf("%lld",ans);//输出最优解 
}
