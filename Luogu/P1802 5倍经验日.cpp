//�㷨��DP/01����
//һ��01�����ı���
//����ͨ01������������:
//��ѡĳ��ʱ,Ҳ��õ�һ���ļ�ֵ
//����״̬ת�Ʒ���Ϊ:f[j]=max(f[j]+lose[i],f[j-use[i]]+win[i]);
//ͬʱע��,��j<use[i]ʱ,Ҳ��Ҫ���ϲ�ѡ��i����Ʒ�ļ�ֵ
#include<cstdio>
#include<algorithm>
using namespace std;
int n,x;
int lose[1010],win[1010],use[1010];
long long f[1010];//ע��long long 
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&lose[i],&win[i],&use[i]);//���� 
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=x;j>=0;j--) 
	  	  if(j>=use[i])//�ܹ�ѡ 
			 f[j]=max(f[j]+lose[i],f[j-use[i]]+win[i]); 
	  	  else//���ܹ�ѡ 
		   f[j]=f[j]+lose[i];
	  }
	printf("%lld",5*f[x]);//���ˢ�(��ĿҪ��) 
}
