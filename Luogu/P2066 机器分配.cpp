//�㷨��DP
/*
״̬ת�Ʒ���ʽ��
iΪ��˾��,jΪ������ 
f[i][j]=max(f[i-1][j-k]+map[i][k]) , k��[0,m];
��:ö�ٵ�i����˾��������k,
i����˾j̨������ӯ������:
i-1����˾j-k̨�豸��ӯ�� + i����˾k̨�豸��ӯ�� 

��������Ƚ��鷳,
marxΪi����˾����ӯ��,��ʼΪf[n][m]. 
���ڵ�i����˾�Ļ�����,
��Ҫö��.
���ҵ�һ������k,
ʹf[i-1][k]+map[i][j-k]==marx
���ҵ��˵�i����˾�Ļ�����,
��i-1����˾�Ļ����� 
����i����˾�Ļ�����ѹ��ջ��,
ʹmarx=f[i-1][k],������i-1����˾����ӯ�� 
���ݹ�����һ����˾������ 
*/
#include<cstdio>
using namespace std;
int m,n,marx;
int map[15][20];
int f[15][20];
void pr(int i,int j)//�������,iΪ��˾���,jΪʣ�µ�δ����Ļ��� 
{
	if(i==0) return;//�߽� 
	for(int k=0;k<=j;k++)
	  if(marx==f[i-1][k]+map[i][j-k])//��k 
	    {
	      marx=f[i-1][k];//����i-1����˾����ӯ�� 
	      pr(i-1,k);//�ݹ� 
	      printf("%d %d\n",i,j-k);//��� 
	      break;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&map[i][j]);//����
//==================================================		 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  	for(int k=0;k<=j;k++)
	  	  if(f[i-1][j-k]+map[i][k] > f[i][j])//DP 
	  	  	f[i][j]=f[i-1][j-k]+map[i][k];
	marx=f[n][m];//��¼����marx 
	printf("%d\n",f[n][m]);//��� 
	pr(n,m);
} 
