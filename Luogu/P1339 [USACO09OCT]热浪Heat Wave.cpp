//֪ʶ��:��Դ���· 
/*
ģ����
���ע�� 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int MAXX=2147483640;//���ֵ 
using namespace std;
//======================================================================
struct line
{
	int be,af,we;//�ִ�ǰ�� ��� Ȩ�� 
	int next;
}l[50010];
struct p//���ȶ����Ż� 
{
	int num,diss;
	bool operator < (const p &a) const
	{
	  return diss > a.diss;
	}
};
int head[10010],dis[10010];//����С���� 
bool f[10010]; 
int n,m,s,x,t,num;
//======================================================================
void add(int bee,int aff,int wee)//�ڽӱ����Ԫ�� 
{
	l[++num].next=head[bee];head[bee]=num;
	l[num].be=bee;l[num].af=aff;l[num].we=wee;
}
void dj(int s)
{
	memset(f,0,sizeof(f));//��ʼ�� 
	priority_queue <p> q;
	p tmp;
	tmp.num=s,tmp.diss=0;
	for(int i=1;i<=n;i++) dis[i]=MAXX;//����ֵ 
	dis[s]=0;//��ʼ�� 
	q.push(tmp);
	while(!q.empty())
	{
	  int topp=q.top().num;
	  q.pop();
	  if(f[topp]) continue;
	  f[topp]=1;
	  for(int j=head[topp];j;j=l[j].next)//��topp����ٵ�,�����бȽ� 
	  {
		if(dis[l[j].af] > dis[topp]+l[j].we && !f[l[j].af])
		{
		  dis[l[j].af] = dis[topp]+l[j].we;
		  tmp.num=l[j].af;
		  tmp.diss=dis[l[j].af];
		  q.push(tmp);//�������ȶ��� 
		}
	  }
	}
}
//=================================================================
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);//����
	for(int i=0;i<m;i++)
	{
	  int bee,aff,wee;
	  scanf("%d%d%d",&bee,&aff,&wee);
	  add(bee,aff,wee),add(aff,bee,wee); 
	}
	dj(s);
	printf("%d",dis[t]); //�����t����Сֵ 
}
