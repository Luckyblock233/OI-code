//ʹ���㷨��dfs+����
//������������,
//ֱ����ģ��,���߾���,�ҵ����ͼ�Ѫ,��������
//�������������,������Ž� 
#include<cstdio>
using namespace std;
int map[15][15];//��ͼ 
bool vis[15][15];//�Ƿ񾭹� 
int n,m;
int sx,sy,ex,ey;//����յ����� 
bool flag;//�ж�minn�Ƿ��滻 
int minn=2100000000;//��Сֵ 
int xx[5]={1,-1,0,0};//��λ�õ������� 
int yy[5]={0,0,1,-1};
void dfs(int x,int y,int t,int hp);//��Ϊ��ǰ��ĺ�,������,��ǰʱ��,��ǰѪ�� 
int main()
{
	scanf("%d%d",&n,&m);//���벢��ͼ,���ҵ�����յ�. 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    {
	      scanf("%d",&map[i][j]);
	      if(map[i][j]==2)
	        {
	          sx=i;sy=j;
			}
		  if(map[i][j]==3)
	        {
	          ex=i;ey=j;
			}
		}
	dfs(sx,sy,1,6);//����㿪ʼ�� 
	if(flag)  printf("%d",minn);//���,minn���滻 
	else  printf("-1");//δ���滻 
}
void dfs(int x,int y,int t,int hp)
{
	if(hp <= 1) return ;//Ѫ������֧�ż�����,���˳� 
	for(int i=0;i<=3;i++)//ö���ܵ��ĵ� 
	  {
	  	int x1=x+xx[i];
	  	int y1=y+yy[i];
	  	if(x1>=1 && x1<=n)//�߳��жϱ߽� 
	  	  if(y1>=1 && y1<=m)
	  	    if(!vis[x1][y1])
	  	      if(map[x1][y1] != 0)
	  	        {
	  	          vis[x1][y1]=1;//��¼ 
	  	          if(x1==ex && y1==ey && t<=minn)//�����Ž� 
	  	            {
	  	              flag=1;
	  	              minn=t;
	  	            }
	  	          else
	  	            {
	  	              if( map[x1][y1]==4 )//����ܼ�Ѫ 
						dfs(x1,y1,t+1,6);
					  else//���ܼ�Ѫ 
					    dfs(x1,y1,t+1,hp-1);
					}
				  vis[x1][y1]=0;//����` 
				}
	  }
}
