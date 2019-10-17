#include<cstdio>
#include<algorithm>
using namespace std;
int dui[30100]; 
int size=0;
void put(int x)//����ѵ�put 
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
int get()//����ѵ�get 
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
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);//������һ������ 
	for(int j=1;j<=m;j++)//�Զѽ��г�ʼ�� 
	  put(a*j*j+b*j+c);//����� 
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);//������������ 
	  	for(int j=1;j<=m;j++)
	  	  {
	  	  	 if(a*j*j+b*j+c <dui[1])//dui[1]Ϊ������������,�����ֱ�����С����,������Ϊ�� 
	  	      {
	  	        get();//��ԭ���������ӳ�ȥ 
				  put(a*j*j+b*j+c);//�����µĽ�С���� 
	  	      }
	  	    else 
				break;//��������ԭ������������,��ֹͣ 
	  	  }
	  }
	int ans[500000];
	for(int i=m;i>=1;i--)//������Ԫ�ص������������� 
	  {
	  	ans[i]=get();
	  }
	for(int i=1;i<=m;i++)
	  printf("%d ",ans[i]);//��� 
}
