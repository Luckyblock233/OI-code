#include<cstdio>
#include<iostream>
using namespace std;
int n;
int b[1000];//����ÿ����ĸ������λ�� 
struct node
{
	char data;//���� 
	char lc,rc;//���� 
}a[30];
void q(int i)
{
	if(a[i].data && i<=n)//��Ϊ�� 
	  {
	  	printf("%c",a[i].data);//������� 
	  	if(a[i].lc!='*')//����������� 
	  	  q(b[a[i].lc]);//����ǰ����� 
	  	if(a[i].rc!='*')//�Ҷ���,ͬ�� 
	  	  q(b[a[i].rc]);
	  }
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	cin>>a[i].data>>a[i].lc>>a[i].rc;
	  	b[a[i].data]=i;//��¼����λ�� 
	  }
	q(1);
	return 0;
}
