//知识点:筛法求素数 
/*
By:Luckyblock
题目要求: 
给定区间 [l,r] , (l<=r<=maxint , r-l<=1e6)
求 [l,r] 中素数的个数 

分析题意:
显然 , 直接将[l,r]内的素数筛出是不可能的
需要使用一些技巧.

发现性质: 
对于 合数x, 至多存在一个质因子>=sqrt(x),
其他 质因子都 <= sqrt(x)
则: 若 预处理出 [1,sqrt(maxint)] 中的质数,
则 [l,r] 中的合数 必然有质因子存在于 [1,sqrt(maxint)]中

那么可以使用筛法 求得 [1,sqrt(maxint)]中的质数,
由于 r-l <=1e6,  
则可使用 这些质数 ,再将 [l,r]中的合数筛出
最后统计 [l,r] 中 未被筛去的 元素, 即质数, 即可

注意 l,r<=maxint,
筛 [l,r]内元素时, 打标记的数组下标不可开到maxint
可以将数组下标全部减去 l进行使用  
*/
#include<cstdio>
#include<cmath>
#include<vector>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int MARX = 5e4+10;
//=============================================================
int l,r,ans;
bool flag[MARX]={1,1},flag1[20*MARX];
std:: vector <int> prime;
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
	l=read(),r=read();
	for(int i=2; i<MARX-10; i++)//筛出[1,50000]内的质数 (50000>sqrt(maxint)) 
	{
	  if(!flag[i]) prime.push_back(i);
	  for(int j=2; i*j<=MARX-10; j++)
	    flag[i*j] = 1;
	}
	 
	for(int i=0,size=prime.size(); i<size; i++)//使用筛出的质数, 再筛去[l,r]的合数 
	  for(int j=max(2ll,(l-1)/(prime[i])+1); prime[i]*j <= r; j++)
		//当j过小, 使prime[i]*j <l, 对区间无贡献, 且会导致数组越界 
		//则为j设置一合理初值,以避免越界,并减小循环次数 
		flag1[prime[i]*j-l] = 1;
	for(int i=l; i<=r; i++) ans += (!flag1[i-l]);//统计答案 
	printf("%lld",ans);
}
