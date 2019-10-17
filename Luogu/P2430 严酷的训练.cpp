/*
本题为01背包模板题 
注意按照题目要求变化即可 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,s1,s2,t;//s1为wky水平，s2为老王水平,t为规定时间 
int w[3500],v[3500];
int w1[3500];
int f[12900];
int main()
{
	scanf("%d%d",&s1,&s2);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)//输入老王做题所需时间,并计算wky所需时间 
	  {
	  	scanf("%d",&w1[i]);
	  	w1[i]=w1[i]*(s2/s1);//计算 
	  }
	for(int i=1;i<=m;i++)//输入每道题 
	  {
	  	scanf("%d%d",&w[i],&v[i]);
	  	w[i]=w1[w[i]];//计算wky所需时间 
	  }
	scanf("%d",&t);
	for(int i=1;i<=m;i++)//dp 
	  for(int j=t;j>=w[i];j--)
	  	f[j]=max(f[j],f[j-w[i]]+v[i]);
	printf("%d",f[t]);
}

