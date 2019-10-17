//
/*
By:Luckyblock
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 1e5+10;
//=============================================================
int n,m , pre[MARX],enemy[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int find(int x) {return x==pre[x]?x:pre[x]=find(pre[x]);}
void unico(int fir,int sec)
{
	int r1=find(fir),r2=find(sec);
	if(r1 != r2) pre[r1] = r2;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<=n; i++) 
	{
	  int u=read(), v=read();
	  unico(u,find(enemy[v])); 
	  unico(v,find(enemy[v]));
	  enemy
	}
}
