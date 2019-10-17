//֪ʶ��:�����ѧ/Lucas���� 
/*
Lucas�����ģ��
������� C(n,m)%mod�Ľ��
��������ȡ�������

����: C(n,m)%p= C(n%p,m%p) ��C(n/p,m/p)%p 
��:	  Lucas(n,m)%p=Lucas(n/p,m/p)*C(n%p,m%p)%p 

��: C(n, m)%mod = n! / (m! * (n-m)!)%mod = n! * inv(m!*(n-m)! , mod) % mod

��:����ͨ���ݹ� , �����÷���С��������Ԫ���и��� , �����Lucas(n,m)��ֵ
	�ݹ�߽�������: m==0ʱ,Lucas(n,0)=C(n,0)=1; 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//======================================
const int MARX = 1e5+10;
int fac[MARX]={1};//��׳� 
//======================================
inline int read()
{
	//isdigit����,�ж��ַ��Ƿ�Ϊ�����ַ�,������<ctype.h>���� 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int mul(int x,int y,int mod)//������ 
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
int c(int n,int m,int mod)//��C(n,m) 
{
	return m>n?0 : (fac[n] * mul(fac[m],mod-2,mod))%mod * mul(fac[n-m],mod-2,mod)%mod;
}
int lucas(int n,int m,int mod)//�ݹ����Lucas(n,m) 
{
	return !m?1 : c(n%mod,m%mod,mod) * lucas(n/mod,m/mod,mod)%mod;
}
//======================================
signed main()
{
	int T;
	T=read();
	while(T--)
	  {
	  	int n=read(),m=read(),mod=read();
	    for(int i=1;i<=mod;i++)//Ԥ���� 1~p �Ľ׳�(%p������,��ൽp) 
	      fac[i]=(fac[i-1]*i)%mod;
	    printf("%lld\n",lucas(n+m,n,mod)); 
	  }
}
