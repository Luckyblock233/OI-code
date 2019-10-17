//知识点 : 模拟 
/*
By:Luckyblock
题目要求:
求一给定大小矩阵 内点权之和 的最大值

分析题意:
这不是二维树状数组模板题吗???
一看数据范围:
x,y <=128, n<=10
范围极小, 直接暴力模拟即可;

枚举可以选择的位置,再枚举有权值的点
暴力求和迭代即可 
*/
#include<cstdio>
#include<ctype.h>
//=============================================================
struct nodee
{
	int x,y,w;
}node[30];
int d,n,ans1,ans2;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void prepare()
{
	d=read() , n=read();
	for(int i=1; i<=n; i++) 
	  node[i].x = read(),
	  node[i].y = read(),
	  node[i].w = read();
}
int check(int x,int y)//求给定大小矩阵内权值和 
{
	int ret=0,up=x-d,down=x+d,le=y-d,ri=y+d;//获得边界 
	for(int i=1;i<=n;i++)
	  if(node[i].x>=up && node[i].x<=down)
	    if(node[i].y>=le && node[i].y<=ri)
	      ret+=node[i].w;//加和 
	return ret;
}
//=============================================================
signed main()
{
	prepare();
	for(int i=0; i<=128; i++)//暴力枚举可以选择的位置 
	  for(int j=0,tmp; j<=128; j++)
	    if( (tmp=check(i,j))>=ans2 )
	      ans1=(tmp==ans2?ans1+1:1),//迭代 
	      ans2=tmp;
	printf("%d %d",ans1,ans2);
}
