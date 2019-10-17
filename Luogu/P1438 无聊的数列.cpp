//֪ʶ��:�������/�߶��� 
/*
����һ������, 
�����ֲ���:
1.����һ������Ϊ(R-L+1)�ĵȲ�����,
  ������[L,R]�е�Ԫ�ض�Ӧ���
2.��ѯĳ�����ֵ

������޸ķǳ�����ɫ
�����޸ĵ�ֵ��ͬ, ���ǵȲ�
�������,����ת��Ϊ��ͬ���޸�
 
���� �Ȳ�����,�����ѯ
�����뵽,ʹ�ò��˼��

���߶���,ά��һ��������� 
����һ���Ȳ������޸�,
   1.L����֮ǰ ��Ĳ��ֵ+=k(���� 
   2.[L+1,R]�еĵ� ,���ֵ+=d (����
   3.R+1��Ĳ��ֵ+= -(k+(y-x)*d)

���ڵ����ѯ ��x,
�����[1,X] �������

����ͱ���������޸�,�����ѯ���߶���ģ�� 

ע��Ȳ������޸ĵı߽�
  R����<=n 
  L==Rʱ�������� 2.[L+1,R]�еĵ� ,���ֵ+=d (����
  R+1>nʱ, ������  3.R+1��Ĳ��ֵ+= -(k+(y-x)*d)
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
void build(int s , int l , int r)//�ݹ齨�� 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) //Ҷ�ӽڵ� 
	  {
	  	a[s].w=raw[l]-raw[l-1];
	  	return ;
	  }
	build (ls,l,mid);//�������� 
	build (rs,mid+1,r);
	a[s].w=a[ls].w+a[rs].w;
}
void pushdown(int s)//�·������ 
{
	a[ls].w+=(a[ls].r-a[ls].l+1)*a[s].tag;//�������Ҷ��ӵ�ֵ 
	a[rs].w+=(a[rs].r-a[rs].l+1)*a[s].tag;
	a[ls].tag+=a[s].tag , a[rs].tag+=a[s].tag;//�������Ҷ��ӵ������ 
	a[s].tag=0;
}
void change(int s , int l , int r , int k )//������� 
{
	if(a[s].l>=l && a[s].r<=r)//����Ҫ�������� 
	  {
	  	a[s].w+=(a[s].r-a[s].l+1)*k;//���� 
		a[s].tag+=k;
	  	return ;
	  }
	if(a[s].tag) pushdown(s);//�·� 
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//������������������� 
	if(r>mid)  change(rs,l,r,k);
	a[s].w=a[ls].w+a[rs].w;
}
int search(int s , int l , int r)//�����ѯ 
{
	if(a[s].l>=l && a[s].r<=r)//����Ҫ�������� 
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
		    if(y>n) y=n;//�޸ĵĵ㲻��Խ�� 
			change(1,x,x,k);
		    if(x<y) change(1,x+1,y,d);//ע��߽�,Ҫ�޸ĵĵȲ����г���Ϊ1����� 
		    if(y+1<=n) change(1,y+1,y+1,-(k+(y-x)*d));//�޸ĵĵ㲻��Խ�� 
		  }
	  	else 
		  {
		  	scanf("%lld",&x);
		    printf("%lld\n",search(1,1,x));	
		  }
	  }
}
