//�㷨:DP 
//������ͷ��,����������ͬʱ��һ������. 
//��Ϊn<=50,���ӶȽϵ�,
//����ʹ��4άDP,
//��: f[i][j][k][l] , 
//���У�i,j��Ϊ��һ���˵�����,(k,l)Ϊ�Ķ����˵�����
// f[i][j][k][l] ���������߹���·����Ȩֵ�ܺ�

//����ĳ��f[i][j][k][l],��Ӧ��ĳһ��(i,j)��(k,l):
//1.������ߵĵ�ת�ƹ���
//2.(i,j)�����ת�ƹ���,(k,l)���ϱ�ת�ƹ���
//3.(k,l)�����ת�ƹ���,(i,j)���ϱ�ת�ƹ���
//4.�����ϱߵĵ�ת�ƹ���

//��,���Դ��������������ȡ���ֵ,�ټ��� (i,j)��(k,l)��Ȩֵ��

//�ر��,��(i,j)==(k,l)ʱ,Ȩֵֻ��Ҫ��һ��,��Ϊ�����ظ�ȡ��. 
#include<cstdio>
using namespace std;
int max(int a,int b,int c,int d)
{
	int max1=a>b?a:b , max2=c>d?c:d;
	return max1>max2?max1:max2;
}
int m,n;
int map[51][51];
int f[51][51][51][51];//4άdp 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&map[i][j]);
	for(int i=1;i<=n;i++)//״̬ת�� 
	  for(int j=1;j<=m;j++)
	    for(int k=1;k<=n;k++)
		  for(int l=1;l<=m;l++)
		    {
		      f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+map[i][j]+map[k][l];
			  if(i==k && j==l) f[i][j][k][l]-=map[i][j];//��(i,j)==(k,l)ʱ�� �ر���� 
			}
	printf("%d",f[n][m][n][m]);
}
