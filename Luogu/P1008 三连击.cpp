//�㷨������/ö��
//ö����������
//���ж��Ƿ�Ϸ����� 
#include<cstdio>
#include<string.h>
using namespace std;
int d[10];
void cf(int o)//ռ������ 
{
    d[o/100]++;
    d[(o/10)%10]++;
    d[o%10]++;
}
int main()
{
    for(int a=1;a<=4;a++)
      for(int b=1;b<=9;b++)
        for(int c=1;c<=9;c++)
          {
          	int u=1;
          	int p=100*a+10*b+c;//�������� 
          	memset(d,0,sizeof(d));
          	cf(p);//ռ������ 
          	cf(2*p);
          	cf(3*p);
          	for(int y=1;y<=9;y++)//���ֲ��ظ�ռ�� 
          	  if(d[y]!=1)
          	    u=0;
          	if(u==1)//�Ϸ����� 
          	  printf("%d %d %d\n",p,2*p,3*p);
          	u=0;
          }
}
