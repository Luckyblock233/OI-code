//����˼·:
//���Գ��淽�������a�㵽��b������·
//�������·ͬʱ��path�����¼·��
//�㷨������,�ٿ����·���������𻵵�·��
//�����ۼ������� 
#include<cstdio>
#include<cstring>
using namespace std;
int map[110][110];//�治�� 
bool mapbreak[110][110];//���� 
int dis[110];
bool f[110];
int path[110];
int MA=21474830;//���ֵ 
int n,m,d,A,B;
int ans;
void dj(int);//������dj 
int main()
{
	scanf("%d%d",&n,&m);//û����˼������ 
	memset(map,MA,sizeof(map));//��ʼ�� 
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	  	scanf("%d%d%d",&x,&y,&z);
	    map[x][y]=map[y][x]=z;
	  }
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	    mapbreak[x][y]=mapbreak[y][x]=1;
      }	
	scanf("%d%d",&A,&B);
	dj(A);
	int k1=B;//��ѭ����·�� 
	for(int i=k1;i;i=path[i])
	  {
	  	if(mapbreak[i][path[i]])//�������ۼ� 
	  	  ans+=map[i][path[i]];
	  }
	printf("%d",ans);
}
void dj(int s)//��dj,��׸�� 
{
	for(int i=1;i<=n;i++)
	  {
	  	dis[i]=map[s][i];
	  	path[i]=s;
	  }
	f[s]=1;
	dis[s]=0;
	path[s]=0;
	for(int i=1;i<=n;i++)
	  {
	  	int minn=MA,k=-1;
	  	for(int j=1;j<=n;j++)
	  	  if(dis[j] < minn && !f[j])
	  	  	{
	  	  	  minn=dis[j];
	  	  	  k=j;
			}
		if(k==-1) break;
		f[k]=1;
		for(int j=1;j<=n;j++)
		  {
		  	if(dis[j] > dis[k] + map[k][j])
		  	  {
		  	  	dis[j] = dis[k] + map[k][j];
		  	  	path[j]=k;
			  }
		  }
	  }
}
