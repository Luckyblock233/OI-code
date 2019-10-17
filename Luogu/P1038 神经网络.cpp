//所用算法：拓扑排序（topsort）
/*
思路：先输入各数据,建立单向图,找出根结点,压入栈,并记录.
之后开始topsort算法.找到栈顶元素,如果该元素不为根点,就减去它的阀值. 
如果减去阀值后,该点兴奋度不为负,
就枚举与点的子点,使子点的c加上按公式计算出的值,并使子点的入度减一 
如果子点入度为0,就将其压入栈
当找完所有子点后,将母点的兴奋度置零. 
一直到栈为空
最后找到兴奋度不为0的点,并输出
找不到就输出null 
*/ 
#include<cstdio>
#include<stack>
using namespace std;
struct baka9//邻接表存边 
{
	int u,v,w,ne;
}a[100100];
int head[110];
bool root[110];
int c[110],u[110];//存输入的兴奋度与阀值 
int ru[110];//存入度 
int num;
void add(int u,int v,int w)//邻接表 
{
	a[++num].ne=head[u];	
	head[u]=num;
	a[num].u=u;a[num].v=v;a[num].w=w;
}
int main()
{
	stack <int> s;
	int n,p;
	scanf("%d%d",&n,&p);//输入 
	for(int i=1;i<=n;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	c[i]=x;u[i]=y;
	  }
	for(int i=1;i<=p;i++)
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);
	  	ru[v]++;//计算入度 
	  }
	for(int i=1;i<=n;i++)//找到根点,并记录 
	  if(!ru[i])
	    {
	      s.push(i);
	      root[i]=1;
		}
	while(!s.empty())
	  {
	  	int u1=s.top();
	  	s.pop();
	  	if(!root[u1])//不为根 
	  	  c[u1]-=u[u1];
	  	if(c[u1] > 0)//如果母点兴奋 
	  	  for(int i=head[u1];i;i=a[i].ne)//找到子点 
	  	    {
	  	  	  int v=a[i].v,w=a[i].w;
			  c[v]+=w*c[u1];//计算子点兴奋度 
			  ru[v]--;//入度减一 
	  	  	  if(!ru[v]) 
			    s.push(v);//压入栈 
		    }
		if(head[u1]) 
		  c[u1]=0;//置零有子点的母点 
	  }
	int flag_no_0=0;//找答案 
	for(int i=1;i<=n;i++)
	  if(c[i] > 0)
	    flag_no_0=1;
	if(!flag_no_0)
	  printf("NULL"); 
	else
	  for(int i=1;i<=n;i++)
	    if(c[i] > 0) printf("%d %d\n",i,c[i]);
}
