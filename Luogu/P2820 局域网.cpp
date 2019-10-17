//模板题,不再赘述
//此题注意，先求所有路径的权值总和，
//然后将总权值减去 最小生成树求得的路径值相减 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int x,y,w;//分存每一条边前,后坐标与权值 
}a[10100];
int num;//存边的数量 
int pre[150];//存并查集中的祖先 
int n,m;
int tot,ans;
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
void add(int xx,int yy,int ww)
{
	a[++num].x=xx;
	a[num].y=yy;
	a[num].w=ww;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pre[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	int xx,yy,ww;
	    scanf("%d%d%d",&xx,&yy,&ww);//输入各边权值 
	    tot+=ww;
	    add(xx,yy,ww);//加入无向图 
	    add(yy,xx,ww);
	  }
	sort(a+1,a+num+1,cmp);
	int n1=0,i=1;
	while(n1++!=n)//循环找num条边,当找到n-1条边时停止 
	  {
	  	while(find(a[i].x) == find(a[i].y) && i<=num)
	  	  i++;
	  	join(a[i].x,a[i].y);//并集 
	  	ans+=a[i].w;//加和 
	  }
	printf("%d",tot-ans);//减去 
}
