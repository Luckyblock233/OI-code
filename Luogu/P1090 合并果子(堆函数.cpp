//��**��д�����������Ѻ��������������ഺ������ 
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;//С���� 
}
int dui[20100];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&dui[i]);
	make_heap(dui,dui+n,cmp);//���� 
	for(int i=0;i<n-1;i++)
	  {
	  	int size=n-i;//��ʱ���������г��� 
	  	int x=dui[0];//ȡ��С���� 
	  	pop_heap(dui,dui+size,cmp); 
	  	int y=dui[0];//ȡ��С���� 
	  	pop_heap(dui,dui+size-1,cmp);
	  	ans+=x+y;//�ۼ� 
	  	dui[size-2]=x+y;//�ŵ������ 
	  	push_heap(dui,dui+size-1,cmp);//����� 
	  }
	printf("%d",ans);
}
//10 3 5 1 7 6 4 2 5 4 1
//120
