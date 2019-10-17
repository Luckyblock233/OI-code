//知识点:二分图匹配/匈牙利算法
/*
二分图匹配模板
使用匈牙利算法 
详见注释 
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define int long long
using namespace std; 
//===================================================
const int MARX = 1e3+10;
int n,m,e,ans;
bool road[MARX][MARX] , vis[MARX];
int hus[MARX];//hus为int,误写成bool 
//===================================================
bool marry(int u)//匈牙利算法:配对 
{
	for(int v=m+1;v<=n;v++)//枚举能到达的点 
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
	scanf("%lld%lld",&m,&n);
	while(1) 
	{
	  int u,v;//读入优化出锅 
	  scanf("%lld%lld",&u,&v);
	  if(u==-1 && v==-1) break;
	  if(u<=m && v<=n)
	    road[u][v]=1;
	}
			
	for(int i=1;i<=m;i++)//枚举一组中的n个点 
	{
	  memset(vis,0,sizeof(vis));//初始化 
  	  if(marry(i)) ans++;//更新答案 
	}
	if(ans==0) {printf("No Solution!");return 0;}
	printf("%lld\n",ans);
	for(int i=m+1;i<=n;i++)//输出匹配对象 
	  if(hus[i]) printf("%lld %lld\n",hus[i],i);
}
