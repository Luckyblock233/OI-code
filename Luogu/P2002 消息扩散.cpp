//֪ʶ��:Tarjan���� 
/*
By:Luckyblock
�������:
�Ƚ�����������ͼ�������� 
���Է��� :
1.��ȷ�0�ĵ����Ϣ, �����Դӱ�ĵ㴫�����.
2.���Ϊ0�ĵ����Ϣ���ɴ������㴫��,
  ���� ���������Ϊ0�ĵ��� ������Ϣ	
  
����ֻ�����Ϊ0�ĵ��ϴ�����Ϣ�����ŵ� , 
���Դ� = ��������Ϊ0�ĵ�ĸ��� 
*/
#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#define int long long
const int MARX = 1e5+10;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<3];
int n,p,m,num , head[MARX];//graph build
int DFN,BEL , dfn[MARX],low[MARX],bel[MARX];//Tarjan
int ans,in[MARX];//topsort
std::stack <int> st; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v)//��ͼ 
{
	if(u==v) return ;
	e[++num].v = v,e[num].u=u;
	e[num].ne = head[u];head[u] = num;
}
void tarjan(int u)//tarjan���� 
{
	dfn[u]=low[u]=++DFN;//��ʼֵ 
	st.push(u);
	for(int i=head[u];i;i=e[i].ne)
	{
	  int v=e[i].v;
	  if(!dfn[v]) tarjan(v),low[u]=std::min(low[v],low[u]); 
	  //����µ�δ�������, �����µ�dfs, ���ڻ���ʱ����ԭ���lowֵ 
	  else if(!bel[v]) low[u]=std::min(low[u],dfn[v]);
	  //����µ㵽��� ������һ��ǿ��ͨ������, �����µ��dfs�����Դ��  
	}
	if(low[u]==dfn[u])//�ҵ�һ��ǿ��ͨ���� 
	{
	  ++BEL;
	  for(int i=u+1;i!=u;st.pop())
	    i=st.top() , bel[i]=BEL;
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();//��ͼ 
	for(int i=1;i<=m;i++)
	{
	  int u=read(),v=read();
	  add(u,v);
	}
	
	for(int i=1;i<=n;i++) 
	  if(!dfn[i]) tarjan(i);
	  
	for(int i=1;i<=num;i++)//������� 
	  if(bel[e[i].u]!=bel[e[i].v])
	    in[bel[e[i].v]]++;
	for(int i=1;i<=BEL;i++)  ans+=(!in[i]);//���´� 
	printf("%lld",ans);
}
