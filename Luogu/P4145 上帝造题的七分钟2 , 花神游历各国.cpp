//֪ʶ��:�������/�߶���/�ֿ�(�����㷨) 
/*
����һ������
�����ֲ���:
1.��ĳ����ȫ��ȡƽ��
2.��ѯĳ����ĺ�

���ڿ�������,��ͬ�������������
�����Ͻ�����������
���޷����д��������

����,���Է���:
��ʹ�Ǳ������ݷ�Χ���Ͻ� 10^12
����5�ο�����,Ҳ���� 1

��:�����뵽һ�ֻ��ڷֿ��(α)��������:

����ÿһ������,��¼�����޸ĵĴ���(���������Ĵ���)
1.������ı��޸Ĵ��� ��С��5 
  ֤�������������Ԫ�ص�ֵ
  ���ѱ����1
  ���Բ���Ҫ�����޸Ĳ���
  ֱ��return ;����
  
2.��������޸Ĵ��� С��5
  ˵�������� ���� ����δ������������Ԫ��
  �����������²�ݹ�
  ������������޸Ĵ���++ 
  
  ����δ������������ Ҷ��Ԫ��ʱ,
  ������п�������
  ����return ;�����������϶� 
   
��ѯ���� ������������ѯ����

���������޸Ĳ������ѱ��ݹ����,
���Բ���Ҫ����� 
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
inline int read()//��� 
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
void build(int s , int l , int r)//�ݹ齨�� 
{
    int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
    if(l==r) //Ҷ�ӽ�� 
      {
      	a[s].w=raw[l];
      	return ;
      }
    build (ls,l,mid);
    build (rs,mid+1,r);
    a[s].w=a[ls].w+a[rs].w;
}
void change(int s , int l , int r )//�޸Ĳ��� 
{
	if(a[s].num>5) return ;//�����䱻�������� 
    if(a[s].l>=l && a[s].r<=r)//��������Ҫ���޸� 
      {
      	a[s].num++;//�޸Ĵ���++ 
      	if(a[s].l==a[s].r)//Ҷ�ӽ��,ֱ�ӽ����޸� 
		  {
		  	a[s].w=sqrt(a[s].w);
		    return ;
		  }
      }
    int mid=(a[s].l+a[s].r)>>1;
    if(l<=mid) change(ls,l,r);//�޸��������� 
    if(r>mid)  change(rs,l,r);
    a[s].w=a[ls].w + a[rs].w;//���¸��� 
}
int search(int s , int l , int r)//���������ѯ���� 
{
    if(a[s].l>=l && a[s].r<=r)//������ȫ�������� 
      return a[s].w;
    int mid=(a[s].l+a[s].r)>>1,ans=0;
    if(l<=mid) ans+=search(ls,l,r);//��ѯ�������� 
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
