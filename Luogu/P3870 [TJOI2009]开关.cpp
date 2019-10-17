//֪ʶ��:�߶��� 
/*
���߶���,ά��ÿһ���� ���Ƶ� ����

���ڷ��򿪹صƲ���,
����: ��������=�������-��ʱ��������

ͬʱ��������,
��ʾ�·����������� , ��Ҫ��ȡ��
����ȡ�� ����,���ɻص�ԭ״̬
���������ʹ��bool��
ÿ�θ���,ȡ������ 
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
void build(int s , int l , int r)//����,��ֵ�� 0 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) return ;
	build (ls,l,mid);
	build (rs,mid+1,r);
}
void pushdown(int s)//�·������ 
{
	a[ls].w=(a[ls].r-a[ls].l+1)-a[ls].w;
	a[rs].w=(a[rs].r-a[rs].l+1)-a[rs].w;
	a[ls].tag=!a[ls].tag , a[rs].tag=!a[rs].tag;//ȡ�� 
	a[s].tag=0;
}
void change(int s , int l , int r)//�����޸� 
{
	if(a[s].l>=l && a[s].r<=r)
	  {
	  	a[s].w=(a[s].r-a[s].l+1)-a[s].w;//���� 
		a[s].tag=!a[s].tag;
	  	return ;
	  }
	if(a[s].tag) pushdown(s);
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r);
	if(r>mid)  change(rs,l,r);
	a[s].w=a[ls].w+a[rs].w;
}
int search(int s , int l , int r)//������� 
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
