//知识点:拓扑排序,拓扑序DP 
/*
题目要求:
求 1~n 之间的最长路

由于题目给出的图有向且无环 
并且对于1~i的最短路,
有多条路径可以选择
所以可以进行
拓扑序DP

先将 拓扑序在1之前的点去除
并将他们出边上的点的入度-- 
再从1开始进行拓扑排序DP 
*/ 
#include<cstdio>
#include<queue>
#include<algorithm>
#include<ctype.h>
#include<cstring>
const int MARX = 1510;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[50010];
int n,m,num , head[MARX],in[MARX];
long long f[MARX];//f[i]表示 1到i点的最长距离 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)//加边 
{
	e[++num].u=u,e[num].v=v,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
void prepare()//输入并初始化 
{
	memset(f,-1,sizeof(f));
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w);
	  in[v]++;//入度++ 
	}
}
void topsort()//拓扑排序 
{
	std::queue <int> q;
	for(int i=1;i<=n;i++)//找到入度为0的点 
	  if(!in[i] && i!=1)
	    q.push(i);
	//去除拓扑序在1之前的点 
	for(int u=q.front();!q.empty();q.pop(),u=q.front()) 
	  for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)
	  {
	    in[v]--;
		if(!in[v]) q.push(v);
	  }
	
	q.push(1);f[1]=0;//初始化 ,从1开始DP 
	for(int u=q.front();!q.empty();q.pop(),u=q.front())
	  for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)
	  {
	    f[v]=std::max(f[v],f[u]+e[i].w);//更新1到v点的最长距离 
		in[v]--;
		if(!in[v]) q.push(v);
	  }
}
//=============================================================
signed main()
{
	prepare();
	topsort();
	printf("%lld",f[n]);
}
