//֪ʶ��:��/ģ��
/*
�����ѹ��ӵĴ�С��ΪԪ��
����һ��С���ѵ���

ÿ��ȡ���Ѷ���������С��Ԫ�� 
�����Ǻϲ���
�ٴη������
ͬʱ�ۼӴ� 
*/ 
#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
int main()
{
	priority_queue < int , vector<int> ,greater<int> > s;//������С�������е����ȶ��� 
	int n,x,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  {
	  	scanf("%d",&x);
	  	s.push(x);//ѹ�����ȶ��� 
	  }
	for(int i=0;i<n-1;i++)
	  {
	  	int x=s.top();//����С��Ԫ�� 
	  	s.pop();//ɾ�� 
	  	int y=s.top();//�ҵڶ�С��Ԫ�� 
	  	s.pop();//ɾ�� 
	  	ans+=x+y;//�ۼ� 
	  	s.push(x+y);//ѹ�� 
	  }
	printf("%d",ans);
}
