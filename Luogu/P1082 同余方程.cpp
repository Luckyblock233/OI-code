//�㷨������/��չŷ����ö��� 
/*
��ⲻ������a*x+b*y==gcd(a,b);
�ⷨ�Ƶ���
��a=[a/b]*b+a%b;
�֡�ŷ�����֪��gcd(a,b)==gcd(b,a%b);
��([a/b]*b+a%b)*x+b*y=gcd(a,b);
��[a/b]*b*x+(a%b)*x+b*y=gcd(a,b);
��b*([a/b]*x+y)+(a%b)*x=gcd(b,a%b);
����������ѷ��֣�
�a'=b,x'=[a/b]*x+y,b'=a%b,y'=x;
�����ԭʽ�ֱ���ˣ�a'*x'+b'*y'==gcd(a',b');

��Ȼ����Ȼ��С�������Ǹ�����
��b/gcd(a,b)��ģ��b/gcd(a,b)����
*/
#include<cstdio>
#include<algorithm>
int a,b,x,y;
void exgcd(int a,int b)
{
	if(b)
	{
	  exgcd(b,a%b);
	  int k=x;
	  x=y,y=k-a/b*y;
	}
	else x=1,y=0;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	exgcd(a,b);
	printf("%d",(x+b)%b);
}
