//֪ʶ��:�����ѧ 
/*
����: 
���ж����ֳ���Ϊ n ������ A,
��������������
1.  1 ~ n��n�����������и�������һ��
2.  ���� i ����A[i]��ֵΪi�����i���ȶ��ġ�
	����ǡ���� m �������ȶ���

��������:
1. ���� i�����ڵ� i��λ����ʱ,�� i���ȶ���
   ���� ���� ����˳��Ĺ�ϵ
   ��Ȼ���뵽�� ����. 
   ���Է���: 
   λ�ô�������� n-m��
   �ʴ��ŵķ�����ΪD[n-m] 

2. ��λ�ô��������
   ���� m ����λ����ȷ
   �� m ���˵����
   ��Ҫ��n����������ѡ�� 
   ������Ϊ��
   C(n,m) 
3. ����,��֪:
   λ�ô���ķ�����Ϊ D[n-m]
   λ����ȷ�ķ�����Ϊ C(n,m)
   ��:�ܷ�����Ϊ 
   D[n-m] * C(n,m) 
   
�㷨ʵ��:
���˹�ʽ,��ʲô���ð���
1.����Ԥ���� ���ŷ�����D[] �� �׳�fac[]
2.ʹ��Lucas���� , ���C(n,m) 
3.ʹ�ÿ��ٳ�ȥ��,��� D[n-m] * C(n,m) 
*/ 

//˼·д��֮�� 
//����ע�����ûʲô��д�İ�= = 
#include<cstdio>
#include<ctype.h>
#define int long long
//==========================================
const int MARX = 1e6+10;
const int mod = 1e9+7;
int T,n,m;
int fac[MARX]={1,1,2};//�׳� 
int D[MARX]={1,0,1};//���� 
//==========================================
inline int read()//��� 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline int mul(int x,int y)//������ 
{
	int ans=1;
	x%=mod;
	while(y)
	{
	  	if(y&1) ans=ans*x%mod;
	  	x=x*x%mod;
	  	y>>=1;
	}
	return ans;
}
int c(int n,int m)//��C(n,m) 
{
	return m>n?0 : (fac[n] * mul(fac[m],mod-2))%mod * mul(fac[n-m],mod-2)%mod;
}
int lucas(int n,int m)//�ݹ����Lucas(n,m) 
{
	return !m?1 : c(n%mod,m%mod) * lucas(n/mod,m/mod)%mod;
}
//==========================================
signed main()
{
	for(int i=3;i<MARX;i++)//Ԥ���� ���ŷ����� �� �׳� 
	{
	    D[i]=((i-1)%mod*(D[i-1]%mod + D[i-2]%mod)%mod)%mod;
	    fac[i]=(fac[i-1]*i%mod)%mod;	
	}
	
	T = read();
	while(T--)
	{
	  	n=read(),m=read();
	  	printf("%lld\n",(lucas(n,m)%mod*D[n-m]%mod)%mod);
	}
}
