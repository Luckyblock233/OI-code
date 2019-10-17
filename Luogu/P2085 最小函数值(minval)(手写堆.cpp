#include<cstdio>
#include<algorithm>
using namespace std;
int dui[30100]; 
int size=0;
void put(int x)//大根堆的put 
{
	dui[++size]=x;
	int son=size,dad=size/2;
	while(dad > 0)
	  {
	  	if(dui[son]<=dui[dad]) break;
	  	swap(dui[son],dui[dad]);
	  	son=dad;
	  	dad/=2;
	  }
}
int get()//大根堆的get 
{
	int top=dui[1];
	dui[1]=dui[size--];
	int dad=1,son=2;
	while(son<=size)
	  {
	  	if(son<size && dui[son+1]>dui[son]) son++;
	  	if(dui[son]<=dui[dad]) break;
	  	swap(dui[dad],dui[son]);
	  	dad=son;
	  	son*=2;
	  }
	return top;
}
int main()
{
	int n,m,a,b,c;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);//先输入一组数据 
	for(int j=1;j<=m;j++)//对堆进行初始化 
	  put(a*j*j+b*j+c);//放入堆 
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);//继续输入数据 
	  	for(int j=1;j<=m;j++)
	  	  {
	  	  	 if(a*j*j+b*j+c <dui[1])//dui[1]为答案中最大的数据,若出现比它更小的数,则新数为答案 
	  	      {
	  	        get();//将原先最大的数扔出去 
				  put(a*j*j+b*j+c);//放入新的较小的数 
	  	      }
	  	    else 
				break;//若新数比原来最大的数都大,则停止 
	  	  }
	  }
	int ans[500000];
	for(int i=m;i>=1;i--)//将堆中元素倒序放入答案数组中 
	  {
	  	ans[i]=get();
	  }
	for(int i=1;i<=m;i++)
	  printf("%d ",ans[i]);//输出 
}
