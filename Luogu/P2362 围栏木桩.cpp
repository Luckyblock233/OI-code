//�㷨��DP
//������½������еĳ���
//������½������е�����

//���ȷ���ʽ: f[i] = max(f[j] +1,f[i]) (a[i]>a[j]) 

//���������󳤶�ʱһ�����:
//��f[i]<f[j]+1ʱ,˵�����ȿ��Ը��� , ������Ҫ������,��ʱ g[i] = g[j]
//��f[i]==f[j]+1ʱ,˵�� ���и�������㳤���,��ʱ g[i] += g[j]
#include<cstdio>
using namespace std;
int t,n;
int a[21];
int f[21],g[21];
int main()
{
	scanf("%d",&t);
	while(t--)
	  {
	  	scanf("%d",&n);
	  	for(int i=1;i<=n;i++)
	  	  {
	  	  	scanf("%d",&a[i]);
	  	  	f[i]=g[i]=1;
		  }
		int m1=1,m2=1;
	  	for(int i=1;i<=n;i++)//�󳤶������� 
	  	  for(int j=1;j<i;j++)
	  	    if(a[j]<=a[i])
			  {
			  	if(f[j]+1>f[i]) f[i]=f[j]+1,g[i]=g[j]; 
			  	else if(f[j]+1 == f[i]) g[i]+=g[j];
			  }
		for(int i=1;i<=n;i++)//�����Ž� 
		  {
		  	if(f[i]>m1) m1=f[i];
		    if(g[i]>m2) m2=g[i];
		  }
		printf("%d %d\n",m1,m2);
	  }
}  
