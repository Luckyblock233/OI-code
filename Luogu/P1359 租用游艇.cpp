//����dj�����·�㷨,����׸�� 
//�˴�ע��:��ֻͧ�ܴ����ε����Σ�����ֻ�ܴ浥��ͨ��
//��˫�������� 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxxx=100000;//��ֵ 
int map[1000][1000];//�ڽӾ��� 
int dis[1000];
bool f[1000];
int n;
void dj(int);
int main()
{
	scanf("%d",&n);//��Ȥ���� 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    map[i][j]=maxxx;//��ʼ������ֻ 
	for(int i=1;i<=n-1;i++)//����i�㵽�����εĵ�ľ��� 
	  {
	  	for(int j=i+1;j<=n;j++)
	  	{
	  	  int z;//������� 
	  	  scanf("%d",&z);
	  	  map[i][j]=z;//һ��ע�ⵥ��!!! 
		}
	  }
	dj(1);
	printf("%d",dis[n]);//��� 
}
void dj(int s)//����dj����,����׸�� 
{
	for(int i=1;i<=n;i++)
	  dis[i]=map[s][i];
	dis[s]=0;
	f[s]=1;
	for(int i=1;i<=n;i++)
	  {
	  	int minn=maxxx;
	  	int bian=0;
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	if(dis[j]<minn && !f[j])
	  	  	  {
	  	  	  	minn=dis[j];
	  	  	  	bian=j; 
			  }
		  }
		if(bian==0) break;
		f[bian]=1;
		for(int j=1;j<=n;j++)
		  {
		  	if(dis[bian]+map[bian][j]<dis[j])
		  	  dis[j]=dis[bian]+map[bian][j];
		  }
	  }
}
