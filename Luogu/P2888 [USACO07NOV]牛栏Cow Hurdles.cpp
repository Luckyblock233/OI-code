//����Ϊluogu�ϵ� �������� �㷨��:
//˼·���ڶ�floy��Ŀ������ͬ,�����⽫ģ���и�·��֮�ͱ�Ϊ��:
//��·����·�����ȵ����ֵ
//ֻ�轫��ͳ���,��Ϊ����Сֵ���򼴿� 
//����,����Ϊ����ͨ��,��ע�ⲻҪ˫��ֵ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int hi[405][405];//�����
int main()
{
	memset(hi,1000000,sizeof(hi));
	int lll=hi[1][1];//�泬���ֵ 
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);//���� 
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	    scanf("%d%d%d",&x,&y,&z);
	    hi[x][y]=z;//����ͨ����ֵ 
	  }
	for(int k=1;k<=n;k++)//Floyd�������ѭ�� 
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      if(hi[i][j] > max(hi[i][k],hi[k][j]) )//�˴�������С��,�滻Ϊ����С�ķ�·���� 
	      	hi[i][j]=max(hi[i][k],hi[k][j]);//�滻��ֵ 
	for(int i=1;i<=t;i++)//����Ҫ���������� 
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	if(hi[x][y]!=lll)//�����Ե��� 
	  	  printf("%d\n",hi[x][y]);//��� 
	  	else
	  	  printf("-1\n");//�������-1 
	  }
}
