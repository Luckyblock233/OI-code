//�㷨�����ƣ�����
//����λ����,����nת��Ϊ������01�ַ���
//Ȼ���ն�����תʮ���Ʒ���,
//���ִ�������ĿҪ��Ľ�������,
//������𰸼��� 
#include<cstdio>
#include<stack>
#include<cmath>
using namespace std;
long long n,lth;
char num[50];
stack <char> s;
long long ans;
int main()
{
	scanf("%lld",&n);
	while(n)//��� 
	  {
	  	char x=(n&1)+'0';
	  	s.push(x);
	  	n>>=1,lth++;
	  }
	for(int i=1;i<=32;i++)//����ǰ��0,�������ִ� 
	  {
	  	if(lth>=33-i &&!s.empty())
	  	  {
	  	  	num[i]=s.top();
	  	  	s.pop();
		  }
		else num[i]='0';
	  }
	for(int i=17;i<=32;i++)//�ȼ����16λ 
	  if(num[i]=='1') ans+=pow(2,48-i);
	for(int i=1;i<=16;i++)//�ټ���ǰ16λ 
	  if(num[i]=='1') ans+=pow(2,16-i);
	printf("%lld",ans);
} 
