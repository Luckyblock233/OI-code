/*
һ���򵥵��⣬�������������
��С��������󣬳�����
ע��ڶ���Ҫ��һ���ڶ���Ҫ�������Դ�����
*/
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[100];
long long ans=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	  ans=ans*(a[i]-i+1)%1000000007;
	printf("%lld",ans);
}
