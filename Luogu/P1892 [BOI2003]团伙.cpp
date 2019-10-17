//此题为并查集的模板题, 
//在模板的基础上添加了判断是否为敌人的dd数组
//如果输入的x,y为敌人,则他们分别加入数组中
//储存的y,x的敌人所在的集合
//同时敌人数组赋值为x,y; 
#include<cstdio>
#include<iostream>
using namespace std;
int pre[2010];//存老大 
int dd[2010];//存敌人 
int find(int x)
{
	if(pre[x]==x)
	  return x;
	else
	  return pre[x]=find(pre[x]);
}
void join(int x,int y)
{
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2)
	  pre[r1]=r2;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pre[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	char judge;
	  	int x,y;
		cin>>judge;
		scanf("%d%d",&x,&y);
		if(judge=='F')//为朋友 
		  join(x,y);
		else//为敌人 
		  {
		  	if(dd[x]!=0) join(dd[x],y);
			if(dd[y]!=0) join(dd[y],x);
			dd[x]=y;
			dd[y]=x;
		  }
	  }
	bool laoda[1010]={0};
	int ans=0;
	for(int i=1;i<=n;i++)//判断,每有一个不重复的老大,则答案++. 
	  if(!laoda[find(i)]++)
	    ans++;
	printf("%d",ans);
}
