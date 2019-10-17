//算法:图论/最小生成树 
//模板题,详见注释 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct baka9
{
	int x,y,w;//分存每一条边前,后坐标与权值 
}a[10100];
int pre[150];//存并查集中的祖先 
int n,m;
bool cmp(baka9 aa,baka9 bb)//结构体sort排序必须自定义排序函数 
{
	return aa.w<bb.w;
}
int find(int x)//查集 
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
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
	do
	  {
	  	memset(a,0,sizeof(a));
	    scanf("%d",&n);
	    if(n==0) return 0;
	    scanf("%d",&m);
	    for(int i=1;i<=m;i++)
	      {
	      	int u,v,w;
	      	scanf("%d%d",&u,&v);
	      	a[i].x=u,a[i].y=v;
	      	a[2*i].x=v,a[2*i].y=u;
		  }
	    for(int i=1;i<=n;i++)
	      pre[i]=i;//重置先祖
	    sort(a+1,a+2*m+1,cmp);
	    int n1=0,i=1,tot=0;
	    while(n1++!=n)//循环找num条边,当找到n-1条边时停止 
	      {
	  	    while(find(a[i].x) == find(a[i].y) && i<=2*m)
	  	      i++;
	  	    if(i>m)break;
	  	    join(a[i].x,a[i].y);//并集 
	  	    tot++;//加和 
	      }
	    printf("%d\n",m-tot);//输出
      }
    while(1);
}
