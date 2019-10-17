//
/*
By:Luckyblock
*/
#include<cstdio>
#include<ctype.h>
#define ll long long
const int INF = (1<<30);
const int MARX = 1e4+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<4];
int n,m,num, head[MARX],dis[MARX];
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
	e[++num].u = u, e[num].v = v, e[num].w = w;
	e[num].ne = head[u], head[u] = num;
}
bool spfa(int u)
{
	vis[u] = 1;
	for(int i = head[u]; i; i = e[i].ne)
	  if(dis[e[i].v] < dis[u] + e[i].w)
	  {
	  	dis[e[i].v] = dis[u] + e[i].w;
	  	if(vis[e[i].v]) return 0;
	  	if(!spfa(e[i].v)) return 0;
	  }
	vis[u] = 0;
	return 1;
}
//=============================================================
signed main()
{
	n = read(), m = read();
	for(int i = 1; i <= m; i ++)
	{
	  int opt = read(),u = read(), v = read(), w;
	  if(opt == 1) w = read(), add(u,v,w);
	  if(opt == 2) w = read(), add(v,u,-w);
	  if(opt == 3) add(u,v,0), add(v,u,0);
	}
	for(int i = 1; i <= n; i ++) add(0,i,0),dis[i] = -INF;
	if(!spfa(0)) printf("No");
	else printf("Yes");
}

