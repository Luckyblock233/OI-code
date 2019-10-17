//֪ʶ��:BFS/ͼ��
/*
����õ���ÿ����� ���· ������
��Ȼ,
ÿ��������·���� = ���и��׵�����·���� ֮�� 
���б�Ȩֵ��Ϊ1
���Կ���ͨ��BFS����� 
 
�����ʵ�����ڵ�ʱ��
����ǵ�һ�η��ʣ�
�����Ǵ����1 ��ʼBFS,
����֮ǰ���ʵ�ʱ��,·�����Ȳ����֮�����С 
������ڵ�Ĵ�+=�����ڵ�Ĵ𰸣�
�����˽ڵ���ӣ�

����ǵڶ��η���
�ҵ�ǰ�ľ������֮ǰ��¼�ľ��룬
˵�����ǵڶ������·��
ͬ����������ڵ�Ĵ�+=�����ڵ�Ĵ𰸣�
������Ҫ����ˡ�
*/ 
#include<cstdio>
#include<ctype.h>
#include<queue>
#include<algorithm>
const int MARX = 1e6+10;
const int INF = 2147483647;
//=============================================================
struct edge
{
	int v,ne;
}a[MARX*2];
int head[MARX],dis[MARX],ans[MARX]={0,1};
bool vis[MARX];
int n,m,x,y,num;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)//��ͼ 
{
	a[++num].ne=head[u],a[num].v=v,head[u]=num;
}
void bfs()//BFS 
{
	for(int i=2; i<=n; i++) dis[i]=INF;
	std::queue <int> s; s.push(1);
	while(!s.empty())
	{
	  int top=s.front();
	  s.pop();
	  for(int i=head[top]; i; i=a[i].ne)
	  {
	  	int v=a[i].v;
		if(dis[v] >= dis[top]+1)
		{
		  if(dis[v] == dis[top]+1)//���´� 
			ans[v] = (ans[v]+ans[top])%100003;
		  if(dis[v] > dis[top]+1) //���´𰸲���� 
		  {
			dis[v] = dis[top]+1,
			ans[v] = ans[top]%100003,
			s.push(v);
		  }
		}
	  }
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<=m; i++)//��ͼ 
	{
	  x=read(),y=read();
	  add(x,y),add(y,x);
	}
	bfs();
	for(int i=1; i<=n; i++) 
	  printf("%d\n",ans[i]%100003);
}
