//����ʹ��dijkstra�㷨�Ķ��Ż�+�ڽӱ�,�ű����˳�ʱ 
/* 
����˼������ͨ��dj��ͬ,����Ѱ����С�ľ���ֵʱʹ�������ȶ���
�����Ϳ���ɾȥһ��ѭ��, ��Ϊֱ��������Ԫ��.
Ϊ��ʹ�����ȶ���,����һ���ṹ��p�������������Сֵ
������ ������Сֵ��������
���ɴ�󽵵�ʱ�临�Ӷ�. 
������С��ֵʱ,ֱ��%9987����
�������������� 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int MAXX=9987;//���ֵ 
using namespace std;
struct line
{
	int be,af,we;//�ִ�ǰ�� ��� Ȩ�� 
	int next;
}l[1000010];
struct p
{
	int num,diss;
	bool operator < (const p &a) const
	  {
	  	return diss > a.diss;
	  }
};
int head[1010];
int num=0;
int dis[1010];//����С���� 
bool f[1010]; 
int n,m,s,x;
void add(int bee,int aff,int wee)//�ڽӱ����Ԫ�� 
{
	l[++num].next=head[bee];
	l[num].be=bee;
	l[num].af=aff;
	l[num].we=wee%9987;
	head[bee]=num;
}
void dj(int s);
int main()
{
	scanf("%d%d",&n,&m);//����
	for(int i=0;i<m;i++)
	  {
	  	int bee,aff,wee;
	  	scanf("%d%d%d",&bee,&aff,&wee);
	  	add(bee,aff,wee);
	  }
	dj(1);
	printf("%d",dis[n]);
}
void dj(int s)
{
	memset(f,0,sizeof(f));
	priority_queue <p> q;//���ȶ��� 
	p tmp; 
	tmp.num=s,tmp.diss=0;
	for(int i=1;i<=n;i++)
	  dis[i]=MAXX;//����ֵ 
	dis[s]=1;//��ʼ�� 
	q.push(tmp);
	while(!q.empty())
	  {
	  	int topp=q.top().num;//ȡͷԪ�� 
	  	q.pop();//ɾ 
	  	if(f[topp])
	  	  continue;
	  	f[topp]=1;
		for(int j=head[topp];j;j=l[j].next)//��topp����ٵ�,�����бȽ� 
		  {
		  	if(dis[l[j].af] > dis[topp]*l[j].we && !f[l[j].af])
		  	  {
		  	  	dis[l[j].af] = (dis[topp]*l[j].we)%9987;
		  	  	tmp.num=l[j].af;
		  	  	tmp.diss=dis[l[j].af];//������� 
		  	  	q.push(tmp);
			  }
		  }
	  }
}
