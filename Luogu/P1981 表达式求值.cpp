#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
char a,b;//aΪ��ǰ�ַ�,bΪǰһ���ַ� 
stack<int> s;
int x=0,flag=0,cc=0;
int main()
{
	do
	  {
	  	a=getchar();
	  	if(a>='0' && a<='9')//Ϊ���� 
	  	  x=x*10+a-'0';
		else
		  if(b>='0' && b<='9')//�����������,ѹ��ջ 
		    {
		      s.push(x%100000);
		      x=0,flag=1;//flag����,��ʾ���Խ������� 
			}
		if(cc==1 && flag==1)//��һ�������˳˺� 
		  {
		  	long long k=s.top();//����ջ���������ĳ˻�,��ѹ��ջ 
		  	s.pop();
			k=k*s.top();
		  	s.pop();
		  	s.push(k%100000);
		  	cc=0,flag=0;//flag���� 
		  }
		if(a=='*') cc=1,flag=0;//��һ�������˳˺� 
		b=a;//����b 
	  }
	while(a !='\n');
	int s1=0;
	while(!s.empty())//��ջ��Ԫ���ۼ� 
	  {
	  	s1+=s.top(),s1=s1%10000;
	  	s.pop();
	  }
	printf("%d",s1);
}
