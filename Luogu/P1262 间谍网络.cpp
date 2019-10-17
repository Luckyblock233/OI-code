//֪ʶ��:Tarjan,��������. 
/*
By:Luckyblock

��������:
���ո����� �ٱ��ҷ���ϵ����һ������ͼ��, ���Է���:
1. ����һ��ǿ��ͨ������ĵ�,
   ��һ���ٱ���ϵ�γ���һ���� �ļ��Ⱥ 
   ֻ��Ҫ ��¸��ǿ��ͨ�����е�һ����� , �Ϳ��Դݻ��������Ⱥ
   ��Ȼ , ��¸�������ٵļ������
   ���Զ���һ��ǿ��ͨ����,
   ��ȨֵΪ ǿ��ͨ��������С�ĵ�Ȩ
   
2. ����������γɵ�DAG,
   ֻ��Ҫ�ݻ� ���Ϊ0��ǿ��ͨ����
   ��ô����DAG���ᱻ�ݻ�. 
	
����ת��Ϊ:
�Ƚ������� , �ҵ��������Ϊ0��ǿ��ͨ���� 
1.�н����: 
  ������Ϊ 0��ǿ��ͨ���������Ա��ݻ�,
  ��ô ��Ϊ�������Ϊ0�� ǿ��ͨ���� Ȩֵ�ĺ�.
2.�޽����:
  ������Ϊ 0��ǿ��ͨ������,
  ��Щ���ܱ��ݻ�
  ��ôö��ÿһ�����ܱ��ݻٵ�ǿ��ͨ����
  ��ǿ��ͨ�����б����С�ĵ� , ��Ϊ����. 

����ܺ�д , Tarjan + topsort
���ע�� 
*/
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#define int long long
const int INF = 0x7f7f7f7f7f7f7f7f;//����ֵ 
const int MARX = 3010;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<2];
int n,p,m,num , head[MARX],we[MARX];//raw graph build
int we1[MARX],minn[MARX];//cooked graph build
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
void prepare()
{
	memset(we,0x7f,sizeof(we));//��ʼ��ȨֵΪ����ֵ 
	memset(we1,0x7f,sizeof(we1));
	memset(minn,0x7f,sizeof(minn));
	n=read(),p=read();
	for(int i=1;i<=p;i++) //����ԭʼ��Ȩ 
	{
	  int now=read();
	  we[now]=read();
	}
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
	  	we1[BEL]=std::min(we1[BEL],we[i]);//����ǿ��ͨ����Ȩֵ 
	  	minn[BEL]=std::min(minn[BEL],i);//����ǿ��ͨ�����б����С�ĵ�. 
	  }
	}
}
void topsort()
{
	bool flag=0; int ans1=INF;
	for(int i=1;i<=BEL;i++) 
	  if(!in[i]) //�ҵ��������Ϊ0��ǿ��ͨ���� 
	  {
	 	if(we1[i]>=INF) flag=1,ans1=std::min(ans1,minn[i]);//�޽���� 
		else ans+=we1[i];//�н���� 
	  }
	if(flag) printf("NO\n");//�������޽������� 
	else printf("YES\n");
	printf("%lld",flag?ans1:ans);
}
//=============================================================
signed main()
{
	prepare();
	for(int i=1;i<=n;i++) //ѭ������tarjan 
	  if(!dfn[i]) tarjan(i);
	  
	for(int i=1;i<=num;i++)//���¸�ǿ��ͨ��������� 
	  if(bel[e[i].u]!=bel[e[i].v])
	    in[bel[e[i].v]]++;
	topsort();
	
}
