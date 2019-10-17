//
/*
By:Luckyblock
*/
#include<cstdio> 
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
//=============================================================
int n,k , num[45],mul[45]={1};
char s[45];
int f[45][7];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int getnum(int fir,int sec)
{
	return (num[sec]-num[fir-1])/mul[fir];
}
//=============================================================
signed main()
{
	n=read(),k=read(); scanf("%s",s+1);
	for(int i=1; i<=n; i++) num[i] = num[i-1]*10+s[i]-'0';
	for(int i=1; i<=n; i++) mul[i] = mul[i-1]*10;
	
	for(int i=2; i<=n; i++)
	  for(int j=1; j<=k; j++)
		for(int l=j; l<n; l++)
		  f[i][j] = max(f[i][j], f[l][j-1] * getnum(l+1,i));
	printf("%lld",f[n][k]);
}
