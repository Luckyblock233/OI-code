//֪ʶ��:��������,������DP 
/*
��ĿҪ��:
�� 1~n ֮����·

������Ŀ������ͼ�������޻� 
���Ҷ���1~i�����·,
�ж���·������ѡ��
���Կ��Խ���
������DP

�Ƚ� ��������1֮ǰ�ĵ�ȥ��
�������ǳ����ϵĵ�����-- 
�ٴ�1��ʼ������������DP 
*/ 
#include<cstdio>
#include<queue>
#include<algorithm>
#include<ctype.h>
#include<cstring>
const int MARX = 1510;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[50010];
int n,m,num , head[MARX],in[MARX];
long long f[MARX];//f[i]��ʾ 1��i�������� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)//�ӱ� 
{
	e[++num].u=u,e[num].v=v,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
void prepare()//���벢��ʼ�� 
{
	memset(f,-1,sizeof(f));
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w);
	  in[v]++;//���++ 
	}
}
void topsort()//�������� 
{
	std::queue <int> q;
	for(int i=1;i<=n;i++)//�ҵ����Ϊ0�ĵ� 
	  if(!in[i] && i!=1)
	    q.push(i);
	//ȥ����������1֮ǰ�ĵ� 
	for(int u=q.front();!q.empty();q.pop(),u=q.front()) 
	  for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)
	  {
	    in[v]--;
		if(!in[v]) q.push(v);
	  }
	
	q.push(1);f[1]=0;//��ʼ�� ,��1��ʼDP 
	for(int u=q.front();!q.empty();q.pop(),u=q.front())
	  for(int i=head[u],v=e[i].v;i;i=e[i].ne,v=e[i].v)
	  {
	    f[v]=std::max(f[v],f[u]+e[i].w);//����1��v�������� 
		in[v]--;
		if(!in[v]) q.push(v);
	  }
}
//=============================================================
signed main()
{
	prepare();
	topsort();
	printf("%lld",f[n]);
}
