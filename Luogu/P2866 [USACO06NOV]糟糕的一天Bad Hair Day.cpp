//�㷨:����ջ 
/*
����ջ��,���ս���������� 

����һͷţ,
��������ջʱ,
�ᵲסǰ�������ߵ͵�ţ
���Խ� ջ�������С������ţɾ��
�ٽ���ţ����ջ

ͬʱ��+=ԭջ��Ԫ����
��ʾ����ͷţ��߸ߵ�ţ�ܿ���������+1; 
*/ 
#include<cstdio>
#include<stack>
#define int long long
using namespace std;
int n,ans,num,h;
stack<int> s;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)//����ջ 
	  {
	  	scanf("%lld",&h);
		while(!s.empty())//ɾ�� ջ�������С������ţ
		  {
		    if(h<s.top()) break; 
			s.pop(),num--;
		  }
		ans+=num,s.push(h),num++;//������,����ջ 
	  }
	printf("%lld",ans);
}
