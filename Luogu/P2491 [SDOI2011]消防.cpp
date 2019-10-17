//֪ʶ��:����ֱ��, �������� 
/*
By:Luckyblock
P1099 �����ĺ� �� ���ݼ�ǿ�� 

��ĿҪ��: 
����һ����, ���б�Ȩ
��һ�� �߳��Ⱥ�<=s ��·��, 
ʹ�������е� ������·���ľ���� ���ֵ��С��

��������:

- ��һ��Ȼ�� ����:
  ���� �������ϵĽڵ�, ��������Զ�ĵ� һ��Ϊ����ֱ���Ķ˵� 
  ֤��:
  1. ����ֱ����һ��x,  
     �� ����ֱ�������˵� �ľ���ֱ�Ϊ: x1,x2, ����x1 > x2
	 �� �����ֱ���ϵĵ� �о�����Զ�� ��ľ��� Ϊy
	 ���Ȼ�� x1 > y
	
	 ���Է�֤: 
	 �� y > x1, ��  x1 + y > x1 + x2
	 ��Ӧѡ�� x1 �� y ��Ϊ ֱ��, ���� x1 �� x2
	 ��֤ ������ȷ 
	 
  2.��P����ֱ���ϣ�ʹ�÷�֤����
    �����ʱWQ����ֱ����AB��ֱ��

	��AB��PQ�н���C������P��Q��Զ��
	��ô PC+CQ>PC+CA������CQ>CA���׵� CQ+CB>CA+CB����CQ+CB>AB��
	��AB��ֱ��ì�ܣ�������������ͼ
	
  3.��AB��PQû�н��㣬MΪAB������һ�㣬NΪPQ������һ�㡣
    ���Ȼ���NP+NQ>NQ+MN+MB��ͬʱ����NQ����NP>MN+MB��
	��֪NP+MN>MB������NP+MN+MA>MB+MA����NP+MN+MA>AB��
	��AB��ֱ��ì�ܣ������������Ҳ������
	
  - ��� ���������ֱ��, ����¼����ֱ���ϵĵ�
  	ʹ��DFS�����Ϊ����
  	֮��Ϳ��� ö������ֱ���� ����<=s�ĺϷ����� 

- ���Է��� һЩ����:
  ���̶�����һ�˵�, ������һ��Ѱ�� �Ϸ��Ķ˵�
  �� ���̶��˵� ����, ����һ�˵� ��Ȼ������
	 
  ���˵�� λ�ñ仯�����㵥����
  �����ʹ�� ˫ָ��(��ȡ��) ��ö��ÿһ������

- ����ÿһ�� �Ϸ�����, 
  ������ �������е� ������·���ľ�������ֵ? 
  ��·����ĵ� ���з�������:
  1.������ֱ���ϵĵ�,
  	��Ȼ, ֱ���Ķ˵� ��������� �ȷǶ˵�Զ
	
	��ֻ�迼�� ֱ�����˵� ���������Ӧ���˵�� ���� 
    ���Զ� ֱ���ϵĵ�ά��һǰ׺�� ������O(1)��ѯ
	
  2.������ֱ����ĵ�,
  	��Ȼ, ��ֱ���� �����������ĵ� ��������ʱ,
	���п��� ��������
	���� ѡ��ֱ���Ķ˵� ��Ȼ��ѡ�� ������
	
	����� ά�� ��ÿ��ֱ���ϵĵ�Ϊ���, ������ֱ����������, �ܵ���ĵ�� ��Զ����
	�� ö������ʱ ά�� ��ѡ��·���ϵĵ� ��Զ��ֱ����ĵ� 
	��Ȼ��һ������������ֵ����
	����ʹ�õ�������ά�� 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<queue>
#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int INF = 1e15+7;
const int MARX = 3e5+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<1];
int n,num, s,u,v,head[MARX];//��ͼ����
int dis[MARX], pre[MARX],map[MARX];//������ֱ��, dis��¼����,  pre��¼·��, map��ֱ���������ڵ�ľ���  
int ans = 1e15, sum[MARX], dis1[MARX];//sum��¼ֱ���Ͼ����ǰ׺��, dis1��¼ֱ���ϵ�i�� ֱ����������� 
int que[MARX]={INF},t=0, h=0;//��������- 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v,int w)
{
	e[++num].u = u,e[num].v = v, e[num].w = w;
	e[num].ne = head[u], head[u] = num;
}
void dfs(int now,int fat,int sum,bool flag)//dfs��� ����ֱ�� 
{
	if(flag) pre[now] = fat, map[now] = sum;//�ڶ���dfs��¼·�� (ǰ�� 
	dis[now] = dis[fat] + sum;//���¾��� 
	for(int i = head[now]; i; i = e[i].ne)
	  if(e[i].v != fat) dfs(e[i].v,now,e[i].w,flag);
}
void get_road()//��� ����ֱ�� 
{
	dfs(1,0,0ll,0); //һ��dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//ѡ�� ������Զ�ĵ� 
	  if(dis[i] > maxdis) u = i,maxdis = dis[i];
	dfs(u,0,0ll,1); //����dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//ѡ�� ������Զ�ĵ� 
	  if(dis[i] > maxdis) v = i,maxdis = dis[i];
}
void bfs()//bfs���� ��ÿ��ֱ���ϵĵ�Ϊ���, ������ֱ����������, �ܵ���ĵ�� ��Զ����
{
	memset(dis,63,sizeof(dis));
	std::queue <int> q,from;
	for(int i = v; i != 0; i = pre[i]) //��ֱ���ϵĵ���� ���� 
	  q.push(i), from.push(i), dis[i] = 0;
	  
	for(; !q.empty();)
	{
	  int now = q.front(),fr = from.front(); q.pop(),from.pop();
	  for(int i = head[now]; i ; i = e[i].ne)//ö�ٳ��� 
	    if(dis[e[i].v] >= INF)//δ�����¹� 
	    {
	      dis[e[i].v] = dis[now] + e[i].w;//������Զ���� 
	      dis1[fr] = max(dis1[fr],dis[e[i].v]);
		  q.push(e[i].v),from.push(fr);
		}
	}
}
void solve()
{
	pre[n+1] = v;
	for(int i = n + 1; i != 0; i = pre[i]) //Ԥ����ǰ׺�� 
	  sum[pre[i]] = sum[i] + map[i];
	
	for(int l = v,r = v; l != 0 && r!=u; l = pre[l])//��r=uʱֹͣö��,֮��ö�ٵ����䶼���Ϸ� 
	{
	  int last = r; ++h;
	  while(sum[r] - sum[l] <= s && r != 0) //ö���Ҷ˵� 
	  {
	  	last = r, r = pre[r];
	  	if(r != 0 && sum[r] - sum[l] <= s)//�������и��� 
	  	{
	  	  for(;dis1[r] >= que[t] && t >= h;) t--;
	  	  que[++t] = dis1[r];	
		}
	  }
	  if(r == 0 || sum[r] - sum[l] > s) r = last;//Խ�紦�� 
	  
	  int now = max(sum[l] , sum[u] - sum[r]);//���´� 
	  now = max(now, que[h]);
	  ans = min(now, ans);
	}
}
//=============================================================
signed main()
{
	n = read(), s = read();
	for(int i = 1; i < n ;i ++)
	{
	  int u1 = read(), v1 = read(), w1 = read();
	  add(u1,v1,w1), add(v1,u1,w1);
	}
	get_road(); bfs(); solve();
	printf("%lld",ans);
}
/*
6 1000
1 2 999
2 3 100
3 4 1000
3 5 100
5 6 999
*/ 
