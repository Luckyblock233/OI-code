//�㷨:���� 
/*
��Ŀ�õ�һ������: 
	  һ�����ֳ���9�������������ĸ�λ����֮�ͳ���9������

����ֻ��Ҫ���ÿһλ���ֵĺͼ��� 
������Ŀ������һ���Ȳ�����
���Կ����õȲ����й�ʽ���������֮��,�ٽ���ģ9,���ɵõ��� 
��ʽΪ:
		 ��l+r��*��r-l+1��/2//�Ȳ�������͹�ʽ��l+rΪ�����β�r-l+1Ϊ����

������Ŀ���ݷ�Χ̫��,�ᱬlong long
����Ҫ�ٿ�����С����
�۲���͹�ʽ,(l+r)��(r-l+1)��һ��Ϊ��,һ��Ϊż
������Ƚ���2�Ƶ���ʽǰ��. 
*/
#include<cstdio>
using namespace std;
long long q,l,r;
int main()
{
	scanf("%lld",&q);
	while(q--)
	  {
	  	scanf("%lld%lld",&l,&r);
	  	long long x=(l+r),y=(r-l+1);//������� 
	  	if(!(x%2))//�ȳ����� 
		  x=(x/2)%9;
		else 
		  y=(y/2)%9;  
		printf("%d\n",(x*y)%9);//����� 
	  }
}
/*
60�ֱ���ģ�⣺ 

#include<cstdio>
using namespace std;
long long q,l,r;
int main()
{
    scanf("%lld",&q);
    while(q--)
      {
      	int ans=0;
      	scanf("%lld%lld",&l,&r);
      	for(long long i=l;i<=r;i++)
      	  {
      	  	int now=i;
      	  	while(now)
      	  	  {
      	  	  	ans=(ans+now%10)%9;
      	  	  	now/=10;
              }
          }
        printf("%d\n",ans);
      }
}
*/
