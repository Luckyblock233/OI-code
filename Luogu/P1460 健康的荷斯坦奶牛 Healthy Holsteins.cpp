//ʹ���㷨��dfs+����
//һ��ʼ����ģ���,����tle��������
//��������Ŀ֮��,�����˸Ľ�����:
//����,����ÿ������,ֻ��ȡ��ȡ�������
//��ô�����ͳ���һ���ж���߽��01��������
//dfs����ÿһ������,�ֱ�ѡ��ȡ��ȡ�������
//����ҳ����Ž⼴�� 
#include<cstdio>
using namespace std;
int v,g;
int ne[30],map[20][30];
int ans[20];
int tans[20];
int minn=1000;
void dfs(int,int);
int main()
{
	scanf("%d",&v);//���� 
	for(int i=1;i<=v;i++)
	  scanf("%d",&ne[i]);
	scanf("%d",&g);
	for(int i=1;i<=g;i++)
	  for(int j=1;j<=v;j++)
	    scanf("%d",&map[i][j]);
//-----------------------------------------------------
	dfs(1,0);//�ӵ�һ�ֿ�ʹ��,��ʼ������Ϊ0 
	printf("%d ",minn+1);//��� 
	for(int i=0;i<=minn;i++)
	  printf("%d ",tans[i]);
}
void dfs(int k,int tot)
{
	if(tot >= minn || k>g)//�߽� 
	  return ;
	int flag=1;
	ans[tot]=k;
	for(int j=1;j<=v;j++)//�жϷ����Ƿ����
	  {
	    ne[j]-=map[k][j];
	    if(ne[j] > 0)
	      flag=0;
	  }
	if(flag && tot < minn)//�µ����Ž� 
	  {
		minn=tot;
		for(int i=0;i<=tot;i++)
	  	  tans[i]=ans[i];//���´� 
	  }
	else dfs(k+1,tot+1);//ȡ��������,�������� 
	for(int j=1;j<=v;j++)//���� 
	  ne[j]+=map[k][j];
	dfs(k+1,tot);//��ȡ�������� 
}
