//知识点: 树上差分 
/*
By:Luckyblock
题目要求:
给定一棵 有n个点的树,点权值初始为0 
给出 n条路径, 对每一条路径上的除起点外的点 点权都+1
求 最后 每个点 的点权 

使用对点差分
先忽略 起点对答案的 影响 
对于每一条路径u->v , 求得 起点终点的 lca,
维护一个差分数组diff ,使diff[u]++,diff[v]++,diff[lca]--,diff[fa[lca]]--

当还原某点点权时, 
统计出 此点为根的 子树点权和,即为点权  

再考虑起点的影响
只需要把 作为起点的点 点权-1即可 
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
int n,num, way[MARX],head[MARX],diff[MARX];//差分数组diff 
int dep[MARX] , fa[MARX][32];//倍增求 lca变量 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)//建图 
{
	e[++num].u = u, e[num].v = v;
	e[num].ne = head[u], head[u] = num;
}
void dfs(int u,int fat)//dfs 倍增预处理,收集各信息 
{
	dep[u] = dep[fat]+1 , fa[u][0] = fat;//更新信息 
	for(int i=1; i<=30; i++) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v != fat) dfs(e[i].v,u);
}
int LCA(int fir,int sec)//倍增求 lca 
{
	if(dep[fir] < dep[sec]) std::swap(fir,sec);
	for(int i=25; i>=0; i--)//将fir,sec 跳到同一深度 
	  if(dep[fa[fir][i]] >= dep[sec])
	    fir = fa[fir][i];
	if(fir == sec) return fir;
	
	for(int i=25 ; i>=0; i--)//fir,sec同时上调 
	  if(fa[fir][i] != fa[sec][i])
	    fir = fa[fir][i], sec = fa[sec][i];
	return fa[fir][0];
}
void dfs1(int u,int fat)//dfs求子树和, 
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
	for(int i=1; i<n; i++)//枚举路径,进行差分 
	{
	  int lca = LCA(way[i],way[i+1]);
	  diff[way[i]] ++, diff[way[i+1]] ++;//差分 
	  diff[lca] --, diff[fa[lca][0]]--; 
	}
	dfs1(1,0);
	for(int i=2; i<=n; i++) diff[way[i]]--;//起点点权去重 
	for(int i=1; i<=n; i++) printf("%d\n",diff[i]);
}
