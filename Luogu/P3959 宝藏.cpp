//知识点:状压DP 
/*
分析题意:
任意指定起点
并且父亲点距离起点的距离
会影响边的权值

首先想到枚举出发点 , 
跑n遍spfa , 必然TLE 

发现n非常小 , 
并且对于n个点在答案中的包含状况 , 
有重复的状态出现
考虑进行状压dp

算法实现:
对和起点已经联通的点的集合 ,进行状态压缩
使用f[i][j][k] 表示 ,
状态为 j , 深度(dfs的深度)为k , 将第i个点加入集合 的代价
设置k的目的 , 是为了防止搜索深度不一 , 影响答案 

则可以进行记忆化dfs
dfs传递参数 : 当前状态now , 当前总代价sum ,当前dfs深度dep
然后以当前状态中包含的点  , 
来疏导当前状态中不包含的点
并更新答案,将它们加入状态

当所有点都加入集合后 , 
答案 = min(答案,总代价sum) 
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
//=================================================
const int MARX = 1e9+7;
int n,m,lim,  map[15][15],dis[15];
int ans=MARX , f[15][5000][15];
//=================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void dfs(int now , int sum , int dep)
{
	if(sum>=ans) return ;
	if(now==lim) {ans=min(ans,sum); return;}//当所有点都加入集合 , 取较小的答案 
	for(int i=1;i<=n;i++) 
	  if(1<<(i-1)&now)//枚举在集合中的点i 
	    for(int j=1;j<=n;j++)
	      if(!(1<<(j-1)&now) && map[i][j]<MARX)//枚举i可以到达的 , 且不在集合中的点j 
	  	  {
	  	    if(f[j][1<<(j-1)|now][dep+1] <= sum+dis[i]*map[i][j]) continue;//疏导后不优 
	  	    f[j][1<<(j-1)|now][dep+1] = sum+dis[i]*map[i][j];
	  	    dis[j]=dis[i]+1;//更改j的深度 
	  	    dfs(1<<(j-1)|now ,f[j][1<<(j-1)|now][dep+1] ,dep+1);//继续疏导 
		  }
}
//=================================================
signed main()
{
	n=read(),m=read();lim=(1<<n)-1;
	memset(map,MARX,sizeof(map));
	for(int i=1;i<=m;i++)//建图 
	{
	  int u=read(),v=read(),w=read();
	  map[u][v]=map[v][u]=min(map[u][v],w);
	}
	for(int i=1;i<=n;i++)//枚举出发点 
	{
	  memset(dis,0,sizeof(dis));//初始化 
	  memset(f,MARX,sizeof(f));
	  dis[i]=1; dfs(1<<(i-1),0,0);
	}
	printf("%d",ans);
}
