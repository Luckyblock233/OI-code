//使用算法：分治
//观察样例可知,有如下规律:
/*
n=i时,可以通过两步转化:
先将"o*"移动到空格
再将"**"移动到新空格 
转化为n=i-1的情况
当n=4时,规律不适用，但可以打表 
*/ 
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string baka[6]={"","ooo--***o*","ooo*o**--*","o--*o**oo*","o*o*o*--o*","--o*o*o*o*"};//最后四步 
char map[100000],ans[100000];
int n;
void mo(int n1)// 当n=n1的情况 
{
	int n2=n1-1;
	int n3=2*n1;
	swap(map[n2],map[n3]);
	swap(map[n2+1],map[n3+1]);//"o*"移动到空格
	cout<<map<<endl;
	swap(map[n2],map[n3-2]);
	swap(map[n2+1],map[n3-1]);//将"**"移动到新空格 
	cout<<map<<endl;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) map[i]='o';
	for(int j=n;j<2*n;j++) map[j]='*';
	map[2*n]=map[2*n+1]='-';//构造初始图 
	cout<<map<<endl;
	for(int i=n;i>4;i--)
	  mo(i);
	for(int i=10;i<=2*n+1;i++)
	  ans[i-10]=map[i];//记录最后固定的部分,方便打表 
	for(int i=1;i<=4;i++)//打表,并输出最后固定的部分 
	  {
	  	cout<<baka[i];
	  	cout<<ans<<endl;
	  }
	cout<<"--";
	for(int i=1;i<=2*n;i++)
	  if(i%2!=0) cout<<"o";//输出最后情况 
	  else cout<<"*";
}
