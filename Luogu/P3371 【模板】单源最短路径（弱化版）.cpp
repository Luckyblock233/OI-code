//ģ����,��Ϊ�ǵ���·�������ݱȽ���,�������ڽӱ�+��dijkstra 
//�ڽӱ�ͦ��
//�ڽӾ����MLE�����ڽӱ�ÿ� ������  
#include<cstdio>
#include<cstring>
const int MAXX=2147483647;//���ֵ 
using namespace std;
struct line
{
	int be,af,we;//�ִ�ǰ�� ��� Ȩ�� 
	int next;
}l[500010];
int head[10010];
int num=0;
int dis[10010];//����С���� 
bool f[10010]={0};
int n,m,s;
void add(int bee,int aff,int wee)//�ڽӱ����Ԫ�� 
{
	l[++num].next=head[bee];
	l[num].be=bee;
	l[num].af=aff;
	l[num].we=wee;
	head[bee]=num;
}
void dj();
int main()
{
	scanf("%d%d%d",&n,&m,&s);//���� 
	for(int i=0;i<m;i++)
	  {
	  	int bee,aff,wee;
	  	scanf("%d%d%d",&bee,&aff,&wee);
	  	add(bee,aff,wee);
	  }
	dj();
	for(int i=1;i<=n;i++)
	  printf("%d ",dis[i]);//��� 
}
void dj()
{
	for(int i=1;i<=n;i++)
	  dis[i]=MAXX;//����ֵ 
	for(int i=head[s];i;i=l[i].next)//Ϊdis��s��ֱ�����ڵ㸳ֵ 
	  {
	  	if(l[i].we <dis[l[i].af]) //��Ϊ�����������������,��ȡ������С��һ�� 
	  	  dis[l[i].af]=l[i].we;
	  }
	dis[s]=0;//��ʼ�� 
	f[s]=1;
	for(int i=1;i<=n;i++)//��ʼ����dj�㷨 
	  {
	  	int minn=MAXX,k=0;//����С 
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	if(dis[j] < minn && !f[j])
	  	  	  {
	  	  	  	minn=dis[j];k=j;
			  }
		  }
		if(k==0) break;//�Ҳ���,����ֹ 
		f[k]=1;//��һ 
		for(int j=head[k];j;j=l[j].next)//��k����ٵ�,�����бȽ� 
		  {
		  	if(dis[l[j].af] > dis[k]+l[j].we)
		  	  dis[l[j].af] = dis[k]+l[j].we;
		  }
	  }
}
