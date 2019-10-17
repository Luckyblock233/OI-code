//知识点: 进制
/*
一道 奇妙 的题目

题意分析:
1.
    如样例序列:   		 1,3,4,9,10,12,13,…
	即: 		  		 3^0 ,3^1 ,3^0+3^1 ,3^2 ,3^0+3^2 ,3^0+3^1+3^2 ,...
	转成3进制数:  		 1,10,11,100,101,110,...
	ん?(要素察觉)

	把这些3进制数,
	当成2进制转成10进制: 1,2,3,4,5,6...
	好像发现了什么规律...
	
2.把上述操作反过来:
  1.先将n转化为2进制
  2.再将转化后的2进制数当作k进制,
    再转化为10进制
  3.得到了答案= = 

算法实现:
	使用类似快速幂 的思想
	循环 n 的二进制码长度 次
	每次,
	1.记录当前是在第几位num 
	2.如果n的最后一位为 1 (即 n&1==1)
	    则答案+= pow(k,num); (num为当前位数) 
	3.n右移一位 
*/ 
#include<cstdio>
#include<cmath>
#include<ctype.h>
#define int long long
int k,n,num;
int ans;
inline int read()//快读 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
signed main()
{
	k=read(),n=read();
	while(n)// 循环 n 的二进制码长度 次
	{
	  	if(n&1) ans+=pow(k,num);//最后一位为 1  
	  	num++; //增加位数 
		n>>=1;//右移一位 
	}
	printf("%lld",ans);
}
