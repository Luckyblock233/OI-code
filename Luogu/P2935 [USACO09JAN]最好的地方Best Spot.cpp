//�㷨��Floyd���Դ���·
//���е�Floyd����
//��������,���ڽӱ���
//Ȼ���ʼ��map[i][i]����0,��i�㵽i��ľ���Ϊ0
//��Ϊ����ѡ��ĵ������ȥ�ĵ�,����Ҫ��ǰ��ʼ��,��ȻFloyd��һ�������
//Ȼ����Floyd
//֮��ö��ÿһ����,�������ǵ���Ҫ���ľ���֮��,
//ѡ�����к���С�ĵ�ı��
//������� 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MARX=0xf;
int p,f,c,ans;
double minn=999999999;
int map[510][510];
int want[510];
int main()
{
	memset(map,MARX,sizeof(map));//��ʼ������ֵ 
	scanf("%d%d%d",&p,&f,&c);
	for(int i=1;i<=f;i++)
	  scanf("%d",&want[i]);
	for(int i=1;i<=c;i++)//�ڽӾ����� 
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	map[u][v]=map[v][u]=w;
	  }
	for(int i=1;i<=p;i++)//��ʼ��map 
	  map[i][i]=0;
	for(int i=1;i<=p;i++)//floyd 
	  for(int j=1;j<=p;j++)
	    for(int k=1;k<=p;k++)
	      if(map[j][k]>map[j][i]+map[i][k])
	        map[j][k]=map[j][i]+map[i][k];
	for(int i=1;i<=p;i++)//ö��ÿ����,������С�� 
	  {
	  	int sum=0;
	  	for(int j=1;j<=f;j++)
	  	  sum+=map[i][want[j]];
	    if(minn>(1.0*sum/f))//ע��ƽ��ֵ��double�� 
	      {
	      	minn=1.0*sum/f;
	      	ans=i;
		  }
	  }
	printf("%d",ans);
}
