//
/*
By:Luckyblock
有下列 状态之间可以进行转移:
 
*/
#include<cstdio>
#include<ctype.h>
#define ll long long
const int MARX = 110;
//=============================================================
int n,m,k, sum[MARX][3];
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
	n = read(),m = read(), k = read();
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; j <= m ; j ++)
	  {
	    int tmp = read();
	    sum[i][j] = sum[i][j-1] + tmp;
	  }
	
	
}
