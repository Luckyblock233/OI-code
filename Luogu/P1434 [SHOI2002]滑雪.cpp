//�����㷨��DFS+���� �����仯����
//ʹ��maxx�����ӵ�ǰ�㿪ʼ����������
//Ȼ����dfsģ��,�����Ը���Ϊ��������� 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[110][110];//��ͼ 
bool use[110][110];//�Ƿ��ù� 
int maxx[110][110];//������� 
int ax[5]={1,-1,0,0};
int ay[5]={0,0,1,-1};
int ans=-1;
int dfs(int,int);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//���� 
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)//����ö�ٸ�����Ϊ��� 
	  for(int j=1;j<=n;j++)
	    if(!use[i][j])
	      {
	      	use[i][j]=1;
	      	int tot1=dfs(i,j);//�����Դ˵�Ϊ���ľ��� 
	      	maxx[i][j]=tot1;
	      	use[i][j]=0;
	      	if(tot1>ans) ans=tot1;//��¼���ֵ 
		  }
	printf("%d",ans);
}
int dfs(int x,int y)
{
	if(maxx[x][y])//�������¼,��ֱ�ӷ��� 
	  return maxx[x][y];
	int tot2=0;
	for(int i=0;i<4;i++)
	  {
	  	int xx=x+ax[i];
	  	int yy=y+ay[i];
	  	if(!use[xx][yy] && xx>=1 && yy>=1 && xx<=n && yy<=m)
	  	  if(a[xx][yy] < a[x][y])
	  	    {
	  	  	  use[xx][yy]=1;
	  	  	  tot2=max( dfs(xx,yy),tot2 );//�ҵ����ܵ���ĵ�������� 
	  	  	  use[xx][yy]=0;
		    }
	  }
	return tot2+1;//�����ܵ���ĵ�+�˵�ĺ� 
}
