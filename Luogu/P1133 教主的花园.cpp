//知识点:DP 
/*
By:Luckyblock
简单(?)DP 
题目要求:
只有三种高度 (10/20/30) 的树可以选择, 
每一个位置 的树 , 都大于/小于相邻的两棵树,
并且: 地图是环形的, 第1个位置与第n个位置 相邻 

分析题意:
假设当前已经种到第i个位置 
如果要满足: 每一个位置 的树 , 都大于/小于相邻的两棵树   
那么 第i个位置的树的高度,
要受到 第i-1和第i-2个位置树的高度的影响.
那么 只需要记录第i-1和第i-2个位置树的高度 , 就可以进行DP.

如何体现: 第i个位置与第n个位置互相影响 ?
考虑:对于每次DP , 枚举第1个位置的高度
在所有 位置种树后 , 再枚举第n个位置和第n-1个位置
判断1,n,n-1三个位置的影响情况,
取合法的状态的答案 .  

算法实现: 
设 f[i][j][k] 为:
选择到第i个位置 , 第i-1个位置的树为j,第i个位置的树为k, 的最大价值  
则有DP转移方程式:
枚举第i-2个位置的 树 为l , 第i个位置种第k种树的价值为w[i][k]. 
f[i][j][k] = max(f[i][j][k] , f[i-1][l][j] + w[i][k]) 
((满足 j>k && j>l) 或 (满足 j<k && j<l))
 
对于第1个位置 和 第2个位置, 
由于没有限制,所以预处理出两位置所有的情况.

最后, 枚举第n个位置和第n-1个位置, 
判断1,n,n-1三个位置的影响情况, 
取合法的状态的答案 .   
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int MARX = 1e5+10;
//=============================================================
int n,ans,w[MARX][3];
int f[MARX][3][3]; //0,1,2 分别代表10,20,30的树 
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
	for(int i=1; i<=n; i++) //读入各位置 种各种树的价值 
	  for(int j=0; j<3; j++)
	    w[i][j]=read();
	
	
	for(int fir=0; fir<3; fir++)//枚举第1个位置 的树 
	{
	  memset(f,-1,sizeof(f));
	  
	  for(int sec=0; sec<3; sec++) //预处理前两个位置的树 
	    if(sec!=fir) f[2][fir][sec]=w[1][fir]+w[2][sec];
	    
	  for(int i=3; i<=n; i++)//给i位置填树 
	  {
	    for(int j=0; j<3; j++)//i-1位置树 为 j 
		  for(int k=0; k<3; k++)//i-2 位置树 为 k
		    if(f[i-1][k][j] > 0)//合法状态,则进行转移 
		    {
		  	  for(int l=0; l<3; l++)//i位置树 为 l 
		  	    if( (k<j && j>l) || (k>j && j<l) )//状态合法,则进行转移 
		  	      f[i][j][l] = max(f[i][j][l] , f[i-1][k][j] + w[i][l]);
		    }
	  }
	  
	  for(int las=0; las<3; las++)//枚举 第n个位置和第n-1个位置, 
	    for(int lass=0; lass<3; lass++)
	      if((lass<las && fir<las) || (lass>las && fir>las))//判断合法性 
	        ans = max(ans,f[n][lass][las]);//取合法状态 的 最大值 
	}
	
	printf("%lld",ans);
}
