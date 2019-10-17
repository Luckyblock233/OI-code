//知识点:二分答案,贪心
/*
分析题意:
因为答案范围已知，
且答案区间以答案为界，
一半为真，一半为假。
则可以用二分答案法，找可能的答案，

再用贪心来求得满足此答案所需的移走数量。
移走数量小于m，证明此答案可行，
再找区间[mid+1，r]，反之则找[l，mid-1]。

贪心方法:
对于一个序列,
假使前k个石头之间的距离已经合法
但第k个与第k+1个石头之间距离不合法
此时可以去掉第k个石头,也可以去掉第k+1个石头 
为了方便第k+2个石头与之前的石头形成合法序列,
所以去掉第k+1个石头较合适
这样一路贪下来,便得到了需要挪走的石头个数 
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 5e4+10;
//=============================================================
int l,n,m , a[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool judge(int mid)//贪心模拟 
{
	int m1=0 , pa=0;//记录上一个没有被挪走的石头 
	for(int i=1;i<=n+1;i++) 
	  if(a[i]-a[pa]<mid) m1++;//挪去第i个 
	  else pa=i;//i成为上一个未被挪走 
	return m1<=m;//此答案不可行 
}
//=============================================================
signed main()
{
	l=read(),n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	a[n+1]=l;
	
	int l=1,r=1e9+7;
	while(l<=r)//二分答案 
	{
	  int mid = (l+r)>>1;
	  if(judge(mid)) l=mid+1;
	  else  r=mid-1;
	}
	printf("%d",(l+r)>>1);
}
