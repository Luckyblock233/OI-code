//�㷨:DP
//������֪, ֻ����С��I������С��I+1
//����ĳһ����,ѡ��ĳһС�������,
//ֻ�� ��С����һ���ڵ�����,����һС����һ���ڵ������й�

//�Ϳ�������д��״̬ת�Ʒ���:
//f[j][i]=min(f[j][i-1],f[be[j]][i-1])+a[j][i];
//�����i������ѡ���j��С�� �����������Ž�

//�����ѭ��m��С��,�ҵ���С�⼴�� 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[2010][2010];
int f[2010][2010];
int be[2010];
int main()
{
	scanf("%d%d",&n,&m);
	be[1]=m;
	for(int i=2;i<=m;i++) be[i]=i-1;//��¼��һС�� 
	
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%d",&a[i][j]); 
	    
	for(int i=1;i<=n;i++)//����DP 
	  for(int j=1;j<=m;j++)
	    f[j][i]=min(f[j][i-1],f[be[j]][i-1])+a[j][i];
	    
	int ans=2147483640;
	for(int i=1;i<=m;i++)//�ҵ����Ž� 
	  ans=min(ans,f[i][n]);
	printf("%d",ans);
}
