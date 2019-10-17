//知识点:模拟 
/*
By:Luckyblock
通过给出的胜负关系 ,
先预处理出所有 组合的胜负关系 
然后暴力模拟,

模拟每一轮猜拳时 , a,b的出拳状况
按照预处理出的胜负标准进行加值即可 
*/
#include<cstdio>
#include<ctype.h>
//=============================================================
int n,na,nb,a[220],b[220],win[6][6];
int ansa,ansb;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()//预处理所有的胜负状况 
{
	win[0][2]=win[0][3]=1;
	win[1][0]=win[1][3]=1;
	win[2][1]=win[2][4]=1;
	win[3][2]=win[3][4]=1;
	win[4][0]=win[4][1]=1;
}
//=============================================================
signed main()
{
	prepare(); 
	n=read(),na=read(),nb=read(); 
	for(int i=1; i<=na; i++) a[i]=read(); 
	for(int i=1; i<=nb; i++) b[i]=read();
	int i=1,j=1;
	while(n--)//循环模拟 
	{
	  ansa+= win[a[i]][b[j]];//更新a,b的答案 
	  ansb+= win[b[j++]][a[i++]];
	  if(i==na+1) i=1;//循环 
	  if(j==nb+1) j=1;
	}
	printf("%d %d",ansa,ansb);
}
