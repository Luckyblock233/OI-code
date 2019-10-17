//知识点:模拟
/* 
By:Luckyblock
题目中给出了 填涂的规则
根据规则暴力模拟即可
注意边界的细节. 
详见注释 
*/ 
#include<cstdio>
#include<ctype.h>
//=============================================================
int n,px,py;//存上一位置 ;
int map[3010][3010];//存图 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void solve()
{
	for(int i=2; i<=n*n; i++)
	{
	  if(py==1 && px!=n)//在第一行但不在最后一列 
	  {
	  	map[n][++px]=i , py=n;
		continue;
	  }
	  if(py!=1 && px==n)//在最后一列但不在第一行 
	  {
		map[--py][1]=i , px=1;
		continue;
	  }
	  if(py==1 && px==n)//在第一行最后一列 
	  {
		map[++py][px]=i;
		continue;
	  }
	  if(py!=1 && px!=n)//既不在第一行，也不在最后一列 
	  {
		if(!map[py-1][px+1]) map[--py][++px]=i;
		else map[++py][px]=i;
	  }
	}
}
//=============================================================
signed main()
{
	n=read();
	map[1][n/2+1]=1;//初始的1 
	px=n/2+1,py=1;
	solve();
	for(int i=1; i<=n; putchar('\n'),i++)//输出矩阵 
	  for(int j=1; j<=n; j++)
	  	printf("%d ",map[i][j]);
}
