//�㷨��DP/��ά��ֵ���� 
//���õ���������,����һά���� 
//ֻ��Ҫ��һά����ת��Ϊ��ά����,
//�����һ��ѭ������ 
//״̬ת�Ʒ���ʽ:f[j][k]=max(f[j][k],f[j-v[i]][k-w[i]]+c[i]);
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x;
int w[110];//αװ���� 
int c[110];//���� 
int v[110];//�õ����� 
int f[1010][1010];//ǰ αװ���� ������ 
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&v[i],&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=w[i];j--)
	  	for(int k=x;k>=c[i];k--)
	  	  f[j][k]=max(f[j][k],f[j-w[i]][k-c[i]]+v[i]);
	printf("%d",f[m][x]);
}
