//֪ʶ��:����DP,���鼯 
/*
By:Luckyblock
��ĿҪ��:
����һЩ��Ʒ ,�м�ֵ������.
һЩ��Ʒ����һ����,
�� ���������ı����ܵ��������ֵ�� 

��������:
���ǽ� ����һ�������Ʒת��Ϊ һ���ϳ���Ʒ
�ϳ���Ʒ ��ֵ = �ڲ���Ʒ��ֵ֮��,
�ϳ���Ʒ ���� = �ڲ���Ʒ����֮��, 
����ʹ�ò��鼯����ά�� ,
����ø��ϳ���Ʒ�ļ�ֵ����.

��Ʒ�ϳ���Ϻ�,
�����ת��Ϊ��һ���01��������. 
*/
#include<cstdio>
#include<ctype.h>
#define max(a,b) (a>b?a:b) 
const int MARX = 1e4+10;
//=============================================================
int n,m,w,c[MARX],d[MARX] , c1[MARX],d1[MARX]; 
int BEL,pre[MARX],group[MARX],bel[MARX];//���鼯
int f[MARX];//����DP 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int find(int x) { return (pre[x]==x)?(x):(pre[x]=find(pre[x])); }//�鼯 
void join(int x,int y)//���� 
{
	int r1=find(x),r2=find(y);
	if(r1!=r2) pre[r2]=r1;
}
//=============================================================
signed main()
{
	n=read(),m=read(),w=read();
	for(int i=1;i<=n;i++)//���벢��ʼ�� 
	{
	  pre[i]=i;
	  c[i]=read(),d[i]=read();
	}
	for(int i=1;i<=m;i++)
	{
	  int u=read(),v=read();
	  
	  if(bel[u] || bel[v])//�����һ�� ������һ���ϳ���Ʒ 
	  {
	    if(bel[u]) c1[bel[u]]+=c[v] , d1[bel[u]]+=d[v],bel[v]=bel[u];//����u�ĺϳ���Ʒ 
	    else c1[bel[v]]+=c[u] , d1[bel[v]]+=d[u],bel[u]=bel[v];//����v�ĺϳ���Ʒ 
	  }
	  else
	  {
	    bel[u]=bel[v]= ++BEL;//�½�һ���ϳ���Ʒ 
	    c1[BEL]+=(c[u]+c[v]) , d1[BEL]+=(d[u]+d[v]);
	  }
	  join(u,v);//���� 
	}
	for(int i=1;i<=n;i++)//������,����Ҫ�ϲ��������Ʒ , ת��Ϊ�ϳ���Ʒ 
	  if(!bel[i]) c1[++BEL]+=c[i] , d1[BEL]+=d[i];
	for(int i=1;i<=BEL;i++)//01���� 
	  for(int j=w;j>=c1[i];j--)
	    f[j]=max(f[j],f[j-c1[i]]+d1[i]);
	printf("%d",f[w]);
}
