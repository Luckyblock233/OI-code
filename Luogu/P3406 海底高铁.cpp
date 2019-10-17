//知识点:差分,前缀和 
/*
By:Luckyblock
分析题意:
1.显然, 如果在出发前就 办好所需的所有的 IC卡,
  必然比 出发后再办 要优 
2.显然, 总花费 = ∑(每条路径总花费)
  而 每条路径总花费 =  路径经过次数 * 不优惠花费  
  或= ic卡价格 + 路径经过次数 * 优惠花费
  
  则若已知所有的 路径经过次数
  则 可以 比较出 两种情况的花费
  取 最小值, 即此条路径的 总花费  
3.对题目给出的 城市之间的 转移路径
  可以看做 将起点-->终点 的所有路径 出现次数+1
  变成了一个 数列区间加 的问题
  
  对于此题, 只需要一次询问
  则 使用差分 进行O(1)修改
  最后 O(n)前缀和 还原出所有道路经过次数
  取 两种花费方案的 最小值即可 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
#define int long long
using std::max;
using std::min;
const int MARX = 1e5+10;
//=============================================================
int n,m,ans , diff[MARX];
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
	n=read(),m=read();
	int last = read();
	for(int i=2; i<=m; i++)//读入路径,进行差分修改 
	{
	  int now = read();//当前城市 
	  diff[min(last,now)]++,diff[max(last,now)]--;//差分 
	  last = now;
	}
	
	for(int i=1,sum=0; i<n; i++)//前缀和还原 各路径经过次数 
	{
	  int a=read(),b=read(),c=read();
	  sum += diff[i];//累加次数 
	  ans += min(sum*a,c+sum*b);//取较小 花费方案 
	}
	printf("%lld",ans);
}
