//算法：DP/01背包
//虽然题目提示上是多重背包
//实际上是01背包=_=

//先输入各物品, 按照类别，存下各物品的数量，上限。
//然后进行拆解,对数量超过上限的物品,
//将其数量置为上限, 
//并增加一个数量为 原数量-上限 的物品
//一直拆解到都满足条件.

//之后跑一遍01背包即可 
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int m,n,num;
int a[1100],b[1100],c[1100];
int f[25];
map <string,int> gr;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)//输入数据,按类别记录 
	  {
	  	int a1,b1,c1;
	  	string s;
	  	cin>>a1>>b1>>c1;
	  	cin>>s;
	  	if(!gr[s]) a[++num]=a1,b[num]=b1,c[num]=c1,gr[s]=num;//没有出现过 
		else a[gr[s]]+=a1;  //出现过 
	  }
	m=21-m;//背包容量 
	for(int i=1;a[i];i++)//拆解 
	  if(a[i]>c[i])//超过上限 
	    {
	      a[++num]=a[i]-c[i];//增加新物品 
	      b[num]=b[i];
	      c[num]=c[i];
	      a[i]=c[i];//原物品数量改变 
		}
	for(int i=1;i<=num;i++)//跑01背包 
	  for(int j=m;j>=1;j--)
	    f[j]=max(f[j],f[j-1]+a[i]*b[i]);
	printf("%d",f[m]);
}
