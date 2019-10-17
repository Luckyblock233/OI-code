//知识点:单源最短路 
/*
模板题
详见注释 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int MAXX=2147483640;//最大值 
using namespace std;
//======================================================================
struct line
{
	int be,af,we;//分存前点 后点 权重 
	int next;
}l[50010];
struct p//优先队列优化 
{
	int num,diss;
	bool operator < (const p &a) const
	{
	  return diss > a.diss;
	}
};
int head[10010],dis[10010];//存最小距离 
bool f[10010]; 
int n,m,s,x,t,num;
//======================================================================
void add(int bee,int aff,int wee)//邻接表加入元素 
{
	l[++num].next=head[bee];head[bee]=num;
	l[num].be=bee;l[num].af=aff;l[num].we=wee;
}
void dj(int s)
{
	memset(f,0,sizeof(f));//初始化 
	priority_queue <p> q;
	p tmp;
	tmp.num=s,tmp.diss=0;
	for(int i=1;i<=n;i++) dis[i]=MAXX;//赋极值 
	dis[s]=0;//初始化 
	q.push(tmp);
	while(!q.empty())
	{
	  int topp=q.top().num;
	  q.pop();
	  if(f[topp]) continue;
	  f[topp]=1;
	  for(int j=head[topp];j;j=l[j].next)//找topp点的临点,并进行比较 
	  {
		if(dis[l[j].af] > dis[topp]+l[j].we && !f[l[j].af])
		{
		  dis[l[j].af] = dis[topp]+l[j].we;
		  tmp.num=l[j].af;
		  tmp.diss=dis[l[j].af];
		  q.push(tmp);//放入优先队列 
		}
	  }
	}
}
//=================================================================
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);//输入
	for(int i=0;i<m;i++)
	{
	  int bee,aff,wee;
	  scanf("%d%d%d",&bee,&aff,&wee);
	  add(bee,aff,wee),add(aff,bee,wee); 
	}
	dj(s);
	printf("%d",dis[t]); //输出到t的最小值 
}
