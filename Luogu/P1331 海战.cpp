//ʹ���㷨��dfs
/*
�������ѵ������ж��Ƿ��д����ڡ�
 ͨ���Լ�ģ������ݿ��Եó����ۣ� 
 ���ͼ�ǲ��Ϸ��ģ�һ���������½ṹ��
# # 
. #
��
# #
# .
��
# .
# #
��
. #
# #
����һ��2*2�ķ�����������#�����Ծ��ܵó����룺
*/
//�ж����Ƿ�Ϸ���,����ͨ�������� 
#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
char k;
int sum;
int ax[5][5]={{0,1,1},{0,-1,-1},{-1,0,-1},{0,1,1}};//2*2��������仯�� 
int ay[5][5]={{1,0,1},{1,0,1},{0,-1,-1},{-1,0,-1}};
int xx[5]={0,0,1,-1};//����仯�� 
int yy[5]={1,-1,0,0};
bool map[1010][1010],flag;
void judge(int,int);
void dfs(int,int);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)//���� 
	    {   
	      cin>>k;
	      if(k=='#') map[i][j]=1;
	      else map[i][j]=0;
		}
	for(int i=1;i<=n;i++)//�ж��Ƿ�Ϸ� 
	  for(int j=1;j<=m;j++)
	    if(map[i][j])
	      {
	      	judge(i,j);
	      	if(flag)
			  return 0;
		  }
	for(int i=1;i<=n;i++)//����ͨ�� 
	  for(int j=1;j<=m;j++)
	    if(map[i][j])
	      {
	      	map[i][j]=0;
	      	sum++;
	      	dfs(i,j);
		  }
	printf("There are %d ships.",sum);
}
void judge(int x,int y)//�ж��Ƿ�Ϸ� 
{
	for(int i=0;i<4;i++)//ö��4�����ڵ�2*2���� 
	  {
	  	int flag1=0;
	  	for(int j=0;j<3;j++)//�����ڵ�2*2�ĸ����г����˼���# 
	  	  if(map[x+ax[i][j]][y+ay[i][j]])
	  	  	flag1++;
	  	if(flag1==2)
	  	  {
	  	  	printf("Bad placement.");//���Ϸ� 
	  	  	flag=1;
	  	  	return ;
		  }
	  }
}
void dfs(int x,int y)//��׼dfsģ�� 
{
	for(int i=0;i<4;i++)
	  {
	  	if(map[x+xx[i]][y+yy[i]])
	  	  {
	  	  	map[x+xx[i]][y+yy[i]]=0;
	  	  	dfs(x+xx[i],y+yy[i]);
		  }
	  }
}
