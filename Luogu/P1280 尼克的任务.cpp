//知识点:记忆化搜索/线性DP 
/*
欲求得最大休息时间
即求得最小工作时间 

使用f[]数组,
记录 完成第i个任务后, 
最小的工作时间(包括第i个任务的时间) . 

先将任务按照开始时间升序排列 
搜索时,记录当前任务的编号
枚举据 当前任务结束点 
最近开始的任务(可能有多个)
然后进行转移
并对返回值取最小值 

当没有任务可以转移时
(即到达了时间的结束),
使f[i] = 当前任务持续时间
并返回当前任务持续时间

递归更新之前任务的 f[i] 

最后输出f[0]即可 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
#define R register
#define min(a,b) a<b?a:b
//=================================================
const int MARX = 1e4+10;
struct kikaku
{
	int l,r;
}a[MARX];
int n,k,ans;
int f[MARX];
//=================================================
bool cmp(kikaku x,kikaku y)
{
	return x.l<y.l;
}
int dfs(int now)//搜索 
{
	if(f[now]) return f[now];//已经被赋值 
	int res=MARX,limit=MARX;
	//赋初值(res为之后任务的持续时间,limit被赋值为最近的任务开始时间 
	for(R int i=now+1;i<=k;i++)
	  {
	  	if(a[i].l>limit) break;//不再是最近任务 
	    if(a[i].l>a[now].r)//可以开始 
	      res=min(res,dfs(i)),limit=min(limit,a[i].l);//更新最值 
	  }
	f[now]=a[now].r-a[now].l+1;//更新当前任务 
	if(res==MARX) return f[now];//后面没有任务 
	return f[now]+=res;//后面有任务 
}
//==================================================
signed main()
{
	scanf("%d%d",&n,&k);
	a[0].l=1;//赋初值 
	for(R int i=1;i<=k;i++)//获得一个任务的左右端点 
	  scanf("%d%d",&a[i].l,&a[i].r),a[i].r+=a[i].l-1;
	std::sort(a+1,a+k+1,cmp);//升序排序 
	dfs(0);	//搜索 
	printf("%d",n-f[0]);//获得最大空余时间 
}
