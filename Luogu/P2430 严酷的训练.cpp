/*
����Ϊ01����ģ���� 
ע�ⰴ����ĿҪ��仯���� 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,s1,s2,t;//s1Ϊwkyˮƽ��s2Ϊ����ˮƽ,tΪ�涨ʱ�� 
int w[3500],v[3500];
int w1[3500];
int f[12900];
int main()
{
	scanf("%d%d",&s1,&s2);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)//����������������ʱ��,������wky����ʱ�� 
	  {
	  	scanf("%d",&w1[i]);
	  	w1[i]=w1[i]*(s2/s1);//���� 
	  }
	for(int i=1;i<=m;i++)//����ÿ���� 
	  {
	  	scanf("%d%d",&w[i],&v[i]);
	  	w[i]=w1[w[i]];//����wky����ʱ�� 
	  }
	scanf("%d",&t);
	for(int i=1;i<=m;i++)//dp 
	  for(int j=t;j>=w[i];j--)
	  	f[j]=max(f[j],f[j-w[i]]+v[i]);
	printf("%d",f[t]);
}

