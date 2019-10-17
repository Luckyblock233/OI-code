//知识点:并查集 
/*
一种类似最小生成树的并查集解法

先将 所有敌对关系按照怒气值
按照降序排序

优先将怒气值大的两个罪犯,  
放到不同的监狱里
即:与对方的敌人加入同一集合 

当找到一个不得不
放到同一个监狱里的一对罪犯时
就找到了解

如果最后仍没有解
输出0即可 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n;
int minn;
struct line
{
	int u,v,w;
}a[100100];
int pre[20010];
int dd[20010];
//--------------------------------------------------
bool cmp(line xx,line yy)
{
	return xx.w>yy.w;
}
int find(int x)//查集 
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)//并集 
{
	int r1=find(x),r2=find(y);
	if(r1!=r2) pre[r2]=r1;
}
//----------------------------------------------------
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)//建边 
	{
	  int x,y,z;
	  scanf("%d%d%d",&x,&y,&z);
	  a[i].u=x;a[i].v=y;a[i].w=z;
	}
	sort(a+1,a+m+1,cmp);//排序 
	for(int i=1;i<=n;i++) pre[i]=i;//初始化各祖先 
	for(int i=1;i<=m;i++)
	{
	  if( find(a[i].u) == find(a[i].v) )//不得不分到同一监狱 
		{
		  printf("%d",a[i].w);
		  return 0;
		}
	  if(dd[a[i].u]!=0) join(a[i].v,dd[a[i].u]);//加入相反集合 
	  if(dd[a[i].v]!=0) join(a[i].u,dd[a[i].v]);
	  dd[a[i].u]=a[i].v; dd[a[i].v]=a[i].u;//记录敌对关系 
	  }
	printf("0");
	return 0;
}
