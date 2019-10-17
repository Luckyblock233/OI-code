//知识点:模拟 
/*
By:Luckyblock
题目要求:
进行区间矩阵修改,所有修改完成后,查询单点权值

发现询问是离线的,并且只有一次
所以可以将修改操作也进行离线处理 ,
对于区间矩阵修改,
只需要判断它对查询单点有无影响即可 

如果矩阵覆盖了 单点,
那么将单点的权值,更改为修改后的权值 
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 1e5+10; 
//=============================================================
int x,y,n,p=-1,  a[MARX],b[MARX],g[MARX],k[MARX];
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
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=read(),g[i]=read(),k[i]=read();
	x=read(),y=read();
	for(int i=1;i<=n;i++)//枚举每一个修改操作 
	{
	  int l1=a[i] , l2=b[i] , r1=a[i]+g[i] , r2=b[i]+k[i];//修改区间 
	  if(x<=r1 && x>=l1)//判断是否影响到单点 
	  	if(y<=r2 && y>=l2)
		  p=i;//更新单点权值 
	}
	printf("%d",p);
}
