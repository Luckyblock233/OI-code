//算法：暴力/模拟
//虽然数据量很大,
//但是直接根据题意暴力模拟 
//也不会超时 
//详见注释 
#include<cstdio>
#include<iostream>
using namespace std;
int num[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//每月有几天 
string a,b;
int ans;
string change(string c)//变成下一天 
{
	int ye=0,mo=0,da=0;//计算几年几月几号 
	for(int i=0;i<4;i++) ye=ye*10+c[i]-'0';
	mo=(c[4]-'0')*10+c[5]-'0';
	da=(c[6]-'0')*10+c[7]-'0'+1;
	
	bool run;//判断是否为闰年 
	if(ye%4==0 && ye%100!=0)run=1;
	if(ye%400==0) run=1;
	
	if(mo==2)//改变年月号 
	  {
	  	if(da>28 && !run) mo=3,da=1;
	  	if(da>29 && run) mo=3,da=1;
	  }
	if(da>num[mo] && mo!=2) mo++,da=1;//月份进一 
	if(mo>12) ye++,mo=1;//年份进一 
	
	string ans="00000000";//重新赋值给字符串 
	int i=7;
	while(da>0) //日 
	  {
	  	char tmp=(char)(da%10)+'0';
	  	ans[i--]=tmp;
	  	da/=10;
	  }
	i=5;
	while(mo>0)//月 
	  {
	  	char tmp=(char)(mo%10)+'0';
	  	ans[i--]=tmp;
	  	mo/=10;
	  }
	i=3;
    while(ye>0)//年 
	  {
	  	char tmp=(char)(ye%10)+'0';
	  	ans[i--]=tmp;
	  	ye/=10;
	  }
	return ans;//返回 
}
void judge(string c)//判断是否为回文 
{
	for(int i=0;i<=3;i++)
	  if(c[i]!=c[7-i]) 
	    return ;//不为回文 
	ans++;
	return ;
}
int main()
{
	cin>>a;cin>>b;
	string c=a;
	do//循环判断 
	  {
	  	judge(c);
	  	if(c==b) break;
	  	c=change(c);
	  }
	while(1);
	printf("%d",ans);
}
