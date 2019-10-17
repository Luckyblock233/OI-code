//算法：卡特兰数/递推/dp 
//题目要求
//对于一个栈 
// 给定的n个数 
//计算并输出由操作数序列1,2,…,n,
//经过操作可能得到的输出序列的总数。

//很明显,就是卡特兰数
//直接递推即可 
#include<cstdio>
using namespace std;
int n;
int f[20]={1,1};
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)//递推公式 
	  for(int j=0;j<=i-1;j++)
	    f[i]+=(f[j]*f[i-j-1]);
	printf("%d",f[n]);
}
