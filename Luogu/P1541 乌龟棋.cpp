//�㷨��DP

//�����Ͽ���������,ʵ���Ϸǳ�����DP,һ��AC 
//��Ϊ������С��40,
//���Կ��Խ�����ֵ���Ƶ�����
//��Ϊ����Ŀ���Ԫ��
//Ҳ���Էǳ�����ļ������ǰ��ı�� 

//��ǰ������now=i+2*j+3*k+4*l+1;
//ת�Ʒ���ʽ:f[i][j][k][l]=max(f[i][j][k][l],judge(i,j,k,l)+a[now]);
//����judge��ȡ��now����1,2,3,4���ļ�ֵ�����ֵ 
#include<cstdio>
#include<algorithm>
using namespace std;
int f[42][42][42][42];//�ֱ��������1,2,3,4,���Ŀ�������
int n,m;
int a[355];
int b[5];
int judge(int i,int j,int k,int l)
{
    //�ҵ��ܵ�����Ϊi+2*j+3*k+4*l+1�ĵ��ֵ�����ֵ. 
	//�ֱ�ö������1,2,3,4������� 
	int maxx=-1;
	if(i>0) maxx=max(maxx,f[i-1][j][k][l]); 
	if(j>0) maxx=max(maxx,f[i][j-1][k][l]);
	if(k>0) maxx=max(maxx,f[i][j][k-1][l]);
	if(l>0) maxx=max(maxx,f[i][j][k][l-1]);
	return maxx;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	  {
	  	int x;
	  	scanf("%d",&x);
	  	b[x]++;//��¼���� 
	  }
//==========================================================
	f[0][0][0][0]=a[1];//��ʼֵ 
	for(int i=0;i<=b[1];i++)//��������= = 
	  for(int j=0;j<=b[2];j++)
	    for(int k=0;k<=b[3];k++)
	      for(int l=0;l<=b[4];l++)
	        {
	          int now=i+2*j+3*k+4*l+1;//��ǰ��ı�� 
	          f[i][j][k][l]=max(f[i][j][k][l],judge(i,j,k,l)+a[now]);
			}
	printf("%d",f[b[1]][b[2]][b[3]][b[4]]);//��� 
}
