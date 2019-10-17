//知识点:DP 
/*
用f[i][j][k]表示 , a字串到第i个字符,b字串到第j个字符,
使用了k个子串,并且a中第i个字符必须选的方案数 

用ans[i][j][k]表示, a字串到第i个字符,b字串到第j个字符,
使用了k个子串,总方案数,
ans数组实际上为f数组的前缀和 
 
三层循环枚举a字串的字符,b字串的字符,使用的字串数量
则有状态转移方程式为:
1. f[i][j][k] = 0;    							(a[i]!=b[j]);
2. f[i][j][k] = f[i][j-1][k] + ans[i][j-1][k-1] (a[i]==a[j]);
更新f后,再更新ans即可. 

由于此题只有128mb的空间限制
直接开f[1000][200][200]会爆炸
观察转移方程式,
可以使用滚动数组滚掉i维 
*/ 
#include<cstdio>
#include<string>
#include<iostream>
#include<ctype.h>
#define int long long
//============================================================
const int mod = 1e9+7;
int lth1,lth2,num;
int f[2][210][210];// 滚动到第i个 , B到达第j位 , 使用了k个子串 
int ans[2][210][210]={1};//总方案数 
std::string a,b;
int now = 1;
//============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//============================================================
signed main()
{
	lth1=read(),lth2=read(),num=read();
	std::cin>>a>>b;
	for(int i=1;i<=lth1;i++)//枚举a字串中的字符 
	{
	  ans[now][0][0]=1;
	  for(int j=1;j<=lth2;j++)//枚举b字串中的字符 
	    for(int k=1;k<=num;k++)
	    {
	      if(a[i-1] == b[j-1]) f[now][j][k]=(f[!now][j-1][k] + ans[!now][j-1][k-1])%mod;//可以匹配 
 	      else f[now][j][k]=0;//不可匹配 
 	      ans[now][j][k]=(ans[!now][j][k] + f[now][j][k])%mod;//更新前缀和 
		}
	  now=!now;
	}
    std::cout<<ans[!now][lth2][num];
}
//10分暴力字符串匹配 
/* 
#include<cstdio>
#include<iostream>
#include<string> 
#include<ctype.h>
//=============================================================
int n,m,k,ans;
std::string a,b;
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
	n=read(),m=read(),k=read();
	std::cin>>a;std::cin>>b;
	for(int pos=a.find(b,0);pos!=-1;pos=a.find(b,pos+1)) 
	  ans++;//循环匹配b串 
	printf("%d",ans);
} 
*/
