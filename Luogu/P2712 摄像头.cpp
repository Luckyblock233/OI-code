//拓扑排序模板题,不再赘述 
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
void add(int u,int v)//邻接表 
{
	a[num].u=u;a[num].v=v;
	a[++num].ne=head[u];head[u]=num;
}
int main()
{
	stack <int> s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//存儿子 
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	if(!ju[x])//未被记录 
		  bian[++num1]=x;
	  	while(y--)
	  	{
	  	  int x1;
	  	  scanf("%d",&x1);
				add(x,x1);//存边
				ru[x1]++;//入度++
				if(!ju[x1])//此点未被记录过 
			    bian[++num1]=x1;
		  }
	  }
	int n1=0;
	for(int i=1;i<=num1;i++)
	  if(ru[bian[i]]==0)
	  {
		  s.push(i);n1++;
	  }
	while(!s.empty())//模板
	  {
	  	int u=s.top();
	  	s.pop();
	  	for(int i=head[u];i;i=a[i].ne)
	  	  {
	  	  	ru[a[i].v]--;
	  	  	if(ru[a[i].v]==0)//找到新的入度为0的点,加入栈 
	  	  	  {
	  	  	  	s.push(a[i].v);
	  	  	  	n1++;
			  		}
		  	}
	  }
	if(n1==n) printf("YES");//都能到达 
	else printf("%d",n-n1);//有到不了的 
}
