//知识点:分块/暴力
/*
看到此题 :
有 强制底层修改查询,且每次询问的参数不同 
并且 N<=1e6 , Q<=3000 的数据范围，
线段树必然是十分不可做的. 
这时考虑一种暴力算法:分块.

保留原序列, 
再 建立sqrt(n)个区块 , 
使各区块赋初值为原序列
然后对 每个区块 单独进行排序(不修改原序列 

对于修改操作:
	 1.对于整块的区块,
	 将修改值当做懒标记,记录
	 2.对于非整块的区块( 即两端部分
	 先暴力修改原序列
	 在将原序列 全部 对应部分
	 重新赋值给此区块
	 再重新对此区块进行排序
	 
对于查询操作:
	1. 对于非整块的区块
	   直接暴力查询符合的个数
	2.对于整块的区块
	   对每一个区块进行二分查找
	   查找到满足条件的分界人
	   然后计算出符合的总人数 
*/ 
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define int long long
#define R register
//========================================
const int MARX = 1e6+10;
int n,m;
int block,tot;
int raw[MARX],cooked[MARX];
int le[MARX],ri[MARX],bel[MARX],tag[MARX];
//========================================
void build()//建立sqrt(n)个区块 
{
	block=sqrt(n);//每个区块大小 
	
	tot=n/block;//获得总区块数 
	if(n%block) tot++;
	
	for(R int i=1;i<=n;i++)//赋初值,并获得每个点的区块 
	  cooked[i]=raw[i],
	  bel[i]=(i-1)/block+1;
	  
	for(R int i=1;i<=tot;i++)//获得每个区块的边界 
	  le[i]=(i-1)*block+1,
	  ri[i]=i*block;
	ri[tot]=n;//特判最右 的 区块边界 
	  
	for(R int i=1;i<=tot;i++)//对每个区块排序 
	  std:: sort(cooked+le[i],cooked+1+ri[i]);
}
void change(int l,int r,int k) 
{
	if(bel[l]==bel[r])//两端点在同一区块 
	  {
	  	for(R int i=l;i<=r;i++)//暴力修改原序列
	  	  raw[i]+=k;
	  	for(R int i=le[bel[l]];i<=ri[bel[r]];i++)
	  	  cooked[i]=raw[i];//将原序列 全部 对应部分,重新赋值给此区块
	  	std:: sort(cooked+le[bel[l]],cooked+ri[bel[r]]+1);//重新对此区块进行排序
	  	return ;
	  }
	
	for(R int i=l;i<=ri[bel[l]];i++)//暴力修改不完整区块
	  raw[i]+=k;
	for(R int i=le[bel[l]];i<=ri[bel[l]];i++)//将原序列 全部 对应部分,重新赋值给此区块
	  cooked[i]=raw[i];
	std:: sort(cooked+le[bel[l]],cooked+ri[bel[l]]+1);//重新对此区块进行排序
	
	for(R int i=bel[l]+1;i<=bel[r]-1;i++)//整个的区块,记录懒标记 
	  tag[i]+=k;
	
	for(R int i=le[bel[r]];i<=r;i++)//同上,对不完整区块进行修改 
	  raw[i]+=k;
	for(R int i=le[bel[r]];i<=ri[bel[r]];i++)
	  cooked[i]=raw[i];
	std:: sort(cooked+le[bel[r]],cooked+ri[bel[r]]+1);
	
}
int search(int l,int r,int c)
{
	int ans=0;
	
	if(bel[l]==bel[r])//两端点在同一区块 
	  {
	  	for(R int i=l;i<=r;i++)//暴力查询即可 
	  	  ans+=(tag[bel[l]]+raw[i]>=c);
	  	return ans;
	  }
	
	for(R int i=l;i<=ri[bel[l]];i++)//端点区块,暴力查询 
	  ans+=(tag[bel[l]]+raw[i]>=c);
	for(R int i=le[bel[r]];i<=r;i++)
	  ans+=(tag[bel[r]]+raw[i]>=c);
	  
	for(R int i=bel[l]+1;i<=bel[r]-1;i++)//完整区块 
	  {
	  	if(cooked[le[i]]+tag[i]>=c) //全部符合条件(因为排好序后最左边为最小值 
	  	  {
	  	  	ans+=block;//加上区块大小 
	  	  	continue;
		  }
	  	int ll=le[i],rr=ri[i];
	  	int sum=0,mid;
	  	while(ll<=rr)//二分查找,第一个满足的人 
	  	  {
	  	  	mid=(ll+rr)>>1;
	  	  	if(cooked[mid]+tag[i]>=c) rr=mid-1,sum=ri[i]-mid+1;
	  	  	else ll=mid+1;
		  }
		ans+=sum;//添加 
	  }
	return ans;
}
//========================================
signed main()
{
	char q;
	int x,y,k,c;
	std::cin>>n>>m;
	for(R int i=1;i<=n;i++) std::cin>>raw[i];
	build();
	while(m--)
	  {
	  	std::cin>>q;
		std::cin>>x>>y;
	  	if(q=='M') std::cin>>k,change(x,y,k);
	  	else std::cin>>c,printf("%lld\n",search(x,y,c));
	  }
}
/*

//超蠢暴力线段树 50分 TLE版:

#include<cstdio>
#define int long long
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a
#define ls s * 2
#define rs s * 2 + 1
using namespace std;
const int MARX = 1e6+10;
struct node
{
	int maxx,minn,w,l,r,tag;
}a[MARX*4];
int n,m,raw[MARX];
int x,y,k,c;
char q;
void build(int s , int l , int r)//递归建树 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) //叶子节点 
	  {
	  	a[s].w=raw[l];
	  	a[s].maxx=a[s].w;
	  	a[s].minn=a[s].w;
	  	return ;
	  }
	build (ls,l,mid);//左右子树 
	build (rs,mid+1,r);
	a[s].maxx=max(a[ls].maxx,a[rs].maxx);
	a[s].minn=min(a[ls].minn,a[rs].minn);
}
void change(int s , int l , int r , int k)//区间更新 
{
	if(a[s].l>=l && a[s].r<=r && a[s].l==a[s].r)//在需要的区间内 
	  {
	  	a[s].w+=k;//更新
		a[s].maxx=a[s].w;
	  	a[s].minn=a[s].w;
	  	return ;
	  }
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//左右区间包括所需区间 
	if(r>mid)  change(rs,l,r,k);
	a[s].maxx=max(a[ls].maxx,a[rs].maxx);
	a[s].minn=min(a[ls].minn,a[rs].minn);
}
int search(int s , int l , int r, int c)//区间查询 
{
	if(a[s].l>=l && a[s].r<=r && a[s].minn>=c)//在需要的区间内 
	  return a[s].r-a[s].l+1;
	int mid=(a[s].l+a[s].r)>>1,ans=0;
	if(l<=mid && a[ls].maxx>=c) ans+=search(ls,l,r,c);
	if(r>mid && a[rs].maxx>=c) ans+=search(rs,l,r,c);
	return ans;
}
signed main()
{
	scanf("%lld%lld\n",&n,&m);
	for(int i=1;i<n;i++) scanf("%lld",&raw[i]);
	scanf("%lld\n\n",&raw[n]);
	build(1,1,n);
	while(m--)
	  {
	  	scanf("%c %lld %lld ",&q,&x,&y);
	  	if(q=='M') scanf("%lld\n\n",&k),change(1,x,y,k);
	  	else scanf("%lld\n",&c),printf("%lld\n",search(1,x,y,c));
	  }
}
 
*/
