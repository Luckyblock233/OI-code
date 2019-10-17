//知识点：康托展开
/*
康托展开:
即: 求 元素为 1～N 的一个给定全排列,
	在所有 元素为 1～N 全排列中的排名
如: 1 2 3 ,其康托展开为1
	1 3 2 ,其康托展开为2
	3 2 1 ,其康托展开为6

求得方法:
采用进制转换法,
将一个 给定全排列 
转化为 (XXXXX...)unknow进制的形式 

转换方式如下:

对于一个全排列，第i为有n+1-i种选择，
如果用变进制数表示，这一位就是n+1-i进制的。
如果这一位选择了第k种情况，
那么对应的变进制数的这一位就是k。
为了方便起见，通常以0起下标。

例1.12345变成变进制数是(00000)
首位1是5种选择{1,2,3,4,5}的第1种，故变为0
次位2是4种选择{2,3,4,5}的第1种，故变为0 
【解释：为什么是4种选择，其实是还没有使用过的数字的总数，下同】
中间位3是3种选择{3,4,5}的第1种，故变为0
次低位4是2种选择{4,5}的第1种，故变为0
末位5是1种选择的{5}第1种，故变为0
最后，1,2,3,4,5变成了 (00000)unknown

例2.把1,4,5,2,3变成变进制数
首位1是5种选择{1,2,3,4,5}的第1种，故变为0
次位4是4种选择{2,3,4,5}的第3种，故变为2
中间位5是3种选择{2,3,5}的第3种，故变为2
次低位2是2种选择{2,3}的第1种，故变为0
末位3是1种选择的{3}第1种，故变为0
最后，1,4,5,2,3变成了 (02200) unknown

可以看到，第i位的值就是 ai 
减去它左边比它小的数的数量-1 

通过进制转换,可以得知每一位上的数
在原序列中的排名情况

在进制转换中,需要统计0~a[i]中
被用过的数
这里可以通过树状数组求前缀和
来进行优化 

然后 通过规律得知：
一个进制转换后为 (a,b,c,d,e,...)unknown的全排列 
其康托展开 = (a*(n-1)!) + (b*(n-2)!) + (c*(n-3)!) + (d*(n-4)!) + .....+ ?*1! + ??*0!
*/ 
#include<cstdio>
#include<cctype>
#define int long long
#define lowbit(a) a&(-a)
//============================================
const int MARX = 1e6+10;
const int mod = 998244353;
int n,sum;
int a[MARX],b[MARX],fac[MARX] = {1,1};
//============================================
inline int read()//此题卡快读 
{
	int tmp;
	scanf("%lld",&tmp);
	return tmp;
}
inline void change(int ta)//单点修改 
{
	for(int i=ta;i<=n;i+=lowbit(i))
	  a[i]+=1;
}
inline int search(int ta)//区间查询 
{
	int tmp=0;
	for(int i=ta;i>0;i-=lowbit(i))
	  tmp+=a[i];
	return tmp;
}
//============================================
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	  fac[i]=fac[i-1]*i%mod;//计算阶乘 
	for(int i=1;i<=n;i++)
	  {
	  	b[i]=read();//转换进制数 
	  	int tmp=b[i]-search(b[i]-1);
	  	change(b[i]);
	  	b[i]=tmp-1;
	
		sum=(sum+ fac[n-i]*b[i]%mod )%mod;//进制转康托展开 
		//sum=( (sum+b[i]%mod)%mod*(n-i)%mod)%mod;  //另一种可行的转换方式 
	  }
	printf("%lld",(sum+1)%mod);
}
