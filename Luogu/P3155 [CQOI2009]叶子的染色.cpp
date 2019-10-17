//֪ʶ��:����DP 
/*
��������:
��֤,����ѡ��һ����ΪҶ�ڵ�ĵ�Ϊ��
�Դ�û���κ�Ӱ��
	֤��:����,
	��ɫ����Ӧ�ñ�֤����㵽ÿ��Ҷ�ӵļ�·����
	�����ٰ���һ����ɫ��㣨���������Ҷ�ӱ���
	Ҷ�ڵ����ɫ����
	ֻ�����Ϸ���һ����ɫ�ڵ��й�  
	�ɴ�,��֤.

���Խ�������DP: 
��f[i][j] ,Ϊ ��i����,����Ⱦ��j��ɫ,����Ҫ�Ĵ���
����Գ�ʼ��: 
	f[i][1]=1,f[i][0]=1,����ÿ���㣬Ⱦ��ĳ����ɫ�Ĵ��۾�Ϊ1
	�ر��,����Ҷ�ڵ�,f[i][!c[i]] = INF ,
	��c[i]ΪҶ�ڵ���ҪȾ��ɫ)��ʾҶ�ڵ�i��Ӧ��Ⱦ��������ɫ,���Դ��ۼ���

Ȼ������ѡ��һ����Ҷ�ڵ�,��Ϊ���ڵ�,��ʼdfs 
���Ե�֪,
	���ĳһ���ڵ���Ҫ��Ⱦ�� x ɫ
	�������ĸ��׽ڵ��Ѿ���Ⱦ���� x ɫ
	��,������Ҫ��Ⱦɫ,�Ϳ��Լ̳и��׵���ɫ
	��,����ĳһ���ڵ�,
	�䱻Ⱦ�� x ɫ�Ĵ���,
	����ֱ�Ӽ̳��丸�ױ�Ⱦ�� x ɫ�Ĵ���
	Ҳ���Ա��ָ���Ϊ ��x ɫ,�����˽ڵ㵥��Ⱦ�� x ɫ 
����Եõ�:
	״̬ת�Ʒ���: 
	f[u][0]+=min(f[v][0]-1,f[v][1]); (u��ʾv�ĸ��׽ڵ�) 
	f[u][1]+=min(f[v][1]-1,f[v][0]);

*/
#include<cstdio>
#include<queue>
#include<ctype.h>
#define int long long
#define min(a,b) a<b?a:b
//======================================================
const int MARX = 1e4+10;
const int INF = 2147483647;//����ֵ 
struct edge 
{
	int u,v,ne;
}e[2*MARX];
int m,n,c[MARX];//�������� 
int root,num,head[MARX]; //���� 
int f[MARX][2]; // f[i][j]��ʾ,��i����,����Ⱦ��j��ɫ,����Ҫ�Ĵ���
//======================================================
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
void dfs(int u,int fa)
{
	if(u<=n) return ;//Ҷ�ڵ�,ֱ��return ; 
	for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)//ö�����зǸ��ڵ� 
	  if(v!=fa)
	  {
	    dfs(v,u);
		f[u][0]+=min(f[v][0]-1,f[v][1]);//���ӽڵ�,���µ�ǰ��ĸ�ֵ 
		f[u][1]+=min(f[v][1]-1,f[v][0]);
	  }
}
//======================================================
signed main()
{
	m=read(),n=read();
	root=n+1;//����ѡ��һ����ΪҶ�ڵ�Ľڵ� 
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=m-1;i++)
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u);
	}
	for(int i=1;i<=m;i++)//��ʼ�� 
	{
	  f[i][0]=f[i][1]=1;
	  if(i<=n) f[i][(!c[i])]=INF;//Ҷ�ڵ������ʼ�� 
	}
	dfs(root,root);
	printf("%lld",min(f[root][0],f[root][1]));//ȡ��С��ֵ 
}
