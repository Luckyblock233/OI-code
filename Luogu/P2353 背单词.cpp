//知识点:KMP/字符串 
/*
暴力标算的神奇的题目

题目要求: 
给定区间内匹配字符穿的数量

分析题目 & 算法实现:
m<=10??
这么低的复杂度
直接跑10遍KMP即可 

在KMP过程中,取前缀和
记录每个字符之前
匹配的字符串的个数

查询时:
枚举m个前缀和
用前缀和作差 
计算区间内每个字符串匹配的个数
再求和即可

在求区间字符串匹配个数时 : 
注意判断给定区间的长度,
是否可以容纳下一个模式串.
如果不可,则匹配个数必为0 .
*/
#include<cstdio>
#include<string>
#include<ctype.h>
#include <iostream>
#define int long long
//=============================================================
const int MARX = 1e6+10;
std::string s1,s2;
int n,m,q,ls1,ls2;
int length[11];
int sum[11][MARX] , next[MARX];
//=============================================================
inline int read()
{
    int fl=1,w=0;char ch=getchar();
    while(!isdigit(ch) && ch!='-') ch=getchar();
    if(ch=='-') fl=-1;
    while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
    return fl*w;
}

void get_next()// 求得前缀数组 
{
    int i=0,j=-1;
    next[0]=-1;
    while(i < ls2)
      if(j==-1 || s2[i]==s2[j])//匹配情况 
      {
        i++,j++;
        next[i]=j;
      }
      else j=next[j];//不匹配 
}
void kmp(int now)//kmp匹配 
{
    int i=0,j=0;
    while(i<ls1)
    {
      if(j==-1 || s1[i]==s2[j]) i++,j++;//匹配 
      else j=next[j];
        
      if(j==ls2) //找到一个完整模式串 
        sum[now][i]++ , j=next[j];//当前字符位置前缀和++ 
    }
}
int qu(int l,int r)//询问操作 
{
    int ans=0;
    for(int i=1;i<=m;i++)
      if (l - 1 <= r - length[i])//是否可以容纳下一个模式串 
      ans += (sum[i][r] - sum[i][l + length[i] - 2]);
    return ans;
}
//=============================================================
signed main()
{
    m=read() , q=read();
  	std :: cin >> s1;
    ls1=s1.length();
    
    for(int i=1;i<=m;i++)//循环读入 
    {
      std :: cin >> s2;
      length[i]=ls2=s2.length();
      get_next();
        kmp(i);
    }
    
    for(int i=1;i<=ls1;i++)//更新前缀和 
      for(int j=1;j<=m;j++)
        sum[j][i]+=sum[j][i-1];
    
  /*
    for(int i=1;i<=m;putchar('\n'),i++)
    for(int j=0;j<=10;j++)
      printf("%d ",sum[i][j]);
  */
    while(q--)//回答询问 
    {
      int l,r;
      l=read(),r=read();
      printf("%lld\n",qu(l,r));
    }
}
