#include<cstdio>
#include<iostream>
using namespace std;
int n;
int b[1000];//储存每个字母的数组位置 
struct node
{
	char data;//数据 
	char lc,rc;//儿子 
}a[30];
void q(int i)
{
	if(a[i].data && i<=n)//不为空 
	  {
	  	printf("%c",a[i].data);//先输出根 
	  	if(a[i].lc!='*')//若他有左儿子 
	  	  q(b[a[i].lc]);//继续前序遍历 
	  	if(a[i].rc!='*')//右儿子,同上 
	  	  q(b[a[i].rc]);
	  }
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	cin>>a[i].data>>a[i].lc>>a[i].rc;
	  	b[a[i].data]=i;//记录数组位置 
	  }
	q(1);
	return 0;
}
