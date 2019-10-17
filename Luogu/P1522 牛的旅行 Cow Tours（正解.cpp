/*
������������˼·
������������ݣ�����������ͬʱ������ֱ�������ĵ�֮��ĳ���
��ʹ��Floyd�����������ͬһ��������������֮��ľ���
֮���ټ���ÿ��Ĺ���ڣ������ܵ�����Զ��������ľ��룬
֮��ѭ���Ҳ�ͬ�����ڵ�����i,j 
���ҵ�����������������ʾ��������֮���һ���ߣ��������ߵľ���
���ʱ��ֱ��Ϊ: �ߵľ��� + i������Զ��������ľ��� + j������Զ��������ľ��룬
�ҳ���С��ֱ��
�����벻����ʱ,ÿ��������ֱ���Ƚ� (��Ϊ���ܴ�����������,��ֱ��������ԭ���ķ�ֱ����),�������滻 
�������� 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int n;
int po[161][3];//���� 
double map[161][161];//���� 
double maxx[161];//���㵽����Զ��������ľ��룬
double ans;
int main()
{
    memset(map,127,sizeof(map));//���ó���ֵ 
    double lll=map[1][1];
    ans=lll;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d%d",&po[i][1],&po[i][2]);
    for(int i=1;i<=n;i++)
      {
      	for(int j=1;j<=n;j++)
      	  {
            char a;
      	  	cin>>a;
            if(a =='1')
              map[i][j]=map[j][i]=sqrt( ( (po[i][1]-po[j][1])*(po[i][1]-po[j][1]) )+( (po[i][2]-po[j][2])*(po[i][2]-po[j][2]) ) );//������� 
      	  }
      }
    for(int k=1;k<=n;k++)//Floyd����� 
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          {
            if( map[i][j] > map[i][k] + map[k][j] )
          	  map[i][j] = map[i][k] + map[k][j];
          }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)//�Ҹ��㵽����Զ��������ľ��룬 
        {
        	if(map[i][j] > maxx[i] && map[i][j]!=lll && i!=j)
        	  maxx[i]=map[i][j];
        }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        {
        	if(map[i][j]==lll && i!=j)
        	  {
        	  	double x=sqrt( ( (po[i][1]-po[j][1])*(po[i][1]-po[j][1]) )+( (po[i][2]-po[j][2])*(po[i][2]-po[j][2]) ) );//����,������Сֱ�� 
              	if(ans > x+maxx[i]+maxx[j] )//�滻 
              	  ans= x+maxx[i]+maxx[j];
              }
        }
	for(int i=1;i<=n;i++)//���ڷ�ֱ���Ƚ� 
	  if(maxx[i] > ans)
	    ans=maxx[i];
	printf("%.6lf\n",ans);//��� 
}
