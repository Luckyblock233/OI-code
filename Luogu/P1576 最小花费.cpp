//����Ϊdijkstra ������,˼·����dj�㷨�ĵͼ���ʽ
//ֻ��Ҫ������ļ��ٰٷֱ�,ת��Ϊʣ��ٷֱ�,
//�����ת��Ϊ�������·���˻������� 
#include<cstdio>
#include<cstring>
using namespace std;
double map[2005][2005]={0};//��ʼ�� 
double dis[2005]={0};
bool f[2005]={0};
int n,m,s,t;
int bian;
void dj();
int main()
{
	scanf("%d%d",&n,&m);//���� 
	for(int i=1;i<=m;i++)
	  {
	  	int x,y;
	  	double z;
	  	scanf("%d%d",&x,&y);
	  	scanf("%lf",&z);
	  	map[x][y]=map[y][x]=(100-z)/100;// ������ļ��ٰٷֱ�,ת��Ϊʣ��ٷֱ�,
	  }
	scanf("%d%d",&s,&t);//����յ� 
	dj();
	printf("%0.8lf",100/dis[t]);//��ת��Ϊ��Ҫ��Ǯ,������� 
}
void dj()//����dj�㷨,����׸�� 
{
	for(int i=1;i<=n;i++)
	  dis[i]=map[s][i];
	f[s]=1;
	dis[s]=1;
	for(int i=1;i<n;i++)
	  {
	  	double minn=0;
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	if(dis[j] > minn && !f[j])
	  	  	  {
	  	  	  	minn=dis[j];
	  	  	  	bian=j;
			  }
		  }
		f[bian]=1;
		if(bian==t) break;//��t��ȷ��,�Ϳ������. 
		for(int j=1;j<=n;j++)
		  {
		  	if(dis[bian]*map[bian][j] > dis[j] && !f[j])//�˴������·����ת��Ϊ���·���˻� 
		  	  dis[j]=dis[bian]*map[bian][j];
		  }
	  }
}
