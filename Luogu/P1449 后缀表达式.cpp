#include<stack>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a[1010]; 
	cin>>a;
	stack <int> s;
	int i=0;//ָ��,��ָ��ÿһλ 
	while(a[i]!='@')//�߽� 
	  {
	  	switch(a[i])//�ж� 
	  	  {
	  	  	case '+':
	  	  	  {
	  	  	  	int p=s.top(); //��ջ��������Ԫ�����,������ջ�� 
	  	  	  	s.pop();
	  	  	  	p+=s.top();
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '-':  //��ջ��������Ԫ�����,������ջ�� 
			  {
			  	int p=s.top();
	  	  	  	s.pop();
	  	  	  	p=s.top()-p;
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '*'://��ջ��������Ԫ�����,������ջ�� 
			  {
			  	int p=s.top();
	  	  	  	s.pop();
	  	  	  	p=p*s.top();
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '/'://�� 
			  {
			  	int p=s.top();
	  	  	  	s.pop();
	  	  	  	p=s.top()/p;
	  	  	  	s.pop();
	  	  	  	s.push(p);
	  	  	  	break;
			  }
			case '.'://��Ϊ�ָ���,��ֱ��break 
			  {
			  	break;
			  }
			default://��Ϊ����,��������� 
			  {
			  	int x=0;
			  	while(a[i]!='.')
			  	  {
			  	  	x=x*10+(a[i]-'0');
			  	  	i++;
				  }
				s.push(x);//ѹ��ջ 
				break;
			  }
		  }
		i++;
	  }
	printf("%d",s.top());//���ջ�� 
}
