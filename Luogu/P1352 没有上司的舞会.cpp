//֪ʶ��:����DP 
/*
��ĿҪ��:
��һ�����ϵ�ĵ㼯 a, 
ʹ ai != father[aj] (i,j �� [1,n]) 
��˵㼯 �����Ȩֵ�� 

��������:
����һ����,
ѡ���� �� ��ѡ����
ֻ����� ֱ�ӵĶ��ӽ�� ����Ӱ�� 
Ҳ����˵,
�����ֱϵ���ӽڵ��״̬�Ѿ�ȷ��
�Ϳ����Ƴ� �õ��״̬

�㷨ʵ��:
��: f[i] ��ʾ ѡ��� i �����,�����������Ȩֵ��
    g[i]��ʾ , ��ѡ���i����,�����������Ȩֵ��

��ô����һ�������ĸ��ڵ� i,
���� ֱϵ���ӽ�� ���� son 
��״̬ת�Ʒ���Ϊ:
	f[i] = r[i] + ��(g[v])  (v�� son); 
	g[i] = ��max(f[v],g[v]) (v�� son);  

���ڸ��ڵ�����״̬���������
��ֻ���� f[root] �� g[root]ȡ���ֵ���� 


ע��ĵ�:
���ڿ��ܳ��ָ���Ȩ
������ʱѡ��˵� , 
�Ȳ�ѡ��˵����
Ҫע������ж� 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define int long long
const int MARX = 6e3+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX];
int n,num,root,head[MARX],in[MARX];//graph building
int r[MARX] , f[MARX],g[MARX];
//f[i]��ʾi�μӵ���iΪ���ڵ�����������Ȩֵ��,g[i]Ϊ���μ� 
//=============================================================
inline int read() 
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void add(int u,int v)//��ͼ 
{
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
void dfs(int u)
{
	int sum1=0,sum2=0; 
	for(int i=head[u];i;i=e[i].ne)
	{
	  dfs(e[i].v);//���ȸ��¶��ӽ�� 
	  sum1+=std::max(f[e[i].v],g[e[i].v]);//������� 
	  sum2+=g[e[i].v];
	}
	f[u]=sum2+r[u] , g[u]=sum1;//�����������ڵ��ֵ 
//	printf("%lld %lld %lld\n",u,f[u],g[u]);
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1;i<=n;i++) r[i]=read();
	for(int i=1;i<n;i++)
	{
	  int v=read(),u=read();
	  add(u,v);
	  in[v]++;//���++ 
	}
	for(int i=1;i<=n;i++)//Ѱ�Ҹ��ڵ� 
	  if(!in[i]) {root=i;break;}
	dfs(root);
	printf("%lld",std::max(f[root],g[root]));//ѡ�����ո��ŵ�״̬ 
}
