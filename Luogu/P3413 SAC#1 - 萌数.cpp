//知识点: 数位DP 
/*
By:Luckyblock
题目要求:
给定 两整数l,r
求 [l,r] 中有多少个 包含长度>=2的回文串 的数
l <=r <= 1e1000  

分析题意:
可以发现, 一些显然的结论:
1.包含长度 >=2 的回文串 等价于:
  包含 长度==2 或者 包含 长度==3 的回文串
  
  证明: 
  最短的回文串只有: aa 或者 aba 两种形态
  且 在一个回文串首尾 各添加一相同字母后, 得到的仍为一回文串 
  
  若考虑 每一个数各位 的选择情况, 即可得知其是否合法 
  考虑数位DP 

2.可以发现, 对于一个合法的数, 向其尾部/首部添加任意数量的任意数,
  得到的新数 仍然是一个合法的数
   
  则可使用记忆化DFS 实现数位DP.
  对于一个数, 若其已知其最后一位, 与倒数第二位,
  则可以通过选择 向尾部添加的数, 从而构造合法的数
  
3.开始构建状态:
  设 f[i][j][k][0/1]: 枚举到第i位, 第i-1位为j, 第i-2位为k ,0/1代表在第i位前是否有回文串  
  
  - 为什么需要标记 是否有回文串?
  	对于 下列两种状态:
	54123 , 32123,
	尾部两元素相同, 但是前者不合法, 后者合法
	则需要进行标记, 防止错解发生 

4.然后就可以套数位DP的 记忆化dfs模板
  1.前缀和思想, 求 1 ~ l-1 的答案, 求 1 ~ r 的答案, 并进行相减
  2.枚举每一位数, 判断是否全为前导零, 是否到达可选择的上界, 是否已为合法串
  3.深入到 第0层时, 说明构造完成, 返回答案即可
  4.注意进行记忆化 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define ll long long
const int MARX = 1010;
const ll mod = 1e9+7;
//=============================================================
char num[MARX];
//f[i][j][k][0/1]: 枚举到第i位, 第i-1位为j, 第i-2位为k 
ll ans1,ans2, lim[MARX],f[MARX][10][10][2];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//分别代表: 枚举到的位数, 倒数第一个数, 倒数第二个数, 是否到达可选择的上界, 是否全为前导零, 是否为合法状态 
int dfs(ll pos, ll last1, ll last2, bool limit, bool zero, ll flag) 
{
	ll sum = 0;
	if(!pos) return flag;//搜到第 0位, 返回答案 
	if(!limit && (!zero) && (last1 != -1) && (last2 != -1) && f[pos][last1][last2][flag] != -1) return f[pos][last1][last2][flag];//已被搜过, 返回记忆化的值                        
	for(int i = 0, up = (limit?lim[pos]:9); i <= up; i ++)//枚举每一位(注意判断上界 
	{
	  bool limit1 = (limit && i == up), zero1 = (!i && zero);//更新各变量 
	  ll flag1 = (flag || (!zero && i == last1) || (!zero && i == last2));//判断是否合法 
	  ll last11 = (zero1 ?-1 : i), last21 = (zero ? -1 : last1);//更新 倒数的数 
	  ll ret = dfs(pos-1, last11, last21, limit1, zero1,flag1) % mod; 
	  sum = (sum + ret) % mod;//累加返回值 
	}
	if(!limit && (!zero) && (last1 != -1) && (last2 != -1)) return (f[pos][last1][last2][flag] = sum);//合法状态,进行记忆化 
	return sum;
}
ll solve(char s[], ll op) //将字符串 转化为数字 
{
	ll lth = strlen(s+1), tot = 1;
	memset(f,-1,sizeof(f));//初始化 
	for(ll i = 1; i <= lth; i ++) lim[lth-i+1] = s[i] - '0';//倒序存储 
	while(lim[tot] - op < 0)//l-1的特殊操作 
	{
	  if(tot == lth) break;
	  lim[tot] = 9, tot ++;
	}
	lim[tot] -= op;//l-1的特殊操作 
	return dfs(lth,-1,-1,1,1,0);
}
//=============================================================
signed main()
{
	scanf("%s", num+1);  ans1 = solve(num,1);//求解 
	scanf("%s", num+1);  ans2 = solve(num,0);
	printf("%lld",(ans2 - ans1 + mod) % mod);//前缀和 
}
