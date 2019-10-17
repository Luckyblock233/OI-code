//算法：DP，多重背包
/*
多重背包
未优化版30,优化版100 
详见注释 
*/
#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
const int MARX = 1e5+10;
//=============================================================
int n,m,num;
int v[MARX],w[MARX],s[MARX];//单个价值,质量,总数量 
int v1[MARX],w1[MARX];//拆分后价值,质量 
int f[MARX]; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void brick(int i)//拆分 
{
	for(int j=1;j<=s[i];j*=2)//按二进制拆分 
	{
	  v1[++num]=j*v[i];
	  w1[num]=j*w[i];
	  s[i]-=j;
	}
	if(s[i])//补上余下的 
	{
	  v1[++num]=s[i]*v[i];
	  w1[num]=s[i]*w[i];
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();//输入并拆分 
	for(int i=1;i<=n;i++)
	{
	  v[i]=read(),w[i]=read(),s[i]=read();
	  brick(i);
	}
	for(int i=1;i<=num;i++)//转化成了01背包问题 
	  for(int j=m;j>=w1[i];j--)
	  	f[j]=max(f[j],f[j-w1[i]]+v1[i]);
	printf("%d",f[m]);
}
//30分暴力未优化版多重背包 
/*
#include<cstdio>
#include<algorithm>
#include<cctype>
const int MARX = 1e6+10;
//=============================================================
int n,m,w[MARX],v[MARX],s[MARX];//占用容量,价值,数量 
int f[MARX];
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
	n=read(),m=read();
	for(int i=1;i<=n;i++) v[i]=read(),w[i]=read(),s[i]=read();
	
	for(int i=1;i<=n;i++)
	  for(int k=m;k>=w[i];k--)
		for(int j=1;j<=s[i];j++)
	  	  if(k-j*w[i]>=0)
	  	  	f[k]=std::max(f[k],f[k-j*w[i]]+j*v[i]);
	
	printf("%d",f[m]);
}
*/
