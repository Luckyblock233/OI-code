//֪ʶ��:���ϲ��, �����ʷ�,lca 
/*
By:Luckyblock
����,���Ǹ���������������
���ǲ��ַ�:

si=ti 10��:
ÿ���˵������յ���ͬ,��0��ʱ�������յ� 
����һ���˵����յ�� ,�Ͳ��ɱ��۲쵽
���� ���Թ۲쵽�˵Ĺ۲�Ա,
ֻ��wj=0�Ĺ۲�Ա.
����Ҫ�ҵ����� ����� wj=0�Ĺ۲�Ա��ͬ����. 

wj=0 10��:
�۲�Աֻ���ڵ�0��۲�.
Ҳ����˵,
ֻ�� ��� �� �۲�Ա���ڵ� ��ͬ���� , �Żᱻ�۲쵽. 
*/
#include<cstdio>
#include<ctype.h>
#include<vector>
const int MARX = 1010;
//=============================================================
struct edge
{
	int u,v,ne;
}e[MARX<<1];
int n,m,num , head[MARX],w[MARX],ans[MARX];
bool zero[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v)
{
	e[++num].u=u,e[num].v=v;
	e[num].ne=head[u],head[u]=num;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<n; i++)
	{
	  int u=read(),v=read();
	  add(u,v),add(v,u);
	}
	for(int i=1; i<=n; i++)
	{
	  w[i]=read();
	  if(!w[i]) zero[i]=1;
	}
	for(int i=1; i<=m; i++)
	{
	  int s=read(),t=read();
	  if(zero[s]) ans[s]++;
	}
	for(int i=1; i<=n; i++) printf("%d ",ans[i]);
}
