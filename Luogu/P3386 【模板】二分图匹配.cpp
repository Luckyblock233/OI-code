//֪ʶ��:����ͼƥ��/�������㷨
/*
����ͼƥ��ģ��
ʹ���������㷨 
���ע�� 
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
using namespace std; 
//===================================================
const int MARX = 1e3+10;
int n,m,e,ans;
bool road[MARX][MARX] , vis[MARX];
int hus[MARX];//husΪint,��д��bool 
//===================================================
inline int read()//��� 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
bool marry(int u)//�������㷨:��� 
{
	for(int v=1;v<=m;v++)//ö���ܵ���ĵ� 
	{
	  if(road[u][v] && (!vis[v]))
	  {
		vis[v]=1;//���� 
		if((!hus[v]) || marry(hus[v]))//���������� 
		{
		  hus[v]=u;//���� 
		  return 1;
		}
	  }
	}
	return 0;
}
//====================================================
signed main()
{
	n=read(),m=read(),e=read();
	for(int i=1;i<=e;i++)
	{
	  int u=read(),v=read();//�����Ż����� 
	  if(v>m || u>n) continue;//�ӱ� 
		road[u][v]=1;
	}
			
	for(int i=1;i<=n;i++)//ö��һ���е�n���� 
	{
	  memset(vis,0,sizeof(vis));//��ʼ�� 
  	  if(marry(i)) ans++;//���´� 
	}
	printf("%d",ans);
}