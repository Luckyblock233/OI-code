//知识点:树上差分, 树链剖分,lca 
/*
By:Luckyblock
首先,这是个不可做的神仙题
考虑部分分:

si=ti 10分:
每个人的起点和终点相同,第0秒时即到达终点 
由于一个人到达终点后 ,就不可被观察到
所以 可以观察到人的观察员,
只有wj=0的观察员.
则需要找到所有 起点与 wj=0的观察员相同的人. 

wj=0 10分:
观察员只会在第0秒观察.
也就是说,
只有 起点 与 观察员所在点 相同的人 , 才会被观察到. 
*/
#include<cstdio>
#include<ctype.h>
#include<vector>
const int MARX = 1010;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<1];
int n,m,num , head[MARX],w[MARX],ans[MARX];
bool zero[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v)
{
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<n; i++)
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u);
	}
	for(int i=1; i<=n; i++)
	{
	  w[i]=read();
	  if(!w[i]) zero[i]=1;
	}
	for(int i=1; i<=m; i++)
	{
	  int s=read(),t=read();
	  if(zero[s]) ans[s]++;
	}
	for(int i=1; i<=n; i++) printf("%d ",ans[i]);
}
