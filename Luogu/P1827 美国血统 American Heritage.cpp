#include<iostream>
using namespace std;
string a,b;
void f(int l1,int r1,int l2,int r2)
{
	int n=b.find(a[l1]);//找到中序中前序中的第一个元素,即根 
	if(n>l2) f(l1+1,l1+n-l2,l2,n-1);//将两序列二分为左右子树 
	if(n<r2) f(l1+n-l2+1,r1,n+1,r2);
	cout<<a[l1];//后序输出根
}
int main()
{
	cin>>b>>a;
	f(0,a.length()-1,0,b.length()-1); //递归 
	return 0;
}
