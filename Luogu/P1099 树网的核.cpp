//知识点: 树的直径, 暴力枚举, 双指针 
/*
By:Luckyblock
题目要求:
给定一棵树T = (V,E,W), 边有边权, 并给定一参数S 
设: 偏心距ECC(F) 表示距离路径F 最远的节点 到路径F的距离 
	有: ECC(F) = max(d(v,F) , v属于V) 
求 : 一段路径F, 为树的直径上 长度不超过S的 一段路径
	使 偏心距ECC(F) 最小化 
	
分析题意: 
- 首先 求得树的直径, 并记录树的直径上的点
  使用DFS处理较为容易

- 由于数据范围 较小, n<=300, 
  则可再floyd暴力 求得 树上任意两点之间 的 距离 

-  由于数据范围 较小, n<=300, 
   则可以 再暴力枚举 直径上每一段 长度不超过S的 路径
   
   - 可以发现 一些性质:
     若固定区间一端点, 并向另一侧寻找 合法的端点
	 若 被固定端点 左移, 则另一端点 必然不右移
	 
	 两端点的 位置变化量满足单调性
	 则可以使用 双指针(尺取法) 来枚举每一个区间
	 
   - 使用尺取法 枚举 每一段 合法区间
   	 每次都 暴力计算出 所选路径 F 与路径F外每一个点 的距离
	 取 最小值作为答案 
	 
数据加强: 
由于 此题数据范围较小, 所以可以直接暴力水过
可以挑战: 数据加强版: P2491 [SDOI2011]消防
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int MARX = 310;
//=============================================================
int n,s,u,v, ans = 2e9, map[MARX][MARX];
int dis[MARX], pre[MARX];
bool use[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void dfs(int now,int fat,int sum,bool flag)//dfs求得 树的直径 
{
	if(flag) pre[now] = fat;//第二次dfs记录路径 (前驱 
	dis[now] = dis[fat] + sum;//更新距离 
	for(int i = 1; i <= n; i ++)//枚举出边更新 
	  if(map[now][i] <= 1e9 && i!=fat)
	    dfs(i,now,map[now][i],flag);
}
void get_road()//求得 树的直径 
{
	dfs(1,0,0,0); //一次dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//选择 距离最远的点 
	  if(dis[i] > maxdis) u = i,maxdis = dis[i];
	dfs(u,0,0,1); //二次dfs 
	for(int i = 1, maxdis = 0; i <= n; i ++)//选择 距离最远的点 
	  if(dis[i] > maxdis) v = i,maxdis = dis[i];
}
void floyd()//floyd 求得 任意两点路径 
{
	for(int i = 1; i <= n; i ++) map[i][i] = 0;
	for(int i = 1; i <= n; i ++)
	  for(int j = 1; j <= n; j ++)
	    for(int k = 1; k <= n; k ++)
	      if(i != j && j != k)//floyd注意判断 
	        if(map[j][k] > map[j][i] + map[i][k])
	    	  map[j][k] = map[j][i] + map[i][k];
}

void solve() 
{
	int l = v,r = v;   use[v] = 1;//初始化 
	for(int sum = 0; l!=u; use[l]=0, l = pre[l], sum=0)//枚举 左端点 
	{
	  memset(dis,63,sizeof(dis));//初始化 
	  for(; map[l][r] <= s;) r = pre[r],use[r] = 1;//更新右端点 
	  use[r] = 0;
	  for(int i = l; i != r; i = pre[i])//暴力计算出 所选路径 F 与路径F外每一个点 的距离
	    for(int j = 1; j <= n; j ++)
	      if(!use[j]) dis[j] = min(dis[j],map[i][j]);
	      
	  for(int i = 1; i <= n; i ++)//求得 偏心距 
	    if(!use[i]) sum = max(sum,dis[i]);
	    
	  ans = min(ans,sum);//更新答案 
	}
}
//=============================================================
signed main()
{
	memset(map,63,sizeof(map));//初始化路径长度 
	n = read(), s = read();
	for(int i = 1; i < n ;i ++)
	{
	  int u1 = read(), v1 = read(), w1 = read();
	  map[u1][v1] = map[v1][u1] = w1;
	}
	get_road();  floyd();  solve();
	printf("%d",ans);
}
