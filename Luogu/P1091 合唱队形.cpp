//�㷨��DP/���ֲ���
//��ĿҪ�� 
//T1 < ... < Ti > Ti+1 > ��> TK    (1��i��K)��
//������,����ö���м�����Ti,
//ά��һ��������,ά��һ��������,
//�������ɾȥѧ������. 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=10000000;
int a[110];
int st1[110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	  {
	  	int minn=0,marx=0;
	  	st1[0]=a[i];//ö��Ti��,��Ϊ���ֵ 
	  	for(int j=i-1;j>=1;j--)//ά��������,������ά�������� 
	  	  {
	  	  	if(a[j]>=st1[0]) continue;//�����ֵ��,ֱ������ 
	  	  	if(a[j]<st1[marx])
		  	  st1[++marx]=a[j];//�ȶ�ͷԪ��С,ֱ�Ӽ��� 
	  		else//���ֲ��ҵ�һ������С��,������ǰ�� 
	  	  	  {
	  	  		int l=1,r=marx,mid;
	  	  		while(l<=r)
	  	  	  	  {
	  	  	  		mid=(l+r)/2;
	  	  	  		if(a[j]<st1[mid])
	  	  	  	  	  l=mid+1;
	  	  	  		else
	  	  	  	  	  r=mid-1;
			  	  }
				st1[l]=a[j];
		  	  }
		  }
		minn+=(i-marx-1),marx=0;
		for(int j=i+1;j<=n;j++)//ά�������� 
		  {
		  	if(a[j]>=st1[0]) continue; 
		  	if(a[j]<st1[marx]) 
		  	  st1[++marx]=a[j];//�ȶ�ͷԪ��С,ֱ�Ӽ��� 
	  		else//���ֲ��ҵ�һ������С��,������ǰ�� 
	  	  	  {
	  	  		int l=1,r=marx,mid;
	  	  		while(l<=r)
	  	  	  	  {
	  	  	  		mid=(l+r)/2;
	  	  	  		if(a[j]<st1[mid])
	  	  	  	  	  l=mid+1;
	  	  	  		else
	  	  	  	  	  r=mid-1;
			  	  }
				st1[l]=a[j];
		  	  }
		  }
		minn+=(n-marx-i);
		ans=min(ans,minn);
	  }
	printf("%d",ans);
}
