//֪ʶ��:�������/�߶���
/*
�߶��� �����Դ� ��O2�ɹ�
���߶���ά���������ֵ 

Ϊ����RE, 
�����������������䷶Χ
(����ʱ��ᱬը) 

��NUM��ʾ��ǰ���еĳ��� 

�����޸Ĳ���
ֱ�ӽ��е����޸ļ���
����NUM��Ԫ�ظ���ΪҪ���������

���ڲ�ѯ����,
��:��ѯ����[NUM-L,NUM]
�ҵ����ֵ���� 
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
void build(int s , int l , int r)//�ݹ齨�� 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) return ;
	build (ls,l,mid);//�������� 
	build (rs,mid+1,r);
}
void change(int s , int l , int r , int k)//������� 
{
	if(a[s].l>=l && a[s].r<=r)//����Ҫ�������� 
	  {
	  	a[s].w+=(a[s].r-a[s].l+1)*k;//���� 
	  	return ;
	  }
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//������������������� 
	if(r>mid)  change(rs,l,r,k);
	a[s].w=max(a[ls].w,a[rs].w);
}
int search(int s , int l , int r)//�����ѯ 
{
	if(a[s].l>=l && a[s].r<=r)//����Ҫ�������� 
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
