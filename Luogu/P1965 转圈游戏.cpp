//֪ʶ��:������
/* 
����ѧ��Ŀ, ���Խ���Ŀת��Ϊ: 
�����ʽ (x+10^k*m)%n �Ĵ𰸣�
k<=10^9��������ֱ����˷� �� �������ƣ�
ʹ�ÿ��������༴�� 
*/ 
#include<cstdio>
#include<ctype.h>
//=============================================================
int n,m,k,x;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int mul(int a,int b,int mod)//���������� ģ�� 
{
	int ans=1;
	while(b)
	  {
	  	if(b&1) ans=ans*a%mod;
	  	a=(a*a)%mod;
	  	b>>=1;
	  }
	return ans%mod;
}
//=============================================================
signed main()
{
	n=read(),m=read(),k=read(),x=read();
	int y= ( x%n + m%n*mul(10,k,n)%n ) %n ;//�����ʽ 
	printf("%d",y);
}
