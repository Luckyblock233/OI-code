//�㷨��ģ��
//��A-B=Cת��ΪA-C=B
//��������������ʱ˳���ȥC�����B 
//���ͳ��B��ԭ������ �ĳ��ִ������� 
#include<cstdio>
#include<map>
using namespace std;
int n,c;
long long ans;
long long a[2000010];
map <long long,int> s;//map����ִ��� 
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld",&a[i]);
	  	s[a[i]]++;//��¼���� 
	  	a[i]-=c;//��ȥ,���b 
	  }
	for(int i=1;i<=n;i++)//ͳ�Ƴ��ִ��� 
	  ans+=s[a[i]];
	printf("%lld",ans);
}
