//�ṩһ�ַ��������� 
//����Ҫʹ��use����,
//��˳������Ҫ�г�����,
//ÿ��λ���Ͽ�ѡ������Ϊ(�ϸ�λ�õ���~�����)
//��˳��ѭ����ֵ
//�������㹻ʱ,������� 
#include<cstdio>
using namespace std;
int n1,r1;
int a[25];
void z(int n,int r,int b[25])
//nΪ��ǰ����,rΪ��ǰλ��,b�������鷽�� 
{
	if(r==r1)//������������� 
	  {
	  	for(int i=0;i<r1;i++)
	  	  printf("%3d",b[i]);
	  	printf("\n"); 
	  }
	else
	  for(int i=n;i<=n+n1;i++)  //ѭ������ 
	    {
	  	  int c[25];
		  for(int j=0;j<=r1;j++)
	  	    c[j]=b[j];
	  	  c[r]=i;  //��ֵ 
		  if(i <= n1) 
	  	    z(i+1,r+1,c);//���������ٵݹ� 
	    }
}
int main()
{
	scanf("%d%d",&n1,&r1);
	z(1,0,a);
}
