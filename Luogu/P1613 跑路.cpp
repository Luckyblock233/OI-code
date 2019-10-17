//知识点:倍增/最短路floyd 
/*
分析题意:
题目中指出 , 
  两个相距 2^i 的点都可以通过1s , 直接到达 (不一定要走不重复的路)
  也就是说 , 如果把时间看做距离(边权值
  那么相距路程为2 ^i的点, 他们的距离为 1 

由上 , 发现不可以直接跑最短路
要预处理出所有相距路程为 2^i的点
并将它们之间的距离置为1 
考虑DP , 来进行动态更新

算法实现:
设map[u][v] 为 u点到v点的时间 
设 f[u][v][i] ,为 u点到v点 , 路程可否为 2^i , 能否通过1s到达

则可以使用floyd的思想 , 
寻找一个中转点k ,如果有 : f[u][k][i-1] 并且有: f[k][v][i-1] , 
则 u和v之间的路程可为 2^i, 满足可用1s的时间到达
然后将map[u][v]置为1s

由于总路程<=2^63-1. 所以将k循环到64即可 

更新完所有的时间后 , 再跑一遍floyd
获得1 ~ n的距离(时间)即可 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//================================================= 
int n,m , map[60][60];
int f[60][60][70];
//=================================================
inline int read()
{
	int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=================================================
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)//为 map初始化极大值 
	  for(int j=1;j<=n;j++)
	    map[i][j]=2147483647; 
	for(int i=1;i<=m;i++) 
	{
	  int u=read(),v=read();
	  f[u][v][0]=1 , map[u][v]=1;
	}
	
	for(int i=1;i<=64;i++)//floyd思想 , 对距离进行动态更新 
	  for(int k=1;k<=n;k++)
	    for(int u=1;u<=n;u++)
	      for(int v=1;v<=n;v++)
	        if(f[u][k][i-1] && f[k][v][i-1])//如果可以中转 
		  	  f[u][v][i]=1 , map[u][v]=1;//置1 
		  	  
	for(int k=1;k<=n;k++)//floyd获得1~n的距离 
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      if(map[i][j] > map[i][k]+map[k][j])//更新距离 
	        map[i][j] = map[i][k]+map[k][j];
	        
    printf("%lld",map[1][n]);
}
