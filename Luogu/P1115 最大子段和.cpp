//�㷨��DP 
//���ڵ�i����Ҫô�ӵ�ǰһ��������,
//Ҫô�Լ���Ϊ���,�ٿ�һ�������� 
//��: 
//f[i]��ʾ��βΪi�����е����� , 
//ת�Ʒ���ʽ��f[i]=max(f[i-1]+a[i],a[i]);
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=-10010;
int a[200010];
int f[200010];//��βΪi�����е����� 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);//���� 
	for(int i=1;i<=n;i++)
	  {
	  	f[i]=max(f[i-1]+a[i],a[i]);
	  	ans=max(ans,f[i]);//�Ҵ� 
	  }
	printf("%d",ans);
}
