#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
char a,b;//a为当前字符,b为前一个字符 
stack<int> s;
int x=0,flag=0,cc=0;
int main()
{
	do
	  {
	  	a=getchar();
	  	if(a>='0' && a<='9')//为数字 
	  	  x=x*10+a-'0';
		else
		  if(b>='0' && b<='9')//数字输入完毕,压入栈 
		    {
		      s.push(x%100000);
		      x=0,flag=1;//flag立起,表示可以进行运算 
			}
		if(cc==1 && flag==1)//上一个输入了乘号 
		  {
		  	long long k=s.top();//计算栈顶两个数的乘积,并压入栈 
		  	s.pop();
			k=k*s.top();
		  	s.pop();
		  	s.push(k%100000);
		  	cc=0,flag=0;//flag倒下 
		  }
		if(a=='*') cc=1,flag=0;//上一个输入了乘号 
		b=a;//更新b 
	  }
	while(a !='\n');
	int s1=0;
	while(!s.empty())//将栈内元素累加 
	  {
	  	s1+=s.top(),s1=s1%10000;
	  	s.pop();
	  }
	printf("%d",s1);
}
