//�㷨:���ִ�
/*
�����㵥����,�����ʹ�ö��ִ𰸷�
���ִ�ö����С�ٶ�
��ö�ٵ�������ģ���� 

����Ծ���Ҫ��ϸ�,����long double 
*/ 
#include<cstdio>
#define double long double
using namespace std;
const int MARX = 2e6+10;
int n;
double x[MARX],y[MARX],s[MARX];
bool judge(double k)
{
	double t=0;
	for(int i=1;i<=n;i++)
	  {
	  	t+=s[i]/k;
	  	if(t>=y[i])return 0;// ������ǩ��ʱ���Ҷ˵㣨�������ˣ���˵���Դ��ٶȲ����У�ֱ�ӷ���false 
	  	t=t<x[i]?x[i]:t;//���С��ǩ��ʱ����˵㣨�������ˣ�����ȴ���ǩ��ʱ�� 
	  }
	return 1;
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%LF%LF%LF",&x[i],&y[i],&s[i]);
	double le=1,ri=1e9,mid;
	while(ri-le>=1e-6)//���ִ� 
	  {
	  	mid=(le+ri)/2;
	  	if(judge(mid)) ri=mid;
	  	else le=mid;
	  }
	printf("%.2LF",mid);
}
