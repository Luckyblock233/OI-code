//�㷨:DP/���� 
/* 
��ά����01����
�з���ά �� ����ά
Ҫ�������<=�ֵܷ�һ�� , ����<=��������һ�� 
�÷����滻��ֵ 
*/
#include<cstdio>
#define max(a,b) a>b?a:b
const int MARX = 1e6+10;
//===============================================
int n,ans,sum,a[MARX],f[60][MARX];
//===============================================
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//���� 
	{
	  scanf("%d",&a[i]);
	  sum+=a[i];
	}
	sum>>=1,n>>=1;
	for(int i=1;i<=(n<<1);i++)
	  for(int j=sum;j>=a[i];j--)
	    for(int k=n;k>=1;k--)//��������ֵ 
	      f[k][j]=max(f[k][j],f[k-1][j-a[i]]+a[i]);
	printf("%d",f[n][sum]);//��� 
}
