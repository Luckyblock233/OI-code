//�����㷨:bfs
//��������Ϳ��ɫ,��Ϊ����ʧȥ��ɫ
//�Ƚ����е�0���2
//�����δ�������һȦ�㿪ʼ�������
//����2,�Ͱ������0,����ӽ�����
//����1,��ֱ�ӽ�����һ��ѭ��
//֪������Ϊ��,��1����2ȫ�������0
//������� 
#include<cstdio>
#include<queue>
using namespace std;
int map[35][35];
int xx[12]={1,-1,0,0};//��λ�õ������� 
int yy[12]={0,0,1,-1};
queue <int> x;
queue <int> y;
int n;
void bfs();
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    {
	      scanf("%d",&map[i][j]);//��ͼ,����ʼ�� 
	      if(map[i][j]==0)
	        map[i][j]=2;
		}
	bfs(); 
	for(int i=1;i<=n;i++) 
	  {
	    for(int j=1;j<=n;j++)
	      printf("%d ",map[i][j]);
	    printf("\n");
	  }
}
void bfs()
{
	for(int i=1;i<=n;i++)//�������һȦ�ĵ���ӽ����� 
	  for(int j=1;j<=n;j++)
	    if(i==1 || j==1 || j==n || i==n)
	      {
	        x.push(i);
	        y.push(j);
		  }
	while(!x.empty())//��׼����ģ�� 
	  {
	  	int x1=x.front();
	  	int y1=y.front();
	  	x.pop();
	  	y.pop();
	  	if(map[x1][y1]==1)//����1ֱ����һ�� 
	  	  continue ;
	  	for(int i=0;i<=3;i++)
	  	  {
	  	  	int x2=x1+xx[i];
	  	  	int y2=y1+yy[i];
	  	  	if(x2>=1 && x2<=n)
	  	  	  if(y2>=1 && y2<=n)
	  	  	    if(map[x2][y2] == 2)
	  	  	      {
	  	  	      	map[x2][y2]=0;//���� 
	  	  	      	x.push(x2);//ѹ����� 
	  	  	      	y.push(y2);
				  }
		  }
	  }
}
