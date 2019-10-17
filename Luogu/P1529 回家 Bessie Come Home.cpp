//算法：图论/最短路
//裸最短路问题
//将字母当成数字存即可 
#include<cstdio>
#include<cstring>
using namespace std;
int road[53][53];
bool vis[53];
const int INF=2e9;
int dis[53];
int P,d,k,end,minn=INF,start=26;
char ch1,ch2;


void calcdist(char a,char b,int dist);//把两个牧场转为数字存入数组 
void dj();


int main(){
    //init
    memset(vis,false,sizeof(vis));
    for(k=0;k<53;k++)
	  {
        for(int j=0;j<53;j++)
		  {
            if(k==j) road[k][j]=0;
            else road[k][j]=INF;
          }
        dis[k]=INF;
      }
    dis[start]=0;
    vis[start]=true;
    //input
    scanf("%d",&P);
    for(k=1;k<=P;k++)
	  {
        scanf(" %c %c %d",&ch1,&ch2,&d);
        calcdist(ch1,ch2,d);
      }
    //dj
    dj();
    //output
    printf("%c %d",start-1+'A',dis[start]);
    return 0;
}
void calcdist(char a,char b,int dist)
{
    int x,y;
    if(a>='a'&&a<='z')
	  x=a-'a'+27; 
    else 
	  if(a>='A'&&a<='Z')
        x=a-'A'+1;
    if(b>='a'&&b<='z')
      y=b-'a'+27;
    else 
	  if(b>='A'&&b<='Z')
        y=b-'A'+1;
    if(dist<road[x][y])
	  {
        road[x][y]=dist;
        road[y][x]=dist;
      }
}
void dj()
{
    while(start>=26)
	  {
        for(k=1;k<53;k++)
		  if(!vis[k]&&road[start][k]!=INF)
			if(dis[k]>dis[start]+road[start][k])
			  dis[k]=dis[start]+road[start][k];
        minn=INF;
        for(k=1;k<53;k++)
		  if(!vis[k]&&dis[k]<minn)
		    {
              minn=dis[k];
              start=k;
            }
        vis[start]=true;
      }
}
