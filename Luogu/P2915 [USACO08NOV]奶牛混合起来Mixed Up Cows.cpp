//知识点:状态压缩 DP/记忆化搜索 
/*
可以使用二进制拆分,
来模拟队列中 牛 的存在情况
以进行状态压缩
如: 9(十进制) = 1001(二进制) ,
表示队列中有第1头和第4头牛 
 
可以使用记忆化搜索 
这里打了一个状态压缩DP 

数组f[i][j]
表示 队列情况为i,队末为j的队列
满足条件的方案数

状态转移方程: f[i+(1<<(k-1))][k]+=f[i][j];
表示向 队列情况为i,队末为j的队列 的末尾
添加一头编号为k的牛

最后统计出所有满队列的答案总和 
即:队列中有n人的队列的答案总和 
*/
#include<cstdio>
#include<cctype>
#define int long long
using namespace std;
int n,kkk;
int s[17];
int f[(1<<16)+1][17];
int abs(int a){return a>=0?a:-a;}
signed main()
{
	scanf("%lld%lld",&n,&kkk);
	for(int i=1;i<=n;i++) //输入顺便初始化 
	  {
	  	scanf("%lld",&s[i]);
		f[1<<(i-1)][i]=1;
	  }
	for(int i=1;i<=(1<<n)-1;i++)//枚举队列情况 
	  for(int j=1;j<=n;j++)//枚举队列末尾元素 
	    if( (1<<(j-1))&i )//在队列中 
	      for(int k=1;k<=n;k++)//枚举要添加的元素 
	        if( ((1<<(k-1))&i)==0 && (abs(s[k]-s[j])>kkk) )//不在队列中 且 添加到尾部合法 
	          f[i+(1<<(k-1))][k]+=f[i][j];//进行添加,更新答案 
	int ans=0;
	for(int i=1;i<=n;i++)//统计答案 
	  ans+=f[(1<<n)-1][i];
	printf("%lld",ans);
}
