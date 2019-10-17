//知识点:贪心 
/*
By:Luckyblock
分析题意:
- 对于 最优的推销对象顺序, 可以发现, 
  X = i时的最优顺序, 一定可以由 X=i-1 时的最优顺序 推出
  则可以 先只考虑 X=i-1 到 X=i 的转移
- 假设 当 X = i-1时, 到达的最远的 住户编号为now 
  则 X = i时新添加进序列中的住户, 
  编号 可能 <= now, 也可能 >= now 
  
  当编号 <= now时, 新住户k 做出的贡献为 :a[k]
  当编号 >= now时, 新住户k 做出的贡献为: 2*(s[k]-s[now]) + a[k]
  选择 较大的 贡献 加入答案, 并更新 最远的住户编号j
  
- 则可以维护 两优先队列, 来维护上述信息
  两优先队列 分别维护:
  1. 编号=<now 的住户中 做出的最大贡献的编号
  2. 编号>=now 的住户中 做出的最大贡献的编号
  
  按照上述思路贪心取数,
  更新答案与 优先队列元素即可
  
  复杂度O(nlogn) 
*/
#include<cstdio>
#include<ctype.h>
#include<queue>
#define int long long
const int MARX = 1e5 + 10;
//=============================================================
int n,ans,now, s[MARX], a[MARX];
bool use[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
struct cmp1//自定义优先级
{
	bool operator ()(const int sec,const int fir)
	{
	  return 2*s[sec] + a[sec] < 2*s[fir] + a[fir];
	}
};
struct cmp2//自定义优先级
{
	bool operator ()(const int sec,const int fir)
	{
	  return a[sec] < a[fir];
	}
};
//=============================================================
signed main()
{
	std:: priority_queue < int, std::vector <int> , cmp1> q1;//编号>=now 的住户中 做出的最大贡献的编号
	std:: priority_queue < int, std::vector <int> , cmp2> q2;//编号=<now 的住户中 做出的最大贡献的编号
	n = read();
	for(int i = 1; i <= n; i ++) s[i] = read();
	for(int i = 1; i <= n; i ++) a[i] = read(),q1.push(i);//初始化 
	
	for(int x = 1; x <= n; x ++)//枚举x 
	{
	  for(; !q1.empty() && (use[q1.top()] || q1.top() <= now); ) q1.pop();//删除 队列中 更新后编号<now的元素 
	  for(; !q2.empty() && use[q2.top()]; ) q2.pop();//删除被使用的 q2元素  
	  if(!q1.empty())//按照两队列 空/非空情况分类讨论 
	  {
	  	if(!q2.empty())//两队列都非空 
	    {
	      if(2*s[q1.top()] - 2*now + a[q1.top()] > a[q2.top()]) // 选择 q2顶部 劣于选择q1顶部 
	      {
	        ans += 2*s[q1.top()] - 2*now + a[q1.top()],
		    use[q1.top()] = 1;
		    for(int j = now+1; j < q1.top(); j++) q2.push(j);//更新队列与答案 
		    now = q1.top() , q1.pop();
	      }
	      else //两队列都非空 , 选择 q1顶部 劣于选择q2顶部 
	        ans += a[q2.top()], 
		    use[q2.top()] = 1, q2.pop();	
		}
		else //q1非空, q2空, 直接更新 
		{
		  ans += 2*s[q1.top()] - 2*now + a[q1.top()],
		  use[q1.top()] = 1;
		  for(int j = now+1; j < q1.top(); j++) q2.push(j);
		  now = q1.top() , q1.pop();
		}
	  }
	  else //q1空, q2必然非空, 直接更新 
	    ans += a[q2.top()], 
		use[q2.top()] = 1, q2.pop();	
	  printf("%lld\n",ans);
	}
}
