//模板题,因为是单向路径且数据比较弱,就用了邻接表+裸dijkstra 
//邻接表还挺简单
//邻接矩阵会MLE，但邻接表好快 ！！！  
#include<cstdio>
#include<cstring>
const int MAXX=2147483647;//最大值 
using namespace std;
struct line
{
	int be,af,we;//分存前点 后点 权重 
	int next;
}l[500010];
int head[10010];
int num=0;
int dis[10010];//存最小距离 
bool f[10010]={0};
int n,m,s;
void add(int bee,int aff,int wee)//邻接表加入元素 
{
	l[++num].next=head[bee];
	l[num].be=bee;
	l[num].af=aff;
	l[num].we=wee;
	head[bee]=num;
}
void dj();
int main()
{
	scanf("%d%d%d",&n,&m,&s);//输入 
	for(int i=0;i<m;i++)
	  {
	  	int bee,aff,wee;
	  	scanf("%d%d%d",&bee,&aff,&wee);
	  	add(bee,aff,wee);
	  }
	dj();
	for(int i=1;i<=n;i++)
	  printf("%d ",dis[i]);//输出 
}
void dj()
{
	for(int i=1;i<=n;i++)
	  dis[i]=MAXX;//赋极值 
	for(int i=head[s];i;i=l[i].next)//为dis中s的直接相邻点赋值 
	  {
	  	if(l[i].we <dis[l[i].af]) //因为数据中有两点多边情况,就取其中最小的一条 
	  	  dis[l[i].af]=l[i].we;
	  }
	dis[s]=0;//初始化 
	f[s]=1;
	for(int i=1;i<=n;i++)//开始经典dj算法 
	  {
	  	int minn=MAXX,k=0;//找最小 
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	if(dis[j] < minn && !f[j])
	  	  	  {
	  	  	  	minn=dis[j];k=j;
			  }
		  }
		if(k==0) break;//找不到,就终止 
		f[k]=1;//置一 
		for(int j=head[k];j;j=l[j].next)//找k点的临点,并进行比较 
		  {
		  	if(dis[l[j].af] > dis[k]+l[j].we)
		  	  dis[l[j].af] = dis[k]+l[j].we;
		  }
	  }
}
