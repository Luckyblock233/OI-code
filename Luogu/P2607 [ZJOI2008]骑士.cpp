//
/*
By:Luckyblock
*/
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define ll long long
const int MARX = 1e6+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<1];
int n,num, head[MARX],w[MARX];
int u1, v1, num1;
bool circle, used[MARX], vis[MARX], vis1[MARX], vis2[MARX];
ll ans, f[MARX][2], g[MARX][2];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)
{
	e[++num].u = u, e[num].v = v;
	e[num].ne = head[u], head[u] = num;
}
void cover(int u)
{
	used[u] = 1;
	for(int i = head[u]; i; i = e[i].ne)
	  if(!used[e[i].v]) cover(e[i].v);
}
void find_circle(int u,int fat)
{
	if(circle) return;
	vis[u] = 1;
	for(int i = head[u]; i; i = e[i].ne)
	  if(!vis[e[i].v]) find_circle(e[i].v,u);
	  else if(e[i].v != fat)
	  {
	  	u1 = e[i].u, v1 = e[i].v, num1 = i;
	  	circle = 1;
	  	return ;
	  }
}
void dfs1(int u)
{
	f[u][1] = w[u], vis1[u] = 1;
	for(int i = head[u]; i; i = e[i].ne)
	  if(!vis1[e[i].v] && (i^1 != num1))
	  {
	  	dfs1(e[i].v);
	  	f[u][0] += max(f[e[i].v][0],f[e[i].v][1]);
	    f[u][1] += f[e[i].v][0];
	  }
}
void dfs2(int u)
{
	g[u][1] = w[u], vis2[u] = 1;
	for(int i = head[u]; i; i = e[i].ne)
	  if(!vis2[e[i].v] && (i^1 != num1))
	  {
	  	dfs2(e[i].v);
	  	g[u][0] += max(g[e[i].v][0],g[e[i].v][1]);
	    g[u][1] += g[e[i].v][0];
	  }
}
//=============================================================
signed main()
{
	n = read();
	for(int i = 1, v; i <= n; i ++)
	{
	  w[i] = read(), v = read();
	  add(i,v), add(v,i);
	}
	
	for(int i = 1; i <= n; i ++)
	  if(!used[i])
	  {
	  	cover(i);
	  	circle = 0;
	  	find_circle(i,0);
	  	dfs1(u1); dfs2(v1);
	  	ans += max(f[u1][0], g[v1][0]);
	  }
	printf("%lld",ans);
}
