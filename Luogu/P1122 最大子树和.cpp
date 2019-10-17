//֪ʶ��: DP 
/*
By:Luckyblock
��ĿҪ��:
����һ����, ���е�Ȩ
��һ�� ����, ʹ���Ȩ�����

��������:
���� ��u�� Ϊ��������,
�� ����Ȩ��Ϊ:
�� ����Ȩ��>0�������� ����Ȩ�� + ������Ȩֵ
���ֿ���ͨ���ݹ�, �����и���
��������dp

��f[i] Ϊ�� u�� Ϊ��������, ������Ȩ��:
����״̬ת�Ʒ���Ϊ: 
f[u] = ��(f[v] * (f[v]>0)) + w[u]
dfs��������dp
�ڽ���dfsʱ, ȡ���ĵ�Ȩ��Ϊ�� 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
#define max(a,b) a>b?a:b
const int MARX = 1e4+6e3+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<1];
int n,num,ans, w[MARX],head[MARX];
int f[MARX]; // �� u�� Ϊ��������, ������Ȩ��
//============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)//��ͼ 
{
	e[++num].u=u, e[num].v=v;
	e[num].ne=head[u], head[u]=num;
}
void dfs(int u,int fa)//dfs��������dp 
{
	f[u] = w[u];
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v != fa)
	  {
		dfs(e[i].v,u);//ת�Ƹ��� 
		f[u] += f[e[i].v]*(f[e[i].v]>0);
	  }
	ans = max(ans,f[u]);//ȡ���ֵ 
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1; i<=n; i++) w[i]=read();
	for(int i=1; i<n; i++)
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%lld",ans);
}
