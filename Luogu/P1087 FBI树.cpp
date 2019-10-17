//知识点:二分/树的遍历
/*
将树分为大小相等的两个区间
判断区间的情况
然后在进行二分
一直分到叶节点后return ; 
*/ 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int n;
char a[10001];
void f(int l,int r,int l1)
{
	if(l>r)//为空 
	  return ;
	int j1=0,j0=0;//判断1,0的含有情况 
	for(int i=l;i<=r;i++)
	  {
	  	if(a[i]=='1') j1=1;
	  	if(a[i]=='0') j0=1;
	  }
	if(l==r)//只有一个元素时 ,就到了该输出的时候了 
	  {
	  	if(j1==1 && j0==1) printf("F");
	    if(j1==0 && j0==1) printf("B");
	    if(j1==1 && j0==0) printf("I");
	    return ;
	  }
	f(l,r-l1/2,l1/2);//继续二分判断 
	f(r-l1/2+1,r,l1/2);
	if(j1==1 && j0==1) printf("F");//后序输出根 
	if(j1==0 && j0==1) printf("B");
	if(j1==1 && j0==0) printf("I");
}
int main()
{
	cin>>n>>a;
	for(int i=pow(2,n);i>=1;i--)//全部后移一位,方便 
	  a[i]=a[i-1];
	f(1,strlen(a)-1,strlen(a)-1);//递归二分判断,分别代表左右区间与区间长度 
}

