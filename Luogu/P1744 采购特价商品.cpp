//������spfa��ģ����Ŀ,����׸�� 
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int INTMAX=2147483647;
int po[1000][3];
double map[1000][1000];//��ʼ�� 
bool vis[1000];
double dis[1000];
int n,m,s,t;
void spfa();
int main()
{
	scanf("%d",&n);//���� 
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&po[i][1],&po[i][2]);
	memset(map,INTMAX,sizeof(map));
	scanf("%d",&m);
	for(int i=1;i<=m;i++)//����� 
	  {
	  	int a,b;
	  	scanf("%d%d",&a,&b);
	  	map[a][b]=map[b][a]=sqrt( ( (po[a][1]-po[b][1])*(po[a][1]-po[b][1]) )+( (po[a][2]-po[b][2])*(po[a][2]-po[b][2]) ) );
	  }
	scanf("%d%d",&s,&t);
	spfa();
	printf("%.2lf",dis[t]);
}
void spfa()//����spfa 
{
	for(int i=1;i<=n;i++)//����ֵ 
	  dis[i]=INTMAX;
	queue<int> q;//���� 
	q.push(s);
	dis[s]=0;//��ʼ�� 
	vis[s]=1;
	while(!q.empty())//�����в�Ϊ�� 
	  {
	  	int u=q.front();//ȡ��ǰ 
	  	q.pop();//ɾ���� 
	  	vis[u]=0;//����,��ʾ�ε��뿪���� 
	  	for(int v=1;v<=n;v++)//��n���� 
	  	  {
	  	  	if(map[u][v]!=INTMAX)
	  	  	  {
	  	  	  	if(dis[u]+map[u][v]<dis[v])//���� 
	  	  	  	  {
	  	  	  	  	dis[v]=dis[u]+map[u][v];
	  	  	  	  	if(!vis[v])//ѹ������� 
	  	  	  	  	  {
	  	  	  	  	  	q.push(v);
	  	  	  	  	  	vis[v]=1;//��һ 
					  }
				  }
			  }
		  }
	  }
}
