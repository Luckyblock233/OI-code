//知识点:堆/模拟
/*
将各堆果子的大小作为元素
放入一个小根堆当中

每次取出堆顶的两个最小的元素 
将他们合并后
再次放入堆中
同时累加答案 
*/ 
#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
int main()
{
	priority_queue < int , vector<int> ,greater<int> > s;//建立从小到大排列的优先队列 
	int n,x,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  {
	  	scanf("%d",&x);
	  	s.push(x);//压入优先队列 
	  }
	for(int i=0;i<n-1;i++)
	  {
	  	int x=s.top();//找最小的元素 
	  	s.pop();//删掉 
	  	int y=s.top();//找第二小的元素 
	  	s.pop();//删掉 
	  	ans+=x+y;//累加 
	  	s.push(x+y);//压入 
	  }
	printf("%d",ans);
}
