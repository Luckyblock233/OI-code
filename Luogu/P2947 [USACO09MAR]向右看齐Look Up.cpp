//֪ʶ��:����ջ
/*
ά��һ�������ݼ��ĵ���ջ
ջ�е�ţ����û�� �������� ��ţ

����һ���¼����ţ,
whileѭ��,������ջ�����С������ţ
��ʹ ������ţ���������� = ��ţ

Ȼ����ţ����ջ�� 

���������� 
*/ 
#include<cstdio>
#include<stack>
using namespace std;
const int MARX = 1e5+10;
int n,h[MARX],ans[MARX];
stack <int> s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&h[i]);
	  	while(!s.empty())
	  	  {
	  	  	if(h[s.top()]>=h[i]) break;
	  	  	ans[s.top()]=i;//������ţ���������� = ��ţ
	  	  	s.pop();//whileѭ��,������ջ�����С������ţ 
		  }
	  	s.push(i);//��ջ 
	  }
	for(int i=1;i<=n;i++)
	  printf("%d\n",ans[i]);
}
