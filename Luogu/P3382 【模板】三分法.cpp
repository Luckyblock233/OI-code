//֪ʶ��:����,�������� 
/*
ʹ�����ַ���������
���������������ȷ�
�Ƚ������ȷֵ�ĺ���ֵ
��ɾȥ ��/�ұ߽� ~ ��/�����ȷֵ��� 
�����ܳ��ֺ������������ 
*/
#include<cstdio>
#include<cmath>
//==========================================
const double eps = 1e-7;//0�Ľ���ֵ 
int n;
double l,r , a[15];
//==========================================
double f(double x)//���x=xʱ�ĺ���ֵ 
{
	double ans=0.0 , y=1;//y����x^? 
	for(int i=n+1;i>=1;i--)
	  ans+=a[i]*y , //��ֵ 
	  y*=x;//�˷� 
	return ans;
}
//==========================================
signed main()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=1;i<=n+1;i++) 
	  scanf("%lf",&a[i]);
	  
	while(fabs(r-l)>eps)//�������� 
	{
	  double mid1=(2*l+r)/3.0; //�����ȷֵ� 
	  double mid2=(l+2*r)/3.0;
	  if(f(mid1)<f(mid2)) l=mid1;//ɾȥ�����ܳ��ֺ�������Ĳ��� 
	  else r=mid2;
	}
    printf("%.5lf",l);
}
