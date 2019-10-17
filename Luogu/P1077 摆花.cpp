//知识点:DP 
/*
线性动规 

用f[i][j]表示前i个数总和为j的方案数
初始化 f[0][0]=1;
状态转移方程:
f[i][j] = ∑(f[i-1][j-k]) , k∈[0,a[i]]; 

复杂度 O(n^3)级别 
稳过

注意枚举j,k时,从0开始 
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
	
	f[0][0]=1;//初始化 
	for(int i=1;i<=n;i++)
	  for(int j=0;j<=m;j++)
	    for(int k=0;k<=a[i];k++) 
	      f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
	
	printf("%lld",f[n][m]);
}
