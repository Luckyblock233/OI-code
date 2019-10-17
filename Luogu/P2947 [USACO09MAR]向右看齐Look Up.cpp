//知识点:单调栈
/*
维护一个单调递减的单调栈
栈中的牛都是没有 仰望对象 的牛

对于一个新加入的牛,
while循环,来弹出栈顶身高小于它的牛
并使 被弹出牛的仰望对象 = 新牛

然后将新牛加入栈中 

最后输出即可 
*/ 
#include<cstdio>
#include<stack>
using namespace std;
const int MARX = 1e5+10;
int n,h[MARX],ans[MARX];
stack <int> s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&h[i]);
	  	while(!s.empty())
	  	  {
	  	  	if(h[s.top()]>=h[i]) break;
	  	  	ans[s.top()]=i;//被弹出牛的仰望对象 = 新牛
	  	  	s.pop();//while循环,来弹出栈顶身高小于它的牛 
		  }
	  	s.push(i);//入栈 
	  }
	for(int i=1;i<=n;i++)
	  printf("%d\n",ans[i]);
}
