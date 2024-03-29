//知识点:DP , 奇妙思路 , 暴力枚举(?)   
/*
- 题目要求:  
  求 a 的子序列 b 的最长长度,  
  满足 bi & bi-1 !=0    
  n <=1e5 , ai <= 1e9

- 	暴力思路:  
	类比最长上升子序列  
	
	直接 O(n^2) 暴力枚举  
	当前要添加的数,以及序列b结尾的数 
	  
	设 f[i] 表示以a[i]结尾的,b 数列的最长长度    
	则: 状态转移方程式为:   
	f[i] = max(f[i], f[j]+1) (a[i] & a[j] !=0)   
    
   可以取得 90分的好成绩(大雾)  

-   考虑优化  
	发现新添加的数,  
	只能由:   
   在同一二进制位上 , 同为1的数转移而来
	
	也就是说,  
	可以选择 枚举  
	新添加的数的 二进制上的1位  
	
	考虑枚举二进制位  
	并记录 :   
	此二进制位全为为 1 的数 组成的 子序列 b   
	所能达到的最大长度为多少  
    
   设 f[i] 表示 : 最后一位为 i的 b数列的最长长度,  
	bit[j] 表示 : 二进制第 j 位为1 的数 , 组成的子序列 b的最长长度      
    k为 枚举的: a[i]中 , 二进制上为1的二进制位数   
   
	则可以推出新的状态转移方程式:   
   f[i] =  max(f[i] , bit[k]+1) 
   
   这样 就可以少一层循环  
   来枚举 新添加的数 可接到 哪些数之后.
	
	更新完 f[i]后 , 再用更新后的 f[i] ,  
	反过来 更新 bit[k]  
    
	对于枚举k , 可以使用lowbit() , 并取其 log 函数值来获得   
	在更新 f[i] 的过程中取最大的f[i]作为答案   
	最后优化到了O(31*n) 级别 . (因为最多只有31 个二进制位上的1 )   
*/
//正解: 
#include<cstdio>
#include<algorithm>
#include<map>
#include<ctype.h>
#define lowbit(x) (x)&-(x)
const int MARX = 1e5+10;
//=============================================================
int n,ans,a[MARX]; 
int bit[40] , f[MARX];  //具体意义见上文
std::map <int,int> log_2;
//=============================================================
inline int read()
{
    int fl=1,w=0;char ch=getchar();
    while(!isdigit(ch) && ch!='-') ch=getchar();
    if(ch=='-') fl=-1;
    while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
    return fl*w;
}
//=============================================================
signed main()
{
    for(int i=0,sum=1;i<=31;i++,sum<<=1) log_2[sum]=i; //预处理log函数 
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
      for(int j=a[i],low=lowbit(j);j;j-=low,low=lowbit(j)) //枚举二进制位更新f[i] 
        f[i]=std::max(f[i],bit[log_2[low]]+1);
      for(int j=a[i],low=lowbit(j);j;j-=low,low=lowbit(j)) //使用更新过的f[i]更新bit[k] 
        bit[log_2[low]]=std::max(bit[log_2[low]],f[i]); 
      ans=std::max(f[i],ans); //取得最大答案 
    }
    printf("%d",ans);
}
//暴力90:
/*
#include<cstdio>
#include<ctype.h>
#include<algorithm>
const int MARX	= 1e5+10;;
//=============================================================
int n,ans,a[MARX];
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
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),f[i]=1;//读入并初始化 
	
	for(int i=2;i<=n;i++)
	  for(int j=1;j<i;j++)
	    if(a[i] & a[j])
		  f[i]=std::max(f[i],f[j]+1),//更新f[i]并找到最大值 
		  ans=std::max(ans,f[i]);
	printf("%d",ans);
}
*/ 
