//知识点:floyd,奇妙思路 
/*	
题目要求:
	每个点,只有在其给定时间后,
	在可以被经过
	求给定时间 时
	两个点的最短路

分析题意:
发现n <=200 ,  
一个随便乱搞的数据范围( ) 
但是询问数 Q<=50000
考虑能够O(1)或O(log)查询的算法

想到floyd 第三层循环枚举的中转点 
可不可以进行一些改动.

想到 记录当前时间
如果询问时间 > 当前时间
就将 当前时间~询问时间 区间内
开放的点作为中转点
跑 一遍floyd,
更新其他的点之间的最短路 
 
那么当前时间 已开放的点之间的最短路便已求出
判断询问两点是否都开放
并且是否联通后 
便可以直接回答询问 
*/
#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<algorithm>
#define int long long
const int MARX = 2100;
const long long INF = 0x3f3f3f3f3f3f3f3f;//极大值 
//=============================================================
int n,m,q , t[MARX];
int map[MARX][MARX];
int p=1;
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void prepare()
{
	memset(map,0x3f,sizeof(map));//初始化各边权 
	n=read(),m=read();
	for(int i=1;i<=n;i++) t[i]=read();
	for(int i=1;i<=m;i++) 
	{
	  int u=read()+1,v=read()+1,w=read();//加边 
	  map[u][v]=map[v][u]=w;
	}
	q=read();
}
//=============================================================
signed main()
{
	prepare();
	while(q--)
	{
	  int x=read()+1,y=read()+1,t1=read();
	  while(t[p]<=t1 && p<n+1)//当前时间更新到询问时间 
	  {
	  	for(int i=1;i<=n;i++)//以区间内新开放的点为中转点,跑floyd. 
	  	  for(int j=1;j<=n;j++)
	  	    map[i][j]=std::min(map[i][j],map[i][p]+map[p][j]);
	  	p++;
	  }
	  if(t1<t[x] || t1<t[y]) printf("-1\n");//有点未开放 
	  else printf("%lld\n",map[x][y]==INF?-1:map[x][y]);//判断连通性 
	}
}
