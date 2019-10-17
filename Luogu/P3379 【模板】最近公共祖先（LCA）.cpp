//֪ʶ��:LCA/�����ʷ� 
/*
ʹ�������ʷֽ���LCA
���ע�� 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
//========================================================
const int MARX = 5e5+10;
struct edge
{
		int u,v,ne;
}a[2*MARX];
int head[MARX];
int num,n,m,root;
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
		for(int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)
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
		for(int i=head[u],v=a[i].v ;i; i=a[i].ne,v=a[i].v)//���� 
			if(v!=fa[u] && v!=son[u])
				dfs2(v,v);
}
int lca(int x,int y)//���lca 
{
		for( ;c[x]!=c[y]; x=fa[c[x]])//ѭ������Ƚϴ�ĵ�����,ֱ��������ͬһ������ 
		  if(dep[c[x]] < dep[c[y]])
		    std::swap(x,y);
		return dep[x]<dep[y]?x:y;//������Ƚ�С�ĵ� 
}
//========================================================
signed main()
{
		n=read(),m=read(),root=read();
		for(int i=1;i<n;i++)
		{
		  int u=read(),v=read();
		  add(u,v) , add(v,u);
		}
		dfs1(root,0);//��ʼ��,�����ʷ� 
		dfs2(root,root);
		while(m--)
		{
			int u=read(),v=read();
			printf("%d\n",lca(u,v));
		}
}

//ʱ��ռ䶼���������ʷ�
//���Һ��Ѵ�,���׳����ı���LCA
//���ע�� 
/* 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX = 5e5+10;
int f[MARX][25],g[MARX][25];
int dep[MARX],head[MARX],lg[MARX];
int num;
struct baka9  //��� 
{
    int v;
    int ne;
}a[2*MARX];
int lca(int a,int b) //���������� 
{
    if(dep[a] < dep[b]) swap(a,b);
    while(dep[a] > dep[b])				  //�Ƶ�ͬһ��� 
      a=f[a][ lg[dep[a]-dep[b]] -1];
    if(a==b) return a;
    for(int k=lg[dep[a]]-1;k>=0;k--)//ͬʱ���� 
      if(f[a][k] != f[b][k])
        a=f[a][k],b=f[b][k];
    return f[a][0];
}
void dfs(int u,int fa)  //dfs�����,������2^n��ĸ��� 
{
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=1;(1<<i)<=dep[u];i++)
      f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=a[i].ne)
      if(a[i].v != fa)
        dfs(a[i].v,u);
}
void add(int u,int v)//��ͼ 
{
    a[++num].v=v;
    a[num].ne=head[u];
    head[u]=num;
}
int main()
{
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)//��ͼ 
      {
      	int u,v;
      	scanf("%d%d",&u,&v);
      	add(u,v);add(v,u);
      }
    dfs(s,0);
    for(int i=1;i<=n;i++)//Ԥ����log���� 
      lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=m;i++)
      {
      	int a,b;
      	scanf("%d%d",&a,&b);
      	printf("%d\n",lca(a,b));
      }
}
*/ 
