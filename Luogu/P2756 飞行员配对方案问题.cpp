//֪ʶ��:����ͼƥ��/�������㷨
/*
����ͼƥ��ģ��
ʹ���������㷨 
���ע�� 
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define int long long
using namespace std; 
//===================================================
const int MARX = 1e3+10;
int n,m,e,ans;
bool road[MARX][MARX] , vis[MARX];
int hus[MARX];//husΪint,��д��bool 
//===================================================
bool marry(int u)//�������㷨:��� 
{
	for(int v=m+1;v<=n;v++)//ö���ܵ���ĵ� 
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
	scanf("%lld%lld",&m,&n);
	while(1) 
	{
	  int u,v;//�����Ż����� 
	  scanf("%lld%lld",&u,&v);
	  if(u==-1 && v==-1) break;
	  if(u<=m && v<=n)
	    road[u][v]=1;
	}
			
	for(int i=1;i<=m;i++)//ö��һ���е�n���� 
	{
	  memset(vis,0,sizeof(vis));//��ʼ�� 
  	  if(marry(i)) ans++;//���´� 
	}
	if(ans==0) {printf("No Solution!");return 0;}
	printf("%lld\n",ans);
	for(int i=m+1;i<=n;i++)//���ƥ����� 
	  if(hus[i]) printf("%lld %lld\n",hus[i],i);
}
