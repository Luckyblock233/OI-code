//算法:二分答案/图论
/*
题目要求 经过的所有城市中 最多的 一次收取的费用的 最小值 是多少
根据题目, 显然,答案满足单调性,
即较小答案合法,则比他大的答案都合法 
就可以使用二分答案法

二分答案枚举 最多的一次收取的费用的最小值
并将其作为一个参数 x ,传递给子函数
在子函数中,跑一遍SPFA,
以损失的血量尽量少为目的,
同时对于收取费用大于x的城市,不可到达.

跑完一遍后,判断到达n点消耗的血量是否小于最大血量
如果比最大血量大,证明最多的一次收取的费用的最小值为x时,不可到达
否则则可到达

二分得到最后的答案后,再判断此答案是否合法
合法则输出,否则输出AFK 
*/ 
#include<cstdio>
#include<queue>
#include<algorithm> 
#define int long long
using namespace std;
const int MARX = 1e6+10;
const int INF = 2147483647;
struct edge
{
	int u,v,w,ne;
}a[MARX];
int n,m,b,maxcost;
int num;
int head[MARX],cost[MARX],cost1[MARX],dis[MARX];
bool vis[MARX]={0,1};
struct cmp1//自定义优先级,优化SPFA 
{
	bool operator ()(const int a,const int b)
      {
        return dis[a]>dis[b];
      }
};
priority_queue <int,vector<int>,cmp1> s;//优先队列优化SPFA 
//========================================================================
void add(int u,int v,int w)
{
	a[++num].u=u,a[num].v=v,a[num].w=w;
	a[num].ne=head[u],head[u]=num;
}
bool judge(int x)//判断是否合法 
{
	if(cost[1]>x) return 0;//起点花费是否大于x 
	for(int i=2;i<=n;i++) dis[i]=INF,vis[i]=0;//SPFA 
	s.push(1);
	while(!s.empty())
	  {
	  	int top=s.top();
	  	s.pop();
	  	vis[top]=0;
	  	for(int i=head[top];i;i=a[i].ne)
	  	  {
	  	  	int v=a[i].v,w=a[i].w;
	  	  	if(dis[v]>dis[top]+w && cost[v]<=x)//限制一次收取的费用<=x 
	  	  	  {
	  	  	  	dis[v]=dis[top]+w;
	  	  	  	if(!vis[v])
	  	  	  	{
				  s.push(v);
	  	  	  	  vis[v]=1;
	  	  	    }
			  }
		  }
	  }
	return dis[n]<b;
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&b);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld",&cost[i]);
	  	cost1[i]=cost[i];
	  }
	for(int i=1;i<=m;i++)//建图 
	  {
	  	int u,v,w;
	  	scanf("%lld%lld%lld",&u,&v,&w);
	  	add(u,v,w),add(v,u,w);
	  }
	sort(cost1+1,cost1+n+1);
	int le=1,ri=n,mid;
	while(le<=ri)//二分答案 
	  {
	  	mid=(le+ri)>>1;
	  	if(judge(cost1[mid])) ri=mid-1;
	  	else le=mid+1;
	  }
	if(!judge(cost1[le]))printf("AFK");//不可到达的情况 
	else printf("%lld",cost1[le]);
}
