//֪ʶ��:Tarjan/ǿ��ͨ����/���
/*
Ӧ��Tarjan���� 

����dfs�ı���˳�� , 
��ͼ����һ����,
ͼ�����˲����. 
��dfs���ݵıߵ����ر� 

��Tarjan,
dfn[]��¼ÿһ�����dfs��,
low[]��¼����ͨ��dfs����С�ĵ�ı��

���Է���,��ʼʱdfn[i]=low[i]
�ڲ���dfs�ݹ�����н��и���

1.�����������ĸ��ڵ�,
  ��������������������ϵ�����
  ȥ��������,�����������᲻��ͨ
  ˵������һ�����
2.���������Ľڵ�: 
  ������ɺ�,
  �����һ���� ,����low[v]>=dfn[u]
  ˵��v��,һ�����ﲻ��u������� (dfs�������µ�����) 
  ��ôu����һ����� 
*/
#include<cstdio>
#include<stack>
#include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b 
#define max(a,b) a>b?a:b
#define int long long
#define R register
using namespace std;
//=================================================
const int MARX = 2e4+10;
struct edge //�г��˸�����������
{
	int u,v,ne;
}e[MARX*10];
int n,m,num ,  head[MARX];  //graph_building��ͼ 
int dn,sum, dfn[MARX],low[MARX];//Tarjan
bool cut[MARX];
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
void Tarjan(int u,int fa) 
{
	dfn[u]=low[u]= ++dn;//Ϊ DFS�� �� low ��ֵ 
	int child=0;
	for(R int i=head[u];i;i=e[i].ne)//ö�ٿ��Ե���ı� 
	{
	  int v=e[i].v;
	  if(!dfn[v]) //����µ�δ�������, �����µ�dfs, ���ڻ���ʱ����ԭ���lowֵ 
	  {
	  	Tarjan(v,fa);
		low[u]=min(low[u],low[v]);//�����ܵ����dfs����С�ĵ�ı�� 
		if(low[v]>=dfn[u] && u!=fa)//u�㲻Ϊ�������ĸ��ڵ�,��v�㵽�ﲻ��u�������
		{
		  if(!cut[u]) sum++;
		  cut[u]=1;//u��Ϊ���
		}
		if(u==fa) child++;//��������++ 
	  }
	  low[u]=min(low[u],dfn[v]);//����lowֵ 
	}
	if(child>=2 && u==fa)//uΪ�������ĸ��ڵ�,������������������ 
	{
	  if(!cut[u]) sum++;
	  cut[u]=1;
	}
}
//=================================================
signed main() 
{
	n = read(),m = read();
	for(R int i=1;i<=m;i++) 
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u); 
	}
	for(R int i=1;i<=n;i++)//ѭ������tarjan,ֱ��ÿ���㶼�������  
	  if(!dfn[i]) Tarjan(i,i);
	  
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++)
	  if(cut[i]) printf("%lld ",i);
}
