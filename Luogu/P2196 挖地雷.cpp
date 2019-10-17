//算法：DP
//本题为简单的有向无环图,注意是单向图 
//状态转移方程式: 
//f[i]=max(f[i],f[j]+w[i]),其中j为可以到达i的点。
//即:i点能挖到的最大地雷数=能到达i点的点能挖到的最大地雷数+i点地雷 
//注意用pre存路径 
#include<cstdio>
using namespace std;
int n,ans,ans1;
int w[25],f[25],pre[25];
bool map[25][25];
void pr(int k)//递归输出路径 
{
	if(pre[k]==k) 
	  {
	  	printf("%d ",k);
	  	return ;
	  }
	pr(pre[k]);
	printf("%d ",k);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&w[i]);
	  	pre[i]=i;//输入,顺便初始化 
	  }
	for(int i=1;i<=n;i++)//输入是否有路 
	  for(int j=i+1;j<=n;j++)
	    {
	      int x;
	      scanf("%d",&x);
	      map[i][j]=x;
		}
	for(int i=1;i<=n;i++)//DP 
	  {
	  	f[i]=w[i];
	  	for(int j=1;j<i;j++)
	  	  if(map[j][i] &&  f[j]+w[i]>f[i])//替换过程 
	  	  	{
	  	  	  f[i]=f[j]+w[i];
	  	  	  pre[i]=j;
			}
		if(ans<f[i])//记录答案 
	  	  {
	  	  	ans=f[i];
	  	  	ans1=i;
		  }
	  }
	pr(ans1);
	printf("\n%d",ans);//输出 
}
