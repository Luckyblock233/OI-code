//算法：DP

//表面上看起来很难,实际上非常蠢的DP,一遍AC 
//因为牌数都小于40,
//所以可以将各面值的牌的数量
//作为数组的控制元素
//也可以非常方便的计算出当前点的编号 

//当前点坐标now=i+2*j+3*k+4*l+1;
//转移方程式:f[i][j][k][l]=max(f[i][j][k][l],judge(i,j,k,l)+a[now]);
//其中judge获取了now少走1,2,3,4步的价值的最大值 
#include<cstdio>
#include<algorithm>
using namespace std;
int f[42][42][42][42];//分别代表爬行1,2,3,4,步的卡牌数量
int n,m;
int a[355];
int b[5];
int judge(int i,int j,int k,int l)
{
    //找到能到达编号为i+2*j+3*k+4*l+1的点的值的最大值. 
	//分别枚举少走1,2,3,4步的情况 
	int maxx=-1;
	if(i>0) maxx=max(maxx,f[i-1][j][k][l]); 
	if(j>0) maxx=max(maxx,f[i][j-1][k][l]);
	if(k>0) maxx=max(maxx,f[i][j][k-1][l]);
	if(l>0) maxx=max(maxx,f[i][j][k][l-1]);
	return maxx;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	  {
	  	int x;
	  	scanf("%d",&x);
	  	b[x]++;//记录牌数 
	  }
//==========================================================
	f[0][0][0][0]=a[1];//初始值 
	for(int i=0;i<=b[1];i++)//超级暴力= = 
	  for(int j=0;j<=b[2];j++)
	    for(int k=0;k<=b[3];k++)
	      for(int l=0;l<=b[4];l++)
	        {
	          int now=i+2*j+3*k+4*l+1;//当前点的编号 
	          f[i][j][k][l]=max(f[i][j][k][l],judge(i,j,k,l)+a[now]);
			}
	printf("%d",f[b[1]][b[2]][b[3]][b[4]]);//输出 
}
