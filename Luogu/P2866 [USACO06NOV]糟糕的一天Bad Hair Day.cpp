//算法:单调栈 
/*
单调栈中,按照降序排列身高 

对于一头牛,
当他加入栈时,
会挡住前面比她身高低的牛
所以将 栈顶部身高小于它的牛删除
再将此牛加入栈

同时答案+=原栈中元素数
表示比这头牛身高高的牛能看到的数量+1; 
*/ 
#include<cstdio>
#include<stack>
#define int long long
using namespace std;
int n,ans,num,h;
stack<int> s;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)//单调栈 
	  {
	  	scanf("%lld",&h);
		while(!s.empty())//删除 栈顶部身高小于它的牛
		  {
		    if(h<s.top()) break; 
			s.pop(),num--;
		  }
		ans+=num,s.push(h),num++;//答案增加,加入栈 
	  }
	printf("%lld",ans);
}
