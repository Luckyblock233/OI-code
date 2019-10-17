//算法：DP
//如果只是取一遍数,会非常简单,跑一遍复杂度O(n*n)的dp即可
//但是该题要求重复取数,
//且第一次取得会变成 0 
//这就要求一点高深的算法

//将取两边数看做两个人同时走. 
//因为n<=9,复杂度较低,
//考虑使用4维DP,
//即: f[i][j][k][l] , 
//其中（i,j）为第一个人的坐标,(k,l)为的二个人的坐标
// f[i][j][k][l] 存两个人走过的路径的权值总和

//对于某个f[i][j][k][l],对应的某一组(i,j)和(k,l):
//1.都由左边的点转移过来
//2.(i,j)由左边转移过来,(k,l)由上边转移过来
//3.(k,l)由左边转移过来,(i,j)由上边转移过来
//4.都由上边的点转移过来

//则,可以从以上四种情况中取最大值,再加上 (i,j)和(k,l)的权值和

//特别的,当(i,j)==(k,l)时,权值只需要加一遍,因为重复取数会变成0. 
#include<cstdio>
using namespace std;
int max(int a,int b,int c,int d)//求得最大值 
{
	int m1=a>b?a:b , m2=c>d?c:d;
	return m1>m2?m1:m2;
}
int n;
int map[10][10];//存图 
int f[10][10][10][10];//四维dp 
int main()
{
	scanf("%d",&n);
	while(1)//输入 
	  {
	  	int x,y,z;
	  	scanf("%d%d%d",&x,&y,&z);
	  	if(!x && !y && !z) break;
	  	map[x][y]=z;
	  }
	for(int i=1;i<=n;i++)//DP,转移状态 
	  for(int j=1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      for(int l=1;l<=n;l++)
	        {
	          f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+map[i][j]+map[k][l];
			  if(i==k && j==l) f[i][j][k][l]-=map[i][j];//当(i,j)==(k,l)时的 特别情况 
			}
	printf("%d",f[n][n][n][n]);//输出 
}
