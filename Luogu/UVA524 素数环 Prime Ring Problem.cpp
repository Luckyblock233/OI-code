//ʹ���㷨:DFS+����
//����ɸ��������� 
//�����λ�������� ������������ǰһ������Ϊ������������ 
//�����n����ʱ,�ж������һ�����Ƿ��Ϊ����
//�����Ϊ����,���ҵ���һ���,���. 
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
bool zhi[50]={1,1};//ɸ�������� 
bool use[30];
int ans[30];
int n,tot,n1;
void zzz();
void dfs(int k);
void print();
int main()
{
	zzz();
	while(scanf("%d",&n) != EOF)//ѭ������ 
	  {
	    memset(ans,0,sizeof(ans));
		memset(use,0,sizeof(use)); 
	  	if(++n1>=2) printf("\n");
	    printf("Case %d:\n",n1);
	    ans[1]=1;
	    dfs(2);//��! 
	  }
}
void zzz()//ɸ 
{
	for(int i=2;i<=sqrt(2*20+1);i++)
	  for(int j=2;j<=(2*20+1)/i;j++)
	    zhi[i*j]=1;
}
void dfs(int k)
{
	for(int i=2;i<=n;i++)//���������� 
	  if(!zhi[i+ans[k-1]] && !use[i])//�������� 
	    {
	  	  ans[k]=i;//���� 
	  	  use[i]=1;//��¼�Ƿ��ù� 
	  	  if(k==n && !zhi[i+ans[1]]) //����߽� 
			print();
	  	  else 
			dfs(k+1);//������ 
	  	  use[i]=0;//���� 
	  	  ans[k]=0;
	    }
	return ;
}
void print()//��� 
{
	printf("%d",ans[1]);
	for(int i=2;i<=n;i++)
	  printf(" %d",ans[i]);
	printf("\n");
	return ;
}
