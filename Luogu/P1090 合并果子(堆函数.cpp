//真**难写！！！垃圾堆函数！！！毁我青春！！！ 
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;//小根堆 
}
int dui[20100];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&dui[i]);
	make_heap(dui,dui+n,cmp);//建堆 
	for(int i=0;i<n-1;i++)
	  {
	  	int size=n-i;//此时的数据序列长度 
	  	int x=dui[0];//取最小数据 
	  	pop_heap(dui,dui+size,cmp); 
	  	int y=dui[0];//取次小数据 
	  	pop_heap(dui,dui+size-1,cmp);
	  	ans+=x+y;//累加 
	  	dui[size-2]=x+y;//放到堆最后 
	  	push_heap(dui,dui+size-1,cmp);//放入堆 
	  }
	printf("%d",ans);
}
//10 3 5 1 7 6 4 2 5 4 1
//120
