//知识点:差分,二分答案 
/*
题意分析:
有: 如果在分配的过程中遇到一份订单无法完全满足，则需要停止教室的分配
发现: 
如果后面一份订单可以被分配 , 
那么前面的所有订单都可以被分配 
则答案满足单调性 , 
可以进行二分答案

题目要求进行区间修改
首先想到使用线段树
直接进行模拟操作
但是 n,m<=1e6 , 并且需要进行逐个对比
线段树卡过这题的概率变的很玄乎

考虑其他 , 
能够进行区间操作 , 并且易于对比的数据结构 
想到进行差分 , 建立差分数组 

算法实现:
使用二分答案 , 
枚举第一个遇到的,无法满足的订单号 x 
进行check操作 

然后枚举从 1~x 的所有订单 , 
使用差分数组 , 
对每个 s-t 区间进行操作
获得一个可以求得
各点改变量的差分数组

然后与原序列进行对比 ， 
如果原数 < abs(改变量)
那么该订单就不可满足
否则就满足
根据结果,进行边界调整 

如果 check(m)满足 , 那么所有订单都可满足 ,输出 0 
否则 ,使用二分答案找到第一个不满足的即可 
*/
#include<cstdio>
#include<ctype.h>
#include<cstring>
//=============================================================
const int MARX = 1e6+10;
int n,m;
int raw[MARX];
int d[MARX],s[MARX],t[MARX];
int dif[MARX];
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
bool check(int x)//检查操作 
{
	memset(dif,0,sizeof dif);//初始化 
	int now=0,las=0;
	for(int i=1;i<=x;i++)//建立差分数组  , 从而获得各点的改变量 
	  dif[s[i]]-=d[i],
	  dif[t[i]+1]+=d[i];
	for(int i=1;i<=n;i++)
	{
	  now=las+dif[i];//获得第i个点的改变量 
	  if(-now>raw[i]) return 0;//与原数进行对比 
	  las=now; 
	}
	return 1;//满足 
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) raw[i]=read();
	for(int i=1;i<=m;i++) d[i]=read(),s[i]=read(),t[i]=read();
	if(check(m)) {putchar('0');return 0;}  //所有订单都满足 
	
	int le=1,ri=m;
	while(le<=ri)//进行二分答案 
	{
	  int mid=(le+ri)/2;
	  if(check(mid)) le=mid+1;//更改边界 
	  else ri=mid-1;
	}
	printf("-1\n%d",le);
}

