//dfs����ͨ�� 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int que[101000][2];//��������Ķ��� 
char a[1100][1100];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	  {
	  	cin>>a[i];//������ 
	  }
//==============�����봦��ľ���=================================================
	for(int i=0;i<n;i++)//��������������� 
	  {
	  	for(int j=0;j<m;j++)
	  	  {
	  	  	if(a[i][j]>'0')//������Ϊ0,��֤����Ԫ�� 
	  	  	  {
	  	  	  	ans++;//��++ 
	  	  	  	int l=1,r=1;//������ѹ����� 
	  	  	  	que[r][0]=i;
	  	  	  	que[r][1]=j;
	  	  	  	r++;//βԪ��++; 
	  	  	  	while(l<r)//�����в�Ϊ�� 
	  	  	  	  {
	  	  	  	  	int x=que[l][0];//�������� 
	  	  	  	  	int y=que[l][1];
	  	  	  	  	if(a[x+1][y]>'0' && x+1<n)//�±� 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x+1;//ѹ����� 
	  	  	  			que[r][1]=y;
	  	  	  			r++;//βָ��++ 
					  }
	  	  	  	  	if(a[x-1][y]>'0' && x-1>=0)//�ϱ� 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x-1;
	  	  	  			que[r][1]=y;
	  	  	  			r++;
					  }
	  	  	  	  	if(a[x][y+1]>'0' && y+1<m)//�ұ� 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x;
	  	  	  			que[r][1]=y+1;
	  	  	  			r++;
					  }
	  	  	  	  	if(a[x][y-1]>'0' && y-1>=0)//��� 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x;
	  	  	  			que[r][1]=y-1;
	  	  	  			r++;
					  }
					a[x][y]=0;//��ǰԪ������,��ֹ�ظ����� 
					l++;//ͷָ��++; 
				  }
				memset(que,0,sizeof(que));//��0���� 
			  }
		  }
	  }
	printf("%d",ans);//��� 
}
/*
5 5
1 1 1 1 1
0 0 0 0 0
1 1 0 1 1
0 0 0 0 0
1 1 1 1 1
*/
