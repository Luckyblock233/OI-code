//
/*
By:Luckyblock
Ç°×ººÍ *2 
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 2e5+10;
//=============================================================
int n,k,p;
int sumk[MARX][110],sump[MARX]; 
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
	n=read(),k=read(),p=read();
	for(int i=1; i<=n; i++)
	{
	  int col=read(),pay=read();
	  for(int j=0;j<k;j++) sumk[i][j]=sumk[i-1][j];
	  sumk[i][col]++ , sump[i]+=pay;
	  
	  
	} 
}
