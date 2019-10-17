//֪ʶ��:̰��,������ 
/*
By:Luckyblock
���ȿ��� 60%������ һ����:   
��Ŀ��������ת�Ʒ���:   
1. ����һ��û��ȥ���ĳ���,   
2. �������ŵ�һ�η��ʸ� ����ʱ�����ĵ�· ���˵���һ������.   
��ô����һ�����ϵ��ӽڵ� ��˵,   
���� �Ƚ����������ϵĽڵ������, ���ܻص��ýڵ�ĸ��׽��  
���� �������޷���������,���ǲ��Ϸ���.   

��ĿҪ�� �ֵ�����С�ķ���,   
������������ , ��ô�������� ��ʼ̰��.   
1. ���� , ��Ȼѡ�� 1�Ž��Ϊ ���   
2. ����ÿ�����������ӽڵ�, ���ձ���������ν���ת��, 
3. ������������������ݵ����׽��
�ܸ��Ӷ� O(n) 
 
100%���� ������:  
�����ܷ���ת��Ϊ��״���. 
n<=5000??? 
ֱ��O(n)�����ϱ�,��O(n)����״�������
����Ҫ��֤ �ϱ�֮��ͼ��Ȼ��ͨ 
һ�ֱȽϺõ�ʵ�ַ���:
  ����һ��tarjan,�ҵ�ͼ�еĻ�
  ��ö�� �ϱߵ�ʱ��,ֻ�бߵ����˶� �ڻ���ʱ,�Ž���Ͽ�
  �����Ϳ��Ա�֤ ÿ�� �ϱ�֮��,ͼ������ͨ��
  Ҳ���Խ��͸��Ӷ� 
�ܸ��Ӷ� O(n^2) 
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
void dfs(int u,int fa,int s)//dfs,̰�����ֵ��� 
{
	tmp.push_back(u);//����� 
	std::vector <int> son; //��Ϸ��ӽڵ� 
	for(register int i=head[u]; i; i=e[i].ne)//ö�ٳ��� 
	  if((e[i].v!=fa) && (i!=s) && ((i-1)!=s))//���ص����׽��,�Ҵ˱�δ���Ͽ� 
	    son.push_back(e[i].v);//����Ϸ��ӽڵ� 
	std::sort(son.begin(),son.end());//�������� 
	for(register int i=0,size=son.size(); i<size; i++)//̰��ѡ���յ� 
	  dfs(son[i],u,s);
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
	if(m == n-1) dfs(1,0,114514),get_min();//ԭ����Ϊһ���� 
	else 
	{
	  tarjan(1,0);
	  for(register int i=1; i<=num;i+=2)//ö���ڻ��ϵ� �ϱ� 
	    if(bel[e[i].u]==circle && bel[e[i].v]==circle)
	    {
	  	  tmp.clear();
	      dfs(1,0,i); get_min();
	    }
	}
	for(register int i=0; i<n; i++) printf("%d ",ans[i]);
}
