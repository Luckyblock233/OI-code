//知识点:最小生成树 
/*
使用了prim算法
套模板即可 
另外，只需要输出minn中的最大值即可 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MARX=2147483640;//最大值 
int map[1010][1010];//邻接矩阵存边 
int minn[1010];
bool f[1010];
int n,m,ans,flag=1;
void prim();
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    map[i][j]=MARX;//初始化 
	for(int i=1;i<=m;i++)
	  {
	  	int xx,yy,ww;
	    scanf("%d%d%d",&xx,&yy,&ww);
	    map[xx][yy]=map[yy][xx]=ww;//赋值 
	  }
	prim();
	if(flag)//如果不存在无法到达 
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
	  	if(minn[i]==MARX)//存在无法到达 
	  	  {
	  	  	flag=0;//输出负一 
	  	  	printf("-1");
	  	  	break;
		  }
	    ans=max(ans,minn[i]);//找最大值 
	  } 
}
