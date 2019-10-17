//经典裸spfa的模板题目,不再赘述 
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int INTMAX=2147483647;
int po[1000][3];
double map[1000][1000];//初始化 
bool vis[1000];
double dis[1000];
int n,m,s,t;
void spfa();
int main()
{
	scanf("%d",&n);//输入 
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&po[i][1],&po[i][2]);
	memset(map,INTMAX,sizeof(map));
	scanf("%d",&m);
	for(int i=1;i<=m;i++)//输入边 
	  {
	  	int a,b;
	  	scanf("%d%d",&a,&b);
	  	map[a][b]=map[b][a]=sqrt( ( (po[a][1]-po[b][1])*(po[a][1]-po[b][1]) )+( (po[a][2]-po[b][2])*(po[a][2]-po[b][2]) ) );
	  }
	scanf("%d%d",&s,&t);
	spfa();
	printf("%.2lf",dis[t]);
}
void spfa()//经典spfa 
{
	for(int i=1;i<=n;i++)//赋初值 
	  dis[i]=INTMAX;
	queue<int> q;//队列 
	q.push(s);
	dis[s]=0;//初始化 
	vis[s]=1;
	while(!q.empty())//当队列不为空 
	  {
	  	int u=q.front();//取最前 
	  	q.pop();//删了他 
	  	vis[u]=0;//置零,表示次点离开队列 
	  	for(int v=1;v<=n;v++)//找n个点 
	  	  {
	  	  	if(map[u][v]!=INTMAX)
	  	  	  {
	  	  	  	if(dis[u]+map[u][v]<dis[v])//疏松 
	  	  	  	  {
	  	  	  	  	dis[v]=dis[u]+map[u][v];
	  	  	  	  	if(!vis[v])//压入队列中 
	  	  	  	  	  {
	  	  	  	  	  	q.push(v);
	  	  	  	  	  	vis[v]=1;//置一 
					  }
				  }
			  }
		  }
	  }
}
