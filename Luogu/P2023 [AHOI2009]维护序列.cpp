//知识点:区间操作/线段树 
/*
对于一个给定数列
给出3种操作:
1.区间加法
2.区间乘法
3.区间查询

一道线段树模板题
设置两种懒标记:
加法标记与乘法标记

两种运算,对懒标记的影响不相同:
1.加法运算:
  只修改加法懒标记,使其加上一个值即可
2.乘法运算:
  根据:(k*a+b)*c = k*c*a+c*b,则有: 
  使:加法懒标记*=k,乘法懒标记*=k

在下放懒标记时,
某点的值 = (原值*乘法懒标记 + 区间长度*加法懒标记) 

由于懒标记可能为负值
所以要注意判断 
*/ 
#include<cstdio>
#include<cctype> 
#define ll long long
#define ls 2 * s
#define rs 2 * s + 1
//======================================================================
const ll MARX = 1e5+10;
struct node
{
    ll w,l,r,tagc,tagj;
}a[4*MARX];
ll n,m,p;
ll raw[MARX];
ll q,x,y,k;
//======================================================================
inline ll read()//快读 
{
    int fl=1;ll w=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') fl=-1;ch=getchar();}
    while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
    return fl*w;
}
void build(ll s,ll l,ll r)//递归建树 
{
    a[s].tagc=1,a[s].l=l,a[s].r=r;
    if(l==r)
      {
      	a[s].w=raw[l]%p;
      	return ;
      }
    ll mid = (l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    a[s].w=(a[ls].w+a[rs].w)%p;
}
inline void pushdown(ll s)
{
    ll tagc=a[s].tagc , tagj=a[s].tagj;
    
    a[ls].w=( (a[ls].w*tagc)%p + ((a[ls].r-a[ls].l+1)%p*tagj)%p )%p;//某点的值 = (原值*乘法懒标记 + 区间长度*加法懒标记)  
    a[rs].w=( (a[rs].w*tagc)%p + ((a[rs].r-a[rs].l+1)%p*tagj)%p )%p;
    
    a[ls].tagc=(a[ls].tagc*tagc)%p , a[rs].tagc=(a[rs].tagc*tagc)%p;//加法懒标记*=k,乘法懒标记*=k 
    a[ls].tagj=((a[ls].tagj*tagc)%p+tagj)%p; 
    a[rs].tagj=((a[rs].tagj*tagc)%p+tagj)%p;
    
    a[s].tagc=1,a[s].tagj=0;
}
void change(ll s,ll l,ll r,ll k,ll mode)//区间修改 
{
    if(a[s].l>=l && a[s].r<=r)
      {
      	if(mode==1)//乘法 
          {
          	a[s].w=(a[s].w*k)%p;
            a[s].tagc=(a[s].tagc*k)%p;//加法懒标记*=k,乘法懒标记*=k 
            a[s].tagj=(a[s].tagj*k)%p;
          }
        else //加法 
          {
            a[s].w=(a[s].w+(a[s].r-a[s].l+1)%p*k%p)%p ;
            a[s].tagj=(a[s].tagj+k)%p;//只修改加法懒标记,使其加上一个值即可 
          }
        return ;
      }
    pushdown(s);
    ll mid = (a[s].l+a[s].r)>>1;
    if(l<=mid) change(ls,l,r,k,mode);//递归左右子树 
    if(r>mid) change(rs,l,r,k,mode);
    a[s].w=(a[ls].w+a[rs].w)%p;
}
ll search(ll s,ll l,ll r)//区间查询 
{
    if(a[s].l>=l && a[s].r<=r)
      return a[s].w;
    pushdown(s);
    ll mid=(a[s].l+a[s].r)>>1,ans=0;
    if(l<=mid) ans=(ans+search(ls,l,r))%p;//递归左右子树 
    if(r>mid) ans=(ans+search(rs,l,r))%p;
    return ans%p;
}
signed main()
{
    n=read(),p=read();
    for(int i=1;i<=n;i++) raw[i]=read();
    build(1,1,n);
    m=read();
    while(m--)
      {
      	q=read(),x=read(),y=read();
      	if(q<3) { k=read()%p; change(1,x,y,k,q); }
        else printf("%lld\n",search(1,x,y));
      }
}
