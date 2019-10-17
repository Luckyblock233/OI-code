//知识点:区间操作/线段树
/*
线段树 常数稍大 开O2可过
用线段树维护区间最大值 

为避免RE, 
将操作次数当做区间范围
(但是时间会爆炸) 

用NUM表示当前序列的长度 

对于修改操作
直接进行单点修改即可
将第NUM个元素更改为要求的数即可

对于查询操作,
即:查询区间[NUM-L,NUM]
找到最大值即可 
*/ 
#include<cstdio>
#define int long long
#define max(a,b) a>b?a:b
#define ls s * 2
#define rs s * 2 + 1
using namespace std;
const long long MINN = -(2<<63);
const int MARX = 2e5+10;
struct node
{
	int w,l,r;
}a[MARX*4];
int n,m,mod,num;
void build(int s , int l , int r)//递归建树 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) return ;
	build (ls,l,mid);//左右子树 
	build (rs,mid+1,r);
}
void change(int s , int l , int r , int k)//区间更新 
{
	if(a[s].l>=l && a[s].r<=r)//在需要的区间内 
	  {
	  	a[s].w+=(a[s].r-a[s].l+1)*k;//更新 
	  	return ;
	  }
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//左右区间包括所需区间 
	if(r>mid)  change(rs,l,r,k);
	a[s].w=max(a[ls].w,a[rs].w);
}
int search(int s , int l , int r)//区间查询 
{
	if(a[s].l>=l && a[s].r<=r)//在需要的区间内 
	  return a[s].w;
	int mid=(a[s].l+a[s].r)>>1,ans=0;
	if(l<=mid) ans=max(ans,search(ls,l,r));
	if(r>mid) ans=max(ans,search(rs,l,r));
	return ans;
}
signed main()
{
	scanf("%lld %lld\n",&m,&mod);
	build(1,1,m);					
	char q;
	int x,last=0;
	while(m--)
	  {
	  	scanf("%c %lld\n",&q,&x);
	  	if(q=='A') num++,change(1,num,num,(x+last)%mod);
	  	else printf("%lld\n",last=search(1,max(num-x+1,1),num));
	  }
}
