//算法:单调栈
/*
使栈中的信号塔按照高度降序排列

对于一个新的信号塔,
当他加入栈中时,会挡住之前比它低的塔的传播
即,会接受到比它低的塔的信号

所以将栈顶所有比它低的塔删除,
(因为他们已经不能再传播给其他塔信号了)
同时,新的塔接收到的能量 加上 删掉的塔传播的能量 

对于原有的高度比它高的信号塔,
离此新的信号塔最近的,会接受到新的塔的信号
故,将此时栈顶的塔,即 离此新的信号塔最近的,高度比它高的塔
接收到的能量,加上新的塔传播的能量 

再将此新的信号塔加入栈中

O(n)复杂度扫一遍后,将所有塔接收到的能量排序一下
输出最大值即可 
*/ 
#include<cstdio>
#include<algorithm>
#include<stack>
#define ll long long
using namespace std;
const int MARX = 1e6+10;
ll n;
ll h[MARX],v[MARX],w[MARX];
stack <int> s;
signed main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	  {
	  	scanf("%lld%lld",&h[i],&v[i]); 
	  	while(!s.empty())// 将栈顶所有比它低的塔删除,
	  	  {
	  	  	if(h[s.top()]>h[i]) break;//遇到比新塔高的 
	  	  	w[i]+=v[s.top()];// 加上 删掉的塔传播的能量 
			s.pop();
		  }
		if(!s.empty()) w[s.top()]+=v[i];//加上新的塔传播的能量  
		s.push(i);//加入栈 
	  }
	sort(w+1,w+n+1);//找到最大值 
	printf("%lld",w[n]);
}
