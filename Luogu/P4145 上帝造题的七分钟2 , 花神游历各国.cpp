//知识点:区间操作/线段树/分块(暴力算法) 
/*
给定一段数列
有两种操作:
1.对某区间全部取平方
2.查询某区间的和

由于开方运算,不同于四项基本运算
不符合结合律与分配律
故无法进行大区间操作

但是,可以发现:
即使是本题数据范围的上界 10^12
经过5次开方后,也会变成 1

故:可以想到一种基于分块的(伪)暴力做法:

对于每一个区间,记录它被修改的次数(即被开方的次数)
1.如果它的被修改次数 不小于5 
  证明此区间的所有元素的值
  都已变成了1
  所以不需要进行修改操作
  直接return ;即可
  
2.如果它的修改次数 小于5
  说明此区间 可能 还有未被开方开尽的元素
  继续向树的下层递归
  并将此区间的修改次数++ 
  
  遇到未被开方开尽的 叶子元素时,
  对其进行开方操作
  并且return ;并更新树的上端 
   
查询操作 即经典的区间查询操作

由于所有修改操作都已被递归完成,
所以不需要懒标记 
*/ 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#define int long long
#define ls s * 2
#define rs s * 2 + 1
const int MARX = 1e5+10;
struct node
{
    int w,l,r,num;
}a[MARX*4];
int n,m , q,x,y,k;
int raw[MARX];
inline int read()//快读 
{
    int fl=1,w=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') fl=-1;ch=getchar();}
    while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
    return fl*w;
}
/*
void check(int s)
{
    printf("%lld  %lld ~ %lld : %lld \n",s,a[s].l,a[s].r,a[s].w);
    if(a[s].l==a[s].r) return ;
    check(ls),check(rs);
}
*/
void build(int s , int l , int r)//递归建树 
{
    int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
    if(l==r) //叶子结点 
      {
      	a[s].w=raw[l];
      	return ;
      }
    build (ls,l,mid);
    build (rs,mid+1,r);
    a[s].w=a[ls].w+a[rs].w;
}
void change(int s , int l , int r )//修改操作 
{
	if(a[s].num>5) return ;//此区间被开方开尽 
    if(a[s].l>=l && a[s].r<=r)//此区间需要被修改 
      {
      	a[s].num++;//修改次数++ 
      	if(a[s].l==a[s].r)//叶子结点,直接进行修改 
		  {
		  	a[s].w=sqrt(a[s].w);
		    return ;
		  }
      }
    int mid=(a[s].l+a[s].r)>>1;
    if(l<=mid) change(ls,l,r);//修改左右子树 
    if(r>mid)  change(rs,l,r);
    a[s].w=a[ls].w + a[rs].w;//更新根部 
}
int search(int s , int l , int r)//经典区间查询操作 
{
    if(a[s].l>=l && a[s].r<=r)//此区间全部被包含 
      return a[s].w;
    int mid=(a[s].l+a[s].r)>>1,ans=0;
    if(l<=mid) ans+=search(ls,l,r);//查询左右子树 
    if(r>mid) ans+=search(rs,l,r);
    return ans;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;i++) raw[i]=read();
    build(1,1,n);
    m=read();
    while(m--)
      {
      	q=read(),x=read(),y=read();
      	if(x>y) std::swap(x,y);
      	if(q==0) change(1,x,y);
      	else printf("%lld\n",search(1,x,y));
      	//check(1);
      }
}
