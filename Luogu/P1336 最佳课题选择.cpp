//知识点: DP 
/*
By:Luckyblock
简单dp??
分析题意:
对于本题, 影响总价值的 因素有:
1. 选择的课题
2. 选择的每个课题的 数量
按照上述 要求, 设计状态: 
设 f[i][j] , 为 当前选到第i种课,选了j节课,的最小价值 

先预处理出 i=1时，所有的j对应的价值
三重循环 枚举 
当前选择的课, 总选择课数, 当前课选择的数量
则状态转移方程为: 
(mul[k][b[i]]为 k的b[i]次方) 
f[i][j] = min(f[i][j], f[i-1][j-k] + a[i]*mul[k][b[i]]); 
*/
#include<cstdio>
#include<cstring> 
#include<ctype.h>
#define min(a,b) a<b?a:b
#define int long long
//=============================================================
int n,m, a[25],b[25];
int mul[210][7];//预处理幂 
int f[25][210]; // 当前选到第i种课,选了j节课,的最小价值
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
	for(int j=1; j<=n; j++)//预处理幂 
	{
	  mul[j][0]=1;
	  for(int k=1; k<=6; k++) mul[j][k] = mul[j][k-1]*j;	
	}
	    
	memset(f,63,sizeof(f));
	for(int i=1; i<=m; i++) a[i]=read(),b[i]=read(); 
	for(int i=0; i<=n; i++) f[1][i] = a[1]*mul[i][b[1]];//预处理i=1时的情况 
	
	for(int i=2; i<=m; i++)//枚举课题编号 
	  for(int j=0; j<=n; j++)//枚举当前选择的课数 
		for(int k=0; k<=j; k++)//枚举第i门课选择的数量 
		  f[i][j] = min(f[i][j], f[i-1][j-k] + a[i]*mul[k][b[i]]);//更新,取最小值 
		  
	printf("%lld",f[m][n]);
}
