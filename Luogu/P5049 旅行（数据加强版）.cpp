//֪ʶ��:̰��,������ 
/*
By:Luckyblock

*/
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctype.h>
const int MARX = 5010;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<1];
int num,n,m , head[MARX];
int dn,be,circle , dfn[MARX],low[MARX],bel[MARX];
std::vector <int> tmp,ans;
std::stack <int> st;
std::priority_queue <int> q;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int plus)
{
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
void tarjan(int u,int fa)//tarjan�ҵ�ͼ�еĻ� 
{
	dfn[u]=low[u]= ++dn; st.push(u);	
	for(register int i=head[u]; i; i=e[i].ne)//ģ�� 
	  if(e[i].v!=fa)
	  {
	  	if(!dfn[e[i].v]) tarjan(e[i].v,u),low[u]=std::min(low[u],low[e[i].v]);
	  	else if(!bel[e[i].v]) low[u]=std::min(low[u],dfn[e[i].v]);
	  }
	if(low[u] == dfn[u]) 
	{
	  ++be;
	  int sum=0; 
	  for(register int r=u+1; r!=u; st.pop()) 
	    r=st.top(),bel[r]=be,sum++;
	  if(sum>1) circle = be;//��ǿ��ͨ������Ԫ����>1,��Ϊ��. 
	}
}
void dfs(int u,int fa,int anc,int minn)//dfs,̰�����ֵ��� 
{
	tmp.push_back(u);//����� 
	std::vector <int> son; //��Ϸ��ӽڵ� 
	for(register int i=head[u]; i; i=e[i].ne)//ö�ٳ��� 
	  if((e[i].v!=fa) && (i!=s) && ((i-1)!=s))//���ص����׽��,�Ҵ˱�δ���Ͽ� 
	    son.push_back(e[i].v);//����Ϸ��ӽڵ� 
	
	std::sort(son.begin(),son.end());//�������� 
	
	for(register int i=0,size=son.size(); i<size; i++)//̰��ѡ���յ� 
	  if((bel[u]==circle && (son[i+1]<minn) ||(anc==u)))
	    dfs(son[i],u,son[i+1]);
}
void get_min()//�Ƚ������ֵ��� 
{
	if(ans.size()<n) //ansΪ��ʱ 
	{
	  for(register int i=0; i<n; i++) 
	    ans.push_back(tmp[i]);
	  return ;
	}
	int i;
	for(i=0; i<n; i++)//�Ƚ�ÿһλ 
	  if(tmp[i]!=ans[i]) break;
	if(tmp[i]>ans[i]) return ;//����� ���� 
	for(i=0; i<n; i++) ans[i] = tmp[i];//���´� 
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(register int i=1; i<=m; i++)
	{
	  int u=read(),v=read();
	  add(u,v,0),add(v,u,m);
	}
	if(m == n) tarjan(1,0);
	dfs(1,0,-1); 
	for(register int i=0; i<n; i++) printf("%d ",ans[i]);
}
