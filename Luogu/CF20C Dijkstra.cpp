//֪ʶ��:���· 
/*
Ҫ���¼���·��·��

��Ҫ�������·ʱ , ��¼�赼ÿ�������ת��
�����յ㿪ʼ��ǰѰ��
������ת�����, һֱ�ҵ����

�ٷ���������� 
���ע�� 
*/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long 
const int INF = 0x7fffffffff;//���ֵ 
const int MARX = 1e5+10;
using namespace std;
//=============================================================
struct edge
{
	int u,v,w,ne;//�ִ�ǰ�� ��� Ȩ�� 
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
void add(int u,int v,int w)//�ڽӱ����Ԫ�� 
{
	e[++num].ne=head[u],head[u]=num;
	e[num].u=u,e[num].v=v,e[num].w=w;
}
void dj(int s)
{
	priority_queue <p> q;
	tmp.num=s,tmp.diss=0;q.push(tmp);
	for(int i=1;i<=n;i++) dis[i]=INF;//����ֵ 
	dis[s]=0;//��ʼ�� 
	while(!q.empty())
	{
	  int top=q.top().num; q.pop();
	  if(f[top]) continue;
	  f[top]=1;
	  for(int j=head[top];j;j=e[j].ne)//��k����ٵ�,�����бȽ� 
	  {
		if(dis[e[j].v] > dis[top]+e[j].w && !f[e[j].v])
		{
		  pre[e[j].v]=top;//��¼��ת��,��·�� 
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
	scanf("%lld%lld",&n,&m);//����
	for(int i=1;i<=m;i++)
	{
	  int u,v,w;
	  scanf("%lld%lld%lld",&u,&v,&w);
	  add(u,v,w);add(v,u,w);
	}
	dj(s);
	int num1=0;
	for(int i=n;i>1;i=pre[i]) ans[++num1]=i;//����Ѱ��·�� 
	if(pre[ans[num1]]!=1)//�޽����,1��n����ͨ 
	{
	 printf("-1");
	 return 0;
	}
	printf("1");//���·�� 
	for(int i=num1;i>=1;i--) printf("%d",ans[i]);
}
