//֪ʶ��:����/���ı���
/*
������Ϊ��С��ȵ���������
�ж���������
Ȼ���ڽ��ж���
һֱ�ֵ�Ҷ�ڵ��return ; 
*/ 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int n;
char a[10001];
void f(int l,int r,int l1)
{
	if(l>r)//Ϊ�� 
	  return ;
	int j1=0,j0=0;//�ж�1,0�ĺ������ 
	for(int i=l;i<=r;i++)
	  {
	  	if(a[i]=='1') j1=1;
	  	if(a[i]=='0') j0=1;
	  }
	if(l==r)//ֻ��һ��Ԫ��ʱ ,�͵��˸������ʱ���� 
	  {
	  	if(j1==1 && j0==1) printf("F");
	    if(j1==0 && j0==1) printf("B");
	    if(j1==1 && j0==0) printf("I");
	    return ;
	  }
	f(l,r-l1/2,l1/2);//���������ж� 
	f(r-l1/2+1,r,l1/2);
	if(j1==1 && j0==1) printf("F");//��������� 
	if(j1==0 && j0==1) printf("B");
	if(j1==1 && j0==0) printf("I");
}
int main()
{
	cin>>n>>a;
	for(int i=pow(2,n);i>=1;i--)//ȫ������һλ,���� 
	  a[i]=a[i-1];
	f(1,strlen(a)-1,strlen(a)-1);//�ݹ�����ж�,�ֱ�����������������䳤�� 
}

