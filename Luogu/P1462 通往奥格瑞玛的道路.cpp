//�㷨:���ִ�/ͼ��
/*
��ĿҪ�� ���������г����� ���� һ����ȡ�ķ��õ� ��Сֵ �Ƕ���
������Ŀ, ��Ȼ,�����㵥����,
����С�𰸺Ϸ�,�������Ĵ𰸶��Ϸ� 
�Ϳ���ʹ�ö��ִ𰸷�

���ִ�ö�� ����һ����ȡ�ķ��õ���Сֵ
��������Ϊһ������ x ,���ݸ��Ӻ���
���Ӻ�����,��һ��SPFA,
����ʧ��Ѫ��������ΪĿ��,
ͬʱ������ȡ���ô���x�ĳ���,���ɵ���.

����һ���,�жϵ���n�����ĵ�Ѫ���Ƿ�С�����Ѫ��
��������Ѫ����,֤������һ����ȡ�ķ��õ���СֵΪxʱ,���ɵ���
������ɵ���

���ֵõ����Ĵ𰸺�,���жϴ˴��Ƿ�Ϸ�
�Ϸ������,�������AFK 
*/ 
#include<cstdio>
#include<queue>
#include<algorithm> 
#define int long long
using namespace std;
const int MARX = 1e6+10;
const int INF = 2147483647;
struct edge
{
	int u,v,w,ne;
}a[MARX];
int n,m,b,maxcost;
int num;
int head[MARX],cost[MARX],cost1[MARX],dis[MARX];
bool vis[MARX]={0,1};
struct cmp1//�Զ������ȼ�,�Ż�SPFA 
{
	bool operator ()(const int a,const int b)
      {
        return dis[a]>dis[b];
      }
};
priority_queue <int,vector<int>,cmp1> s;//���ȶ����Ż�SPFA 
//========================================================================
void add(int u,int v,int w)
{
	a[++num].u=u,a[num].v=v,a[num].w=w;
	a[num].ne=head[u],head[u]=num;
}
bool judge(int x)//�ж��Ƿ�Ϸ� 
{
	if(cost[1]>x) return 0;//��㻨���Ƿ����x 
	for(int i=2;i<=n;i++) dis[i]=INF,vis[i]=0;//SPFA 
	s.push(1);
	while(!s.empty())
	  {
	  	int top=s.top();
	  	s.pop();
	  	vis[top]=0;
	  	for(int i=head[top];i;i=a[i].ne)
	  	  {
	  	  	int v=a[i].v,w=a[i].w;
	  	  	if(dis[v]>dis[top]+w && cost[v]<=x)//����һ����ȡ�ķ���<=x 
	  	  	  {
	  	  	  	dis[v]=dis[top]+w;
	  	  	  	if(!vis[v])
	  	  	  	{
				  s.push(v);
	  	  	  	  vis[v]=1;
	  	  	    }
			  }
		  }
	  }
	return dis[n]<b;
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&b);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld",&cost[i]);
	  	cost1[i]=cost[i];
	  }
	for(int i=1;i<=m;i++)//��ͼ 
	  {
	  	int u,v,w;
	  	scanf("%lld%lld%lld",&u,&v,&w);
	  	add(u,v,w),add(v,u,w);
	  }
	sort(cost1+1,cost1+n+1);
	int le=1,ri=n,mid;
	while(le<=ri)//���ִ� 
	  {
	  	mid=(le+ri)>>1;
	  	if(judge(cost1[mid])) ri=mid-1;
	  	else le=mid+1;
	  }
	if(!judge(cost1[le]))printf("AFK");//���ɵ������� 
	else printf("%lld",cost1[le]);
}
