//�㷨:DP,01����

//01��������
//����Ҫ�󷽰���,
//��ʼ��f[0]=1,�����û���0Ԫ�ķ���Ϊ1. 
//״̬ת�Ʒ���Ϊ:f[j]=f[j]+f[j-a[i]]
//����iΪ��Ʒ���,jΪ���û���Ǯ�� 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
int f[10010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	f[0]=1;//��ʼ�� 
	for(int i=1;i<=n;i++)//DP 
	  if(a[i]<=m)//���� 
	    {
	  	  for(int j=m;j>=a[i];j--)
	  	    f[j]+=f[j-a[i]];
	    } 
	printf("%d",f[m]);
}
