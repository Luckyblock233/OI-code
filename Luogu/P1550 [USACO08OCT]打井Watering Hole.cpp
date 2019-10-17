//֪ʶ��:������ 
/*
��ĿҪ��:
���е�Ȩ,���б�Ȩ
���ѵ�Ȩ��,������������� "�õ�"
����С����,
ʹ���е㶼��"�õ�"��ֱ�Ӽ������.(���߱���Ϊ "�õ�")

˼·:
���е�Ȩ,���б�Ȩ,
��Ҫ��һ�������� 
��ԭͼֱ�Ӳ�������.

�����ؽ�ͼ,
����Ȩת��Ϊ��Ȩ.

�㷨ʵ��:
����һ������Դ��,
����ÿ���㶼�볬��Դ������
��Ȩֵ��Ϊÿ����ĵ�Ȩֵ.

Ȼ�󽫳���Դ�����ͼ��,
����С����������. 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
const int MARX = 510;
//=============================================================
struct edge
{
	int u,v,w;
}e[MARX*MARX/2];
int n,num,fa[MARX];
bool map[MARX][MARX];
long long ans;
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline bool cmp(edge first,edge second){return first.w<second.w;}
inline void add(int u,int v,int w){e[++num].v=v,e[num].u=u,e[num].w=w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}//�鼯 

inline void join(int x,int y)//���� 
{
	int r1=find(x),r2=find(y);
	fa[r1]=r2;
}
void kruscal()//kruscal��С������ 
{
	for(int i=1;i<=num;i++)
	  if(find(e[i].u) != find(e[i].v))
	  {
	  	join(e[i].u,e[i].v);
		ans+=(long long)e[i].w;//����� 
	  }
}
void prepare()
{
	n=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
	  int w=read();
	  add(n+1,i,w),add(i,n+1,w);//�򳬼�Դ��n+1���� 
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)//�ӱ� 
	  {
	  	int w=read();
		if(!map[i][j] && i!=j) add(i,j,w),add(j,i,w); 
	    map[i][j]=map[j][i]=1;
	  }
	std::sort(e+1,e+num+1,cmp);//���ձ�Ȩ�������� 
}
//=============================================================
signed main()
{
	prepare();
	kruscal();
	printf("%lld",ans); 
}
