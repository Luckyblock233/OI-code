//�����㷨����������topsort��
/*
˼·�������������,��������ͼ,�ҳ������,ѹ��ջ,����¼.
֮��ʼtopsort�㷨.�ҵ�ջ��Ԫ��,�����Ԫ�ز�Ϊ����,�ͼ�ȥ���ķ�ֵ. 
�����ȥ��ֵ��,�õ��˷ܶȲ�Ϊ��,
��ö�������ӵ�,ʹ�ӵ��c���ϰ���ʽ�������ֵ,��ʹ�ӵ����ȼ�һ 
����ӵ����Ϊ0,�ͽ���ѹ��ջ
�����������ӵ��,��ĸ����˷ܶ�����. 
һֱ��ջΪ��
����ҵ��˷ܶȲ�Ϊ0�ĵ�,�����
�Ҳ��������null 
*/ 
#include<cstdio>
#include<stack>
using namespace std;
struct baka9//�ڽӱ��� 
{
	int u,v,w,ne;
}a[100100];
int head[110];
bool root[110];
int c[110],u[110];//��������˷ܶ��뷧ֵ 
int ru[110];//����� 
int num;
void add(int u,int v,int w)//�ڽӱ� 
{
	a[++num].ne=head[u];	
	head[u]=num;
	a[num].u=u;a[num].v=v;a[num].w=w;
}
int main()
{
	stack <int> s;
	int n,p;
	scanf("%d%d",&n,&p);//���� 
	for(int i=1;i<=n;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	c[i]=x;u[i]=y;
	  }
	for(int i=1;i<=p;i++)
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);
	  	ru[v]++;//������� 
	  }
	for(int i=1;i<=n;i++)//�ҵ�����,����¼ 
	  if(!ru[i])
	    {
	      s.push(i);
	      root[i]=1;
		}
	while(!s.empty())
	  {
	  	int u1=s.top();
	  	s.pop();
	  	if(!root[u1])//��Ϊ�� 
	  	  c[u1]-=u[u1];
	  	if(c[u1] > 0)//���ĸ���˷� 
	  	  for(int i=head[u1];i;i=a[i].ne)//�ҵ��ӵ� 
	  	    {
	  	  	  int v=a[i].v,w=a[i].w;
			  c[v]+=w*c[u1];//�����ӵ��˷ܶ� 
			  ru[v]--;//��ȼ�һ 
	  	  	  if(!ru[v]) 
			    s.push(v);//ѹ��ջ 
		    }
		if(head[u1]) 
		  c[u1]=0;//�������ӵ��ĸ�� 
	  }
	int flag_no_0=0;//�Ҵ� 
	for(int i=1;i<=n;i++)
	  if(c[i] > 0)
	    flag_no_0=1;
	if(!flag_no_0)
	  printf("NULL"); 
	else
	  for(int i=1;i<=n;i++)
	    if(c[i] > 0) printf("%d %d\n",i,c[i]);
}
