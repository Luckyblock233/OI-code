//算法:DP/模拟/(搜索) 
// 由题意可知,每一个点的答案
//可以由左下方,下方,右下方中的最大值得到
//由此,可以进行DP,也可以搜索 

//状态转移方程: map[i][j]+=max(map[i+1][j+e[k]])
//[i+1][j+e[k]]为可以到达i的点 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans=-2100000000;
int map[210][210];//map存图, 
bool f[210][210];//存是否可以到达 
int e[4]={0,-1,0,1};//存坐标变化量 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&map[i][j]);//输入 
	f[n+1][m/2+1]=1;//初始化起点 
	for(int i=n;i>=1;i--)//dp 
	  for(int j=1;j<=m;j++)
	    {
	      int maxx=-2100000000; 
		  for(int k=1;k<=3;k++)//找到最大值 
		    if(j+e[k]>=1 && j+e[k]<=m && f[i+1][j+e[k]])//不越界 
		      maxx=max(maxx,map[i+1][j+e[k]]); 
		  map[i][j]+=maxx;//赋值 
		  f[i][j]=1;//标记 
		} 
	for(int i=1;i<=m;i++)//找到最大值 
	  ans=max(ans,map[1][i]);
	printf("%d",ans);//输出 
}
