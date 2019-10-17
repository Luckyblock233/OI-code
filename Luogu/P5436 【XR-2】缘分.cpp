//知识点: sb数论 
/*
By:Luckyblock
题目要求: 
求 不大于n的两个正整数
其最大的最小公倍数

sb题
可以发现,n与n-1一定互质,
其最小公倍数 即其 乘积,且最大
注意特判 n=1时 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//=============================================================
int T,n;
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
	T=read();
	for(int i=1; i<=T; i++)
	{
	  n=read();
	  printf("%lld\n",n*(n-1)==0?1:n*(n-1));
	}
}
