//知识点:组合数学 
/*
不易直接求 能够造成越狱的情况数
考虑 求出 总方案数 -  不能造成越狱的方案数
来间接获得答案

可以发现 :
n个牢房中 , 每个牢房的犯人有 m中选择
所以总方案数为 m^n

为不出现冲突: 
第一个房间的犯人可以信仰 
m种中的任意的一种宗教
第二个房间的犯人 , 
则只能信仰不同与第一种的另外 m-1种
第三个房间的犯人
也只能信仰不同于第二个房间的m-1种  
故 , 不出现冲突的方案数为 :
m * (m-1)^(n-1) 种
代表第一个房间信仰任意宗教 , 
其他n-1个房间信仰 m-1种宗教 

故 ,
答案即: m^n - m*(m-1)^(n-1)
为避免取模后 , 前项小于后项 , 使答案为负数
最后需要使答案 +mod再 %mod , 
以使答案为正 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//=============================================================
const int mod = 100003;
int m,n;
//=============================================================
inline int read()
{
    int fl=1,w=0;char ch=getchar();
    while(!isdigit(ch) && ch!='-') ch=getchar();
    if(ch=='-') fl=-1;
    while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
    return fl*w;
}
int mul(int a,int b,int mod)
{
    if(m==0) return 1;
    int ans=1;
    while(b)
    {
      if(b&1) ans=(ans*a)%mod;
      a=(a*a)%mod;
      b>>=1;
    }
    return ans%mod;
}
//=============================================================
signed main()
{
    m=read(),n=read();
    int ans=mul(m,n,mod) - m*mul(m-1,n-1,mod)%mod;
    printf("%lld",(ans+mod)%mod);
}
