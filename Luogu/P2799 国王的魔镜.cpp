#include<cstdio>
#include<iostream>
using namespace std;
string a; 
int s;//���� 
void zun(string b)
{
	if(s%2==1)//�ַ�������Ϊ����,�򲻿��ܻ��� 
	  return ;
	int l=0;//���һ��Ძ 
	int r=s-1; 
	int judge=1;//�жϱ��� 
	while(l<r)
	  {
	  	if(a[l]==a[r])  //��ȼ����ж� 
	  	  {
	  	  	l++;
	  	  	r--;
		  }
		else
		  {
		  	judge=0;//����break 
		  	break;
		  }
	  }
	if(judge==1)
	  {
	  	b.erase(l);//������� 
	  	s=b.length();//���¼��㳤�� 
	  	zun(b);
	  }
	else
	  return ;
}
int main()
{
	cin>>a;
	s=a.length();
	zun(a);
	cout<<s;
}
