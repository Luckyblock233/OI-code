//֪ʶ��:�߶����Ż���ͼ 
/*
�߶����Ż���ͼ
���ڽ�� 
���� �� x ������[L,R]�� 
������������ 

ԭͼ:
1 2 3 4
���������һϵ����� ,
���������ʵ�� , �������� ����,
����ӵı�,�ı�Ȩֵ��Ϊ0 ֮��:
		o 
      /   \ 
    o      o 
  / \     / \ 
 1   2   3   4

�γ�һ����������

���������������,
���Խ��䵱��һ���߶���,
������һϵ�еĲ���:

1. ���� �� x ������[L,R]���߲���:
   ��������ӵı�ȨȫΪ0
   ����ֻ��Ҫ�� x �� 
   "��Ͻ" �� [L,R] �����������߼���
   ��������߶����������ѯ,
   ���еݹ��ѯ, 
   
   Ҫ���ӵı���,
   �� R-L���� ,ת��Ϊ��log(R-L)���� 
   
2. ���� �� ����[L,R] �� x ���߲���:
   �������
   ���Ƿ������߼���
   ͬʱ�ڳ�ʼ��ʱ,
   ҲҪע�� ��ʼ������ı� 
3. ���� ��x �� y���߲���
   ֱ�����Ӽ��� 
   
�㷨ʵ��:
�Ƚ������� ��ʼ����������
�ֱ��������뷴��� ,
�����֮�������, 
��������Ϊ0.

Ȼ�����ÿ�����߲���,
������������,
��x��ʵ��/��� ���� 

�����һ�����·����


ע���һЩС��:
1.Ϊ�˲�Ӱ��ʵ��֮�������
  ���,���߶����ϵĵ� �ı��,
  ��n+1��ʼ��� 
*/ 
#include<cstdio>
#include<queue>
#include<cstring>
#define ll long long
const int MARX = 3e5+10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
//============================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<4];//���� 
int n,q,start;//����ĳ�ʼ���� 
std:: queue <int> qu;//spfa�Ķ��� 
int num,head[MARX];//��ͼ���� 
int cnt,root1,root2,ls[MARX],rs[MARX];//�߶������� (lsΪ�����,rsΪ�Ҷ���) 
ll dis[MARX];//spfa ���� 
//============================================
inline void add(int u,int v,int w)
{
	e[++num].v=v,e[num].u=u,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
void build1(int &s,int l,int r)//��ʼ�� �Ӹ�������ӵ�0�� 
{
	if(l==r)//�ݹ�����,ֱ�� ����Ҷ�Ӳ��� ʵ��, 
	{
	  s=l;//ʵ��ı�Ų��� 
	  return;
	}
	s = ++cnt;//���µ�ǰ���ı�� 
	int mid = (l+r)>>1;
	build1(ls[s],l,mid);//�ݹ��������� 
	build1(rs[s],mid+1,r);
	add(s,ls[s],0);//������0�� 
	add(s,rs[s],0);
}
void build2(int &s,int l,int r)//���build1,���з�����0�� 
{
	if(l==r)
	{
	  s=l;
	  return;
	}
	s = ++cnt;
	int mid = (l+r)>>1;
	build2(ls[s],l,mid);
	build2(rs[s],mid+1,r);
	add(ls[s],s,0);
	add(rs[s],s,0);
}
int L,R;//Ҫ�������������� 
void updata(int s,int l,int r,int u,int w,int type)//s:��ǰ����; l,r:��ǰ��s��Ͻ���� ; type:���������� 
{
	if(L<=l && r<=R)//�������� ���� ��ǰ���� 
	{
	  if(type==2) add(u,s,w);//��������,�������߲���. 
	  else add(s,u,w);
	  return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid) updata(ls[s],l,mid,u,w,type);//�ݹ���в��� 
	if(mid<R) updata(rs[s],mid+1,r,u,w,type);
}
void spfa(int start)//������ 
{
	memset(dis,0x3f,sizeof(dis));
	dis[start]=0;qu.push(start);
	while(!qu.empty())
	{
	  int u=qu.front(); qu.pop();
	  for(int i=head[u];i;i=e[i].ne)
	  {
	  	int v=e[i].v,w=e[i].w;
	  	if(dis[u]+w < dis[v])
	  	{
	  	  dis[v]=dis[u]+w ;
		  qu.push(v);	
		}
	  }
	}
}
//============================================
signed main()
{
	scanf("%d%d%d",&n,&q,&start);
	cnt=n;//Ϊ��Ӱ��ʵ��֮������� , ���,��n+1��ʼ��� 
	build1(root1,1,n),build2(root2,1,n);//��ʼ�� 
	for(int i=1;i<=q;i++)
	{
	  int opt,u,v,w;
	  scanf("%d",&opt);
	  if(opt==1)
	  {
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);//ֱ������ 
	  }
	  else
	  {
	  	scanf("%d%d%d%d",&u,&L,&R,&w);
	  	updata((opt==2?root1:root2),1,n,u,w,opt);//��������,���в��� 
	  }
	}
	
	spfa(start);
	/*
	for(int i=1;i<=n;i++)
	  for(int j=head[i];j;j=e[j].ne)
	    printf("%d %d %d\n",i,e[j].v,e[j].w);
	*/
	for(int i=1;i<=n;i++) printf("%lld ",dis[i]<INF?dis[i]:-1); 
}
