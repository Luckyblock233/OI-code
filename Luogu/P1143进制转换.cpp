#include<cmath>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
char s0[1000000001];
char a[17]="0123456789ABCDEF";//������� 
long long s1=0;
int main()
{
	int n,m;
	stack <int> s;
	cin>>n>>s0>>m;
	int l=strlen(s0)-1;
	int i=0;
	while(l>=0)//��תʮ���� 
	  {
	  	if(s0[l]>='0' && s0[l]<='9')//��Ϊ������� 
	  	  s1+=(s0[l]-'0')*pow(n,i);
	  	else
	  	  s1+=(s0[l]-'A'+10)*pow(n,i);//Ϊ��ĸ��� 
	  	i++;l--;
	  }
	while(s1!=0)//ת��Ҫ����� 
	  {
	  	int k=s1%m;
	  	s.push(k);//ѹ��ջ 
	  	s1/=m;
	  }
	while(!s.empty())//���ջ��Ԫ�� 
	  {
	  	cout<<a[s.top()];
	  	s.pop();
	  }
}
