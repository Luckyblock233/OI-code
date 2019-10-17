//算法：排序
/*
略麻烦的排序
用结构体存储每个人的信息
并创建一个变量,存输入时的次序

按照年,月,日升序排列
年,月,日相同的,按照输入次序降序排列

输出即可 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
const int MARX = 110;
struct baka9//结构体存储每个人的信息 
{
	string na;
	int ye,mo,da;
	int order;
}a[MARX];
bool cmp(baka9 a,baka9 b)//排序 
{
	if(a.ye==b.ye)
	  {
	  	if(a.mo==b.mo)
	  	  {
	  	  	if(a.da==b.da) return a.order>b.order;
	  	  	return a.da<b.da;
		  }
	  	return a.mo<b.mo;
	  }
	return a.ye<b.ye;
}
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	  {
	  	cin>>a[i].na>>a[i].ye>>a[i].mo>>a[i].da;
	  	a[i].order=i;//存次序 
	  }
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	  cout<<a[i].na<<endl;
}
