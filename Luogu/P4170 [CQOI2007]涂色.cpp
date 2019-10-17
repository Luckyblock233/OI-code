//
/*
By:Luckyblock
设 f[l][r] 表示将 [l,r]区间 添涂 为合法颜色的最少涂色次数
则可以初始化 f[i][i] = 1; 

对于一个区间的 合法填涂,
  1.此区间 由 两个互不相交的区间 拼合而成,
	即: [l,k] + [k,r] = [l,r]
	若 拼合的分界线处 颜色相等, 则可以一同填涂,
	减少 1次添涂次数  
	
  2.此区间 由底色和覆盖色组成:
    先在 [l,r]上填涂底色,再对 [l,r]区间进行覆盖,
	在[l1,r1]区间上 填涂 [l1,r1] 的正确颜色 (l1 >= l && r1 <= r)
	即: [l,r] + [l1,r1] = [l,r] 
*/
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b
const int MARX = 55;  
//=============================================================
int n,f[MARX][MARX];
char s[MARX];
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
	scanf("%s",s + 1); n = strlen(s + 1);
	memset(f, MARX, sizeof(f));
	for(int i = 1; i <= n; i ++) f[i][i] = 1;
	
	for(int i = 2; i <= n; i ++)
	  for(int l = 1,r = l + i - 1; r <= n; l ++, r ++)
	  {
	  	for(int k = l; k < r; k ++) 
		  f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] - (s[k] == s[k + 1]));
		
		if(s[l] == s[r]) 
		{
		  int l1 = l, r1 = r;
		  for(; s[l1] == s[r]; l1 ++);
		  for(; s[r1] == s[l]; r1 --);
		  f[l][r] = min(f[l][r], f[l1][r1] + 1);
		}
	  }
	
	printf("%d",f[1][n]);
}

/*
include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b
const int MARX = 55;  
//=============================================================
int n,f[MARX][MARX] , use[MARX][97];
char s[MARX]="%";
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
	scanf("%s",s+1); n=strlen(s)-1;
	memset(f,MARX,sizeof(f));
	for(int i=1; i<=n; i++)
	{
	  f[i][i]=1;
	  for(int j='A'; j<='Z'; j++) use[i][j]=use[i-1][j];
	  use[i][s[i]]++;
	}
	
	for(int i=2; i<=n; i++)
	  for(int l=1,r=l+i-1; r<=n; l++,r++)
	  {
	  	for(int k=l; k<r; k++) 
		  f[l][r]= min(f[l][r], f[l][k]+f[k+1][r]);
		  
	  	if(use[r][s[l]]-use[l][s[l]]>0) f[l][r]= min(f[l][r], f[l+1][r]);
	  	if(use[r-1][s[r]]-use[l-1][s[r]]>0) f[l][r]= min(f[l][r], f[l][r-1]);
		if(s[l]==s[r]) f[l][r] = min(f[l][r], f[l+1][r-1]+1);
	  }
	
	printf("%d",f[1][n]);
}
*/
