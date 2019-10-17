//
/*
By:Luckyblock
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define ll long long
const int MARX = 5e5+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<1];
int n,s,num, head[MARX];
std::vector <int> son[MARX];
bool vis[MARX];
ll maxsum, ans, maxw[MARX];
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
ll dfs1(int u,int fat,int sum)
{
	bool flag = 1;
	for(int i = head[u]; i; i = e[i].ne)
	  if(e[i].v != fat)
	   {
	   	  flag = 0;
	   	  maxsum = max(maxsum, sum + e[i].w);
	   	  ll ret = dfs1(e[i].v, u,sum + e[i].w);
	   	  if(ret > maxw[u]) 
		  {
		  	son[u].clear(); maxw[u] = ret;
		  	for(int j = 0, size = son[e[i].v].size(); j < size; j ++)
		  	  son[u].push_back(son[e[i].v][j]);
		  }
		  else if(ret == maxw[u])
	   	    for(int j = 0, size = son[e[i].v].size(); j < size; j ++)
		  	  son[u].push_back(son[e[i].v][j]);
	   }
	if(flag) maxw[u] = sum, son[u].push_back(u);
	return maxw[u];
}
void dfs2(int u,int fat,int tag)
{
	for(int i = head[u]; i; i = e[i].ne)
	  if(e[i].v != fat)
	   {
	   	  for(int j = 0,size = son[e[i].v].size(); j < size; j ++)
	   	    if(!vis[son[e[i].v][j]])
	   	      ans += maxsum - (maxw[e[i].v] + tag), vis[son[e[i].v][j]] = 1;
		  dfs2(e[i].v,u,tag + maxsum - (maxw[e[i].v] + tag));
	   }
}
//=============================================================
signed main()
{
	n = read(), s = read();
	for(int i = 1; i < n; i ++)
	{
	  int u = read(), v = read(), w = read();
	  add(u,v,w), add(v,u,w);
	}
	dfs1(s,0,0); dfs2(s,0,0);
	printf("%lld",ans);
}

