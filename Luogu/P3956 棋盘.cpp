//֪ʶ��:���仯,dfs 
/*
���� + �򵥼�֦
�Ƚϼ� , ���ע�� 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
const int INF = 0x3f3f3f;
const int ex[5] = {0,1,-1,0,0};//����仯�� 
const int ey[5] = {0,0,0,1,-1};
//=============================================================
int m,n,ans=INF, map[110][110],step[110][110];//map��ͼ�����,step�浽�����Ļ��� 
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//x,y�浱ǰ������,sum �浽�ﵱǰ��Ļ���,magci��ת�Ƶ���ǰ���Ƿ�ʹ����ħ�� 
void dfs(int x,int y,int sum,bool magic)
{
	if(sum>=step[x][y]) return ;//�����Լ�֦ 
	step[x][y]=sum;//��ֵ 
	if(x==m && y==m)//�����յ� 
	{
	  ans=min(ans,step[x][y]);
	  return ;
	}
	for(int i=1,nx=x+ex[i],ny=y+ey[i];i<=4;i++,nx=x+ex[i],ny=y+ey[i])//ö���ܵ���ĵ� 
	  if(nx>=1 && nx<=m && ny>=1 && ny<=m)//��Խ�� 
	  {
	  	if(!map[nx][ny])//��ɫ��� 
	  	{
	  	  if(!magic)//û��ʹ�ù�ħ�� 
	  	  {
	  	    map[nx][ny]=map[x][y];//������ɫ,������ת�� 
	  	    dfs(nx,ny,sum+2,1);
		    map[nx][ny]=0;	
		  }
		  continue;	
		}
	  	dfs(nx,ny,sum+(map[x][y]!=map[nx][ny]),0);//��ɫ���,������ɫͬ���������ת�� 
	  }
}
//=============================================================
signed main()
{
	m=read(),n=read();
	for(int i=1;i<=n;i++)
	{
	  int x=read(),y=read(),c=read()+1;
	  map[x][y]=c;
	}
	memset(step,INF,sizeof(step));//��ʼ������,Ϊ����ֵ 
	dfs(1,1,0,0);
	printf("%d",ans>=INF?-1:ans); 
}

