//知识点:二分答案,贪心 
/*
By :Luckyblock
一些浅显的性质: 
1. 对于每一珂子树上的军队 , 上跳到 根节点的 直接子节点更优.
2. 如果一珂子树上没有 军队,需要从其他子树来获得军队.
   此时 , 支援军队到达该子树根部更优 
3. 对于军队的转移 , 除了从根节点 向 根节点的直接子节点以外, 不会向下转移 
4. 策略: 保证某珂子树上的叶节点都被控制的情况下 , 尽量将军队向其他子树转移. 

一些不那么浅显的结论: 
5. 假设每棵子树上都有军队 , 
   那么只需要使军队上跳到 可以完全控制此子树叶节点的位置 : 
	- 二分答案枚举最长的时间 , 转移使用时间 <=最长时间,
	   在最长时间内 各点 尽量上跳.
	   一直跳跃到每棵子树都被完全控制. 
	   
	   
6. 对 5 进行扩展,
   先对各点尽量上跳,
   如果跳到根节点后 , 还有时间继续进行转移
   那么考虑向其他子树进行转移 .  
	- 能向其他子树转移的先决条件:
	  1. 军队原在子树已被完全控制.
	  2. 转移目标子树未被控制完全.
	- 向其他子树转移后,目标子树一定会被完全控制. 
*/
#include<cstdio>
#include<ctype.h>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
const int MARX = 3e5+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[MARX<<1];
int n,m,edge_num,size , head[MARX];
int fa[MARX],son[MARX] , dis[MARX],stree[MARX],dep[MARX]={0,1};
int army[MARX],now_army[MARX],use[MARX],res[MARX];
bool flag[MARX];
std::vector <int> direct_son;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(;  isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)
{
	e[++edge_num].u=u,e[edge_num].v=v,e[edge_num].w=w;
	e[edge_num].ne=head[u],head[u]=edge_num;
}
bool cmp1(int first,int second) {return res[first] > res[second];}
bool cmp2(int first,int second) {return dis[first] > dis[second];}
void dfs(int u,int fat,int stre)
{
	fa[u]=fat , dep[u]=dep[fat]+1 , son[fat]=u , stree[u]=stre;
	for(int i=head[u];i;i=e[i].ne)
	  if(e[i].v!=fat)
	  {
	    dis[e[i].v]=e[i].w;
	    if(u==1) dfs(e[i].v,u,e[i].v);
	    else dfs(e[i].v,u,stre);
	  }
}
void prepare()
{
	n=read();
	for(int i=1;i<n;i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w) , add(v,u,w);
	}
	m=read();
	for(int i=1;i<=m;i++) army[i]=read();
	for(int i=head[1];i;i=e[i].ne) direct_son.push_back(e[i].v); 
	size = direct_son.size();
	dfs(1,1,0);
}
bool dfs1(int u,int fat)
{
	bool judge=0;
	if(flag[u] && u!=1) return 1;
	for(int i=head[u];i;i=e[i].ne)
	  if(e[i].v!=fat)
	    if(!dfs1(e[i].v,u))
		  judge = 1;
	if(judge) return 0;	
	return (flag[u] = son[u]);
}
bool check(int now)
{
	std::vector <int> tmp1,tmp2;
	bool nouse[MARX]={0};
	std::memset(flag,0,sizeof(flag));
	for(int i=1;i<=m;i++)
	{
	  now_army[i]=army[i] , use[i]=0;
	  for(int j=dep[army[i]];j>=0;j--)
	    if(use[i] + dis[now_army[i]] <= now && now_army[i]!=1 )
	      use[i]+=dis[now_army[i]] , now_army[i]=fa[now_army[i]];
		else break;
	  flag[now_army[i]]=1 , res[i]=now-use[i];
	}
	if(dfs1(1,1)) return 1;
	
	for(int i=1;i<=m;i++)
	  if(now_army[i]==1)
	    tmp1.push_back(i);
	std::sort(tmp1.begin(),tmp1.end(),cmp1);
	int size1=tmp1.size();
	for(int i=size1-1;i>=0;i--)
	  if(!flag[stree[army[tmp1[i]]]]) 
	  {
	  	now_army[tmp1[i]] = stree[army[tmp1[i]]] , flag[stree[army[tmp1[i]]]]=1;
		nouse[i]=1;
	  }
	
	for(int i=0;i<size;i++)
	  if(!flag[direct_son[i]])
	    tmp2.push_back(direct_son[i]);
	std::sort(tmp2.begin(),tmp2.end(),cmp2);
	int size2=tmp2.size() ,i,j;
	
	for(i=0,j=0;i<size1 && j<size2;i++,j++)
	{
	  while(nouse[i]) i++;
	  if(i>=size1) break;
	  if(res[tmp1[i]] < dis[tmp2[j]]) return 0;	
	}
	return j==size2;
}
//=============================================================
signed main()
{
	prepare();
	int le=0,ri=1e18,ans;
	while(le<=ri)
	{
	  int mid=(le+ri)>>1;
	  if(check(mid)) ri=mid-1,ans=mid;
	  else le=mid+1;
	}
	printf("%lld",ans);
	return 0;
}
