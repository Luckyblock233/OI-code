//知识点:贪心 
/*
By:Luckyblock
1.对于 第一周 ,必须生产新的机器
2.对于 其他时刻 , 
  机器 可以来自 之前生产的库存, 也可以生产新的机器 
  
3.那么对于 每一周, 
  都可以比较 新生产这些机器的花费 与 
  在之前某一时刻生产的花费 + 保养费用
  即 比较 当前单价 与 之前单价 + 保养费用*天数 
  
  选择 更优的 , 加入答案
  可以用优先队列自定义优先级进行维护 
  
4.优化:
  优先队列 这种暴力碾压的方案 一点也不优美
  观察 当前单价 与 之前单价 + 保养费用*天数 ;
  可以发现 , 所有的 之前单价 + 保养费用*天数  , 
  在每周过后 , 都递增1*s;
  
  则 无论经过 多少天 ,
  所有 之前单价 + 保养费用*天数的 大小顺序排序不变
  其中最小的 元素 在 ?天之后 仍然是最小的  
  
  所以 对于每一个新的单价, 
  先将其 与 之前单价 + 保养费用*天数中最小的进行比较
  如果更优 ,那么将 之前单价 替换为当前单价 , 同时天数置零
  每次新一周过后 , 更新天数 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//=============================================================
int n,s,ans;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read(), s=read();
	int minn = 1e9+7;//最小的 单价 
	for(int i=1; i<=n; i++)
	{
	  int c=read(), y=read();
	  if(c < minn) minn = c;//单价更优 
	  ans += y*minn;//加入答案 
	  minn +=s;//更新单价 
	} 
	printf("%lld",ans);
} 
//优先队列 
/* 
#include<cstdio>
#include<queue>
#include<ctype.h>
#define int long long
#define min(a,b) (a<b?a:b)
//=============================================================
int n,s,now,ans;
struct week
{
	int c,num;
	//优先队列 自定义优先级 , 按照 (单价+保养费) 升序排序 
	bool operator< (const week &sec) const 
	{  
	  return (c+s*now-s*num) > (sec.c+s*now-s*sec.num);
	}
};
std::priority_queue <week> q;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read(),s=read();
	for(now=1; now<=n; now++)
	{
	  int c=read(),y=read();
	  q.push((week){c,now});
	  ans += y*(q.top().c + s*now -s*q.top().num);
	}
	printf("%lld",ans);
}
*/ 
