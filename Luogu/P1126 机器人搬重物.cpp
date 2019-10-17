//֪ʶ�㣺 bfs
/* 
ע���ߵ��ǵ�,�ϰ��ǿ�;   ��ͼ���ͼ���� 

˼·:�沽��ʱ����Ҫ����������,��Ҫ���Ǹ������������
���Ծ�Ҫ����ά������
����仯��ҲҪ���泯�ķ��������� 
����,������ռ���ĸ����ӵĿռ�
����ʱҪע���ж�һ·���Ƿ����ϰ�
*/ 
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MARX=21000000;//��ֵ 
struct baka9
{
	int x,y;
	int c;
};
int ax[6][6]={{},{0,0,0,0},{0,1,2,3},{0,0,0,0},{0,-1,-2,-3}};//�������,������ı仯�� 
int ay[6][6]={{},{0,1,2,3},{0,0,0,0},{0,-1,-2,-3},{0,0,0,0}};
bool map[60][60];//��ͼ,�Ƿ����ϰ� 
int step[55][55][6];//�����,�������� 
bool ju[55][55][6];//��ĳ����,ĳ�����Ƿ��߹� 
int n,m;
int sx,sy,ex,ey;
char c1;
queue <baka9> s;//���� 
void bfs();
bool judge(int,int,int,int,int);
int main()
{
	scanf("%d%d\n",&n,&m);
	memset(step,MARX,sizeof(step));//��ʼ��step 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  	{
	  	  int x111;
	  	  scanf("%d",&x111);
	  	  map[i][j]=x111;//��ͼ 
		}
	scanf("%d %d %d %d %c",&sx,&sy,&ex,&ey,&c1); 
	int c2;
	if(c1=='E')c2=1;//���������ֱ�Ϊ1,2,3,4 
	if(c1=='S')c2=2;
	if(c1=='W')c2=3;
	if(c1=='N')c2=4;
	step[sx][sy][c2]=0; 
	baka9 tmp={sx,sy,c2};//ѹ����� 
	ju[sx][sy][c2]=1;
	s.push(tmp);
	bfs();
	int minn=MARX;//�ҵ��յ��ĸ������ϵ���Сֵ 
	minn=MARX;
	for(int i=1;i<=4;i++)
	  minn=min(step[ex][ey][i],minn);
	if(minn==MARX) minn=-1;//��СֵΪ��ֵ,���ܵ��� 
	printf("%d",minn);
}
void bfs()//����׼��bfs 
{
	while(!s.empty())
	  {
	  	baka9 tmp=s.front(); 
	  	s.pop();
	  	int xx=tmp.x;
	  	int yy=tmp.y;
	  	int cc=tmp.c;
	  	for(int i=1;i<=3;i++)//ǰ������� 
	  	  {
	  	  	int xxx=xx+ax[cc][i];
	  	  	int yyy=yy+ay[cc][i];
	  	  	if(ju[xx+ax[cc][i-1]][yy+ay[cc][i-1]][cc])//��ǰ��һ���ܷ���,�����ж�·�����Ƿ����ϰ��� 
	  	  	    if(judge(xx,yy,xxx,yyy,cc)) 
			      {
				    step[xxx][yyy][cc]=step[xx][yy][cc]+1;//������һ 
				    ju[xxx][yyy][cc]=1;
				    baka9 tmp1={xxx,yyy,cc};
				    s.push(tmp1);
			      }
	  	  }
	  	for(int i=1;i<=4;i++)//ת������ 
	  	  {
	  	  	  int flag1=1; //ת90����Ϊ1 
	  	  	  if(cc==i+2 || i==cc+2) flag1++;//���ת180,���������һ 
			  if(step[xx][yy][i] > step[xx][yy][cc]+flag1)//����ڴ˵�ת���֮ǰʡʱ 
	  	        {
	  	          step[xx][yy][i]=step[xx][yy][cc]+flag1;//ѹ����� 
	  	          ju[xx][yy][i]=1;
	  	      	  baka9 tmp1={xx,yy,i};
			  	  s.push(tmp1);
				}
			}
	  }
}
bool judge(int xx,int yy,int xxx,int yyy,int ccc)//�ж� 
{
	if(xxx>=1 && xxx<n)//������ 
	  if(yyy>=1 && yyy<m)
	    if(step[xxx][yyy][ccc] > step[xx][yy][ccc]+1)//���Ž� 
		  {
		    int flag=1;
		    if(map[xxx][yyy]) flag=0;//�ж��Ƿ����ϰ� 
		    if(map[xxx+1][yyy]) flag=0;
		    if(map[xxx][yyy+1]) flag=0;
		    if(map[xxx+1][yyy+1])flag=0;
		    return flag; 
		  }
	return 0;
}
