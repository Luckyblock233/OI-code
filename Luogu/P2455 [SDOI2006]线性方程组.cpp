//֪ʶ��:��˹��Ԫ 
/*
��˹��Ԫ�����ݼ�ǿ��
�������ж��޽�����
��д�������ı�

���ע�� 
*/ 
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
//=============================================
const double border = 1e-8;
int n;
double map[110][110],ans[110];
//=============================================
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n+1;j++)
        scanf("%lf",&map[i][j]);
    
    
    for(int i=1;i<=n;i++)
      {
      	int poi=i;
      	for(int j=i+1;j<=n;j++)//�ҵ����Ļ��� 
      	  if(fabs(map[poi][i])<fabs(map[j][i]))
      	    poi=j;
      	
        if(i!=poi) swap(map[i],map[poi]);  //�ҵ����Ļ��� (��߾��� 
        if(fabs(map[i][i])<border) continue;//����ϵ��Ϊ0,������,�������ж� 
        double tmp=map[i][i];
        for(int j=i;j<=n+1;j++)
          map[i][j]/=tmp;
        for(int j=1;j<=n;j++)  //ͬʱ��ȥ���²����ͬϵ��,�����˻ش����� 
          if(i!=j)//�����ڱ��� 
            {
          	  tmp=map[j][i];
          	  for(int k=1;k<=n+1;k++)//�������²������Ԫ�� 
          	    map[j][k]-=map[i][k]*tmp;
            }
      }

    bool imposs=0,over1=0; 
    for(int i=1;i<=n;i++)//�ж��޽� �� ����� 
      {
      	int j=i;
      	while(fabs(map[i][j])<border && j<=n+1) j++;  //�ҵ���һ����0��Ԫ�� 
		if(j==n+1) imposs=1;//���з�0Ԫ��Ϊy , ���޽� 
      	if(j>n+1) over1=1;  //����ȫ��Ϊ0,˵���ж���� 
      }
    if(imposs){printf("-1");return 0;}
    if(over1){printf("0");return 0;}
    
    for(int i=1;i<=n;i++)
      if(fabs(map[i][n+1])<border)printf("x%d=0\n",i);
      else printf("x%d=%.2lf\n",i,map[i][n+1]);
      
}
