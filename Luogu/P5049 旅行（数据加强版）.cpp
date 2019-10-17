//知识点:贪心,基环树 
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
void tarjan(int u,int fa)//tarjan找到图中的环 
{
	dfn[u]=low[u]= ++dn; st.push(u);	
	for(register int i=head[u]; i; i=e[i].ne)//模板 
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
	  if(sum>1) circle = be;//此强连通分量中元素数>1,则为环. 
	}
}
void dfs(int u,int fa,int anc,int minn)//dfs,贪心求字典序 
{
	tmp.push_back(u);//加入答案 
	std::vector <int> son; //存合法子节点 
	for(register int i=head[u]; i; i=e[i].ne)//枚举出边 
	  if((e[i].v!=fa) && (i!=s) && ((i-1)!=s))//不回到父亲结点,且此边未被断开 
	    son.push_back(e[i].v);//加入合法子节点 
	
	std::sort(son.begin(),son.end());//升序排序 
	
	for(register int i=0,size=son.size(); i<size; i++)//贪心选择终点 
	  if((bel[u]==circle && (son[i+1]<minn) ||(anc==u)))
	    dfs(son[i],u,son[i+1]);
}
void get_min()//比较序列字典序 
{
	if(ans.size()<n) //ans为空时 
	{
	  for(register int i=0; i<n; i++) 
	    ans.push_back(tmp[i]);
	  return ;
	}
	int i;
	for(i=0; i<n; i++)//比较每一位 
	  if(tmp[i]!=ans[i]) break;
	if(tmp[i]>ans[i]) return ;//新情况 不优 
	for(i=0; i<n; i++) ans[i] = tmp[i];//更新答案 
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
