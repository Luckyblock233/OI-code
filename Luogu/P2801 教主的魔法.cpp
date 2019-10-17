//֪ʶ��:�ֿ�/����
/*
�������� :
�� ǿ�Ƶײ��޸Ĳ�ѯ,��ÿ��ѯ�ʵĲ�����ͬ 
���� N<=1e6 , Q<=3000 �����ݷ�Χ��
�߶�����Ȼ��ʮ�ֲ�������. 
��ʱ����һ�ֱ����㷨:�ֿ�.

����ԭ����, 
�� ����sqrt(n)������ , 
ʹ�����鸳��ֵΪԭ����
Ȼ��� ÿ������ ������������(���޸�ԭ���� 

�����޸Ĳ���:
	 1.�������������,
	 ���޸�ֵ���������,��¼
	 2.���ڷ����������( �����˲���
	 �ȱ����޸�ԭ����
	 �ڽ�ԭ���� ȫ�� ��Ӧ����
	 ���¸�ֵ��������
	 �����¶Դ������������
	 
���ڲ�ѯ����:
	1. ���ڷ����������
	   ֱ�ӱ�����ѯ���ϵĸ���
	2.�������������
	   ��ÿһ��������ж��ֲ���
	   ���ҵ����������ķֽ���
	   Ȼ���������ϵ������� 
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
void build()//����sqrt(n)������ 
{
	block=sqrt(n);//ÿ�������С 
	
	tot=n/block;//����������� 
	if(n%block) tot++;
	
	for(R int i=1;i<=n;i++)//����ֵ,�����ÿ��������� 
	  cooked[i]=raw[i],
	  bel[i]=(i-1)/block+1;
	  
	for(R int i=1;i<=tot;i++)//���ÿ������ı߽� 
	  le[i]=(i-1)*block+1,
	  ri[i]=i*block;
	ri[tot]=n;//�������� �� ����߽� 
	  
	for(R int i=1;i<=tot;i++)//��ÿ���������� 
	  std:: sort(cooked+le[i],cooked+1+ri[i]);
}
void change(int l,int r,int k) 
{
	if(bel[l]==bel[r])//���˵���ͬһ���� 
	  {
	  	for(R int i=l;i<=r;i++)//�����޸�ԭ����
	  	  raw[i]+=k;
	  	for(R int i=le[bel[l]];i<=ri[bel[r]];i++)
	  	  cooked[i]=raw[i];//��ԭ���� ȫ�� ��Ӧ����,���¸�ֵ��������
	  	std:: sort(cooked+le[bel[l]],cooked+ri[bel[r]]+1);//���¶Դ������������
	  	return ;
	  }
	
	for(R int i=l;i<=ri[bel[l]];i++)//�����޸Ĳ���������
	  raw[i]+=k;
	for(R int i=le[bel[l]];i<=ri[bel[l]];i++)//��ԭ���� ȫ�� ��Ӧ����,���¸�ֵ��������
	  cooked[i]=raw[i];
	std:: sort(cooked+le[bel[l]],cooked+ri[bel[l]]+1);//���¶Դ������������
	
	for(R int i=bel[l]+1;i<=bel[r]-1;i++)//����������,��¼����� 
	  tag[i]+=k;
	
	for(R int i=le[bel[r]];i<=r;i++)//ͬ��,�Բ�������������޸� 
	  raw[i]+=k;
	for(R int i=le[bel[r]];i<=ri[bel[r]];i++)
	  cooked[i]=raw[i];
	std:: sort(cooked+le[bel[r]],cooked+ri[bel[r]]+1);
	
}
int search(int l,int r,int c)
{
	int ans=0;
	
	if(bel[l]==bel[r])//���˵���ͬһ���� 
	  {
	  	for(R int i=l;i<=r;i++)//������ѯ���� 
	  	  ans+=(tag[bel[l]]+raw[i]>=c);
	  	return ans;
	  }
	
	for(R int i=l;i<=ri[bel[l]];i++)//�˵�����,������ѯ 
	  ans+=(tag[bel[l]]+raw[i]>=c);
	for(R int i=le[bel[r]];i<=r;i++)
	  ans+=(tag[bel[r]]+raw[i]>=c);
	  
	for(R int i=bel[l]+1;i<=bel[r]-1;i++)//�������� 
	  {
	  	if(cooked[le[i]]+tag[i]>=c) //ȫ����������(��Ϊ�ź���������Ϊ��Сֵ 
	  	  {
	  	  	ans+=block;//���������С 
	  	  	continue;
		  }
	  	int ll=le[i],rr=ri[i];
	  	int sum=0,mid;
	  	while(ll<=rr)//���ֲ���,��һ��������� 
	  	  {
	  	  	mid=(ll+rr)>>1;
	  	  	if(cooked[mid]+tag[i]>=c) rr=mid-1,sum=ri[i]-mid+1;
	  	  	else ll=mid+1;
		  }
		ans+=sum;//��� 
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

//���������߶��� 50�� TLE��:

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
void build(int s , int l , int r)//�ݹ齨�� 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) //Ҷ�ӽڵ� 
	  {
	  	a[s].w=raw[l];
	  	a[s].maxx=a[s].w;
	  	a[s].minn=a[s].w;
	  	return ;
	  }
	build (ls,l,mid);//�������� 
	build (rs,mid+1,r);
	a[s].maxx=max(a[ls].maxx,a[rs].maxx);
	a[s].minn=min(a[ls].minn,a[rs].minn);
}
void change(int s , int l , int r , int k)//������� 
{
	if(a[s].l>=l && a[s].r<=r && a[s].l==a[s].r)//����Ҫ�������� 
	  {
	  	a[s].w+=k;//����
		a[s].maxx=a[s].w;
	  	a[s].minn=a[s].w;
	  	return ;
	  }
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//������������������� 
	if(r>mid)  change(rs,l,r,k);
	a[s].maxx=max(a[ls].maxx,a[rs].maxx);
	a[s].minn=min(a[ls].minn,a[rs].minn);
}
int search(int s , int l , int r, int c)//�����ѯ 
{
	if(a[s].l>=l && a[s].r<=r && a[s].minn>=c)//����Ҫ�������� 
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
