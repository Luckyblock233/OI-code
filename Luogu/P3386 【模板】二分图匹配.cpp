//知识点:二分图匹配/匈牙利算法
/*
二分图匹配模板
使用匈牙利算法 
详见注释 
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
using namespace std; 
//===================================================
const int MARX = 1e3+10;
int n,m,e,ans;
bool road[MARX][MARX] , vis[MARX];
int hus[MARX];//hus为int,误写成bool 
//===================================================
inline int read()//快读 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
bool marry(int u)//匈牙利算法:配对 
{
	for(int v=1;v<=m;v++)//枚举能到达的点 
	{
	  if(road[u][v] && (!vis[v]))
	  {
		vis[v]=1;//更新 
		if((!hus[v]) || marry(hus[v]))//如果可以配对 
		{
		  hus[v]=u;//更新 
		  return 1;
		}
	  }
	}
	return 0;
}
//====================================================
signed main()
{
	n=read(),m=read(),e=read();
	for(int i=1;i<=e;i++)
	{
	  int u=read(),v=read();//读入优化出锅 
	  if(v>m || u>n) continue;//加边 
		road[u][v]=1;
	}
			
	for(int i=1;i<=n;i++)//枚举一组中的n个点 
	{
	  memset(vis,0,sizeof(vis));//初始化 
  	  if(marry(i)) ans++;//更新答案 
	}
	printf("%d",ans);
}