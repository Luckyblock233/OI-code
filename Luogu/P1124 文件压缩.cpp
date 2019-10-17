//
/*
By:Luckyblock
*/
#include<cstdio>
#include<ctype.h>
#include<string>
#include<iostream>
const int MARX = 1e4+10; 
//=============================================================
int n,p;
std::string s[MARX];
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
	n=read(); std::cin>>s[0]; p=read();
	for(int i=1; i<n; i++)
	{
	  s[i] = s[0].substr(i);
	  s[i] += s[0].substr(0,i-1);
	}
	sort(s,s+n+1)
}
