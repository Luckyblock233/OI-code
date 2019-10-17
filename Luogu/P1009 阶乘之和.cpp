//高精度乘法+加法
//详见注释 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int ans[50010];
int x[50010]={1};
int ltha=1,lthx=1;
void pluss()//高精加 
{
	int i=0;
	while(i<ltha || i<lthx)//计算 
	  {
	  	ans[i]+=x[i];
	  	if(ans[i]>=10)
	  	  {
	  	  	ans[i+1]+=ans[i]/10;
	  	  	ans[i]=ans[i]%10;
		  }
		i++;
	  }
	while(ans[i])//进位 
	  {
	    if(ans[i]>=10)
	  	    {
	  	  	  ans[i+1]+=ans[i]/10;
	  	  	  ans[i]=ans[i]%10;
		    }
	    i++;
	  }
	ltha=i+1;
	if(!ans[ltha-1]) ltha--;
}
void chen(int j)//高精乘 
{
	int c[50010]={0};
	int i=0;
	while(i<lthx)//计算 
	  {
	  	c[i]+=x[i]*j;
	  	if(c[i]>=10)
	  	  {
	  	  	c[i+1]+=c[i]/10;
	  	  	c[i]=c[i]%10;
		  }
		i++;
	  }
	  while(ans[i])//进位 
	    {
	      if(c[i]>=10)
	  	    {
	  	      c[i+1]+=c[i]/10;
	  	  	  c[i]=c[i]%10;
		    }
		  i++;
	    }
	for(int k=0;k<=i;k++) 
	  x[k]=c[k];
	lthx=i+1;
	if(!x[lthx-1]) lthx--;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//计算1~n的阶乘,并累加 
	  {
	  	chen(i);
	  	pluss();
	  }
	bool flag=0;
	for(int i=0;i<=ltha;i++)//去除前置0,并输出 
	  {
	  	if(ans[ltha-i]) flag=1;
	  	if(flag) cout<<ans[ltha-i];
	  }
}
