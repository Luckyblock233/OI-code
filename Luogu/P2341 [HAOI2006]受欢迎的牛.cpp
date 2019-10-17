//֪ʶ��:Tarjan/ǿ��ͨ����/����/topsort
/*
���Ե�����:
�� ������������ֱ��/�������
	  �ĵ������ 

��������: 
��֪: 
��Tarjan���� ,
��ø�ǿ��ͨ������

���������һ��
����Ϊ0��ǿ��ͨ����
��ô��ǿ��ͨ������Ԫ�ظ���
����Ҫ�� 

��ȷ��֤��: 
������ڶ������Ϊ0�ķ���
����Щ����
ȱ������֮����������������
�ʲ���������ĿҪ��:
��������������ֱ��/������� 
 
*/ 
#include<cstdio>
#include<stack>
#include<ctype.h>
#include<cstring>
#define min(a,b) a<b?a:b  //����дalgorithm�� 
#define max(a,b) a>b?a:b
#define int long long
#define R register
using namespace std;
//=================================================
const int MARX = 1e4+10;
struct edge //�г��˸�����������
{
		int u,v,ne;
}e[MARX*10];
int n,m,num ,  head[MARX],we[MARX];  //graph_building��ͼ 
int dn,be,  dfn[MARX],low[MARX],bel[MARX],val[MARX];//Tarjan
int ans,in[MARX];  //topsort�������� 
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
		e[++num].u=u,e[num].v = v;
		e[num].ne = head[u],head[u] = num;
}
void Tarjan(int u) 
{
		dfn[u]=low[u]= ++dn;//Ϊ DFS�� �� low ��ֵ 
		st.push(u);					//��ջ 
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
		  for (R int r=u+1; r!=u; st.pop())//ջ�е�,��ͬһ�����е�Ԫ�ػص�,֪������Դ�� 
				{
					r=st.top(); 
				  bel[r]=be, 		  //�������ڷ����� 
					val[be]+=we[r];	//�˷���Ȩֵ���� 
				}
		}
}
void topsort()//�������� 
{
		int in_num=0; 
		for(int i=1;i<=be;i++)//�ҵ����Ϊ0�ĵ� 
		  if(!in[i]) in_num++,ans=val[i];
		
		printf("%lld",in_num==1?ans:0);//��� 
}
//=================================================
signed main() 
{
		n = read(),m = read();
		for(R int i=1;i<=n;i++) we[i] = 1;
		for(R int i=1;i<=m;i++) add(read(),read());//��ԭʼͼ 
		
		for(R int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);//ѭ������tarjan,ֱ��ÿ���㶼����һ��ǿ��ͨ���� 
		memset(head,0,sizeof head);//���ԭͼ(�ظ�����ԭ���� 
		num=0;
		for(R int i=1 ; e[i].v ; i++)//ö�����е�ԭ�� 
		{
			int u=e[i].u,v=e[i].v;
			if(bel[u]!=bel[v])//����ͬһ������ 
		    in[bel[v]]++ , add(bel[v],bel[u]);
		}
		
		topsort();
}
