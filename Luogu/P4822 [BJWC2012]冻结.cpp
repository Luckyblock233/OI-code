//֪ʶ��:�ֲ�ͼ,���· 
/*
By:Luckyblock
��Ŀ��������:
����ʹ��Ȩֵ��Ϊ ԭ��Ȩ��һ��
����<=50, �� ��������<=50 

����Ȼ�� �ֲ�ͼ���� 
���� ���б�Ȩ����������зֲ�, �����֮��ת�ƴ����Ȩ������� 
����֮�� ������ȨΪ0�� ����� 
����֮�� ������ȨΪԭֵ�� ����� 

֮�󼴿� �ӵ�0���1 �ܵ�Դ���·
���� ����֮��� n, ·������Сֵ
��Ϊ ������ 
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<ctype.h>
#define min(a,b) (a<b?a:b)
const int MARX = 220010;
//=============================================================
struct edge
{
	int u,v,ne,w;
}e[20*MARX];
struct p//���Ż�dj ,�Զ������ȼ� 
{
	int num,diss;
	bool operator < (const p &a) const {return diss > a.diss;}
}tmp;
int n,m,k,s,t, num,head[MARX];
int ans,dis[MARX];
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
	memset(dis,0x3f,sizeof(dis));
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
	s = 1, t = n;
	for(int i = 1; i <= m; i ++)
	{
	  int u = read(), v = read(),w = read();
	  add(u,v,w), add(v,u,w);
	  for(int j = 1; j <= k; j ++)//���� ���ɻ��������зֲ�
	  {
	    add(u + n*(j-1) , v + n*j , w/2);//����֮�� ������ȨΪԭ��Ȩ1��� ����� 
	    add(v + n*(j-1) , u + n*j , w/2);
	    add(u + n*j , v + n*j , w);//����֮�� ������ȨΪԭֵ�� ����� 
	    add(v + n*j , u + n*j , w);
	  }
	}
	djkstra(s);
	ans = 2e9+7;
	for(int i=0; i<=k ;i++) ans = min(ans,dis[t + i*n]);//����С�� 
	printf("%d",ans);
}
