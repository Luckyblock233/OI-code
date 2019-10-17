//知识点:DP/单调队列 
/*
https://i.loli.net/2019/07/15/5d2c66e3abac041765.jpg
https://i.loli.net/2019/07/15/5d2c66e3ca0a366764.jpg

分析题意:
 
很显然  这是一道 DP  
状态转移方程 极其简单 :  
用 f[i][j] 表示在点 (i,j) 能到达的最大价值和 ,
则有: f[i][j] = max(f[i-1][k]) + v[i][j] , (k属于 [j-T , j+T])  
  -暴力:  
    直接枚举所有点 , 再枚举能转移到他的点 ?  
    复杂度 O(NMT)  ,   
    40Pts 到手  
考虑优化 :  
  可知:  
  第 i 行上点的 f[][] , 只与第 i-1 行有关    
  则可将每相邻的两行 , 单独拆分出来考虑 :
可以发现 :   
  1.转移到 点(i,j) 的点 ,    
    为 i-1 行 , 区间 [j-T,j+T]中,f[][]最大的点
  2. 转移到 点(i,j+1) 的点 ,    
    为 i-1 行 ,区间[j-T+1,j+T+1]中,f[][] 最大的点 
  3. 转移到 点(i,j+2)的点 ,    
    为 i-1 行 ,区间[j-T+2,j+T+2]中 ,f[][]最大的点  
  
这种 滑动窗口型最值问题 ,   
显然 , 可以通过 单调队列 来进行维护 .   

由上 , 我们便找到了一种合适 DP 优化方法: 单调队列优化.

算法实现:
假设,现在已经更新到第i行 :    
  1.先初始化单调队列 ,   
    将能够更新 (i,1) 的点(i,k) , (k 属于 [1,1+T]) ,  
    加入单调队列  
  2.开始循环 , 更新 $[1,M]$ 中每一个点 :  
    将能够转移到 j 的最右侧一个点 (i-1 , j+T) , 加入队列  
    使用单调队列找到能够转移到 j 的点的最大f[][]  
    用最大的f[][] 更新 f[i][j]
  3.清空单调队列 , 外层循环进入下一层 ,更新第 i+1 行   
   
最后找到最后一行中  ,   
最大的 f[N][j] ,     
即所求最值 . 
*/
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define int long long
#define max(a,b) a>b?a:b
//=====================================
const int MARX = 4e3+10;
int n,m,k,t, now,ans;
int f[MARX][MARX];
int head=1,tail=1;//手写双端队列 
int q[MARX]={9223372036854775807};//为q[0]赋一个极大值,来插入元素时防止越界 
//=====================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void in(int x)//向单调队列中插入元素 
{
	while(f[now-1][x]>f[now-1][q[tail]] && tail>=head) 
	  tail--;//取出队尾小于插入元素的数 , 以保证单调性 
	q[++tail]=x;//插入队尾 
}
int find(int x)//查询元素 
{
	if(x+t<=m)in(x+t);//将能转移到x点 的 最后一个元素 x+t 插入队列 
	while(q[head]+t<x) head++;//找到队首第一个能够转移到x的点 
	return q[head]; 
}
//=====================================
signed main()
{
	n=read(),m=read(),k=read(),t=read();
	while(k--)
	{
	  int x=read(),y=read(),w=read();
	  f[x][y]=w;
	}
	
	for(now=2;now<=n;now++)//从第二行,开始转移 
	{
	  for(int i=1;i<=t;i++) in(i);//初始化单调队列 , 满足能够 转移j=1的点 
	  for(int j=1;j<=m;j++) f[now][j]+=f[now-1][find(j)];// 进行转移 
	  head=tail=1 , q[1]=0;//清空队列 
	}
	
	for(int i=1;i<=m;i++)//取得最大值 
	  ans=max(ans,f[n][i]);
	printf("%lld",ans);
}
