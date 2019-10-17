//知识点: 二分答案,单调队列,DP
/*
假设g = 花费金币数 
 
分析题意: 
1.可以发现 , 
  每个点只能由 
  区间[i点距离-(d+g),i点距离-(d-g)]
  转移而来
  
  转移第i+1个点时,
  转移区间可由上个转移区间
  整体右移得到
  满足滑动窗口问题的性质
  故可以,使用单调队列,
  进行DP优化 

2.对于要确定的变量g的值:
  可以发现,
  当g取一个较大的值的时候,
  所能转移的范围
  包括,比此时g小的值的转移范围 
  满足单调性,
  可以进行二分答案 
  
算法实现:
  故,使用二分答案,枚举变量g的值 
  在check中,跑一遍单调队列优化DP
  检查总得分
  是否可以达到要求的 k  

注意事项: 
1.对于此题转移区间
  对象并不是点的编号
  而是 距离区间
  所以在进行滑动窗口右移时
  要注意当前不可用于转移的点,
  可能会在之后 有所贡献

  所以要再开一个队列,
  用来存储这种当前暂无贡献的点
  以免漏解错解 
*/
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
#define max(a,b) a>b?a:b
const int MARX = 5e5+10;
const int INF = 0x7f;
//=============================================================
int n,d,k,ans;
int a[MARX],far[MARX],f[MARX],qu[5*MARX];
//=============================================================
inline int read()//迫真快读 
{
	int readd; 
	scanf("%lld",&readd); 
	return readd;
}
bool check(int s)
{
	int l=max(1,d-s),r=d+s , h=1,t=1,start=-1;//获得左右转移区间,并构建单调队列 
	std::queue <int> wait_from;//储存当时暂无贡献的点 
	wait_from.push(0);
	memset(f,-INF,sizeof(f));f[0]=0;//存答案的变量 ,进行初始化 
	for(int i=1;i<=n;i++) 
	  if(far[i]>=l && far[i]<=r)//找到第一个能由起点转移到的点
	  {
	  	start=i;
		break;
	  }
	if(start==-1) return 0;//无法进行转移 
	for(int i=start;i<=n;i++)
	{
	  while(!wait_from.empty())//将此时可以用来转移的点加入单调队列 
	  {
	  	int front=wait_from.front();
	  	if(far[front]+l>far[i])break;//当前点,及之后的点 在转移区间右侧,不可用于转移 
	  	wait_from.pop();
		if(far[front]+r<far[i]) continue;//当前点在转移区间左侧 ,不可用于转移 
	    while(f[qu[t]]<=f[front] && t>=h) t--;//加入单调队列 
	  	qu[++t]=front;
	  }
	  if(far[qu[t]]+r<far[i]) continue;//如果无法转移到此点 (原为break,改成continue后AC) 
	  while(far[qu[h]]+r < far[i]) h++;//删除无法用于转移的点 
	  
	  int from=qu[h];
	  f[i]=f[from]+a[i];//进行转移 
	  wait_from.push(i);//加入暂存队列 
	  if(f[i]>=k) return 1;//满足答案需求 
	}
	return 0;
}
//=============================================================
signed main()
{
	n=read(),d=read(),k=read();
	for(int i=1;i<=n;i++) far[i]=read(),a[i]=read(); 
	int le=0,ri=2e9+10;
	if(!check(ri))//无论如何都无法满足答案 
	{
	  printf("-1");
	  return 0;
	}
	while(le<=ri)//二分答案 枚举 花费数 
	{
	  int mid=(le+ri)>>1;
	  if(check(mid)) ans=mid,ri=mid-1;
	  else le=mid+1;
	}
	printf("%lld",ans);
}
