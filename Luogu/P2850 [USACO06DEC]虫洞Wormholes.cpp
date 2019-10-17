//֪ʶ��:SPFA/��Ȩ��/BFS 
/*
spfa bfs�� �и�Ȩ��

�ڽ���spfa��ͬʱ,��¼ÿ���� �������·���еĳ��ִ���
����ִ��� = �丸�׵���ִ���+1
��֪,����һ���޸�Ȩ��ͼ,

ÿ����ĳ��ִ���<=n
��:�����һ����ĳ��ִ���>n,
��֤�������˸�Ȩ�� 
*/ 
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MARX = 1e5+10;
const int INF = 2147483647;
struct edge
{
	int u,v,w,ne;
}a[MARX];
int f,n,m,w,num;
int head[MARX],dis[MARX],cnt[MARX];
bool vis[MARX];
void add(int u,int v,int w)
{
	a[++num].v=v,a[num].w=w;
	a[num].ne=head[u],head[u]=num;
}
bool spfa_bfs(int s)
{
	queue <int> q;
	dis[s]=0,cnt[s]=1,vis[s]=1;
	q.push(s);
	while(!q.empty())
	  {
	  	int u=q.front();
	  	q.pop();
	  	vis[u]=0;
	  	for(int i=head[u];i;i=a[i].ne)
	  	  {
	  	  	int v=a[i].v,we=a[i].w;
	  	  	if(dis[v]>dis[u]+we)
	  	  	  {
	  	  	  	dis[v]=dis[u]+we;
	  	  	  	cnt[v]=cnt[u]+1;//���´��� 
	  	  	  	if(cnt[v]>n) return 1;//�ж� 
	  	  	  	if(!vis[v])
	  	  	  	  {
	  	  	  	  	q.push(v);
	  	  	  	  	vis[v]=1;
				  }
			  }
		  }
	  }
	return 0;
}
int main()
{
	scanf("%d",&f);
	while(f--)
	  {
	  	
	  	memset(a,0,sizeof(a));
	  	num=0;
	    scanf("%d%d%d",&n,&m,&w);
		for(int i=1;i<=n;i++) dis[i]=INF,head[i]=vis[i]=0;
	    int u,v,we;
		for(int i=1;i<=m;i++)//����,���� 
	      {
	      	scanf("%d%d%d",&u,&v,&we);
	      	add(u,v,we),add(v,u,we);
		  }
	  	for(int i=1;i<=w;i++)
	  	  {
	  	  	bool flag=0;
	  	  	scanf("%d%d%d",&u,&v,&we);
			add(u,v,-we);
		  }
		int fl=0;
		for(int i=1;i<=n;i++)
		  if(spfa_bfs(i))//���ڸ��� 
		    {
		      printf("YES\n");
		      fl=1;
		      break;
			}
		if(!fl) printf("NO\n");
	  }
}
