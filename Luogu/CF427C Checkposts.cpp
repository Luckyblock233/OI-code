//֪ʶ��:Tarjan,����;
/*
By:Luckyblock

��������:
����һn����,m���ߵ�����ͼ , ���е�Ȩ 
Ҫ����ÿ��ǿ��ͨ������ѡ��һ����,
ʹѡ��ĵ�ĵ�Ȩ֮����С
����С��Ȩ��,��ѡ��ķ�����.

��������:
��Ȼ , ѡ��ÿ��ǿ��ͨ�����е�Ȩ��С�ĵ� , �����ŵ� 
������С��Ȩ�� , ��Ψһ��

Ϊʲô����ֲ�ͬ�� ����?
˵������ÿ��ǿ��ͨ�����е���С��Ȩ,�����ж���ѡ�� .  

�㷨ʵ��: 
�Ƚ���Tarjan����,
����ÿһ��ǿ��ͨ���� ,  
��¼ ÿһ��ǿ��ͨ������ ����С��Ȩ �� ��С��Ȩ�ĳ��ִ���.

��ô���ݳ˷�ԭ��, ������ = ��С��Ȩ���ִ��� �� �˻�. 
*/
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#define int long long
const int INF = 0x7f7f7f7f7f7f7f7f;//long long�ļ���ֵ(8���ֽ� 
const int MARX = 1e5+10;
const int mod = 1e9+7;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<2];
int n,p,m,num , head[MARX],we[MARX];//raw graph build
int we1[MARX],quan[MARX];//cooked graph build
int DFN,BEL , dfn[MARX],low[MARX],bel[MARX];//Tarjan
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
void prepare()
{
	memset(we1,0x7f,sizeof(we1));
	n=read();
	for(int i=1;i<=n;i++) we[i]=read();//����ԭʼ��Ȩ 
	m=read();
	for(int i=1;i<=m;i++)//��ͼ 
	{
	  int u=read(),v=read();
	  add(u,v);
	}
}
void tarjan(int u)
{
	dfn[u]=low[u]=++DFN;//u���ԭʼdfnֵ��lowֵ 
	st.push(u);
	for(int i=head[u];i;i=e[i].ne)//dfs u���ܵ���ĵ� 
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
	  for(int i=u+1;i!=u;st.pop())//���������ǿ��ͨ������ 
	  {
	  	i=st.top() , bel[i]=BEL;
	  	
	  	if(we1[BEL]==we[i]) quan[BEL]++;
	  	if(we1[BEL]>we[i]) we1[BEL]=we[i],quan[BEL]=1;//����ǿ��ͨ����Ȩֵ 	
	  }
	}
}
//=============================================================
signed main()
{
	prepare();
	for(int i=1;i<=n;i++) //ѭ������tarjan 
	  if(!dfn[i]) tarjan(i);
	
	int ans1=0,ans2=1;
	for(int i=1;i<=BEL;i++) ans1+=we1[i],ans2=(ans2*quan[i])%mod;//���µ�Ȩ�ͺͷ����� 
	printf("%lld %lld",ans1,ans2);
}
