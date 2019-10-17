//֪ʶ��:��˹��Ԫ
/*���ע��*/ 
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
//=============================================
const double border = 1e-7;
int n;
double map[110][110],ans[110];//mapΪԭϵ������,ansΪ�� 
//=============================================
signed main()
{
	scanf("%d",&n);//����ԭ���� 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n+1;j++)
	    scanf("%lf",&map[i][j]);
	
	
	for(int i=1;i<=n;i++)//����n��ϵ�� 
	  {
	  	int poi=i;
	  	for(int j=i+1;j<=n;j++)//�ҵ����Ļ��� (��߾��� 
	  	  if(fabs(map[poi][i])<fabs(map[j][i])) 
	  	    poi=j;
	  	
		if(fabs(map[poi][i])<border)//�ж��޽�����(��������Ϊ0
	  	  {
	  	  	printf("No Solution");
	  	  	return 0;
		  }
		
		if(i!=poi) swap(map[i],map[poi]);//���������е������ϲ� 
	    double tmp=map[i][i]; 
	    for(int j=i;j<=n+1;j++)//�������н���ת��,ʹ��ȥϵ���Ļ������1 
	      map[i][j]/=tmp;
	    for(int j=i+1;j<=n;j++)//��ȥ��ͬ�Ĳ��� 
	      {
	      	tmp=map[j][i]; 
	      	for(int k=i;k<=n+1;k++)//���²�ͬλ�õ��� 
	      	  map[j][k]-=map[i][k]*tmp;
		  }
	  }
	
	ans[n]=map[n][n+1];
	for(int i=n-1;i>=1;i--)//��ô� 
	  {
	  	ans[i]=map[i][n+1];
	  	for(int j=i+1;j<=n;j++)//���� 
	  	  ans[i]-=(map[i][j]*ans[j]);
	  }
	
	
	for(int i=1;i<=n;i++)//��� 
	  printf("%.2lf\n",ans[i]);
}
