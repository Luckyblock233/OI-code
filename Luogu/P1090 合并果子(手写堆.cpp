#include<cstdio>
#include<algorithm>
using namespace std;
int dui[30100];
int size=0;
void put(int x)//С���ѷ��� 
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
int get()//С����get 
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
	int n,x,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)//����,������ 
	  {
	  	scanf("%d",&x);
	  	put(x);
	  }
	for(int i=1;i<=n-1;i++)
	  {
	  	int x=get();//ȡ��С 
	  	int y=get();//ȡ��С 
	  	ans+=x+y;//�ۼ� 
	  	put(x+y);//���� 
	  }
	printf("%d",ans);
}
