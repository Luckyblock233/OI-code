#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
char a;
int main()
{
	stack<char>s;
	while((a=getchar()) !='@') //�߽� 
	  {
	  	if(s.empty() && a==')')//��ջ��û���������ҳ�����һ��������,��һ�����Ϸ� 
	  	  {
	  	  	printf("NO");
	  	  	return 0;
		  }
	  	if(a=='(')//ѹ��һ�������� 
	  	  s.push(a);
	  	if(a==')')//һ����������ȥһ�������� 
	  	  s.pop();
	  }
	if(s.empty())//��Ϊ��,��Ϸ� 
	  printf("YES");
	else
	  printf("NO");
}
