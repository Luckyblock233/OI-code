//����Ŀ�Ƚ�����,�׳�ʱ, ����dj�㷨���Ż�+�ڽӱ�
//��Ҫע�����,��Ҫö��ÿһ����
//����������ţ����˵�ľ����ܺ�
//�ٽ�����ĺ�ֵ�ҳ���Сֵ,�����. 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int MAXX=2147483647;//���ֵ 
using namespace std;
struct line
{
	int be,af,we;//�ִ�ǰ�� ��� Ȩ�� 
	int next;
}l[3000];
struct p
{
	int num,diss;
	bool operator < (const p &a) const
	  {
	  	return diss > a.diss;
	  }
};
int head[810];
int num=0;
int dis[810];//����С���� 
bool f[810];
int cow[810]; 
int n1,m,n,x;
int sum,minn=MAXX;
void add(int bee,int aff,int wee)//�ڽӱ����Ԫ�� 
{
	l[++num].next=head[bee];
	l[num].be=bee;
	l[num].af=aff;
	l[num].we=wee;
	head[bee]=num;
}
void dj(int s);
int main()
{
	scanf("%d%d%d",&n1,&n,&m);//����
	for(int i=1;i<=n1;i++)//������ţ��,�������ۼӵ�cow������ 
	  {
	  	scanf("%d",&x);
	  	cow[x]++;
	  } 
	for(int i=0;i<m;i++)//����� 
	  {
	  	int bee,aff,wee;
	  	scanf("%d%d%d",&bee,&aff,&wee);
	  	add(bee,aff,wee);//ע��˫�� 
	  	add(aff,bee,wee);
	  }
	for(int i=1;i<=n;i++)//��ÿһ����Ϊ���,����һ�� 
	  dj(i);
	printf("%d",minn);//��� ��Сֵ 
}
void dj(int s)
{
	memset(f,0,sizeof(f));
	priority_queue <p> q;
	p tmp;
	tmp.num=s,tmp.diss=0;
	for(int i=1;i<=n;i++)
	  dis[i]=MAXX;//����ֵ 
	dis[s]=0;//��ʼ�� 
	q.push(tmp);
	while(!q.empty())
	  {
	  	int topp=q.top().num;
	  	q.pop();
	  	if(f[topp])
	  	  continue;
	  	f[topp]=1;
		for(int j=head[topp];j;j=l[j].next)//��topp����ٵ�,�����бȽ� 
		  {
		  	if(dis[l[j].af] > dis[topp]+l[j].we && !f[l[j].af])
		  	  {
		  	  	dis[l[j].af] = dis[topp]+l[j].we;
		  	  	tmp.num=l[j].af;
		  	  	tmp.diss=dis[l[j].af];
		  	  	q.push(tmp);//��tmp��������� 
			  }
		  }
	  }
	for(int i=1;i<=n;i++)
	  sum+=dis[i]*cow[i];//�����ܾ���� 
	minn=min(sum,minn);
	sum=0;
}
