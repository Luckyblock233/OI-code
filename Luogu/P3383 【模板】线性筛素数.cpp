//����ɸ�������� ģ��
//���ע�� 
#include<cstdio>
using namespace std;
int n,m,num;
int p[100000010];//������ 
bool vis[100000010]={1,1};//���Ƿ�Ϊ���� 
void prime(int n)
{
	for(int i=2;i<=n;i++)//ö���� 
	  {
	  	if(!vis[i]) p[++num]=i;//Ϊ���� 
	  	for(int j=1;j<=num;j++)//���� 
	  	  {
	  	  	if(i*p[j]>n) break;
	  	  	vis[i*p[j]]=1;
	  	  	if(i%p[j]==0) break;
		  }
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	prime(n);
	for(int i=1;i<=m;i++)//ѯ�� 
	  {
	  	int x;
	  	scanf("%d",&x);
	  	if(vis[x]) printf("No\n");
	  	else printf("Yes\n");
	  }
}
