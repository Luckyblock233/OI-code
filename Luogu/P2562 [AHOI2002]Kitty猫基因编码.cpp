//�㷨:����/�ַ���
/*
һ�������ַ��������Ķ���

����һ���ִ�,
���ж����Ƿ�ֻ���� 0 �� 1;
������Ϊ��,
  ����ִ���Ϊ: 'C'+ǰ���ִ�+����ִ�
  ���ݹ�����ı�
������Ϊ��,
  �򽫴��ִ��ı�Ϊ 'A' �� 'B'   
*/ 
#include<iostream>
using namespace std;
string a;
string solve(string b)//�ݹ�ı亯�� 
{
	int lth=b.length() , i=0;//��ó��� 
	while(b[i+1])//�ж��Ƿ�ֻ����һ���ַ� 
	  if(b[i]!=b[i++ +1])//Ϊ��,����substr������ȡ��ǰ��������ִ�,�������ı� 
	  	return 'C'+solve(b.substr(0,lth/2))+solve(b.substr(lth/2)); 
	return b[0]=='0'?"A":"B";//ֻ��һ���ַ� 
}
int main()
{
	cin>>a;
	cout<<solve(a);
}
