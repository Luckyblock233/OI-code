//֪ʶ��:Floyd,���· 
/*
ģ����
���ע�� 
*/
#include<cstdio>
#include<cstring> 
using namespace std;
//=========================================================== 
int road[10010];//����Ҫ��·�� 
int danger[105][105];//��Σ�ն� 
int n,m,minn;
//===========================================================
signed main()
{
	memset(danger,0xfffff,sizeof(danger));//��ʼ������ֵ
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&road[i]);//Ԥ��·�� 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%d",&danger[i][j]);//����ÿ���㵽�������Σ�ն� 
	
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)//Floyd���Դ���· 
	      if(danger[i][j] > danger[i][k] + danger[k][j])
	      	danger[i][j]=danger[i][k] + danger[k][j];
	      	
	for(int i=1;i<m;i++)//����Ԥ��·������Сֵ֮�� 
	  minn+=danger[road[i]][road[i+1]];
	
	printf("%d",minn);
}
