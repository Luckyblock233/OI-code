//�㷨:DP/���� 
//������01����������:
//��Ʒ��Ϊk�飬ÿ���е���Ʒ�໥��,��ÿ��ֻ��ȡ1����Ʒ
//��01�����϶��һά,��ʾ�м���.
//״̬ת�Ʒ���ʽ:
//f[j][a[i].g]=max(f[j-a[i].w][k]+a[i].c),k��[0,a[i].g];
//ע��k��0��ʼ 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int c,w,g;
}a[1010];
int n,m,ans;
int f[1010][110];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&a[i].w,&a[i].c,&a[i].g);
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=a[i].w;j--)
	    {
		  for(int k=0;k<a[i].g;k++)
	  	    f[j][a[i].g]=max(f[j][a[i].g],f[j-a[i].w][k]+a[i].c);
		  ans=max(ans,f[j][a[i].g]);//��¼�� 
	    }
	printf("%d",ans);
}
