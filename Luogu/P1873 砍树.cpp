//�㷨:���ִ�
/*
ֱ�����϶��ִ𰸣�
����lȡ0��rȡ�������߶ȣ�
�ؼ���check�ж�
����ֱ��ģ��һ��ѭ����������a[i]-x��
*/ 
#include<cstdio>
#define int long long
using namespace std;
const int MARX = 1e6+10;
int n,m;
int a[MARX];
bool judge(int x)//�ж� 
{
	int tot=0;
	for(int i=1;i<=n;i++)
	  tot+=(a[i]>x?a[i]-x:0);
	return tot>=m;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	int l=1,r=1e9+10;
	while(l<=r)//���� 
	  {
	  	int mid=(l+r)>>1;
	  	if(judge(mid)) l=mid+1;
	  	else r=mid-1;
	  }
	printf("%lld",r);
} 
