//知识点：规律，斐波那契数列 
/*
通过打表，可得：
设f[i] 为第i项斐波那契数列 

第i站上车人数为f[i-2]n+f[i-1]b (i>=2)
下车人数为f[i-3]n+f[i-2]b (i>=3)
车上人数为f[i-2]n+n+f[i-1]b-b（i>=2)

最后一站下车人数=倒数第二站车上人数
带入可解得b

再带入公式解得第x站车上人数 
特判 x=1的情况 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int f[25]={0,1};
int n,a,m,x,b;
signed main()
{
	a=read(),n=read(),m=read(),x=read();
	
	for(int i=2;i<n;i++)
	  f[i]=f[i-1]+f[i-2];
	
	b=(m-f[n-3]*a-a)/(f[n-2]-1);
	
	if(x==1) printf("%lld",a);
	else printf("%lld",(f[x-2]+1)*a+(f[x-1]-1)*b);
}
