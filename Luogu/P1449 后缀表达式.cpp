#include<stack>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a[1010]; 
	cin>>a;
	stack <int> s;
	int i=0;//指针,来指向每一位 
	while(a[i]!='@')//边界 
	  {
	  	switch(a[i])//判断 
	  	  {
	  	  	case '+':
	  	  	  {
	  	  	  	int p=s.top(); //将栈顶的两个元素相加,并赋给栈顶 
	  	  	  	s.pop();
	  	  	  	p+=s.top();
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '-':  //将栈顶的两个元素相减,并赋给栈顶 
			  {
			  	int p=s.top();
	  	  	  	s.pop();
	  	  	  	p=s.top()-p;
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '*'://将栈顶的两个元素相乘,并赋给栈顶 
			  {
			  	int p=s.top();
	  	  	  	s.pop();
	  	  	  	p=p*s.top();
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '/'://除 
			  {
			  	int p=s.top();
	  	  	  	s.pop();
	  	  	  	p=s.top()/p;
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '.'://若为分隔符,则直接break 
			  {
			  	break;
			  }
			default://若为数字,则拆数计算 
			  {
			  	int x=0;
			  	while(a[i]!='.')
			  	  {
			  	  	x=x*10+(a[i]-'0');
			  	  	i++;
				  }
				s.push(x);//压入栈 
				break;
			  }
		  }
		i++;
	  }
	printf("%d",s.top());//输出栈顶 
}
