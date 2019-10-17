//算法:二分/字符串
/*
一道利用字符串函数的二分

对于一个字串,
先判断其是否只含有 0 或 1;
如果结果为假,
  则此字串变为: 'C'+前半字串+后半字串
  并递归继续改变
如果结果为真,
  则将此字串改变为 'A' 或 'B'   
*/ 
#include<iostream>
using namespace std;
string a;
string solve(string b)//递归改变函数 
{
	int lth=b.length() , i=0;//获得长度 
	while(b[i+1])//判断是否只含有一种字符 
	  if(b[i]!=b[i++ +1])//为假,则用substr函数，取出前半与后半的字串,并继续改变 
	  	return 'C'+solve(b.substr(0,lth/2))+solve(b.substr(lth/2)); 
	return b[0]=='0'?"A":"B";//只有一种字符 
}
int main()
{
	cin>>a;
	cout<<solve(a);
}
