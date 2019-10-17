//算法：进制，数论
//先用位运算,将数n转化为二进制01字符串
//然后按照二进制转十进制方法,
//将字串按照题目要求的交换方法,
//计算出答案即可 
#include<cstdio>
#include<stack>
#include<cmath>
using namespace std;
long long n,lth;
char num[50];
stack <char> s;
long long ans;
int main()
{
	scanf("%lld",&n);
	while(n)//拆分 
	  {
	  	char x=(n&1)+'0';
	  	s.push(x);
	  	n>>=1,lth++;
	  }
	for(int i=1;i<=32;i++)//补足前导0,并放入字串 
	  {
	  	if(lth>=33-i &&!s.empty())
	  	  {
	  	  	num[i]=s.top();
	  	  	s.pop();
		  }
		else num[i]='0';
	  }
	for(int i=17;i<=32;i++)//先计算后16位 
	  if(num[i]=='1') ans+=pow(2,48-i);
	for(int i=1;i<=16;i++)//再计算前16位 
	  if(num[i]=='1') ans+=pow(2,16-i);
	printf("%lld",ans);
} 
