//�㷨:���ִ�
/*
�����㵥����, 
��һ��ʵ������

����ö���ܹ��������󳤶�
�ٽ��м���,����� ���г����������� �Ƿ��ܵ���k
�����,��ȴ˳���С�ĳ��ȶ�����,����߽�l=�˳���
����,���ұ߽�r=�˳��� 
*/ 
#include<cstdio>
#include<cmath>
using namespace std;
const int MARX = 1e6+10;
int n,k;
double lth[MARX];
bool judge(double m)//���� ���г����������� �Ƿ��ܵ���k
{
	int tot=0;
	for(int i=1;i<=n;i++)
	  tot+=floor(lth[i]/m);
	return tot>=k;
}
signed main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%lf",&lth[i]);
	double l=0,r=1e6*1.0;
	while(r-l>1e-6 && l<=r)//����ö���ܹ��������󳤶� 
	  {
	  	double m=(l+r)/2;
	  	if(judge(m)) l=m;
	  	else r=m;
	  }
	int ans=r*100;//���ƾ��� 
	printf("%.2lf",ans/100.0);
} 
