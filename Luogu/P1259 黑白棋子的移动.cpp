//ʹ���㷨������
//�۲�������֪,�����¹���:
/*
n=iʱ,����ͨ������ת��:
�Ƚ�"o*"�ƶ����ո�
�ٽ�"**"�ƶ����¿ո� 
ת��Ϊn=i-1�����
��n=4ʱ,���ɲ����ã������Դ�� 
*/ 
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string baka[6]={"","ooo--***o*","ooo*o**--*","o--*o**oo*","o*o*o*--o*","--o*o*o*o*"};//����Ĳ� 
char map[100000],ans[100000];
int n;
void mo(int n1)// ��n=n1����� 
{
	int n2=n1-1;
	int n3=2*n1;
	swap(map[n2],map[n3]);
	swap(map[n2+1],map[n3+1]);//"o*"�ƶ����ո�
	cout<<map<<endl;
	swap(map[n2],map[n3-2]);
	swap(map[n2+1],map[n3-1]);//��"**"�ƶ����¿ո� 
	cout<<map<<endl;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) map[i]='o';
	for(int j=n;j<2*n;j++) map[j]='*';
	map[2*n]=map[2*n+1]='-';//�����ʼͼ 
	cout<<map<<endl;
	for(int i=n;i>4;i--)
	  mo(i);
	for(int i=10;i<=2*n+1;i++)
	  ans[i-10]=map[i];//��¼���̶��Ĳ���,������ 
	for(int i=1;i<=4;i++)//���,��������̶��Ĳ��� 
	  {
	  	cout<<baka[i];
	  	cout<<ans<<endl;
	  }
	cout<<"--";
	for(int i=1;i<=2*n;i++)
	  if(i%2!=0) cout<<"o";//��������� 
	  else cout<<"*";
}
