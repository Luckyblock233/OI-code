//知识点:贪心,基环树 
/*
By:Luckyblock
首先考虑 60%的数据 一棵树:   
题目给出两种转移方法:   
1. 走向一个没有去过的城市,   
2. 或者沿着第一次访问该 城市时经过的道路 后退到上一个城市.   
那么对于一个树上的子节点 来说,   
必须 先将所有子树上的节点遍历完, 才能回到该节点的父亲结点  
否则 该子树无法被遍历完,则是不合法的.   

题目要求 字典序最小的方案,   
根据上述结论 , 那么可以愉快地 开始贪心.   
1. 首先 , 必然选择 1号结点为 起点   
2. 对于每个结点的所有子节点, 按照编号升序依次进行转移, 
3. 遍历完所有子树后回溯到父亲结点
总复杂度 O(n) 
 
100%数据 基环树:  
考虑能否将其转化为树状情况. 
n<=5000??? 
直接O(n)暴力断边,再O(n)跑树状情况即可
但是要保证 断边之后图仍然联通 
一种比较好的实现方法:
  先跑一遍tarjan,找到图中的环
  在枚举 断边的时候,只有边的两端都 在环中时,才将其断开
  这样就可以保证 每次 断边之后,图都是联通的
  也可以降低复杂度 
总复杂度 O(n^2) 
*/
#include<cstdio>
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
void dfs(int u,int fa,int s)//dfs,贪心求字典序 
{
	tmp.push_back(u);//加入答案 
	std::vector <int> son; //存合法子节点 
	for(register int i=head[u]; i; i=e[i].ne)//枚举出边 
	  if((e[i].v!=fa) && (i!=s) && ((i-1)!=s))//不回到父亲结点,且此边未被断开 
	    son.push_back(e[i].v);//加入合法子节点 
	std::sort(son.begin(),son.end());//升序排序 
	for(register int i=0,size=son.size(); i<size; i++)//贪心选择终点 
	  dfs(son[i],u,s);
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
	if(m == n-1) dfs(1,0,114514),get_min();//原本就为一棵树 
	else 
	{
	  tarjan(1,0);
	  for(register int i=1; i<=num;i+=2)//枚举在环上的 断边 
	    if(bel[e[i].u]==circle && bel[e[i].v]==circle)
	    {
	  	  tmp.clear();
	      dfs(1,0,i); get_min();
	    }
	}
	for(register int i=0; i<n; i++) printf("%d ",ans[i]);
}
