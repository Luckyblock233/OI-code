//ʹ���㷨:BFS
//�Ƚ����������ʼ��Ϊ-1.
//�����������,����ĳ�ʼ��ѹ�����
//ÿ��ѭ��,ȡ�����׵ĵ�,ö�����ܵ���ĵ�
//����µ��ھ���Χ��,��û�б������(��Ϊ�󵽵Ĳ���һ�����ȵ��Ĳ����� 
//���µ�Ĳ���Ϊԭ����+1
//������Ϊ��ʱ����
//������㲽�� 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int xm,ym;
int ax[10]={2,-2,2,-2,-1,1,-1,1};//������仯��
int ay[10]={1,1,-1,-1,2,2,-2,-2};
int step[410][410];//�沽�� 
queue <int> x;
queue <int> y;
void bfs();
int main()
{
	memset(step,-1,sizeof(step));//��ʼ�� 
	scanf("%d%d%d%d",&n,&m,&xm,&ym);
	x.push(xm);//ѹ����� 
	y.push(ym);
	step[xm][ym]=0;//��ʼ�� 
	bfs();//�� 
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=m;j++)
	  	  printf("%-5d",step[i][j]);//������� 
	    printf("\n");
	  }
}
void bfs()
{
	while(!x.empty())
	  {
	  	int xx=x.front();
	  	int yy=y.front();
	  	x.pop(),y.pop();
	  	for(int i=0;i<8;i++)
	  	  {
	  	  	if(xx+ax[i]>=1 && xx+ax[i]<=n)//�������� 
	  	  	  if(yy+ay[i]>=1 && yy+ay[i]<=m)
	  	  	    if(step[xx+ax[i]][yy+ay[i]] == -1)
	  	  	      {
	  	  	      	x.push(xx+ax[i]);//ѹ����� 
	  	  	      	y.push(yy+ay[i]);
	  	  	      	step[xx+ax[i]][yy+ay[i]]=step[xx][yy]+1;//���㲽�� 
				  }
		  }
	  }
}
