//�㷨��DP/���� 
/*
��Ȼ˵Ҫ����������������ɸ������
�������������Ҫ�ж��Ƿ�ȡ
ÿ��������������ȡ-->��ȫ����
*/ 
#include<cstdio>
#define max(a,b) a>b?a:b
using namespace std;
const int MARX = 10100;
int n,num;
int p[MARX];
bool vis[MARX]={1,1};//���Ƿ�Ϊ���� 
long long ans[MARX]={1};
void prime(int n)
{
	for(int i=2;i<=n;i++)//ö���� 
	  {
	  	if(!vis[i]) p[++num]=i;//Ϊ���� 
	  	for(int j=1;j<=num;j++)//���� 
	  	  {
	  	  	if(i*p[j]>n) break;
	  	  	vis[i*p[j]]=1;
	  	  	if(i%p[j]==0) break;
		  }
	  }
}
int main()
{
	
	while(scanf("%d",&n)!=EOF)
	  {
	  	for(int i=1;i<=n;i++)
	  	  ans[i]=0;
	    prime(n);
	    for(int i=2;i<=n;i++)//��ȫ���� 
	      if(!vis[i])//������,���ȡ 
	        for(int j=i;j<=n;j++) 
	          ans[j]+=ans[j-i];
	    printf("%lld\n",ans[n]);
	  }
}
