//֪ʶ�� :ͼ�� 
/*
By:Luckyblock
��������:
������ָ��: ·���ϵ����е�ĳ��� , 
��ָ��ĵ㶼ֱ�ӻ������յ���ͨ 

����Ҫ����ֱ�ӻ������յ���ͨ�ĵ� , 
�����Ϸ��㶼��ͼ��ɾ��.

ֱ��Ѱ�����յ㲻ֱ�Ӽ����ͨ�ĵ� �Ƚ��鷳
���ǿ��Խ���ת��,
��Ѱ�� ֱ�Ӽ�����յ������ĵ�. 


�㷨ʵ��:
ҪѰ��ֱ�Ӽ�����յ������ĵ�,
����ͨ�����յ㷴��BFS��ʵ��.

�Ƚ� ���յ�ֱ����ͨ�ĵ�������,
֮�� �ٽ�������еĵ������ӵĵ� �������
�������еĵ����,������ʱ�Ϸ�.

����ʱ�Ϸ��� ����,������һЩ �벻�Ϸ��ĵ�ֱ�������ĵ�
����Ҳ�ǲ��Ϸ���
���Ի�Ҫö�ٲ��Ϸ��ĵ�, ��û�б�������ʱ�Ϸ���ǵĵ�
��������ֱ�������ĵ����ʱ�Ϸ����ȥ��.

��������Ȼ���ڱ�ǵĵ�,
����������һ�� ���·����. 
*/
#include<cstdio>
#include<queue>
#include<ctype.h>
#define int long long
const int INF = 2e9+7;
const int MARX = 1e4+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<5];
int n,m,st,to , head[MARX],dis[MARX];//��ͼ 
bool vis[MARX],ju[MARX];//��ǺϷ��� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void bfs()//bfs��úϷ��� 
{
    std::queue <int> qu; qu.push(to);
	while(!qu.empty())//���յ�Ϊ��� , ���з���bfs 
	{
	  int top=qu.front();
	  qu.pop();
	  for(int i=head[top]; i; i=e[i].ne)//ö�ٳ��� 
	    if(!ju[e[i].v])
		{
	  	  ju[e[i].v]=1;//������ʱ�Ϸ���� 
	  	  qu.push(e[i].v);
	 	}
	}
	ju[to]=1;//����Ϸ� 
	bool jud[MARX]={0};
	for(int i=1; i<=n; i++)
	  if(!ju[i])//�޳� �벻�Ϸ��ĵ����ڵ���ʱ�Ϸ��� 
	    for(int j=head[i]; j; j=e[j].ne)
		  jud[e[j].v]=1;//�򲻺Ϸ���� 
	for(int i=1; i<=n; i++)//ȥ���Ϸ���� 
	  ju[i]=( jud[i]?0:ju[i] );
}
void spfa()//���·ģ�� 
{
	for(int i=1; i<=n; i++) dis[i]=INF * ju[i];//��ʼ�� 
	std::queue <int> qu; qu.push(to);
	dis[to]=0 , vis[to]=1;
	while(!qu.empty())//spfa 
	{
	  int u=qu.front(); 
	  qu.pop();
	  vis[u]=0;
	  for(int i=head[u]; i; i=e[i].ne)
	  	if(ju[e[i].v] && dis[u]+1<dis[e[i].v])
	  	{
	  	  dis[e[i].v]=dis[u]+1;
	  	  if(!vis[e[i].v]) qu.push(e[i].v);
	  	  vis[e[i].v]=1;
		}
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)//��ͼ 
	{
	  int u=read(),v=read();
	  e[i].u=v , e[i].v=u;
	  e[i].ne=head[e[i].u],head[e[i].u]=i;
	}
	st=read(),to=read();
	bfs();
	if(ju[st])//���Ϸ� 
	{
	  spfa();
	  printf("%lld",dis[st]==INF?-1:dis[st]);
	  return 0;
	}
	printf("-1");
}
