#include<cstdio>
using namespace std;
int b[15000001];//�������������� 
int zz(int a)
{
	if(b[a]!=0)
	  return b[a];//����������ֵ 
	int s1=1;//����ֵ,�������� 
	s1+=a/2;
	for(int i=1;i<=a/2;i++)
	  s1+=zz(i)-1;//�����ۼ� ,�ۼ�ʱ��ȥ ������ 
	b[a]=s1;//�����鸳ֵ 
	return s1; 
}
int main()
{
	int a;
	scanf("%d",&a);
	int s=zz(a);  //������� 
	printf("%lld",s);
}
