//�㷨:̰��
/* 
Ҫ�� ��һ���ȴ��С������ ���� ����� 
��֤,ÿ�����һ���߳�Ϊ min(x,y) ��������,���ܳ���С 
    ֤��:
	����ø�С�������θ���ԭ����,����һЩ��
	�ʲ��� 
��:ֱ��x,y����һΪ0,������ӱ߳�Ϊmin(x,y)��������
���ڵȴ��������,�ó˷�,�����ж�����,�Ա��ⳬʱ. 
*/ 
#include<cstdio>
#define ll long long//�궨�� 
#define max(a,b) a>b?&a:&b//���ؽϴ�ֵ���ڴ��ַ(��ΪҪֱ�Ӹı�߳� 
#define min(a,b) a>b?b:a 
using namespace std;
ll x,y,ans;
int main()
{
	scanf("%lld%lld",&x,&y);
	while(x && y)
	  {
	  	ll* maxx=max(x,y);//��ýϴ�,��Сֵ 
	  	ll minn=min(x,y);
	  	ans+=(*maxx/minn)*(4*minn);//���Ӵ� 
	  	*maxx%=minn;//�ı�ϴ�ı߳� 
	  }
	printf("%lld",ans);
}
