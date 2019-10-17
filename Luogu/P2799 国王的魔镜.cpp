#include<cstdio>
#include<iostream>
using namespace std;
string a; 
int s;//长度 
void zun(string b)
{
	if(s%2==1)//字符串长度为奇数,则不可能回文 
	  return ;
	int l=0;//左右互♂搏 
	int r=s-1; 
	int judge=1;//判断变量 
	while(l<r)
	  {
	  	if(a[l]==a[r])  //相等继续判断 
	  	  {
	  	  	l++;
	  	  	r--;
		  }
		else
		  {
		  	judge=0;//不等break 
		  	break;
		  }
	  }
	if(judge==1)
	  {
	  	b.erase(l);//擦出相等 
	  	s=b.length();//重新计算长度 
	  	zun(b);
	  }
	else
	  return ;
}
int main()
{
	cin>>a;
	s=a.length();
	zun(a);
	cout<<s;
}
