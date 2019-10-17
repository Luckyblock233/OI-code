//算法:DP/背包
//由题意得:

// 选取和不超过S的若干个不同的正整数，
//使得所有数的约数（不含它本身）之和最大。

//则可以将此题看作一个容量为S的01背包
//求出各数的约数和作为权值,跑01背包即可 
#include<cstdio>
#include<algorithm>
using namespace std;
int s,yue[1010],f[1010];
int main()
{
	scanf("%d",&s);
	for(int i=1;i<=s;i++)//求出(不包括它本身的)约数和 
	  for(int j=2;i*j<=s;j++)// 使i的倍数的约数中加上i 
	    yue[i*j]+=i;
	for(int i=1;i<=s;i++)//01背包模板 
	  for(int j=s;j>=i;j--)
	    f[j]=max(f[j],f[j-i]+yue[i]);
	printf("%d",f[s]);
}
