//使用算法：并查集+前缀和
//思路: 对于此题,纯模拟最多拿到90分,所以要考虑一些优化措施
//首先,在合并时,不能对每一艘军舰,都计算他们之前的军舰数量,绝对会TLE

//则先设置l数组存当前队列的长度 
//再使用一个pree数组,存储当前军舰,与其队首军舰之间的距离
//合并时,只需要使原队首军舰的pree值加上前面的军舰数量l即可
//并在find函数中,压缩之前维护pree的值.

#include<cstdio>
#include<iostream>
using namespace std;
int pre[30010];//存祖先 
int pree[30010];//存储当前军舰,与其队首军舰之间的距离
int l[30010];//当前队列的长度  
int find(int x)//查集并维护pree 
{
    if(pre[x]==x)
      return x;
    int rx=find(pre[x]);//先计算新的父亲 
    pree[x]+=pree[pre[x]];//再使pree【x】加上与原父亲与新父亲的距离，就得到了x与新父亲的距离 
	return pre[x]=rx;//再返回 
}
int find1(int x,int y)//找答案 
{
    int r1=find(x);//找根并维护pree 
    int r2=find(y);
    if(r1 !=r2)
	  return -1;
    int l1=pree[x];
    int l2=pree[y];
    return max(l1,l2)-min(l1,l2)-1;//求差值,即答案 
}
void join(int x,int y)//并集 
{
    int r1=find(x);
    int r2=find(y);
    pree[r1]+=l[r2];//为原队首元素到队首的距离 赋新值 
    pre[r1]=r2;//换爸爸= = 
    l[r2]+=l[r1];//当前列长度更新 
    l[r1]=0;//原列长度为0 
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=30002;i++)//初始化 
      {
      	pre[i]=i;
      	pree[i]=0;
      	l[i]=1;
      }
    for(int i=1;i<=t;i++)//回答询问 
      {
      	char judge;
      	cin>>judge;
      	int x,y;
      	scanf("%d%d",&x,&y);
      	if(judge=='M')
           join(x,y);
        if(judge=='C')
          printf("%d\n",find1(x,y));
      }
}
//以下为纯模拟90分TLE代码 
/*
#include<cstdio>
#include<iostream>
using namespace std;
int pre[30010];
int pree[30010];
int l[30010];
int find(int x)
{
    if(pre[x]==x)
      return x;
    int rx=find(pre[x]);
    pree[x]+=pree[pre[x]];
    return pre[x]=rx;
}
int find1(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    if(r1 !=r2)
      return -1;
    int l1=pree[x];
    int l2=pree[y];
    return max(l1,l2)-min(l1,l2)-1;
}
void join(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    pree[r1]+=l[r2];
    pre[r1]=r2;
    l[r2]+=l[r1];
    l[r1]=0;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=30002;i++)
      {
      	pre[i]=i;
      	pree[i]=0;
      	l[i]=1;
      }
    for(int i=1;i<=t;i++)
      {
      	char judge;
      	cin>>judge;
      	int x,y;
      	scanf("%d%d",&x,&y);
      	if(judge=='M')
           join(x,y);
        if(judge=='C')
          printf("%d\n",find1(x,y));
      }
}
*/ 
