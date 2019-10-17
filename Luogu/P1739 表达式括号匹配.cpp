#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
char a;
int main()
{
	stack<char>s;
	while((a=getchar()) !='@') //边界 
	  {
	  	if(s.empty() && a==')')//若栈中没有左括号且出现了一个右括号,则一定不合法 
	  	  {
	  	  	printf("NO");
	  	  	return 0;
		  }
	  	if(a=='(')//压入一个左括号 
	  	  s.push(a);
	  	if(a==')')//一个右括号消去一个左括号 
	  	  s.pop();
	  }
	if(s.empty())//若为空,则合法 
	  printf("YES");
	else
	  printf("NO");
}
