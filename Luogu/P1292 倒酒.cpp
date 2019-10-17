//知识点: 扩展欧几里得exgcd/线性不定方程 
/*
题解地址:https://www.luogu.org/blog/koishikoishi/solution-p1292 
由题意, 则有:
ans = -ax1 + by1  (x,y ∈ Z) 

欲使此不定方程有解
则 ans =  k*gcd(a,b) (k∈ Z)
而要求ans的 最小 非负整数解
故ans = gcd(a,b)

用扩展欧几里得
解不定方程 gcd = ax1 + by1 
得到了 一组 合理的x与y的解

然后使 x*=-1,a*=-1;
原方程转化为:
ax1 + by1  = (-a)*(-x1) + by1 =  -ax + by (-x1即真正的x)
得到:
x=-x1,y=y1 

然后通过 
while(x<0 || y<0)
  x+= (x<0 )?b/gcd:0,
  y-= (x>=0)?a/gcd:0;
  
将x,y都转化为最小的非负整数解
即得答案 
*/ 
#include<cstdio>
#include<ctype.h>
//====================================================
int a,b,x,y,gcd;
//====================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void exgcd(int a,int b)//扩展欧几里得求线性不定方程的解 
{
	if(b)
	{
	  	exgcd(b,a%b);
	  	int k=x;
	  	x=y , y=k-a/b*y;
	}
	else 
	  x=1,y=0,gcd=a;
	return ;
}
//====================================================
signed main()
{
	a=read(),b=read();
	exgcd(a,b);
	x*=-1,a*=-1;//进行转化 
	while(x<0 || y<0)//获得最小的非负整数解 
	  x+= (x<0 )?b/gcd:0,
	  y-= (x>=0)?a/gcd:0;
	
	printf("%d\n%d %d",gcd,x,y);
}
