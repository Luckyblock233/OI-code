//�㷨:DP/����
//�������:

// ѡȡ�Ͳ�����S�����ɸ���ͬ����������
//ʹ����������Լ��������������֮�����

//����Խ����⿴��һ������ΪS��01����
//���������Լ������ΪȨֵ,��01�������� 
#include<cstdio>
#include<algorithm>
using namespace std;
int s,yue[1010],f[1010];
int main()
{
	scanf("%d",&s);
	for(int i=1;i<=s;i++)//���(�������������)Լ���� 
	  for(int j=2;i*j<=s;j++)// ʹi�ı�����Լ���м���i 
	    yue[i*j]+=i;
	for(int i=1;i<=s;i++)//01����ģ�� 
	  for(int j=s;j>=i;j--)
	    f[j]=max(f[j],f[j-i]+yue[i]);
	printf("%d",f[s]);
}
