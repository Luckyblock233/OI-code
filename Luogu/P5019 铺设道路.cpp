//知识点:分治,模拟
/* 
脑子一抽想到的分治模拟做法

对于每一个没有高度为0的点的区间,
将各项填入 最小的高度
之后递归,
将此时的非高度为0的区间继续填入

思路很神奇,代码也很玄学
详见注释
*/
#include<iostream>
#include<cstdio>
using namespace std;
//============================================
int h[100005];
//============================================
long long block(int l,int r,int minh)//填入l~r区间,此区间最小值为minh
{
	if(h[l]==0 && h[r]==0) return 0;//全空区间,直接return
	long long sum=minh;//填入的次数
	while(h[l]==minh && l<r) l++;//左侧能填满的全部填入
	int l1=l;//新的左端点
	int minnh=100000;//记录最小值
	for(int i=l;i<=r;i++)
	{
	  h[i]-=minh;//填入
	  if(h[i]<minnh && h[i]>=0) minnh=h[i];
	  if(!h[i])//出现了空点,说明可以递归填
	  {
	  	sum=sum+block(l1,i-1,minnh);//递归填入
	  	l1=i+1,minnh=100000;//重新初始化
	  }
	  if(i==r) sum=sum+block(l1,i,minnh);//到达尽头,继续填剩下的区间
	}
    return sum;//返回l~r填入的次数
}
//============================================
signed main()
{
	int n,minh=100000;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	  	scanf("%d",&h[i]); 
	  	if(h[i]<minh) minh=h[i];//找到最小值
	}
	cout<<block(1,n,minh);//分治模拟
}