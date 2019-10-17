//知识点: 模拟,树状结构 
/*
By:Luckyblock
题目要求:
给定 一棵树, 点有点权
给定两种操作:
1.修改某节点的点权
2.查询 距某节点 最近的 一个祖先,
  满足 此节点 与 其祖先节点 点权值 最大公约数>1
  
分析题意:
由于此题数据 较弱
可以直接 暴力模拟
对于被查询节点, 暴力上跳
对于其每一个祖先 , 都与被查询节点进行比较 
如果 最大公约数 >1 则直接输出

数据加强:
在初期状态和更改节点时，所有定点进行一次更新。之后所有1询问，用O(1)的方法得出。
A[i]的范围约20亿，而将其平方根后，质数约5000个。
先把A[i]全部质因数分解掉，更新的时候再计算就是了。
在这种情况下dfs树，准备好质数的栈组（一个质数准备一个栈，STL随便上），
先找到它的质因数栈的栈顶元素，最大的就是答案，一边把节点编号入栈，进行下一层dfs。
虽然质数很多，但是主要集中在2,3,5,7,11,13，所以时间复杂度平均很低。  
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 2e5+10;
//=============================================================
int n,k,num , fa[MARX],we[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}//求最大公约数 
int inquiry(int now,int value)//暴力上跳 查询操作 
{
	if(now == 0) return -1;//到达根部上方 
	if(gcd(we[now],value) != 1) return now;//满足条件 
	return inquiry(fa[now],value);
}
//=============================================================
signed main()
{
	n=read(), k=read();
	for(int i=1; i<=n; i++) we[i] =read();
	for(int i=1; i<n; i++)//建图 
	{
	  int u=read(),v=read();
	  fa[v] = u;
	}
	
	for(int i=1; i<=k; i++)//修改/回答询问 
	{
	  int type=read(),value1=read(),value2;
	  if(type == 1) printf("%d\n",inquiry(fa[value1],we[value1]));
	  else value2=read(),we[value1]=value2;
	}
}
