//֪ʶ��:LCA,����,��С������ 
/*
��ĿҪ��: 
������Ȩ��������Сֵ�Ƕ���

��������:
�뵽������Сƿ��������
�����ؽ�����ɺ� , 
ԭͼ����һ��ɭ��
Ϊ�����ѯ�����Ƿ���ͨ 
�뵽ʹ��kruscal , �����½�ͼ 

�ؽ�ͼ�� , 
����Ҫ��ѯ������ ,
���ж��Ƿ���һ����ͨ����
�����һ����ͨ���� , 
��ô������ǵ�lca
�� , �����㵽lca·���ϵ���С�ı�Ȩ .

�����ñ��� , 
ά��һ���� , �����Ϸ��� 2^i����
·���ϵĵ���С��Ȩ 

���������lca
ѭ�������Ĺ�����
�� �� �� ������·�ϵ���С��Ȩ ȡС 
ά���� ��С
���������� 
*/ 
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
//====================================================================
const int MARX = 1e5+10;
const int INF = 2147483647;
struct edge
{
	int u,v,w,ne;//�ִ�ÿһ����ǰ,��������Ȩֵ 
}e1[5*MARX],e[10*MARX];
int q,n,m,root,num1,num2,head[MARX],pre[MARX];
int f[MARX][25],g[MARX][25];//�Ϸ���2^i���� �� �����Ϸ��� 2^i����·���ϵĵ���С��Ȩ  
int dep[MARX];
bool vis[MARX];
//====================================================================
bool cmp(edge aa,edge bb){return aa.w>bb.w;}//�ṹ��sort��������Զ��������� 
inline void add1(int u,int v,int w){e1[++num1].u=u,e1[num1].v=v,e1[num1].w=w;}//ԭͼ 
inline void add2(int u,int v,int w) {e[++num2].u=u,e[num2].v=v,e[num2].w=w;e[num2].ne=head[u],head[u]=num2;}//�ؽ�ͼ 
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}//�鼯 
void join(int x,int y)//���� 
{
	int r1=find(x),r2=find(y);
	if(r1 != r2) pre[r1]=r2;
}
int lca(int a,int b) //���������� 
{
	if(find(a)!=find(b)) return -1;//����ͨ 
	int ans=INF;
    if(dep[a] < dep[b]) std::swap(a,b);//��֤��������aΪ����ĵ� 
    for(int i=20;i>=0;i--)			  //�Ƶ�ͬһ��� 
      if(dep[f[a][i]] >=dep[b])
	  {
      	ans=min(ans,g[a][i]);//��ȡС 
      	a=f[a][i];
	  }
    if(a==b) return ans;
    for(int k=20;k>=0;k--)//ͬʱ���� 
      if(f[a][k] != f[b][k])//������lca 
        ans=min(ans,min(g[a][k],g[b][k])),a=f[a][k],b=f[b][k];//�ȸ��´�,�ڽ��������� 
    ans=min(ans,min(g[a][0],g[b][0])); 
	return ans;
}
void dfs(int u)  //dfs�����,������2^n��ĸ��� 
{
    vis[u]=1;
    for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)//���ܵ���ĵ� 
      if(!vis[v])
	  {
        dep[v]=dep[u]+1;//������� 
        f[v][0]=u , g[v][0]=e[i].w;//��ʼ�� 
        dfs(v);
	  }
}
//====================================================================
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int j=1;j<=m;j++)
	{
	  int u,v,w;
	  scanf("%lld%lld%lld",&u,&v,&w);//�������Ȩֵ 
	  add1(u,v,w);
	}
	for(int i=1;i<=n;i++) pre[i]=i;//�������� 
	std::sort(e1+1,e1+num1+1,cmp);
	for(int i=1;i<=num1;i++)//kruscal�ؽ�ͼ 
	{
	  if(find(e1[i].u) == find(e1[i].v)) continue;
	  join(e1[i].u,e1[i].v);
	  add2(e1[i].u,e1[i].v,e1[i].w);//������� 
	  add2(e1[i].v,e1[i].u,e1[i].w);
	}
	for(int i=1;i<=n;i++)//dfs�ռ�����Ϣ 
	  if(!vis[i])
	  {
	  	dep[i]=1; 
	  	dfs(i);
	  	f[i][0]=i , g[i][0]=INF;
	  }
	for(int i=1;i<=20;i++)//��̬���� �Ϸ���2^i���� �� �����Ϸ��� 2^i����·���ϵĵ���С��Ȩ 
	  for(int j=1;j<=n;j++)
	    f[j][i]=f[f[j][i-1]][i-1],
	    g[j][i]=min(g[j][i-1],g[f[j][i-1]][i-1]);
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)//�ش�ѯ�� 
      {
      	int a,b;
      	scanf("%lld%lld",&a,&b);
      	printf("%lld\n",lca(a,b));
      }
}
