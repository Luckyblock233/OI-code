//֪ʶ��:��С������ 
/*
��ĿҪ��:
��n+1�����������������ٻ���
�����С������
���ע�� 
*/
#include<cstdio>
#include<algorithm>
const int MARX = 4e5+10;
//=============================================================
struct edge
{
	int u,v,w;//�ִ�ÿһ����ǰ,��������Ȩֵ 
}a[2*MARX];
int n,m,num;//��ߵ����� 
int pre[MARX];//�沢�鼯�е����� 
//=============================================================
bool cmp(edge aa,edge bb){return aa.w<bb.w;}//�ṹ��sort��������Զ��������� 
void add(int u,int v,int w){a[++num].u=u,a[num].v=v,a[num].w=w;}
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
void join(int x,int y)//���� 
{
	int r1=find(x),r2=find(y);
	if(r1 != r2) pre[r1]=r2;
}
//=============================================================
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) pre[i]=i;//�������� 
	for(int j=1;j<=m;j++)
	{
	  int u,v,w;
	  scanf("%d%d%d",&u,&v,&w);//�������Ȩֵ 
	  add(u,v,w);
	}
	std::sort(a+1,a+num+1,cmp);
	int sum=0;
	for(int i=1,tot=0;i<=num&&tot!=n;i++)
	{
	  if(find(a[i].u) == find(a[i].v)) continue;
	  join(a[i].u,a[i].v);
	  ++tot,sum+=a[i].w;
	}
	printf("%d",sum);//��� 
}
