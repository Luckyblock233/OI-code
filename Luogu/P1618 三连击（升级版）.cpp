//�㷨��ģ��/����
//����ѭ��ö���������
//���ж��Ƿ���������������� 
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
int d[10];
void cf(double o)//ռ������ 
{
	int k=o;
    d[k/100]++;
    d[(k/10)%10]++;
    d[k%10]++;
}
int main()
{
	double a1,b1,c1;
	int judge=0;
	scanf("%lf%lf%lf",&a1,&b1,&c1);
	b1=b1/a1;//ת��Ϊ��ֵ 
	c1=c1/a1;
    for(int a=1;a<=9;a++)//ö�� 
      for(int b=1;b<=9;b++)
        for(int c=1;c<=9;c++)
          {
          	int u=1; 
          	int p=100*a+10*b+c;//�������� 
          	memset(d,0,sizeof(d));
          	cf(p);//ռ������ 
          	cf(b1*p); 
          	cf(c1*p);
          	for(int y=1;y<=9;y++)//������ֲ��ظ� 
          	  if(d[y]!=1)
          	    u=0;
          	if(u==1)
          	  {
          	  	judge=1;//������������� 
          	  	int k1=b1*p;
          	  	int k2=c1*p;
				printf("%d %d %d\n",p,k1,k2);
          	  }
			u=0;
          }
        if(judge==0)
          printf("No!!!");
}
