//�ȸ����������ݣ���ʼ�����С������map
//��ʹ��Floyd�����ҳ�������ȷ���Ĵ�С���
//��ѭ����ÿͷţ���ұ�����ͱ���С������ĸ���
//�������������������Ϊn-1����ɸ�ţ���ο�ȷ��,
//��+1������������ 
#include<cstdio>
using namespace std;
bool map[105][105];//���С�������map[i][j]����i��j�� 
int ans=0;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);//��������� 
	  	map[x][y]=1;//��ʼ��map 
	  }
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      {
	      	if(map[i][k] && map[k][j])//��i��k����k��j�� 
	      	  map[i][j]=1;//֤��i����j 
	      	if(map[k][i] && map[j][k])//��i��kС����j��kС 
	      	  map[j][i]=1;//֤��j����i 
		  }
	for(int i=1;i<=n;i++)//ѭ����ÿ������ 
	  {
	  	int sum1=0,sum2=0;//�ֱ�����С�ͱ������������ 
	    for(int j=1;j<=n;j++)
	      {
	    	if(map[j][i])//���i��j��,��sum1++; 
	    	  sum1++;
	    	if(map[i][j])//��i��jС,��sum2++; 
	    	  sum2++;
		  }
		if( sum1+sum2==n-1 )//��sum1��sum2��Ϊn-1�����ȷ�� 
		  ans++;//ans++; 
	  }
	printf("%d",ans);
}
