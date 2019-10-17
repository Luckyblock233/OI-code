//֪ʶ��: ���ϲ�� 
/*
By:Luckyblock
��ĿҪ��:
����һ�� ��n�������,��Ȩֵ��ʼΪ0 
���� n��·��, ��ÿһ��·���ϵĳ������ĵ� ��Ȩ��+1
�� ��� ÿ���� �ĵ�Ȩ 

ʹ�öԵ���
�Ⱥ��� ���Դ𰸵� Ӱ�� 
����ÿһ��·��u->v , ��� ����յ�� lca,
ά��һ���������diff ,ʹdiff[u]++,diff[v]++,diff[lca]--,diff[fa[lca]]--

����ԭĳ���Ȩʱ, 
ͳ�Ƴ� �˵�Ϊ���� ������Ȩ��,��Ϊ��Ȩ  

�ٿ�������Ӱ��
ֻ��Ҫ�� ��Ϊ���ĵ� ��Ȩ-1���� 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
const int MARX = 3e5+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<1];
int n,num, way[MARX],head[MARX],diff[MARX];//�������diff 
int dep[MARX] , fa[MARX][32];//������ lca���� 
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
	e[++num].u = u, e[num].v = v;
	e[num].ne = head[u], head[u] = num;
}
void dfs(int u,int fat)//dfs ����Ԥ����,�ռ�����Ϣ 
{
	dep[u] = dep[fat]+1 , fa[u][0] = fat;//������Ϣ 
	for(int i=1; i<=30; i++) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v != fat) dfs(e[i].v,u);
}
int LCA(int fir,int sec)//������ lca 
{
	if(dep[fir] < dep[sec]) std::swap(fir,sec);
	for(int i=25; i>=0; i--)//��fir,sec ����ͬһ��� 
	  if(dep[fa[fir][i]] >= dep[sec])
	    fir = fa[fir][i];
	if(fir == sec) return fir;
	
	for(int i=25 ; i>=0; i--)//fir,secͬʱ�ϵ� 
	  if(fa[fir][i] != fa[sec][i])
	    fir = fa[fir][i], sec = fa[sec][i];
	return fa[fir][0];
}
void dfs1(int u,int fat)//dfs��������, 
{
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v != fat) 
	  {
	    dfs1(e[i].v,u);
		diff[u] += diff[e[i].v];	
	  }
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1; i<=n; i++) way[i] = read();
	for(int i=1; i<n; i++)
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u);
	}
	dfs(1,0);
	for(int i=1; i<n; i++)//ö��·��,���в�� 
	{
	  int lca = LCA(way[i],way[i+1]);
	  diff[way[i]] ++, diff[way[i+1]] ++;//��� 
	  diff[lca] --, diff[fa[lca][0]]--; 
	}
	dfs1(1,0);
	for(int i=2; i<=n; i++) diff[way[i]]--;//����Ȩȥ�� 
	for(int i=1; i<=n; i++) printf("%d\n",diff[i]);
}
