//知识点: 双指针(尺取法) ,枚举,模拟 
/*
By:Luckyblock
分析题意:
题目要求 O(n)/O(nlogn) 算法 

由于 m<=2000, 则可以使用桶来进行维护
以确定 一个区间是否合法 

可以发现, 
若固定了区间的左端点, 并向右寻找最优的右端点
当 左端点右移时, 右端点也只单调右移 

所以可以使用双指针(尺取法), 
先令左端点 = 1, 并向右寻找 第一个满足条件的右端点
之后 左端点右移, 右端点 继续右移, 直到满足条件
 
在模拟的 过程中取最小的区间大小 
按照 上述过程进行模拟,
由于 左右端点 都只单调右移, 则 总复杂度为O(n) 


代码实现中 , 固定了右端点, 将左端点右移 
*/
#include<cstdio>
#include<ctype.h>
#define min(a,b) (a<b?a:b)
const int MARX = 1e6+10;
//=============================================================
int n,m,ans, ansl,ansr, a[MARX];
int bucket[2010],cnt; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void Insert(int x)//插入操作 
{
	if(bucket[a[x]] == 0) cnt ++;
	bucket[a[x]] ++;
}
void Delete(int x)//删除操作 
{
	if(bucket[a[x]] == 1) cnt--;
	bucket[a[x]] --;
}
//=============================================================
signed main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; i ++) a[i] = read();
	
	int l = n, r = n;
	Insert(r);//初始化 
	for(;cnt < m;) Insert(--l);
	ans = r-l+1, ansl = l, ansr = r;
	
	for(int r = n - 1; r > 0; r --)//枚举右端点 
	{
	  Delete(r + 1);//删除 右端点位置 
	  for(; cnt < m && l > 1; ) Insert(--l);//左移左端点 
	  if(r - l + 1 <= ans && cnt==m) //计算最优答案 
	    ansl = l,ansr = r, ans = r-l+1;
	}
	printf("%d %d",ansl,ansr);
}

