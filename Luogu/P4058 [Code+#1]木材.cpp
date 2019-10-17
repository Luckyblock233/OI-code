//知识点:二分 答案 
/*
By:Luckyblock
分析题意:
首先观察 答案的性质
当 ans<=i时,满足条件
则 ans>i时也可满足条件
答案满足单调性, 可以使用二分答案 

二分答案枚举 最少用时
之后 枚举每一棵树经过 此用时之后的 高度
如果此高度 >l,则证明这棵树合法,
将合法的树高 求和,并与s比较 
*/
#include<cstdio>
#include<ctype.h>
#define int unsigned long long
const int MARX = 2e5+10;
//=============================================================
int n,s,l,ans , h[MARX],a[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool check(int now)//检查 时间为now时的合法性 
{
	int sum = 0;
	for(int i=1; i<=n; i++)//枚举树高 
	  if(h[i] + now*a[i] >= l)
	    sum += h[i]+now*a[i];//求和 
	return sum >= s;
} 
//=============================================================
signed main()
{
	n=read(), s=read(), l=read();
	for(int i=1; i<=n; i++) h[i] = read();
	for(int i=1; i<=n; i++) a[i] = read();
	
	if(check(0)) {printf("0"); return 0;} 
	for(int l=0,r=2e18; l<=r;) //枚举最少时间 
	{
	  int mid = (l+r)>>1;
	  if(check(mid)) ans=mid,r=mid-1;
	  else l=mid+1;
	}
	printf("%lld",ans);
}
