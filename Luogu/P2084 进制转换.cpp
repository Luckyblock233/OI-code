//��û����ջ������ 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s0[1001];
int main()
{
	int n,m;
	cin>>n>>s0;
	int l=strlen(s0)-1;
	int judge=0;//�����ı������ʽ,��ֹ���ֺ��üӺ� 
	for(int i=0;i<=l;i++)
	  if(s0[i]!='0' && judge==0)//��Ϊ��һ�����Ԫ�� 
	  	{
	  	  printf("%c*%d^%d",s0[i],n,l-i);
	  	  judge=1; 
		}
	  else
		{
		  if(s0[i]!='0')
	  	    printf("+%c*%d^%d",s0[i],n,l-i);//��Ϊ֮������ԭ�� 
		}
}
