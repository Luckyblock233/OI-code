//�㷨������
//�Ƚ�����x��y�����������ֽ�
//Ȼ��ȽϷֽ��ÿһ�������ĳ��ִ���:
//���xx[i]<yy[i],ans*=2;
//���xx[i]>yy[i],֤���������ݲ��Ϸ�,û�д� 
#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 1050;
int xx[N],yy[N];
void split(int x,int *s)//��� 
{
	int n=sqrt(x);
	for(int i=2;i<=n;i++)
	  while(x%i==0) 
	    x/=i,s[i]++;
	if(x!=1)s[x]++;
}
int main() 
{
	int x,y;
	long long ans=1;
	scanf("%d%d",&x,&y);
	split(x,xx);
	split(y,yy);
	for(int i=2;i<=1000;i++) 
	  {
		if(xx[i]>yy[i]) ans=0;
		if(xx[i]<yy[i]) ans*=2;
	  }
	printf("%lld",ans);
}
