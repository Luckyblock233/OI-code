//֪ʶ��:���ִ�,01���· 
/*
By:Luckyblock
��ĿҪ��:
���� һ��Ȩ����ͼ,
�ɽ� ͼ��k���� ��Ȩ����
Ҫʹ: ��1 -->n ·���� ��ı�Ȩֵ��С
�� ��С�� ��ı�Ȩֵ.

��������:
��Ȼ, �����㵥����, 
���Զ� ��ı�Ȩֵ���� ���ִ�ö�� 

����ö�ٳ� ��ı�Ȩֵ.
��μ�� ö�����ĺϷ���?
- ���� С�ڵ���ö������ ��Ȩֵ����Ӱ�� ��ı�Ȩֵ
  �� ���ǶԴ���ȷ�Ե��ж� �޹���.

- ���� ����ö������ ��Ȩֵ
  ��� ����Ҫ������, �ͻ�Ӱ�� ��ı�Ȩֵ 
  ����� ����һ�λ��Ὣ���Ȩֵ����
  
  ��Ȼ, ����� ʹ�ñ�Ȩ����Ļ��� > k,
  ��֤�� �������ӷ������Ϸ�
  
����ͳ�ƴ�1->n·����, ��ö������ı� �� ���ٵĸ���
��� �� ����ö������ ��Ȩֵ����1, ��������0; 
�������·�㷨 , ��õ�1-->n �� "��̾���" 
�� 1-->n ·���� ��ö������ı� �� ���ٵĸ���

ͨ�� ����õ����ٸ��� �� k���бȽ�, ��ɼ��ö�����ĺϷ��� 

�����ⷨ: 
���ڴ��� n,k��С, Ҳ���Կ��ǽ����ֲ�ͼ,���������· �㷨 
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<ctype.h>
#define int long long
const int MARX = 1e3+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[20*MARX];
int n,p,k,num,ans , head[MARX],dis[MARX];
bool vis[MARX];
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
bool check(int maxx)//��� ����ȨΪmaxxʱ�ĺϷ��� 
{
	std::priority_queue <std::pair<int,int> > q;//dij���·Ԥ���� 
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1] = 0 ;//��1Ϊ��� 
	q.push(std::make_pair(0,1));
	
	for(; !q.empty(); )//dij ���· 
	{
	  std::pair <int,int> top = q.top();  q.pop();
	  if(vis[top.second]) continue;
	  vis[top.second] = 1;
	  
	  for(int i=head[top.second]; i; i = e[i].ne)
	    if(dis[e[i].v] > dis[e[i].u] + (e[i].w>maxx))
	    {
	      //����ö������ ��Ȩֵ����1, ��������0; 
	      dis[e[i].v] = dis[e[i].u] + (e[i].w>maxx);
	      q.push(std::make_pair(-dis[e[i].v], e[i].v));
		}
	}
	
	return dis[n] <= k;//���Ϸ��� 
}
//=============================================================
signed main()
{
	n = read(), p = read(), k = read();
	for(int i=1; i<=p; i++) 
	{
	  int u = read(), v = read(), w = read();
	  add(u,v,w), add(v,u,w);
	}
	
	if(check(0)) {printf("0"); return 0;}
	for(int l=1,r=1e6+10; l<=r;)//���ִ� 
	{
	  int mid = (l+r) >> 1;
	  if(check(mid)) ans = mid, r = mid - 1; 
	  else l = mid + 1;
	}
	printf("%lld",ans==0?-1:ans);
}
