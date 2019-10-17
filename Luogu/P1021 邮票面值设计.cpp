//
/*
By:Luckyblock
*/
#include<cstdio>
#include<ctype.h>
//=============================================================
int n,k;
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
	n=read(),k=read();
}
