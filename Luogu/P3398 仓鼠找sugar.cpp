//֪ʶ��:LCA/�����ʷ� 
/*
�������:
���Է���:
�������·�� a-b �� c-d ���غϲ��� , 
��ô��Ȼ��: lca(a,b)��c-d�� , lca(c,d)��a-b��
	֤��: 
	��Ϊlca , ��һ��·���� "ת�۵�" �� ��ǳ�˵�
	��: �������·���й�������
	��ô�������ֵ� һ�˵� , 
	��Ȼ��������lca�е�һ�� 

�����Է��� , 
�������:
  1.deep[x]>=deep[LCA(s,t)]
  2.LCA(s,x)=x��LCA(t,x)=x;
��ôx��·��  s-t�ϵ�һ�� 

�㷨ʵ��:
����,����ͨ������ , ����ö�� lca
�ڽ����ж� , ���� 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define R register
#define abs(a) a<0?-a:a
//========================================================
const int MARX = 5e5+10;
struct edge//���� 
{
		int u,v,ne;
}a[2*MARX];
int head[MARX];
int num,n,m,root;
int s[MARX],dep[MARX],fa[MARX],son[MARX],c[MARX];//������ر��� 
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
	  int aa=read(),bb=read(),cc=read(),dd=read(); 
	  int lca1=lca(aa,bb) , lca2=lca(cc,dd);//��lca 
	  if(dep[lca1]<dep[lca2])//ʹlca1���� 
	  {
	  	std::swap(lca1,lca2);std::swap(aa,cc);std::swap(bb,dd);
	  }
	  if(lca(lca1,cc)==lca1 || lca(lca1,dd)==lca1) printf("Y\n");//����������� 
	  else printf("N\n");
	}
}