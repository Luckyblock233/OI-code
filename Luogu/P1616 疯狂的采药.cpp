//�㷨��DP/��ȫ����
//����Ϊ��ȫ����ģ��
//ע���ڲ�ѭ�� ��w[i]��m 
//����ʽ: f[j]=max(f[j],f[j-w[i]]+c[i])
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int w[10010],c[10010];//��ռ������,��ֵ 
int f[100010]; 
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=w[i];j<=m;j++)
	  	  f[j]=max(f[j],f[j-w[i]]+c[i]);
	  }
	printf("%d",f[m]);
}
