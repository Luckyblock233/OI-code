//算法:图论/最短路
//思路:题目要求离在走最短路径情况下,到达点1最远的点 
//先用最短路算法,
//求出各点到达点1的最短路径
//在找到其中最长的,并统计数量即可

//用了堆优化的dj算法 
#include<cstdio>
#include<queue>
using namespace std;
int n,m;
struct line//存边 
{
	int u,v,ne;
}a[100010];
struct p//自定义优先级 
{
	int num,diss;
	bool operator <(const p &aa) const
	  {
		return diss > aa.diss;
	  }
};
int head[20010];
int f[20010],dis[20010];
int num;
int ans1,ans2,ans3;
priority_queue <p> q;
//============变量与函数的境界===================================
void add(int u,int v)//邻接表加边 
{
	a[++num].u=u;
	a[num].v=v;
	a[num].ne=head[u];
	head[u]=num;
}
void dj(int s)
{
	for(int i=1;i<=n;i++)//初始化 
	  f[i]=0,dis[i]=2147483640;
	dis[1]=0;
	p tmp;
	tmp.num=1,tmp.diss=0;
	q.push(tmp);//加入队列 
	while(!q.empty())
	  {
	  	int topp=q.top().num;//取出队首 
	  	q.pop();
	  	if(f[topp]) continue;
	  	f[topp]=1;
	  	for(int i=head[topp];i;i=a[i].ne)//疏导 
	  	  {
	  	  	if(dis[topp]+1<dis[a[i].v] && !f[a[i].v])
	  	  	  {
	  	  	  	dis[a[i].v]=dis[topp]+1;//加入队列 
	  	  	  	tmp.num=a[i].v,tmp.diss=dis[a[i].v];
	  	  	  	q.push(tmp);
			  }
		  }
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)//输入 
	  {
	  	int u,v;
	  	scanf("%d%d",&u,&v);
	  	add(u,v);
	  	add(v,u);
	  }
	dj(1);
	for(int i=1;i<=n;i++)//寻找答案 
	  {
	  	if(dis[i]>ans2) ans1=i,ans2=dis[i],ans3=0;
	  	if(dis[i]==ans2) ans3++;
	  }
	printf("%d %d %d",ans1,ans2,ans3);
}
