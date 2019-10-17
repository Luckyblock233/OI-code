//֪ʶ��:Tarjan/ǿ��ͨ����/����
/*
ʹ��Tarjan 
������� ǿ��ͨ���� 

�ڵõ�ǿ��ͨ����ʱ
��֮ǰ�Ĵ𰸽��бȽ�
ȡ���Ƚϳ�,���ֵ����С��
��Ϊ��

���ע�� 
*/ 
#include<cstdio>
#include<algorithm>
#include<stack>
#include<string>
#include<ctype.h>
#define min(a,b) a<b?a:b  //����дalgorithm�� 
#define R register
using namespace std;
//=================================================
const int MARX = 5e3+10;
struct edge //�г��˸�����������
{
	int u,v,ne;
}e[MARX*10];
int n,m,num ,  head[MARX];  //graph_building��ͼ 
int dn,be,  dfn[MARX],low[MARX],bel[MARX];//Tarjan
int max_unicom,ans[MARX];//���ǿ��ͨ������С , �� 
stack <int> st;
//=================================================
inline int read()//��� 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void add(int u,int v)//��ͼ 
{
	if(u==v) return ;
	e[++num].v = v,e[num].u=u;
	e[num].ne = head[u];head[u] = num;
}
inline void check(int tmp[],int l)//�ȽϺ���,��ô� 
{
	std::sort(tmp,tmp+l);//�Դ𰸽������� 
	if((l==max_unicom && tmp[0]<ans[0]) || (l>max_unicom))//ȡ���Ƚϳ�,���ֵ����С��,��Ϊ�� 
	  for(int i=0;i<l;i++)//���µĴ� 
	    ans[i]=tmp[i];
	max_unicom=max(max_unicom,l);//���´�С 
}
void Tarjan(int u) 
{
	dfn[u]=low[u]= ++dn;//Ϊ DFS�� �� low ��ֵ 
	st.push(u);	//��ջ 
	for(R int i=head[u];i;i=e[i].ne)//ö�ٿ��Ե���ı� 
	{
	  int v=e[i].v;
	  if(!dfn[v]) Tarjan(v) , low[u]=min(low[u],low[v]);
	  //����µ�δ�������, �����µ�dfs, ���ڻ���ʱ����ԭ���lowֵ 
	  else if(!bel[v]) low[u]=min(low[u],dfn[v]);
	  //����µ㵽��� ������һ��ǿ��ͨ������, �����µ��dfs�����Դ�� 
	}
	if(low[u]==dfn[u])//������ɺ�,���һ�����lowֵ��dfs�����,˵���ҵ���һ����(��ǿ��ͨ����) 
	{
	  ++be;//ǿ��ͨ������++ 
	  int sum=0;
	  int tmp[MARX];
	  for (R int r=u+1; r!=u; st.pop())//ջ�е�,��ͬһ�����е�Ԫ�ػص�,ֱ������Դ�� 
	  {
		r=st.top(),tmp[sum++]=r;
		bel[r]=be; 		  //�������ڷ����� 
	  }
	  check(tmp,sum);
	}
}
//=================================================
signed main() 
{
	n = read(),m = read();
	for(R int i=1;i<=m;i++) //��ԭʼͼ 
	{
	  int u=read(),v=read(),t=read();
	  add(u,v);
	  if(t==2) add(v,u);
	}
	for(R int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);//ѭ������tarjan,ֱ��ÿ���㶼����һ��ǿ��ͨ���� 
	printf("%d\n",max_unicom);
	for(int i=0;i<max_unicom;i++) printf("%d ",ans[i]);
}
