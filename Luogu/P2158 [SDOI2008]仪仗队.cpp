//�㷨:����/ŷ������ 
/*
���ŶԽ���
������������п���
�õ�����ֱ�������Ρ�

���֣�ʵ����Ҫ��Ĵ�
��ž�����1��n�ķ�Χ��
��ͬ��gcd��i��j���ĸ�����

����һ���ض���i��
gcd��i��j���ĸ���
����i-1��ŷ������ֵ��

��ô�������
ת����Ϊ��ŷ�������İ����⡣ 
*/
#include<cstdio>
using namespace std;
int n,num;
int phi[100010]={0,1};
int p[100010];
bool vis[100010]={1,1};
void prime(int n)//ŷ��ɸ��ŷ������ֵ 
{
	for(int i=2;i<=n;i++)
	  {
	  	if(!vis[i]) p[++num]=i,phi[i]=i-1;//������ŷ������ֵ 
	  	for(int j=1;j<=num;j++)
	  	  {
	  	  	if(i*p[j]>=n) break;
	  	  	vis[i*p[j]]=1;
	  	  	if(i%p[j]==0) 
			  {
			  	phi[i*p[j]]=phi[i]*p[j];//������ŷ������ֵ 
			    break;	
			  }
			else phi[i*p[j]]=phi[i]*phi[p[j]];//����С���������ŷ������ֵ 
		  }
	  }
}
signed main()
{
	scanf("%d",&n);
	if(n==1) //n==1ʱ������ 
	  {
		printf("0");
		return 0;
	  }
	prime(n);
	int ans=0;
	for(int i=1;i<=n-1;i++)//��� 
	  ans+=phi[i];
	printf("%d",ans*2+1);//��ô� 
}
