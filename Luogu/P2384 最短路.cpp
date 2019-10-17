//本题使用dijkstra算法的堆优化+邻接表,才避免了超时 
/* 
基本思想与普通的dj相同,但在寻找最小的距离值时使用了优先队列
这样就可以删去一层循环, 变为直接区队首元素.
为了使用优先队列,定义一个结构体p来存编号与距离最小值
并按照 距离最小值升序排列
即可大大降低时间复杂度. 
在求最小积值时,直接%9987即可
最后秩序输出余数 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int MAXX=9987;//最大值 
using namespace std;
struct line
{
	int be,af,we;//分存前点 后点 权重 
	int next;
}l[1000010];
struct p
{
	int num,diss;
	bool operator < (const p &a) const
	  {
	  	return diss > a.diss;
	  }
};
int head[1010];
int num=0;
int dis[1010];//存最小距离 
bool f[1010]; 
int n,m,s,x;
void add(int bee,int aff,int wee)//邻接表加入元素 
{
	l[++num].next=head[bee];
	l[num].be=bee;
	l[num].af=aff;
	l[num].we=wee%9987;
	head[bee]=num;
}
void dj(int s);
int main()
{
	scanf("%d%d",&n,&m);//输入
	for(int i=0;i<m;i++)
	  {
	  	int bee,aff,wee;
	  	scanf("%d%d%d",&bee,&aff,&wee);
	  	add(bee,aff,wee);
	  }
	dj(1);
	printf("%d",dis[n]);
}
void dj(int s)
{
	memset(f,0,sizeof(f));
	priority_queue <p> q;//优先队列 
	p tmp; 
	tmp.num=s,tmp.diss=0;
	for(int i=1;i<=n;i++)
	  dis[i]=MAXX;//赋极值 
	dis[s]=1;//初始化 
	q.push(tmp);
	while(!q.empty())
	  {
	  	int topp=q.top().num;//取头元素 
	  	q.pop();//删 
	  	if(f[topp])
	  	  continue;
	  	f[topp]=1;
		for(int j=head[topp];j;j=l[j].next)//找topp点的临点,并进行比较 
		  {
		  	if(dis[l[j].af] > dis[topp]*l[j].we && !f[l[j].af])
		  	  {
		  	  	dis[l[j].af] = (dis[topp]*l[j].we)%9987;
		  	  	tmp.num=l[j].af;
		  	  	tmp.diss=dis[l[j].af];//加入队列 
		  	  	q.push(tmp);
			  }
		  }
	  }
}
