//知识点:线段树 
/*
用线段树,维护每一段中 开灯的 数量

对于反向开关灯操作,
即令: 开灯数量=区间灯数-此时开灯数量

同时添加懒标记,
表示下方所控制区间 , 需要被取反
由于取反 两次,即可回到原状态
所以懒标记使用bool型
每次更新,取反即可 
*/ 
#include<cstdio>
#define int long long
#define max(a,b) a>b?a:b
#define ls s * 2
#define rs s * 2 + 1
using namespace std;
const int MARX = 1e5+10;
struct node
{
	int w,l,r;
	bool tag;
}a[MARX*4];
int n,m;
int q,x,y,k;
void build(int s , int l , int r)//建树,初值即 0 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) return ;
	build (ls,l,mid);
	build (rs,mid+1,r);
}
void pushdown(int s)//下放懒标记 
{
	a[ls].w=(a[ls].r-a[ls].l+1)-a[ls].w;
	a[rs].w=(a[rs].r-a[rs].l+1)-a[rs].w;
	a[ls].tag=!a[ls].tag , a[rs].tag=!a[rs].tag;//取反 
	a[s].tag=0;
}
void change(int s , int l , int r)//区间修改 
{
	if(a[s].l>=l && a[s].r<=r)
	  {
	  	a[s].w=(a[s].r-a[s].l+1)-a[s].w;//更新 
		a[s].tag=!a[s].tag;
	  	return ;
	  }
	if(a[s].tag) pushdown(s);
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r);
	if(r>mid)  change(rs,l,r);
	a[s].w=a[ls].w+a[rs].w;
}
int search(int s , int l , int r)//区间查找 
{
	if(a[s].l>=l && a[s].r<=r)
	  return a[s].w;
	if(a[s].tag) pushdown(s);
	int mid=(a[s].l+a[s].r)>>1;
	int ans=0;
	if(l<=mid) ans+=search(ls,l,r);
	if(r>mid) ans+=search(rs,l,r);
	return ans;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	build(1,1,n);
	while(m--)
	  {
	  	scanf("%lld%lld%lld",&q,&x,&y);
	  	if(!q) change(1,x,y);
	  	else printf("%lld\n",search(1,x,y));
	  }
}
