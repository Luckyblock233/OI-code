//
/*
By:Luckyblock
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) (a<b?a:b)
const int MARX = 1e6+10;
//=============================================================
int n,mul[110], f[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n = read();
	memset(f,0x3f,sizeof(f));
	for(int i = 1; i*i*i <= MARX; i ++) mul[i] = i*i*i, f[mul[i]] = 1;
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; i + mul[j] <= n; j ++)
	    f[i + mul[j]] = min(f[i + mul[j]], f[i] + 1);
	printf("%d",f[n]);
}
