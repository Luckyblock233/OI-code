//�㷨������/��չŷ����� 
/*
1.��ֻ����������
����[(x-y)+k(m-n)]%l=0;(k��ʾ���Ĵ���

2.��(x-y)��ΪA,
(m-n)��ΪB,
��(A+kB)%l=0,
(A+kB)��lȡ���������Եȼ�Ϊ(A+kB)��ȥy��l�����㣬
��(A+kB)-yl=0��
�����kB-yl=-A

3.��k��Ϊx��
�õ�xB-yl=A
(���ڽ�-A�����A��
�ڿ�ʼ��ֵʱ��B=m-n��
A��Ϊy-x��
��B=n-m��
A��Ϊx-y)��

Ȼ���ж��Ƿ��н⣺
��dΪB��l�����Լ��gcd(B,l);
��������ͬʱ����d��
�õ���xB/d-yl/d=A/d,
����d=gcd(B,l),��
��B/d��l/dΪ������
Ȼ��x��-yҲ��������
���Է��̳�������������A/dҲΪ����. 

4.������̾�����չŷ�����exgcd(B,l,x,y)
������yǰ�ĸ��ţ���
�������Խ��x��
��ʱ��x�������Ž⣬
��Ҫת����
��((x*(A/d))%(l/d)+(l/d))%(l/d)��
*/

#include<cstdio>
#include<cmath>
using namespace std;
long long x,y,m,n,L;
long long xx,yy;
long long d;
void exgcd(long long a,long long b)//��� 
{
	if(b)
	  {
	  	exgcd(b,a%b);
	  	long long k=xx;
	  	xx=yy , yy=k-a/b*yy;
	  }
	else 
	  xx=1,yy=0,d=a;
	return ;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
	int a=n-m,b=L,c=x-y;
	if(a<0) a=-a,c=-c;//ת�� 
	exgcd(a,b);
	if(c%d)//�ж� 
	  {
	  	printf("Impossible");
		return 0;
	  }
	printf("%lld",( ( xx*(c/d) ) % (L/d) + (L/d) ) % (L/d) );
	
}
