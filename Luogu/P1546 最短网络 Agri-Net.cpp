//本题为最小生成树kruskal算法的例题 
//完全为模板题,不再赘述
//注意此题目给的数据为矩阵, 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int x,y,w;//分存每一条边前,后坐标与权值 
}a[10100];
int num;//存边的数量 
int pre[150];//存并查集中的祖先 
int n;
bool cmp(baka9 aa,baka9 bb)//结构体sort排序必须自定义排序函数 
{
	return aa.w<bb.w;
}
int find(int x)//查集 
{
	if(pre[x]==x)
	  return x;
	else
	  return pre[x]=find(pre[x]);
}
void join(int x,int y)//并集 
{
	int r1=find(x);
	int r2=find(y);
	if(r1 != r2)
	  pre[r1]=r2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	pre[i]=i;//顺便重置先祖 
	    for(int j=1;j<=n;j++)
	      {
	    	int ww;
	    	scanf("%d",&ww);//输入各边权值 
	    	a[++num].x=i;
	    	a[num].y=j;
	    	a[num].w=ww;
		  }
	  }
	sort(a+1,a+num+1,cmp);
	int n1=0,i=1,tot=0;
	while(n1++!=n)//循环找num条边,当找到n-1条边时停止 
	  {
	  	while(find(a[i].x) == find(a[i].y) && i<=num)
	  	  i++;
	  	join(a[i].x,a[i].y);//并集 
	  	tot+=a[i].w;//加和 
	  }
	printf("%d",tot);//输出 
}
