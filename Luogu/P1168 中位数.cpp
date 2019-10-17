//知识点:模拟,堆 
/*
By:Luckyblock
题目要求:
给定一数列, 
求:1~1,1~3,...,1~2k-1(2k-1<=n)的中位数 

分析题意:
假设 可以获得前n/2 小的数 和 前n/2大的数
那么就可以很方便地 求得中位数了
考虑 应用某些数据结构 , 来实现上述要求 

可以 开一个小根堆, 一个大根堆
将 前n/2小的数放入大根堆, 将前n/2大的数放入小根堆
那么大根堆 和 小根堆的堆顶 , 即中间元素

算法实现:
按照上述规则, 声明两个 堆,
分别为low(大根堆,存前n/2个数) 与 high(小根堆,存后n/2个数) 
插入新元素时:
  1.将新元素与 low的堆顶进行比较,
    如果大 , 说明新元素 在后n/2个数中,将其放入high堆中
	否则,说明新元素 在前n/2个数中, 将其放入 low堆中
  2.维护两堆之间的元素 数量关系:
    当有一堆 的元素数 >= 另一堆元素数+2时,
	说明 两堆不对称.
	则将 元素多的堆 堆顶元素 移入 另一堆. 
查询中位数时: 
  经过上述 插入维护过程后,
  两堆元素数 相等 或 差一
  当两堆元素数 相等时, 中位数 = (low顶+high顶)/2
  当两堆元素数 不等时, 中位数 = 元素数较多的 堆 堆顶元素 
*/
#include<cstdio>
#include<functional>
#include<queue> 
#include<ctype.h>
const int MARX = 1e5+10;
//=============================================================
int n;
std::priority_queue <int> low;//大根堆,存 前n/2个数
std::priority_queue <int, std::vector<int>, std::greater<int> > high;//小根堆,存后n/2个数
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void insert(int now)//插入 新元素 
{	
	if(low.empty()) {low.push(now); return;}//有空堆时 
	if(now > low.top()) high.push(now);//比较大小关系 
	else low.push(now);
	//维护 元素数相对稳定 
	if(high.size() >= low.size()+2) low.push(high.top()),high.pop();
	if(high.size()+2 <= low.size()) high.push(low.top()),low.pop();
}
void putout()//查询中位数 
{
	if(high.size() > low.size()) printf("%d\n",high.top());
	else printf("%d\n",low.top());
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1,tmp; i<=n; i++) 
	{
	  tmp = read();
	  insert(tmp);
	  if(i%2) putout();
	}
}
