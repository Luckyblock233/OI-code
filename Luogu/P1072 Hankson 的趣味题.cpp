//�㷨: ����,���Լ��,��С������
/*
ֱ��ö��b1�ĵ������� 
(ʱ�临�Ӷ�ΪO(sqrt(b1)))
 
����������a1����������������:
	1. gcd(x/a1,a0/a1)==1
	2. gcd(b1/b0,b1/x)==1
���ҵ���һ�����Ĵ� 
*/
#include<cstdio>
using namespace std;
int n,ans;
int a0,a1,b0,b1;
int gcd(int x,int y)//�����Լ�� 
{
	return y==0?x:gcd(y,x%y);
}
signed main()
{
	scanf("%d",&n);
	while(n--)
	  {
	  	scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
	  	ans=0;
		for(int i=1;i*i<=b1;i++)//ö������ 
		  if(b1%i==0) 
		    {
		      if(i%a1==0 && gcd(i/a1,(a0/a1))==1 && gcd((b1/b0),b1/i)==1) //�������� 
			    ans++;
			    
			  int y=b1/i;
			  if(i!=y)
			    if(y%a1==0 && gcd(y/a1,(a0/a1))==1 && gcd((b1/b0),b1/y)==1) 
			       ans++;
		    }
		printf("%d\n",ans);
	  }
}
