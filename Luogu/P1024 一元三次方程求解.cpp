/*
�㷨������
ԭ�����ַ��������
�ȷֱ�ö��-100~100֮������䣬���䳤Ϊһ
Ȼ���ն��ַ�������㣬
���ҵ�һ�����䣬���˵ĺ���ֵ��ͬ�ţ�
���ҵ���һ�������������
֮��ͨ�����ַ������Ҫ��ȷ�ȵ���㼴�� 
*/
#include<cstdio>
using namespace std;
double a,b,c,d;
double f(double x)
{
	return x*x*x*a+x*x*b+x*c+d;
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(int x=-100;x<=100;x++)//ö��-100~100֮������� 
	  {
	  	double x1=x,x2=x+1;
	  	if(f(x1)==0)
	  	printf("%.2lf ",x1); //�������� 
		if(f(x1)*f(x2) >= 0) continue; 
		while(x2-x1>=0.001)//���ն��ַ�������� 
	  	  {
	  	  	double mid=(x1+x2)/2;
	  	  	if(f(x1)*f(mid)<0)
	  	  	  x2=mid;
	  	  	else
	  	  	  x1=mid;
		  }
		printf("%.2lf ",x1);//ֱ����� 
	  }
	return 0;
}
