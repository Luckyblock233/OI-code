//�㷨:ͼ��,���·
//����Ҫ�����u���ȵ�1���ٵ�v������·����
//������1��Ϊ���,��һ�����·�㷨
//��ĿҪ��ĳ��ȼ�Ϊ: 
//1�㵽u�����̳�,����1�㵽v�����̳�
//���,������� 

//ʹ�������ȶ����Ż���spfa 
#include<cstdio>
#include<queue>
#define INF 2147483647
using namespace std;
priority_queue<int>q;
struct edg//��� 
{
	int u,v,next;
	int w; 
} edge[5000500];
int head[3000000];
int ans[3000000],vis[3000000];
int n,m,num;
int s,t;
void build(int u,int v,int w)
{
	edge[++num].next=head[u];
	head[u]=num;
	edge[num].u=u;
	edge[num].v=v;
	edge[num].w=w;
}
void SPFA(int s)//����spfa 
{
	for(int i=1; i<=n; i++)//��ʼ�� 
	  ans[i]=INF,vis[i]=0;
	ans[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	  {
		int u=q.top();//ȡ������Ԫ�� 
		q.pop();
		vis[u]=0;
		for(int i=head[u]; i; i=edge[i].next)
		  {
			int v=edge[i].v;
			if(ans[v]>edge[i].w+ans[u])//�赼 
			  {
				ans[v]=edge[i].w+ans[u];
				if(!vis[v])//������� 
				  {
					q.push(v);
					vis[v]=1;
				  }
			  } 
		  }
	  }
}
int main()
{
	int s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1; i<=m; i++)
	  {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		build(a,b,c);
		build(b,a,c);
	  }
	SPFA(1);
	for(int i=1;i<=n/2;i++)
	  {
	  	int u,v;
	  	scanf("%d%d",&u,&v);
	  	printf("%d\n",ans[u]+ans[v]);
	  }
	return 0;
}
