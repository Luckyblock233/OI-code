//知识点:二分答案+贪心 
/*
By:Luckyblock
题解地址:https://www.luogu.org/blog/koishikoishi/solution-p1485 
题目要求:
给定一数列 a , 一整数 k.
给定操作:  第 i 个数减 p, 其 左侧的 数列中 左数第j个数减 max(0,p-(i-j)^2) .
操作最多 进行 k 次  , 求将数列全部变为负数时 ,  最小的 p 值.

---

分析题意:
很明显, 可以对 p 进行二分答案.

- 在检查正确性时 , 贪心选择操作对象 :
  对于给定操作, 只对 某个数 及 其左侧的数 有影响, 
  则应优先  对 较右侧的数 进行操作. 
  
- 在进行操作后 ,  如何 维护原数列的值? 
    考虑对计算式进行分析:

	- 若 p-(i-j)^2< 0 :
	  说明 数列中 i 与 j两位置 的 距离 (i-j)>sqrt(p)
	  则: 对 i 位置进行操作 , 不会对 j 位置造成影响. 
	  
	  由于 p 已知 , 则可求得满足 p-(i-j)^2>= 0的, 最大的(i-j) , 记为 max(i-j)
	  则: 对于第 j 个位置 , 区间[j+1,j+max(i-j)] 内位置被操作 , j 位置才会被影响
	   
	-  要 求得第 j 个位置 的 数值 ,
	   设 在 区间[j+1,j+max(i-j)] 进行了k1 次操作 , 每次被操作的位置记录在数组 i 中
	   则: j 位置当前的数值 $\large m[j]'=m[j]- \sum\limits_{x=1}^{k_1}{p-(i_x-j)^2}\ \  (  \text{第}x \text{次操作位置为}i_x , )$
	   
	   对计算式进行转化:
	   $\ \ \ \  m[j]- \sum\limits_{x=1}^{k_1}{[p-(i_x-j)^2]}$
	   $= m[j]-\sum\limits_{x=1}^{k_1}{(p-{i_x}^{2} + 2i_xj-j^2)}$
	   $= m[j]-\sum\limits_{x=1}^{k_1}{p}+\sum\limits_{x=1}^{k_1}{{i_x}^2}-\sum\limits_{x=1}^{k_1}{2i_xj}+\sum\limits_{x=1}^{k_1}{j^2}$
	   $= m[j]- k_1(p-j^2)+\sum\limits_{x=1}^{k_1}{{i_x}^2} - 2j \sum\limits_{x=1}^{k_1}{i_x}$
	   
	   对于式子中的值 : 
	   $k_1=$ 区间 $[j+1,j+\max{(i-j)}]$  内的操作数
	   $\sum\limits_{x=1}^{k_1}{{i_x}^2}=$ 区间 $[j+1,j+\max{(i-j)}]$ 被操作位置编号 的 平方和
	   $\sum\limits_{x=1}^{k_1}{i_x}=$ 区间 $[j+1,j+\max{(i-j)}]$ 被操作位置编号 的 和 
	   
	   以上三个值 , 可以通过维护三个 后缀和 来得到,
	   就可以实现 O(1)的 单点查询 
	  
- 通过上述手段 , 就可以实现在O(n) 复杂度内 , 对一个枚举的 p 进行 check
 
---

算法实现:

首先对 p 进行二分答案.
在 check()函数中,检查枚举 $ 的合法性:
倒序枚举 n~1 中的元素,
通过计算式 $m[j]= m[j]- k_1(p-j^2)+\sum\limits_{x=1}^{k_1}{{i_x}^2} - 2j \sum\limits_{x=1}^{k_1}{i_x}$, 求得 m[j] 的值.
- 如果 m[j]<0 ,则此位置已经满足条件 , 不需要被操作 . 
- 否则 就对 j 位置进行直接操作 , 并更新后缀和.

总复杂度 O(nlogn) , 稳过.

---

其他优化:
真的有必要记录全部的 [i,n] 内的后缀和吗 ???
很明显不需要.
可以在枚举的过程中 直接进行差分 ,  即可维护所需的三个值.
可以大幅优化空间复杂度
反正又不卡空间 所以就没有写(大雾 
*/
#include<cstdio>
#include<cmath>
#include<ctype.h>
#define int long long
const int MARX = 2e6+10;
//=============================================================
int n,k,ans , m[MARX];
int sum1[MARX],sum2[MARX],sum3[MARX];
//sum1~3,分存区间[i,n]内 操作编号的和 , 操作编号平方的和 , 操作数的和. 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool check(int p)
{
	int imax=sqrt(p);
	for(int i=n; i>=1; i--)//倒序枚举数列 
	{
	  sum1[i]=sum1[i+1] , sum2[i]=sum2[i+1] , sum3[i]=sum3[i+1];//维护前缀和 
	  
	  int nowm = m[i] - (sum3[i]-sum3[i+imax+1])*(p-i*i);//计算 更新后的m[i] 
	  nowm += (sum2[i]-sum2[i+imax+1]);
	  nowm -= (2*i*(sum1[i]-sum1[i+imax+1])); 
	  
	  if(nowm<0) continue;//m[i]已经<0,满足条件 
	  for(; nowm>=0; )
	  {
		nowm-=p, sum1[i]+=i, sum2[i]+=i*i,sum3[i]++;//对i位置进行操作,并更新前缀和 
	    if(sum3[i] > k) return 0;//操作次数达到限制 
	  }
	}
	return 1;
}
//=============================================================
signed main()
{
	n=read(),k=read();
	for(int i=1; i<=n; i++) m[i]=read();
	for(int l=1,r=1e12+10; l<=r;)//二分答案枚举p 
	{
	  int mid = (l+r)>>1;
	  if(check(mid)) ans=mid,r=mid-1;
	  else l=mid+1;
	}
	printf("%lld",ans);
}
