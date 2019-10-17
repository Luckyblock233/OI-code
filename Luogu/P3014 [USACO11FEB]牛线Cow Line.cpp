//知识点:康托展开 
/*
康托展开模板题

给出序列,求康托展开
或求逆康托展开 
*/
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#define int long long
#define lowbit(a) a&(-a)
//============================================
int n,sum;
int a[25],b[25],use[25],fac[25] = {1,1};
//============================================
inline int read()//此题卡快读 
{
	int tmp;
	scanf("%lld",&tmp);
	return tmp;
}
void cantor()//求康托展开 
{
	sum=0;
	memset(use,0,sizeof(use));//初始化 
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	  {
	  	b[i]=read();//转换进制数 
	  	int tmp=b[i];
		for(int j=1;j<=b[i];j++)//减去重复数 
	  	  tmp-=use[j];
	  	use[b[i]]=1;
	  	b[i]=tmp-1;
	
	    sum+=fac[n-i]*b[i];//进制转康托展开 
	  }
	printf("%lld\n",sum+1);
}
void re_cantor()//逆康托展开 
{
	memset(a,0,sizeof(a));//初始化 
	memset(use,0,sizeof(use));
	int x=read()-1;
	for(int i=1;i<=n;i++)//转进制表示 
	  {
	  	a[i]=x/fac[n-i];
	  	x%=fac[n-i];
	  }
	
	for(int i=1;i<=n;i++)//转换为全排列 
	  {
	  	for(int j=0;j<=a[i];j++)
	  	  if(use[j]) a[i]++;
	  	printf("%lld ",a[i]+1);//输出 
	  	use[a[i]]=1;
	  }
	printf("\n");
}
//============================================
signed main()
{
	n=read();
	int k=read();
	for(int i=1;i<=n;i++)
	  fac[i]=fac[i-1]*i;//计算阶乘 
	while(k--)
	  {
	  	char q;
	  	std::cin>>q;
	  	if(q=='Q') cantor();
	  	else re_cantor();
	  }
}
