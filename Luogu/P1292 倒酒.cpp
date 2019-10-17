//֪ʶ��: ��չŷ�����exgcd/���Բ������� 
/*
����ַ:https://www.luogu.org/blog/koishikoishi/solution-p1292 
������, ����:
ans = -ax1 + by1  (x,y �� Z) 

��ʹ�˲��������н�
�� ans =  k*gcd(a,b) (k�� Z)
��Ҫ��ans�� ��С �Ǹ�������
��ans = gcd(a,b)

����չŷ�����
�ⲻ������ gcd = ax1 + by1 
�õ��� һ�� �����x��y�Ľ�

Ȼ��ʹ x*=-1,a*=-1;
ԭ����ת��Ϊ:
ax1 + by1  = (-a)*(-x1) + by1 =  -ax + by (-x1��������x)
�õ�:
x=-x1,y=y1 

Ȼ��ͨ�� 
while(x<0 || y<0)
  x+= (x<0 )?b/gcd:0,
  y-= (x>=0)?a/gcd:0;
  
��x,y��ת��Ϊ��С�ķǸ�������
���ô� 
*/ 
#include<cstdio>
#include<ctype.h>
//====================================================
int a,b,x,y,gcd;
//====================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void exgcd(int a,int b)//��չŷ����������Բ������̵Ľ� 
{
	if(b)
	{
	  	exgcd(b,a%b);
	  	int k=x;
	  	x=y , y=k-a/b*y;
	}
	else 
	  x=1,y=0,gcd=a;
	return ;
}
//====================================================
signed main()
{
	a=read(),b=read();
	exgcd(a,b);
	x*=-1,a*=-1;//����ת�� 
	while(x<0 || y<0)//�����С�ķǸ������� 
	  x+= (x<0 )?b/gcd:0,
	  y-= (x>=0)?a/gcd:0;
	
	printf("%d\n%d %d",gcd,x,y);
}
