//�㷨��DP/01����
//����Ϊ01��������,�������,����һά����
//ֻ��Ҫ��һά����ת��Ϊ��ά����,
//�����һ��ѭ������ 
//״̬ת�Ʒ���ʽ:f[j][k]=max(f[j][k],f[j-v[i]][k-w[i]]+c[i]);
#include<cstdio>
#include<algorithm>
using namespace std;
int vm,mm;
int n;
int v[51];//��� 
int w[51];//���� 
int c[51];//��ֵ 
int f[410][410];//ǰ����������� 
int main()
{
	scanf("%d%d%d",&vm,&mm,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&v[i],&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	  for(int j=vm;j>=v[i];j--)
	  	for(int k=mm;k>=w[i];k--)
	  	  f[j][k]=max(f[j][k],f[j-v[i]][k-w[i]]+c[i]);
	printf("%d",f[vm][mm]);
}
