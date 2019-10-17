//本题目比较特殊,易超时, 用了dj算法堆优化+邻接表
//但要注意此题,需要枚举每一个点
//并求所有奶牛到达此点的距离总和
//再将求出的和值找出最小值,并输出. 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int MAXX=2147483647;//最大值 
using namespace std;
struct line
{
	int be,af,we;//分存前点 后点 权重 
	int next;
}l[3000];
struct p
{
	int num,diss;
	bool operator < (const p &a) const
	  {
	  	return diss > a.diss;
	  }
};
int head[810];
int num=0;
int dis[810];//存最小距离 
bool f[810];
int cow[810]; 
int n1,m,n,x;
int sum,minn=MAXX;
void add(int bee,int aff,int wee)//邻接表加入元素 
{
	l[++num].next=head[bee];
	l[num].be=bee;
	l[num].af=aff;
	l[num].we=wee;
	head[bee]=num;
}
void dj(int s);
int main()
{
	scanf("%d%d%d",&n1,&n,&m);//输入
	for(int i=1;i<=n1;i++)//输入奶牛数,并将其累加到cow数组中 
	  {
	  	scanf("%d",&x);
	  	cow[x]++;
	  } 
	for(int i=0;i<m;i++)//输入边 
	  {
	  	int bee,aff,wee;
	  	scanf("%d%d%d",&bee,&aff,&wee);
	  	add(bee,aff,wee);//注意双向 
	  	add(aff,bee,wee);
	  }
	for(int i=1;i<=n;i++)//以每一个点为起点,都找一遍 
	  dj(i);
	printf("%d",minn);//输出 最小值 
}
void dj(int s)
{
	memset(f,0,sizeof(f));
	priority_queue <p> q;
	p tmp;
	tmp.num=s,tmp.diss=0;
	for(int i=1;i<=n;i++)
	  dis[i]=MAXX;//赋极值 
	dis[s]=0;//初始化 
	q.push(tmp);
	while(!q.empty())
	  {
	  	int topp=q.top().num;
	  	q.pop();
	  	if(f[topp])
	  	  continue;
	  	f[topp]=1;
		for(int j=head[topp];j;j=l[j].next)//找topp点的临点,并进行比较 
		  {
		  	if(dis[l[j].af] > dis[topp]+l[j].we && !f[l[j].af])
		  	  {
		  	  	dis[l[j].af] = dis[topp]+l[j].we;
		  	  	tmp.num=l[j].af;
		  	  	tmp.diss=dis[l[j].af];
		  	  	q.push(tmp);//将tmp加入队列中 
			  }
		  }
	  }
	for(int i=1;i<=n;i++)
	  sum+=dis[i]*cow[i];//计算总距离和 
	minn=min(sum,minn);
	sum=0;
}
