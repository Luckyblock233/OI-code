//知识点:DP(棋盘DP 
/*
经典的棋盘DP例题

由于卒只能向下,右走
所以易知,  m,n两条边上的方案数都为一
且可知状态转移方程式为:
f[i][j] = f[i-1][j]+f[i][j-1] (i,j为当前卒的坐标, f[][]存方案数)

直接从左到右,从上到下 
枚举整个棋盘   
按照上述方法进行转移即可

根据上述枚举方式, 
在求得f[i][j]之前, 
f[i-1][j]与f[i][j-1]都已求得
可证明其正确性 
*/ 
#include<cstdio> 
#include<string.h>
#define int long long 
using namespace std;
int n,m,a,b,q[50][50];
int ax[10]={2,-2,2,-2,-1,1,-1,1,0};//存坐标变化量
int ay[10]={1,1,-1,-1,2,2,-2,-2,0};
signed main()
{
    memset(q,-1,sizeof(q));//初始化各点为-1 
    scanf("%d%d%d%d",&n,&m,&a,&b);
    n+=1,m+=1,a+=1,b+=1;//由于原题中,初始点为(0,0),为计算方便,使各值+1
    for(int i=1;i<=n;i++) q[i][m]=1;//使m,n两条边上的值为一 
    for(int i=1;i<=m;i++) q[n][i]=1;
    for(int i=0;i<=8;i++)//将马的控制点的方案数置0 
      if(a+ax[i]>=1 && b+ay[i]>=1)
      	q[a+ax[i]][b+ay[i]]=0;
    for(int i=2;i<=m+n;i++)//递推.从要到达的点向后推,一直推到(0,0) 
      for(int j=1;j<=i-1;j++)
      {
      	int k=i-j;
      	if(q[n-j][m-k]==-1)//不被控制，则赋值 
      	  q[n-j][m-k]=q[n-j+1][m-k]+q[n-j][m-k+1];
      }
    printf("%lld",q[1][1]);//输出= = 
}
