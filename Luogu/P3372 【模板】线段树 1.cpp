#include<cstdio>
#define int long long
using namespace std;
const int MARX = 1e5+10;
struct node
{
	int l,r,w,f;
}a[4*MARX]; 
int n,m;
int raw[MARX];
void build(int l,int r,int k)
{
	a[k].l=l,a[k].r=r;
	if(l==r)
	  {
	  	a[k].w=raw[l];
	  	return ;
	  }
	int mid=(l+r)/2;
	int k2=(k<<1);
	build(l,mid,k2);
	build(mid+1,r,k2+1);
	a[k].w=a[k2].w+a[k2+1].w;
}
void down(int k)
{
	int k2=(k<<1),f1=a[k].f;a[k].f=0;
	a[k2].f+=f1;
	a[k2+1].f+=f1;
	a[k2].w+=f1*(a[k2].r-a[k2].l+1);
	a[k2+1].w+=f1*(a[k2+1].r-a[k2+1].l+1);
}
int sum(int l,int r,int k)
{
	if(a[k].l>=l && a[k].r<=r)
	  return a[k].w;
	if(a[k].f) down(k);
	int mid=(a[k].l+a[k].r)/2,k2=(k<<1);
	int ans=0;
	if(l<=mid) ans+=sum(l,r,k2);
	if(r>mid) ans+=sum(l,r,k2+1);
	return ans; 
}
void change(int l,int r,int w,int k)
{
	if(a[k].l>=l && a[k].r<=r)
	  {
	  	a[k].w+=(a[k].r-a[k].l+1)*w;
	  	a[k].f+=w;
	  	return ;
	  }
	if(a[k].f) down(k);
	int mid=(a[k].l+a[k].r)/2,k2=(k<<1);
	if(l<=mid) change(l,r,w,k2);
	if(r>mid) change(l,r,w,k2+1);
	a[k].w=a[k2].w+a[k2+1].w;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&raw[i]);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	  {
	  	int q,x,y,z;
	  	scanf("%lld",&q);
	  	if(q==1)
	  	  {
	  	  	scanf("%lld%lld%lld",&x,&y,&z);
	  	  	change(x,y,z,1);
		  }
		else
		  {
		  	scanf("%lld%lld",&x,&y);
		  	printf("%lld\n",sum(x,y,1));
		  }
	  }
}
