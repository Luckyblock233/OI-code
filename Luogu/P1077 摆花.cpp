//֪ʶ��:DP 
/*
���Զ��� 

��f[i][j]��ʾǰi�����ܺ�Ϊj�ķ�����
��ʼ�� f[0][0]=1;
״̬ת�Ʒ���:
f[i][j] = ��(f[i-1][j-k]) , k��[0,a[i]]; 

���Ӷ� O(n^3)���� 
�ȹ�

ע��ö��j,kʱ,��0��ʼ 
*/
#include<cstdio>
#include<ctype.h>
#define min(a,b) a<b?a:b
#define int long long
const int mod = 1000007;
const int MARX = 210;
//=============================================================
int n,m , a[MARX];
int f[MARX][MARX];
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	
	f[0][0]=1;//��ʼ�� 
	for(int i=1;i<=n;i++)
	  for(int j=0;j<=m;j++)
	    for(int k=0;k<=a[i];k++) 
	      f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
	
	printf("%lld",f[n][m]);
}
