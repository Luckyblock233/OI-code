//�㷨��ǩ�������,̰�� 
/*
˼·:
�������,
֮��,���䰴������Ĵ�С˳���������,����֮���̰��
����һ���������е����ȶ���,�������AK�Ļ�����ti 
֮��ʼö�ٸ���,�����������Զ����
����m1����,����m-·��ʱ��-����ak��ʱ��,�������õĿ���ʱ�� 
����ǰ����Զ����akʱ��С��m1��֤���˻���Ҳ����ak,�ͼ������,ak��������+1 
����ǰ����Զ����akʱ�� ����m1,����С��m1+������Ԫ��,������akʱ�� 
�ͽ�������Ԫ���޳�,���µ�ʱ�����,������������ 
����ҵ����������ֵ,������� 
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
struct point//����� 
{
	long long x,t;
}a[100010];
long long n,m; 
long long maxx=0;//���ֵ 
priority_queue < long long , vector<long long> , less<long long> > qq;//��akʱ�� 
bool cmp(point aa,point bb) 
{
	return aa.x <  bb.x;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	  scanf("%lld%lld",&a[i].x,&a[i].t);
//-------------------------------------------------
	sort(a+1,a+n+1,cmp);//���������������� 
	long long t1=0,ans=0,sum=0;
	for(int i=1;i<=n;i++)//�ֱ�ö����Զ���� 
	  {
	  	long long m1=m;
	  	t1=a[i].x;
	  	m1-=(t1+sum);//�����ʱ�� 
	  	if(a[i].t <= m1)//ֱ�Ӽ��� 
	  	  {
	  	  	qq.push(a[i].t);
	  	  	ans++;
	  	  	sum+=a[i].t;
		  }
		else
		  if(!qq.empty())
		    {
		    	int topp=qq.top();//�滻����Ԫ�� 
	  		 	if(topp > a[i].t && m1+topp>=a[i].t)
	  	  	   	  {
	  	  		 	qq.pop();
	  	  		 	qq.push(a[i].t);
	  	  		 	sum=sum-topp+a[i].t;
		  	   	  }
			}
		maxx=max(ans,maxx);
	  }
	printf("%lld",maxx);//��� 
}
