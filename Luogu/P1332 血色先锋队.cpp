//ʹ���㷨��bfs
//ģ����,��ע��. 
#include<cstdio>
#include<queue>
using namespace std;
const int MARX=21000000;//��ֵ 
int m,n;
int a1,b1;
int ax[5]={1,-1,0,0};//����仯�� 
int ay[5]={0,0,1,-1};
int a[100010][3];
int b[100010][3];
int step[510][510];
queue <int> x;
queue <int> y;
void bfs();
int main()
{
	scanf("%d%d%d%d",&n,&m,&a1,&b1);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    step[i][j]=MARX;//��ʼ����ֵ 
	for(int i=1;i<=a1;i++)//�����ȾԴ 
	  {
	  	scanf("%d%d",&a[i][1],&a[i][2]);
	  	step[a[i][1]][a[i][2]]=0;//��0 
	    x.push(a[i][1]);//ѹ����� 
	    y.push(a[i][2]);
	  }
	for(int i=1;i<=b1;i++)
	  scanf("%d%d",&b[i][1],&b[i][2]);
//---------------------------------------------------------
	bfs();
	for(int i=1;i<=b1;i++)
	  printf("%d\n",step[b[i][1]][b[i][2]]);//���������Ⱦʱ�� 
}
void bfs()
{
	while(!x.empty())
	  {
	  	int xx=x.front();
	  	int yy=y.front();
	  	x.pop(),y.pop();
	  	for(int i=0;i<4;i++)//ö���ĸ����� 
	  	  {
	  	  	int xxx=xx+ax[i];
	  	  	int yyy=yy+ay[i];
	  	  	if(xxx>=1 && xxx<=n && yyy>=1 && yyy<=m)//������ 
	  	  	  if(step[xxx][yyy] > step[xx][yy]+1)//���Ž� 
	  	  	    {
	  	  	  	  step[xxx][yyy]=step[xx][yy]+1;//�滻 
	  	  	  	  x.push(xxx);
	  	  	  	  y.push(yyy);
			    }
		  }
	  }
}
