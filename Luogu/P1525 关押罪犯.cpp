//֪ʶ��:���鼯 
/*
һ��������С�������Ĳ��鼯�ⷨ

�Ƚ� ���ежԹ�ϵ����ŭ��ֵ
���ս�������

���Ƚ�ŭ��ֵ��������ﷸ,  
�ŵ���ͬ�ļ�����
��:��Է��ĵ��˼���ͬһ���� 

���ҵ�һ�����ò�
�ŵ�ͬһ���������һ���ﷸʱ
���ҵ��˽�

��������û�н�
���0���� 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n;
int minn;
struct line
{
	int u,v,w;
}a[100100];
int pre[20010];
int dd[20010];
//--------------------------------------------------
bool cmp(line xx,line yy)
{
	return xx.w>yy.w;
}
int find(int x)//�鼯 
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)//���� 
{
	int r1=find(x),r2=find(y);
	if(r1!=r2) pre[r2]=r1;
}
//----------------------------------------------------
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)//���� 
	{
	  int x,y,z;
	  scanf("%d%d%d",&x,&y,&z);
	  a[i].u=x;a[i].v=y;a[i].w=z;
	}
	sort(a+1,a+m+1,cmp);//���� 
	for(int i=1;i<=n;i++) pre[i]=i;//��ʼ�������� 
	for(int i=1;i<=m;i++)
	{
	  if( find(a[i].u) == find(a[i].v) )//���ò��ֵ�ͬһ���� 
		{
		  printf("%d",a[i].w);
		  return 0;
		}
	  if(dd[a[i].u]!=0) join(a[i].v,dd[a[i].u]);//�����෴���� 
	  if(dd[a[i].v]!=0) join(a[i].u,dd[a[i].v]);
	  dd[a[i].u]=a[i].v; dd[a[i].v]=a[i].u;//��¼�жԹ�ϵ 
	  }
	printf("0");
	return 0;
}
