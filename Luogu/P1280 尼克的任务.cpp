//֪ʶ��:���仯����/����DP 
/*
����������Ϣʱ��
�������С����ʱ�� 

ʹ��f[]����,
��¼ ��ɵ�i�������, 
��С�Ĺ���ʱ��(������i�������ʱ��) . 

�Ƚ������տ�ʼʱ���������� 
����ʱ,��¼��ǰ����ı��
ö�پ� ��ǰ��������� 
�����ʼ������(�����ж��)
Ȼ�����ת��
���Է���ֵȡ��Сֵ 

��û���������ת��ʱ
(��������ʱ��Ľ���),
ʹf[i] = ��ǰ�������ʱ��
�����ص�ǰ�������ʱ��

�ݹ����֮ǰ����� f[i] 

������f[0]���� 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
#define R register
#define min(a,b) a<b?a:b
//=================================================
const int MARX = 1e4+10;
struct kikaku
{
	int l,r;
}a[MARX];
int n,k,ans;
int f[MARX];
//=================================================
bool cmp(kikaku x,kikaku y)
{
	return x.l<y.l;
}
int dfs(int now)//���� 
{
	if(f[now]) return f[now];//�Ѿ�����ֵ 
	int res=MARX,limit=MARX;
	//����ֵ(resΪ֮������ĳ���ʱ��,limit����ֵΪ���������ʼʱ�� 
	for(R int i=now+1;i<=k;i++)
	  {
	  	if(a[i].l>limit) break;//������������� 
	    if(a[i].l>a[now].r)//���Կ�ʼ 
	      res=min(res,dfs(i)),limit=min(limit,a[i].l);//������ֵ 
	  }
	f[now]=a[now].r-a[now].l+1;//���µ�ǰ���� 
	if(res==MARX) return f[now];//����û������ 
	return f[now]+=res;//���������� 
}
//==================================================
signed main()
{
	scanf("%d%d",&n,&k);
	a[0].l=1;//����ֵ 
	for(R int i=1;i<=k;i++)//���һ����������Ҷ˵� 
	  scanf("%d%d",&a[i].l,&a[i].r),a[i].r+=a[i].l-1;
	std::sort(a+1,a+k+1,cmp);//�������� 
	dfs(0);	//���� 
	printf("%d",n-f[0]);//���������ʱ�� 
}
