/*�������˼·:
��ans����,����� 
��һ��a[7]����,�ֱ𴢴���ĳһ�з�����һ��������ʱ��.
��b[2010]����,��ÿ����ʬ������
���뽩ʬ���ݺ�,���ճ���ʱ��ʱ�������������,��ģ����ֵ�ʱ���Ⱥ�˳��
�ٷֱ�ö��ÿ����ʬ,�������ֵ�ʱ��,�Ƿ���:    �����ϸ�������ʱ��~�����ϸ�������ʱ��+60֮��
����,����Ҫ�µ�����,ans����
������,����Ҫһ���µ�����,��neng����,ans����++;ͬʱ,a������,��Ӧ��������������ʱ����Ϊt-1(����׽����ĥΪʲô-1)
Ȼ��ö����һ����ʬ 
*/ 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct zombie
{
	int p,t;
}b[2010];//��ÿ����ʬ������ 
int a[7];
int ans=0;
int n;
bool cmp(zombie x,zombie y)
{
	return x.t<y.t;
}
int main()
{
	scanf("%d",&n);
	memset(a,-60,sizeof(a));//�Ƚ�a��Ϊ-60,ʹÿһ��t������a[i]+60,�Ա����жϵĿ�ʼ 
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&b[i].p,&b[i].t);
	sort(b+1,b+n+1,cmp);//��t�������� 
	for(int i=1;i<=n;i++)
	  if(a[b[i].p]<b[i].t && a[b[i].p]+60>=b[i].t) bool no_use_bool_just_take_it_a_joke; //Ϊ��ʹ��else�����if 
	  	else
	  	  {
	  	  	ans++;//���Ӵ� 
	  	  	a[b[i].p]=b[i].t-1;//���µ�tֵ 
		  }   
	printf("%d",ans);
}
