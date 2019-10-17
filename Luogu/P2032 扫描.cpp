//知识点:单调队列,滑动窗口 
/*
By:Luckyblock
题目要求:
求所有 长度为k的区间的 最大值
所有询问区间的 端点单调递增 

分析题意:
一道非常显然的 单调队列问题
维护一个 区间元素单调递减的 队列 

每次插入新元素时, 从队尾循环删除 较劣的 元素, 再插入 
每次询问时, 先删除 队首不合法元素, 再询问队首元素 
*/
#include<cstdio>
#include<ctype.h>
const int INF = (1<<30)-1;
const int MARX = 2e6+10;
//=============================================================
int n,k,a[MARX]={INF}; 
int que[MARX],head=0,tail=0;//单调队列 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void insert(int i)//插入操作 
{
	for(;a[i] >= a[que[tail]] && tail>=head;) tail--;//弹出队尾元素 
	que[++tail] = i;//入队 
}
int query(int x)
{
	for(;que[head] + k-1 < x;) head++;//弹出队首 不合法元素 
	return a[que[head]];//回答询问 
}
//=============================================================
signed main()
{
	n = read(),k = read();
	
	for(int i=1; i<k; i++) //将前k-1个数插入 单调队列 
	{
	  a[i] = read();
	  insert(i);
	}
	
	for(int i=k; i<=n; i++)
	{
	  a[i] = read();
	  insert(i);//将第i个数插入 
	  printf("%d\n",query(i)); //询问 
	}
}
