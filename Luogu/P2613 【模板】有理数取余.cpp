//�㷨: ���ۣ���չŷ����ã��˷���Ԫ 
/*
�ɽ�ԭʽ:c=a/b (mod p)
ת��Ϊ:c=a*inv(b) (mod p)
����ͱ������˷���Ԫ 

ע����������Χ����,��10e10001��Χ��
��Ҫ���ַ�������,��ע����ʱȡģ. 
*/ 
#include<cstdio>
#include<cstring>
using namespace std;
char sa[10010],sb[10010];
long long a,b;
long long x,y;
long long p=19260817;
void exgcd(long long a,long long b)
{
    if(b)
      {
      	exgcd(b,a%b);
      	int k=x;
      	x=y,y=k-a/b*y;
      }
    else 
      x=1,y=0;
    return ;
}
int main()
{
	scanf("%s %s",sa,sb);
	int la=strlen(sa) , lb=strlen(sb);
	for(int i=0;i<la;i++)//���봦������ 
	  a=(a*10+sa[i]-'0')%p;
	for(int i=0;i<lb;i++)
	  b=(b*10+sb[i]-'0')%p;
	if(!b)//��ĸΪ0 
	  {
	  	printf("Angry!");
	  	return 0;
	  }
	exgcd(b,p);//����Ԫ 
	x=(x+p)%p;
	long long ans=(a*x)%p;//��� 
	printf("%lld",ans);
}
