//算法: 数论，扩展欧几里得，乘法逆元 
/*
可将原式:c=a/b (mod p)
转化为:c=a*inv(b) (mod p)
此题就变成了求乘法逆元 

注意输入数范围超大,在10e10001范围内
则要用字符串读入,并注意随时取模. 
*/ 
#include<cstdio>
#include<cstring>
using namespace std;
char sa[10010],sb[10010];
long long a,b;
long long x,y;
long long p=19260817;
void exgcd(long long a,long long b)
{
    if(b)
      {
      	exgcd(b,a%b);
      	int k=x;
      	x=y,y=k-a/b*y;
      }
    else 
      x=1,y=0;
    return ;
}
int main()
{
	scanf("%s %s",sa,sb);
	int la=strlen(sa) , lb=strlen(sb);
	for(int i=0;i<la;i++)//输入处理数据 
	  a=(a*10+sa[i]-'0')%p;
	for(int i=0;i<lb;i++)
	  b=(b*10+sb[i]-'0')%p;
	if(!b)//分母为0 
	  {
	  	printf("Angry!");
	  	return 0;
	  }
	exgcd(b,p);//求逆元 
	x=(x+p)%p;
	long long ans=(a*x)%p;//算答案 
	printf("%lld",ans);
}
