//知识点:最小生成树 
/*
题目要求:
将n+1个点连接起来的最少花费
裸的最小生成树
详见注释 
*/
#include<cstdio>
#include<algorithm>
const int MARX = 4e5+10;
//=============================================================
struct edge
{
	int u,v,w;//分存每一条边前,后坐标与权值 
}a[2*MARX];
int n,m,num;//存边的数量 
int pre[MARX];//存并查集中的祖先 
//=============================================================
bool cmp(edge aa,edge bb){return aa.w<bb.w;}//结构体sort排序必须自定义排序函数 
void add(int u,int v,int w){a[++num].u=u,a[num].v=v,a[num].w=w;}
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
void join(int x,int y)//并集 
{
	int r1=find(x),r2=find(y);
	if(r1 != r2) pre[r1]=r2;
}
//=============================================================
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) pre[i]=i;//重置先祖 
	for(int j=1;j<=m;j++)
	{
	  int u,v,w;
	  scanf("%d%d%d",&u,&v,&w);//输入各边权值 
	  add(u,v,w);
	}
	std::sort(a+1,a+num+1,cmp);
	int sum=0;
	for(int i=1,tot=0;i<=num&&tot!=n;i++)
	{
	  if(find(a[i].u) == find(a[i].v)) continue;
	  join(a[i].u,a[i].v);
	  ++tot,sum+=a[i].w;
	}
	printf("%d",sum);//输出 
}
