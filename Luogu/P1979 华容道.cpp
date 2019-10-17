//֪ʶ��:���� 
/*
By:Luckyblock
��Ŀ�� , ���ӿ�����ո����ƶ�
��ô���Խ���ת�� , 
�������ƶ�,��Ϊ�ո����ƶ�.

ʹ�ü��仯dfs , 
��¼ [�ո�������],[Ŀ����������] ״̬ ����Ҫ����С����
ʹ��dfs���и���,
��Ŀ���������� = Ŀ��λ������ʱ,��¼��С�𰸼���.

�����õ�45�ֵĺóɼ�(���� 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
const int INF = 1e9+7;
const int cx[5] = {114514, 0,0,1,-1}; //change_x , change_y
const int cy[5] = {114514, 1,-1,0,0}; 
//=============================================================
int n,m,q , ans, ex,ey,sx,sy,tx,ty;
bool map[31][31];//���� 
int step[31][31][31][31];//���仯, ��¼ [�ո�������],[Ŀ����������] ״̬ ����Ҫ����С����
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(;  isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void dfs(int wx,int wy,int nx,int ny,int sum) //white_x,white_y  and  now_x,now_y
{
	if(sum > step[wx][wy][nx][ny]) return ;//�ǽ��Ž� 
	step[wx][wy][nx][ny]=min(sum,step[wx][wy][nx][ny]);//���� 
	if(nx==tx && ny==ty)//����Ŀ��λ�� 
	{
	  ans = min(ans,sum);
	  return ;
	}
	for(int i=1;i<=4;i++)//�ƶ��ո��� 
	{
	  int nwx=wx+cx[i] , nwy=wy+cy[i]; //new_white_x,new_white_y
	  if(nwx<1 || nwx>n || nwy<1 || nwy>m || map[nwx][nwy]==0) continue;//Խ�� 
	  if(nwx==nx && nwy==ny) dfs(nwx,nwy,wx,wy,sum+1);//�ո�����Ŀ�����ӽ���λ�� 
	  else dfs(nwx,nwy,nx,ny,sum+1);//�ո��Ӳ���Ŀ�����ӽ���λ�� 
	}
}
//=============================================================
signed main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    map[i][j]= read();
	
	while(q--)
	{
	  ans=INF; memset(step,INF,sizeof(step));//��ʼ�� 
	  ex=read(),ey=read(),sx=read(),sy=read(),tx=read(),ty=read();
	  dfs(ex,ey,sx,sy,0);//���� 
	  printf("%d\n",ans==INF?-1:ans);
	}
}
