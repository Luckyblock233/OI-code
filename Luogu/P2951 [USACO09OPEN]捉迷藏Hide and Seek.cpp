//�㷨:ͼ��/���·
//˼·:��ĿҪ�����������·�������,�����1��Զ�ĵ� 
//�������·�㷨,
//������㵽���1�����·��
//���ҵ��������,��ͳ����������

//���˶��Ż���dj�㷨 
#include<cstdio>
#include<queue>
using namespace std;
int n,m;
struct line//��� 
{
	int u,v,ne;
}a[100010];
struct p//�Զ������ȼ� 
{
	int num,diss;
	bool operator <(const p &aa) const
	  {
		return diss > aa.diss;
	  }
};
int head[20010];
int f[20010],dis[20010];
int num;
int ans1,ans2,ans3;
priority_queue <p> q;
//============�����뺯���ľ���===================================
void add(int u,int v)//�ڽӱ�ӱ� 
{
	a[++num].u=u;
	a[num].v=v;
	a[num].ne=head[u];
	head[u]=num;
}
void dj(int s)
{
	for(int i=1;i<=n;i++)//��ʼ�� 
	  f[i]=0,dis[i]=2147483640;
	dis[1]=0;
	p tmp;
	tmp.num=1,tmp.diss=0;
	q.push(tmp);//������� 
	while(!q.empty())
	  {
	  	int topp=q.top().num;//ȡ������ 
	  	q.pop();
	  	if(f[topp]) continue;
	  	f[topp]=1;
	  	for(int i=head[topp];i;i=a[i].ne)//�赼 
	  	  {
	  	  	if(dis[topp]+1<dis[a[i].v] && !f[a[i].v])
	  	  	  {
	  	  	  	dis[a[i].v]=dis[topp]+1;//������� 
	  	  	  	tmp.num=a[i].v,tmp.diss=dis[a[i].v];
	  	  	  	q.push(tmp);
			  }
		  }
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)//���� 
	  {
	  	int u,v;
	  	scanf("%d%d",&u,&v);
	  	add(u,v);
	  	add(v,u);
	  }
	dj(1);
	for(int i=1;i<=n;i++)//Ѱ�Ҵ� 
	  {
	  	if(dis[i]>ans2) ans1=i,ans2=dis[i],ans3=0;
	  	if(dis[i]==ans2) ans3++;
	  }
	printf("%d %d %d",ans1,ans2,ans3);
}
