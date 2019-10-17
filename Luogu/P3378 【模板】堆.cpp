#include<cstdio>
#include<algorithm>
using namespace std;
int dui[100100];
int size=0;
void put(int x)
{
	dui[++size]=x;
	int son=size,dad=size/2;
	while(dad > 0)
	  {
	  	if(dui[son]>=dui[dad]) break;
	  	swap(dui[son],dui[dad]);
	  	son=dad;
	  	dad/=2;
	  }
}
int get()
{
	int top=dui[1];
	dui[1]=dui[size--];
	int dad=1,son=2;
	while(son<=size)
	  {
	  	if(son<size && dui[son+1]<dui[son]) son++;
	  	if(dui[son]>=dui[dad]) break;
	  	swap(dui[dad],dui[son]);
	  	dad=son;
	  	son*=2;
	  }
	return top;
}
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  {
	  	scanf("%d",&x);
	  	if(x==1)
		  {
		  	int y;
		  	scanf("%d",&y);
		  	put(y);
		  } 
	  	if(x==2)
	  	  printf("%d\n",dui[1]);
		if(x==3)
		  get();
	  }
}
