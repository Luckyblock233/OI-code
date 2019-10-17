//知识点:最短路 
/*
要求记录最短路的路径

需要在跑最短路时 , 记录疏导每个点的中转点
最后从终点开始向前寻找
进行中转点迭代, 一直找到起点

再反向输出即可 
详见注释 
*/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long 
const int INF = 0x7fffffffff;//最大值 
const int MARX = 1e5+10;
using namespace std;
//=============================================================
struct edge
{
	int u,v,w,ne;//分存前点 后点 权重 
}e[MARX<<1];
struct p
{
	int num,diss;
	bool operator < (const p &a) const
	  {
	  	return diss > a.diss;
	  }
}tmp;
int head[MARX],dis[MARX],pre[MARX],ans[MARX];
bool f[MARX];
int num,n,m,s=1;
//=============================================================
void add(int u,int v,int w)//邻接表加入元素 
{
	e[++num].ne=head[u],head[u]=num;
	e[num].u=u,e[num].v=v,e[num].w=w;
}
void dj(int s)
{
	priority_queue <p> q;
	tmp.num=s,tmp.diss=0;q.push(tmp);
	for(int i=1;i<=n;i++) dis[i]=INF;//赋极值 
	dis[s]=0;//初始化 
	while(!q.empty())
	{
	  int top=q.top().num; q.pop();
	  if(f[top]) continue;
	  f[top]=1;
	  for(int j=head[top];j;j=e[j].ne)//找k点的临点,并进行比较 
	  {
		if(dis[e[j].v] > dis[top]+e[j].w && !f[e[j].v])
		{
		  pre[e[j].v]=top;//记录中转点,即路径 
		  dis[e[j].v] = dis[top]+e[j].w;
		  tmp.num=e[j].v;
		  tmp.diss=dis[e[j].v];
		  q.push(tmp);
		}
	  }
	}
}
//=============================================================
signed main()
{
	scanf("%lld%lld",&n,&m);//输入
	for(int i=1;i<=m;i++)
	{
	  int u,v,w;
	  scanf("%lld%lld%lld",&u,&v,&w);
	  add(u,v,w);add(v,u,w);
	}
	dj(s);
	int num1=0;
	for(int i=n;i>1;i=pre[i]) ans[++num1]=i;//反向寻找路径 
	if(pre[ans[num1]]!=1)//无解情况,1与n不连通 
	{
	 printf("-1");
	 return 0;
	}
	printf("1");//输出路径 
	for(int i=num1;i>=1;i--) printf("%d",ans[i]);
}
