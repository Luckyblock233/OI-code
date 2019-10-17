//本题使用dijkstra算法的堆优化+邻接表,才避免了超时 
// 基本思想与普通的dj相同,但在寻找最小的距离值时使用了优先队列
//这样就可以删去一层循环, 变为直接区队首元素.
//为了使用优先队列,定义一个结构体p来存编号与距离最小值
//并按照 距离最小值升序排列
//即可大大降低时间复杂度. 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int INF = 2147483647;//最大值 
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
int head[MARX],dis[MARX];
bool f[MARX]; 
int num,n,m,s,x;
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
		if(dis[e[j].v] > dis[top]+e[j].w && (!f[e[j].v]))
		{
		  dis[e[j].v] = dis[top]+e[j].w;
		  tmp.num=e[j].v;
		  tmp.diss=dis[e[j].v];
		  q.push(tmp);
		}
	  }
	}
}
//=============================================================
int main()
{
	scanf("%d%d%d",&n,&m,&s);//输入
	for(int i=1;i<=m;i++)
	{
	  int u,v,w;
	  scanf("%d%d%d",&u,&v,&w);
	  add(u,v,w);
	}
	dj(s);
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);  
}

/*
//2019.10.10
By:Luckyblock
使用STL中的 pair类实现 
简单好写 
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<queue>
#define int long long
const int MARX = 2e6+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<1];
int n,m,num, head[MARX];
int dis[MARX];
bool vis[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v,int w)
{

	e[++num].u = u,e[num].v = v, e[num].w = w;
	e[num].ne = head[u], head[u] = num;
}
void dijkstra(int start)
{
	std::priority_queue <std::pair<int,int> > q;
	memset(dis,63,sizeof(dis));
	dis[start] = 0 ;
	q.push(std::make_pair(0,start));
	
	for(; !q.empty(); )
	{
	  std::pair <int,int> top = q.top();  q.pop();
	  if(vis[top.second]) continue;
	  vis[top.second] = 1;
	  
	  for(int i=head[top.second]; i; i = e[i].ne)
	    if(dis[e[i].v] > dis[e[i].u] + e[i].w)
	    {
	      dis[e[i].v] = dis[e[i].u] + e[i].w;
	      q.push(std::make_pair(-dis[e[i].v], e[i].v));
		}
	}
}
//=============================================================
signed main()
{
	n = read(), m = read();
	int s = read();
	for(int i=1; i<=m; i++) 
	{
	  int u = read(), v = read(), w = read();
	  add(u,v,w);
	}
	dijkstra(s);
	for(int i=1; i<=n; i++) printf("%lld ",dis[i]);
}
*/
