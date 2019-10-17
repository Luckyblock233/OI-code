//知识点:生成树 
/*
题目要求:
点有点权,边有边权
花费点权后,可以让这个点变成 "好的"
求最小花费,
使所有点都与"好的"点直接间接相连.(或者本身为 "好的")

思路:
既有点权,又有边权,
有要求一棵生成树 
对原图直接操作不可.

考虑重建图,
将点权转化为边权.

算法实现:
设立一个超级源点,
并将每个点都与超级源点连边
边权值即为每个点的点权值.

然后将超级源点加入图中,
跑最小生成树即可. 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
const int MARX = 510;
//=============================================================
struct edge
{
	int u,v,w;
}e[MARX*MARX/2];
int n,num,fa[MARX];
bool map[MARX][MARX];
long long ans;
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline bool cmp(edge first,edge second){return first.w<second.w;}
inline void add(int u,int v,int w){e[++num].v=v,e[num].u=u,e[num].w=w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}//查集 

inline void join(int x,int y)//并集 
{
	int r1=find(x),r2=find(y);
	fa[r1]=r2;
}
void kruscal()//kruscal最小生成树 
{
	for(int i=1;i<=num;i++)
	  if(find(e[i].u) != find(e[i].v))
	  {
	  	join(e[i].u,e[i].v);
		ans+=(long long)e[i].w;//答案添加 
	  }
}
void prepare()
{
	n=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
	  int w=read();
	  add(n+1,i,w),add(i,n+1,w);//向超级源点n+1连边 
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)//加边 
	  {
	  	int w=read();
		if(!map[i][j] && i!=j) add(i,j,w),add(j,i,w); 
	    map[i][j]=map[j][i]=1;
	  }
	std::sort(e+1,e+num+1,cmp);//按照边权升序排序 
}
//=============================================================
signed main()
{
	prepare();
	kruscal();
	printf("%lld",ans); 
}
