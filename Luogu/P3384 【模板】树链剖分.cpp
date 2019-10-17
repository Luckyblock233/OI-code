//֪ʶ��:LCA/�����ʷ� /�߶��� 
/*
�ǳ����ĵ����ݽṹģ�� 

��¼�����ʷֵĵڶ���dfsʱ��dfs��
���Է��� , 
ÿһ�������ϵ�Ԫ�� , �� dfs��������
ÿһ�����ڵ�������ϵ�Ԫ�� ,��dfs��������

�����������ڹ�ϵ , 
��:����ʹ���߶�������������� 
��ʵ�����ϲ���
  
�� �����ʷ� + �߶��� �������ں� 
���ע�� 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define int long long
#define ls (s<<1)
#define rs (s<<1)+1
#define R register
//========================================================
const int MARX = 1e5+10;
struct edge
{
	int u,v,ne;
}e[2*MARX];
int head[MARX];//graph build��ͼ���� 
struct node
{
	int w,l,r,tag;
}a[4*MARX];//�߶����ڵ� 
int num,n,m,root,mod; 
int raw[MARX] , cook[MARX];//ԭ���� , ��dfn�����е����� 
int dep[MARX],fa[MARX],son[MARX],top[MARX],s[MARX];//�����ʷֱ���  sΪ(������С) 
int D,dfn[MARX];//dfs����� 
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
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
void dfs1(int u,int fat)//���ÿ�����,������С , �ض��� , ���� , ��� ; 
{
	s[u]=1 , dep[u]=dep[fat]+1 , fa[u]=fat;//���� 
	for(R int i=head[u],v=e[i].v ;i; i=e[i].ne,v=e[i].v)
	  if(v!=fat)
	  {
		dfs1(v,u); 
		s[u]+=s[v];//���� , ����������С 
		if(s[son[u]] < s[v]) son[u]=v;//�����ض��� 
	  }
}
void dfs2(int u,int fat)//���ÿ����������,�����Ķ��� , ��dfs�� 
{
	dfn[u]=++D,cook[D]=raw[u],top[u]=fat;//����dfs�� , ������dfs��Ϊ�±� �� ԭʼȨֵ���� 
	if(son[u]) dfs2(son[u],fat);//���� 
	else return;
	for(R int i=head[u],v=e[i].v ;i; i=e[i].ne,v=e[i].v)//���� 
	  if(v!=fa[u] && v!=son[u])
		dfs2(v,v);
}
void build(int s , int l , int r)//�ݹ齨�� 
{
	int mid=(l+r)>>1;
 	a[s].l=l,a[s].r=r;
	if(l==r) //Ҷ�ӽڵ� 
	{
	  a[s].w=cook[l];return ;
	}
	build (ls,l,mid);//�������� 
	build (rs,mid+1,r);
	a[s].w=(a[ls].w+a[rs].w)%mod;
}
void pushdown(int s)//�·������ 
{
	a[ls].w=(a[ls].w+(a[ls].r-a[ls].l+1)*a[s].tag)%mod;//�������Ҷ��ӵ�ֵ 
	a[rs].w=(a[rs].w+(a[rs].r-a[rs].l+1)*a[s].tag)%mod;
	a[ls].tag=(a[ls].tag+a[s].tag)%mod; 
	a[rs].tag=(a[rs].tag+a[s].tag)%mod;//�������Ҷ��ӵ������ 
	a[s].tag=0;
}
void change(int s , int l , int r , int k)//������� 
{
	if(a[s].l>=l && a[s].r<=r)//����Ҫ�������� 
	{
	  a[s].w=(a[s].w+(a[s].r-a[s].l+1)*k)%mod;//���� 
	  a[s].tag=(a[s].tag+k)%mod;
	  return ;
	}
	if(a[s].tag) pushdown(s);//�·� 
	int mid=(a[s].l+a[s].r)>>1;
	if(l<=mid) change(ls,l,r,k);//������������������� 
	if(r>mid)  change(rs,l,r,k);
	a[s].w=(a[ls].w+a[rs].w)%mod;
}
int search(int s , int l , int r)//�����ѯ 
{
	if(a[s].l>=l && a[s].r<=r)//����Ҫ�������� 
	  return a[s].w;
	if(a[s].tag) pushdown(s);
	int mid=(a[s].l+a[s].r)>>1,ans=0;
	if(l<=mid) ans=(ans+search(ls,l,r))%mod;//������� 
	if(r>mid)  ans=(ans+search(rs,l,r))%mod;
	return ans;
}
//========================================================
void change1(int x,int y,int z)// ������x��y������·�������нڵ��ֵ������z
{
	while(top[x]!=top[y])// ��x,y�Ƶ�ͬһ������ 
	{
	  if(dep[top[x]] < dep[top[y]]) std::swap(x,y);//ÿ�ζ���������ĵ� 
	  change(1,dfn[top[x]],dfn[x],z);//�ı侭�������� 
	  x=fa[top[x]];//ת��λ�� 
	}
	if(dep[x]>dep[y]) std::swap(x,y);//��������ĵ� 
	change(1,dfn[x],dfn[y],z);//�ı�x,y֮������� 
}
void change3(int x,int z){change(1,dfn[x],dfn[x]+s[x]-1,z);}// ����xΪ���ڵ�����������нڵ�ֵ������z 
void search2(int x,int y)//������x��y������·�������нڵ��ֵ֮��
{
	int ans=0;
	while(top[x]!=top[y])// ��x,y�Ƶ�ͬһ������ 
	{
	  if(dep[top[x]] < dep[top[y]]) std::swap(x,y);//ÿ�ζ���������ĵ� 
	  ans=(ans+search(1,dfn[top[x]],dfn[x]))%mod;//��+=���������������е�Ȩֵ�� 
	  x=fa[top[x]];
	}
	if(dep[x]>dep[y]) std::swap(x,y);
	ans=(ans+search(1,dfn[x],dfn[y]))%mod;//ans+=x,y֮������ĵ�Ȩֵ�� 
	printf("%lld\n",ans);
}
void search4(int x){printf("%lld\n",search(1,dfn[x],dfn[x]+s[x]-1));}//����xΪ���ڵ�����������нڵ�ֵ֮��
//========================================================
signed main()
{
	n=read(),m=read(),root=read(),mod=read();
	for(R int i=1;i<=n;i++) raw[i]=read();
	for(R int i=1;i<n;i++)
	{
	  int u=read(),v=read();
	  add(u,v) , add(v,u);
	}
	dfs1(root,0);//��ʼ��,�����ʷ� 
	dfs2(root,root);
	build(1,1,n);
	while(m--)
	{
	  int q=read(),x=read(),y,z;
	  switch (q)//���ֲ��� 
	  {
	  	case 1:{y=read(),z=read()%mod;change1(x,y,z);break;}
	  	case 2:{y=read();search2(x,y);break;}
	  	case 3:{z=read()%mod;change3(x,z);break;}
	  	case 4:{search4(x);break;}
	  }
	}
}
