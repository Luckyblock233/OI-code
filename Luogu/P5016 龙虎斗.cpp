//֪ʶ��:ģ��
//�ȼ������ʼ״̬������ֵ,
//�ٷֱ�ö��p2,�ҳ����Ž�
//���������� 
//ע�⿪long long 
#include<cstdio>
using namespace std;
int n;
long long a[100010]; //����� 
long long m,p1,s1,s2;
long long l,h;
long long minn,ans;
long long jun(long long x)//�����ֵ 
{
	if(x<0) return -x;
	return x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);//���� 
	a[p1]+=s1; 
	for(int i=1;i<m;i++)//���� ���� 
	  l+=((m-i)*a[i]);
	for(int i=m+1;i<=n;i++)//���� ���� 
	  h+=((i-m)*a[i]);
	minn=jun(l-h),ans=m; 
	for(int i=1;i<=n;i++)
	  {
	  	if(i<m)
	  	  {
	  	  	long long s=(m-i)*s2;//��������Ĳ�� 
			if(jun((l+s)-h) < minn)//�滻���Ž� 
	  	      {
	  	        minn=jun(l+s-h);
	  	        ans=i;
			  }
		  }
		else
	  	  {
	  	  	long long s=(i-m)*s2;//ͬ�� 
			if(jun((h+s)-l) < minn)
	  	      {
	  	        minn=jun(h+s-l);
	  	        ans=i;
			  }
	 	  }
	  }
	printf("%lld",ans);//������Ž� 
}
