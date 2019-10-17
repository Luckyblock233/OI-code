//֪ʶ��:�ֲ�ͼ,���· 
/*
By:Luckyblock
�ֲ�ͼ ,����˼��,
������ ��� ��ͬ�����Ƶ� ͼ, ����ͼ��ͼ֮���������
����ʵ�� �������ʵ�ͼ ֮���  ת��,
���� ͼ��ͼ ֮�� �����Ƶ�ת�� 

���� �����ͼʱ��ռ� ���Ķ��޴�, 
������õ� ���ݷ�Χ һ���С 

���ڱ���: 
���� ���ɻ��������зֲ�, �����֮��ת�ƴ������ɻ�
����֮�� ������ȨΪ0�� ����� 
����֮�� ������ȨΪԭֵ�� ����� 

֮�󼴿� �ӵ�0���s �ܵ�Դ���·
���� ����֮��� t, ·������Сֵ
��Ϊ ������ 
*/
#include<cstdio>
#include<queue>
#include<ctype.h>
#define min(a,b) (a<b?a:b)
#define int long long
const int MARX = 2e6+10;
const int INF = 0x7ffffffff;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<2];
struct p//���Ż�dj ,�Զ������ȼ� 
{
	int num,diss;
	bool operator < (const p &a) const {return diss > a.diss;}
}tmp;
int n,m,k,s,t,ans=INF, num,head[MARX],dis[MARX];
bool f[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v,int w)//��ͼ 
{
	e[++num].u = u, e[num].v = v, e[num].w = w;
	e[num].ne = head[u], head[u] = num;
}
void djkstra(int start)//dj�� ��0��s ����k��t �����· 
{
	std::priority_queue <p> q;
	tmp.num = start, tmp.diss = 0; q.push(tmp);
	for(int i=0; i<=n*(k+1); i++) dis[i] = INF;//�����в�����е� ����ֵ 
	dis[start]=0;//��ʼ�� 
	
	while(!q.empty())//���Ż�dj 
	{
	  int top=q.top().num; q.pop();
	  if(f[top]) continue;
	  f[top]=1;
	  for(int j=head[top]; j; j=e[j].ne)//��k����ٵ�, �����бȽ� 
		if(dis[e[j].v] > dis[top] + e[j].w)//�������· 
		{
		  dis[e[j].v] = dis[top] + e[j].w;
		  tmp.num = e[j].v , tmp.diss = dis[e[j].v];
		  q.push(tmp);
		}
	}
}
//=============================================================
signed main()
{
	n = read(), m = read(), k = read();
	s = read(), t = read();
	for(int i = 1; i <= m; i ++)
	{
	  int u = read(), v = read(), w = read();
	  add(u,v,w), add(v,u,w);
	  for(int j = 1; j <= k; j ++)//���� ���ɻ��������зֲ�
	  {
	    add(u + n*(j-1) , v + n*j , 0);//����֮�� ������ȨΪ0�� ����� 
	    add(v + n*(j-1) , u + n*j , 0);
	    add(u + n*j , v + n*j , w);//����֮�� ������ȨΪԭֵ�� ����� 
	    add(v + n*j , u + n*j , w);
	  }
	}
	djkstra(s);
	for(int i=0; i<=k ;i++) 
	  ans = min(ans,dis[t + i*n]);//����С�� 
	printf("%lld",ans);
}
