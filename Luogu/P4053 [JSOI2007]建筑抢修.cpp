//知识点:贪心 
/*
By:Luckyblock
1A开心 
分析题意:
1.显然, 先对报废时间晚, 修复耗时短的建筑进行修复更优
  则 可以先按照 报废时间 对各建筑进行排序 
2.对于 已经选择的 一个任务序列, 最后一个任务 结束时间为nowt,
  考虑 新任务对 任务序列的影响:
  1.如果 结束最后一个任务之后, 紧接着做新任务,可完成 新任务,
  	则 可以直接将 新任务 加入任务序列
  2.如果不满足上面的 情况 ,
  	但是 任务序列中 耗时最长的 任务 耗时> 新任务
	显然, 如果将 耗时长的任务 替换为新任务,
	修复完成的 建筑数量不会改变, 但是 完成最后一个任务的时间右移
	显然, 对之后加入的新任务更优

则可以按照上述结论进行贪心
对于 任务序列中 个任务的耗时, 可以使用堆维护 
复杂度O(nlogn) 
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<ctype.h>
#define int long long
const int MARX = 1e5+5e4+10; 
//=============================================================
struct plan
{
	int t1,t2;
}a[MARX];
int n , nowt,ans;
std::priority_queue <int> q;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool cmp(plan fir,plan sec) {return fir.t2 < sec.t2;}
//=============================================================
signed main()
{
	n = read();
	for(int i=1; i<=n; i++) a[i].t1=read(),a[i].t2=read();
	std::sort(a+1,a+n+1,cmp);//按照结束时间 升序排序 
	
	for(int i=1; i<=n; i++)
	  if(nowt + a[i].t1 <= a[i].t2)
	  {
	  	//若做完 最后一个任务后 ,直接进行 新任务,新任务能完成 
	  	 nowt += a[i].t1 , ans++;//更新 做完最后一个任务的时间 
	  	 q.push(a[i].t1);//加入队列 
	  }
	  else if(a[i].t1 < q.top())
	  {
	  	//若不满足 上面的情况, 但是新任务 比 之前做完的任务中耗时最长的短
	  	nowt = (nowt - q.top() + a[i].t1);//更新 做完最后一个任务的时间  
	  	q.pop(); 
	  	q.push(a[i].t1);//入队 
	  }
	
	printf("%lld",ans);
}
