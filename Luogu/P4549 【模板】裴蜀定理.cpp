//֪ʶ��:���Լ��gcd 
/*
ֱ����n���������Լ������
�������������ƭ�� 
*/
#include<cstdio>
#include<cctype> 
int n,a,b,d;
//==========================================
int gcd(int a,int b)//ŷ����������Լ�� 
{
	return b?gcd(b,a%b):a;
}
//==========================================
signed main()
{
	scanf("%d%d%d",&n,&a,&b);
	a=a<0?-a:a , b=b<0?-b:b;//����ת�� 
	d=gcd(a,b);
	for(int i=3;i<=n;i++)//ѭ���� 
	{
	  scanf("%d",&a);
	  a=a<0?-a:a;//����ת��
	  d=gcd(d,a);
	}
	printf("%d",d);
} 
