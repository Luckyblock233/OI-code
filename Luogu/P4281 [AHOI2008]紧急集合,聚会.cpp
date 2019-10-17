//֪ʶ��:LCA/�����ʷ� 
/*
��ĿҪ��: 
������Ѱ��һ���ڵ�
ʹ����������,
����õ����·�����

��������:
��֤,����������,
���ǵ�����LCA,������������ͬ�� 
�Ƚ����׵õ�,����֤�� 

����֤��,���ż��ϵ�,
�������������LCA �� ��������һ�� 
	֤��:
	�������һx,Ϊa,b��LCA,
	��Ϊ����LCA����������һ��
	��ô��������LCA x':
	    x'����� < x����� 
	   ��֪:������ϵ���Ϊx' , 
	    c�㵽�Ｏ�ϵ��·�̻�����w 
	   ��a,b���㵽�Ｏ�ϵ����·�̻����� 2w

��,�������������LCA��,��������,
�ڼ��������֮��ľ���
�Ϳɵõ��� 

�������ݷ�Χ�ϴ�,
ʹ��ʱ�临�ӶȽ�С��������� 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define max_dep(a,b) dep[a]>dep[b]?a:b
#define R register
//========================================================
const int MARX = 5e5+10;
struct edge
{
		int u,v,ne;
}a[2*MARX];
int head[MARX];
int num,n,m,root,ans;
int s[MARX],dep[MARX],fa[MARX],son[MARX],c[MARX];//Tree Chain Dxxxxx 
//========================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void add(int u,int v) 
{
	a[++num].u=u,a[num].v=v;
	a[num].ne=head[u],head[u]=num;
}
void dfs1(int u,int fat)//���ÿ�����,������С , �ض��� , ���� , ��� ; 
{
	s[u]=1 , dep[u]=dep[fat]+1 , fa[u]=fat;//���� 
	for(R int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)
	if(v!=fat)
	{
	  dfs1(v,u); 
	  s[u]+=s[v];//���� 
	  if(s[son[u]] < s[v]) son[u]=v;
	}
}
void dfs2(int u,int fat)//���ÿ����������,�����Ķ��� 
{
	c[u]=fat;
	if(son[u]) dfs2(son[u],fat);//���� 
	else return;
	for(R int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)//���� 
  	  if(v!=fa[u] && v!=son[u])
		dfs2(v,v);
}
inline int lca(int x,int y)//���lca 
{
	for( ;c[x]!=c[y]; x=fa[c[x]])//ѭ������Ƚϴ�ĵ�����,ֱ��������ͬһ������ 
	  if(dep[c[x]] < dep[c[y]])
	    std::swap(x,y);
	return dep[x]<dep[y]?x:y;//������Ƚ�С�ĵ� 
}
//========================================================
signed main()
{
		n=read(),m=read(),root=1;
		for(R int i=1;i<n;i++)
		{
		  int u=read(),v=read();
		  add(u,v) , add(v,u);
		}
		dfs1(root,0);//��ʼ��,�����ʷ� 
		dfs2(root,root);
		while(m--)
		{
		  int ans1=0,ans2=0;
		  int tmp1=read(),tmp2=read(),tmp3=read();//�������lca 
		  int lca1=lca(tmp1,tmp2) ,lca2=lca(tmp1,tmp3) ,lca3=lca(tmp2,tmp3);
		  ans1=max_dep(lca1,max_dep(lca2,lca3));//�������lca��������� 
		  ans2=dep[tmp1]+dep[tmp2]+dep[tmp3]-dep[lca1]-dep[lca2]-dep[lca3];//������� 
		  printf("%d %d\n",ans1,ans2);
		}
}
