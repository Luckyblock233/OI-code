//�㷨������ö��
//���Դ�ʮ��ѭ��
//�˴�ʹ��dfs 
#include<cstdio>
using namespace std;
int sum=0;
int d[9000][11];  //����洢��� 
void z(int k,int a[11],int n)  // k���浱ǰλ�õ���,a���鴢�淽��,n���滹�����ζ�� 
{
	if(n>20 || k>10)   //������ζ�ȴ���20,����ϱ�Ŵ���10,�򲻳��� 
	  return ;
	for(int i=0;i<=2;i++)  //�о���ζ�� 
	  {
	  	if(i > n) break;  //��������,��ֹͣ 
	    if(n==i)
	  	  {
	  	  	int b[11];
	  		for(int j=1;j<=10;j++)
	  	  	  b[j]=a[j];
	  	  	b[k]=b[k]+i;  //������ζ�� 
			sum++;  //������һ,������ 
			for(int j=1;j<=10;j++)
			  d[sum][j]=b[j];
		  }
	  	else
	  	  {
	  	  	int b[11];
	  		for(int j=1;j<=10;j++)
	  	  	  b[j]=a[j];
	  	  	b[k]=b[k]+i;  //������,������ζ��,�������ݹ� 
	  	  	z(k+1,b,n-i);
		  }
	  }
}
int main()
{
	int n;
	scanf("%d",&n);
	n-=10;
	int s[11]={1,1,1,1,1,1,1,1,1,1,1};
	z(1,s,n);
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++)  //��� 
	  {
	  	for(int j=1;j<=10;j++)
	  	  printf("%d ",d[i][j]);
	  	printf("\n");
	  }
}
