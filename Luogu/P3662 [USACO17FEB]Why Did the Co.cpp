//�㷨:ǰ׺��/ö�� 
/*
����ĳ����Ѿ�ȷ��Ϊk 
����ͨ��ö���������˵�
��ȷ��һ������

ö��ÿһ������Ϊk�����䣬
�ж���һ��������
�𻵵ĵƵ���Ŀ����
�����С�������� 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX = 1e5+10;
int n,b,k,tmp,ans=MARX;
bool a[MARX];
int f[MARX];//ǰ׺�� 
int main()
{
	scanf("%d%d%d",&n,&k,&b);
	for(int i=1;i<=b;i++)//��¼���� 
	  {
	    scanf("%d",&tmp);
		a[tmp]=1;
	  }
	for(int i=1;i<=n;i++)//��ǰ׺�� 
	  f[i]=a[i]?f[i-1]+1:f[i-1];
	for(int i=1;i<=n-k;i++)//ö��ÿ������ 
	  ans=min(ans,f[i+k]-f[i]);
	printf("%d",ans);
}
