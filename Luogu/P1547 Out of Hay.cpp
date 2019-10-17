//此题目为prim算法模板题
//完全套模板即可,不再赘述 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX=2147483640;//最大值 
int map[2010][2010];//邻接矩阵存边 
int minn[2010];
bool f[2010];
int n,m,ans;
void prim();
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        map[i][j]=MARX;
    for(int i=1;i<=m;i++)
      {
      	int xx,yy,ww;
        scanf("%d%d%d",&xx,&yy,&ww);
        if(map[xx][yy]>ww)
          map[xx][yy]=map[yy][xx]=ww;
      }
    prim();
    printf("%d",ans);//输出答案 
}
void prim()
{
    for(int i=1;i<=n;i++)
      minn[i]=MARX;//初始化 
    minn[1]=0;//置零 
    for(int i=1;i<=n;i++)
      {
      	int minnn=MARX,k=-1;
      	for(int i=1;i<=n;i++)
      	  if(!f[i] && minn[i]<minnn)//找到最小 
      	    {
      	  	  minnn=minn[i];
      	  	  k=i;
            }
        if(k==-1) break;//找不到则停止 
        f[k]=1;//置一 
        for(int i=1;i<=n;i++)
          {
          	if(!f[i] && minn[i] > map[k][i])
          	  minn[i]=map[k][i];
          }
      }
    for(int i=1;i<=n;i++)
      {
        ans=max(ans,minn[i]);
      } 
}
