//知识点:区间操作/线段树 
/*
给定一段数列, 
有两种操作:
1.构建一个长度为(R-L+1)的等差序列,
  与区间[L,R]中的元素对应相加
2.查询某个点的值

此题的修改非常有特色
各点修改的值不同, 但是等差
想个方法,将其转化为相同的修改
 
看到 等差序列,单点查询
可以想到,使用差分思想

用线段树,维护一个差分数组 
对于一个等差序列修改,
   1.L点与之前 点的差分值+=k(首项 
   2.[L+1,R]中的点 ,差分值+=d (公差
   3.R+1点的差分值+= -(k+(y-x)*d)

对于单点查询 点x,
即求出[1,X] 的区间和

此题就变成了区间修改,区间查询的线段树模板 

注意等差序列修改的边界
  R必须<=n 
  L==R时，不进行 2.[L+1,R]中的点 ,差分值+=d (公差
  R+1>n时, 不进行  3.R+1点的差分值+= -(k+(y-x)*d)
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
	int w,l,r,tag;
}a[MARX*4];
int n,m,raw[MARX];
void build(int s , int l , int r)//递归建树 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) //叶子节点 
	  {
	  	a[s].w=raw[l]-raw[l-1];
	  	return ;
	  }
	build (ls,l,mid);//左右子树 
	build (rs,mid+1,r);
	a[s].w=a[ls].w+a[rs].w;
}
void pushdown(int s)//下放懒标记 
{
	a[ls].w+=(a[ls].r-a[ls].l+1)*a[s].tag;//更新左右儿子的值 
	a[rs].w+=(a[rs].r-a[rs].l+1)*a[s].tag;
	a[ls].tag+=a[s].tag , a[rs].tag+=a[s].tag;//更新左右儿子的懒标记 
	a[s].tag=0;
}
void change(int s , int l , int r , int k )//区间更新 
{
	if(a[s].l>=l && a[s].r<=r)//在需要的区间内 
	  {
	  	a[s].w+=(a[s].r-a[s].l+1)*k;//更新 
		a[s].tag+=k;
	  	return ;
	  }
	if(a[s].tag) pushdown(s);//下放 
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//左右区间包括所需区间 
	if(r>mid)  change(rs,l,r,k);
	a[s].w=a[ls].w+a[rs].w;
}
int search(int s , int l , int r)//区间查询 
{
	if(a[s].l>=l && a[s].r<=r)//在需要的区间内 
	  return a[s].w;
	if(a[s].tag) pushdown(s);
	int mid=(a[s].l+a[s].r)>>1,ans=0;
	if(l<=mid) ans+=search(ls,l,r);
	if(r>mid) ans+=search(rs,l,r);
	return ans;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) 
	  scanf("%lld",&raw[i]);
	build(1,1,n);
	while(m--)
	  {
	  	int q,x,y,k,d;
	  	scanf("%lld",&q);
	  	if(q==1) 
		  {
		    scanf("%lld%lld%lld%lld",&x,&y,&k,&d);
		    if(y>n) y=n;//修改的点不能越界 
			change(1,x,x,k);
		    if(x<y) change(1,x+1,y,d);//注意边界,要修改的等差序列长度为1的情况 
		    if(y+1<=n) change(1,y+1,y+1,-(k+(y-x)*d));//修改的点不能越界 
		  }
	  	else 
		  {
		  	scanf("%lld",&x);
		    printf("%lld\n",search(1,1,x));	
		  }
	  }
}
