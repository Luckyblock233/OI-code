//��������ģ����,����׸�� 
#include<cstdio>
#include<stack>
using namespace std;
struct baka9
{
	int u,v,ne;
}a[100000];
int n,num,num1;
int head[10000];
int ru[10000];
int bian[1000];
bool ju[100000];
void add(int u,int v)//�ڽӱ� 
{
	a[num].u=u;a[num].v=v;
	a[++num].ne=head[u];head[u]=num;
}
int main()
{
	stack <int> s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//����� 
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	if(!ju[x])//δ����¼ 
		  bian[++num1]=x;
	  	while(y--)
	  	{
	  	  int x1;
	  	  scanf("%d",&x1);
				add(x,x1);//���
				ru[x1]++;//���++
				if(!ju[x1])//�˵�δ����¼�� 
			    bian[++num1]=x1;
		  }
	  }
	int n1=0;
	for(int i=1;i<=num1;i++)
	  if(ru[bian[i]]==0)
	  {
		  s.push(i);n1++;
	  }
	while(!s.empty())//ģ��
	  {
	  	int u=s.top();
	  	s.pop();
	  	for(int i=head[u];i;i=a[i].ne)
	  	  {
	  	  	ru[a[i].v]--;
	  	  	if(ru[a[i].v]==0)//�ҵ��µ����Ϊ0�ĵ�,����ջ 
	  	  	  {
	  	  	  	s.push(a[i].v);
	  	  	  	n1++;
			  		}
		  	}
	  }
	if(n1==n) printf("YES");//���ܵ��� 
	else printf("%d",n-n1);//�е����˵� 
}
