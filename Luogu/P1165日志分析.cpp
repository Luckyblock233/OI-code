//知识点:栈/模拟。
/*
按照题意模拟栈的push与pop 
*/ 
//map可以方便的避免爆空间,不过要注意log(n)的复杂度 
#include<cstdio>
#include<queue>
#include<map>
#include<stack>
using namespace std;
map <int,int> a;//存出现次数 
int n;
stack<int> s;
priority_queue <int> ns;
int main()
{
    scanf("%d",&n);//输入指令数 
    for(int i=0;i<n;i++)
      {
        int c,b;//c为命令,b为质量 
      	scanf("%d",&c);
      	if(c==0)//放货物 
      	  {
      	  	scanf("%d",&b);
      	  	a[b]++;//出现次数++ 
      	  	ns.push(b);
      	  	s.push(b);
          }
        if(c==1)//出货物 
          {
          	int k=s.top();//拿出栈顶元素 
			s.pop();//删除栈顶 
          	a[k]--;//出现次数减一 
          	if(k==ns.top())//如果拿出的是质量最大的 
          	  {
          	  	while(!a[ns.top()] && !ns.empty())//找到新的出现过的,质量最大的 
          	  	  ns.pop();//将出现次数为0的扔出优先队列 
              }
          }
        if(c==2)//查询 
          {
		    if(ns.empty())//没有东西 
              printf("0\n");
            else
              printf("%d\n",ns.top());//输出优先队列顶元素 
  		  }
	  }
}
