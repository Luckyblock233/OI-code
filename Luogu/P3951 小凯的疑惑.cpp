/*
������ a < b a<b
�����Ϊ x x
��
	x = ma (mod b) (1<= m <= b-1)

��
	x = ma + nb (1��m ��b-1)

��Ȼ�� n��0 ʱ x ������ a,b ��ʾ�������������⡣

��˵� n = -1 ʱ x ȡ�����ֵ����ʱ x = ma - b 

��Ȼ�� m ȡ�����ֵ b - 1 ʱ x ��󣬴�ʱ x = (b - 1)a - b = ab-a-b 
��� a, b ����ʾ�������������� ab - a - b
*/ 
#include<cstdio>
using namespace std;
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",a*b-a-b);
}
