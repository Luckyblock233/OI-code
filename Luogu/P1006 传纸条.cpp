//算法:DP 
//将从两头走,看做两个人同时从一个点走. 
//因为n<=50,复杂度较低,
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

//特别的,当(i,j)==(k,l)时,权值只需要加一遍,因为不可重复取数. 
#include<cstdio>
using namespace std;
int max(int a,int b,int c,int d)
{
	int max1=a>b?a:b , max2=c>d?c:d;
	return max1>max2?max1:max2;
}
int m,n;
int map[51][51];
int f[51][51][51][51];//4维dp 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&map[i][j]);
	for(int i=1;i<=n;i++)//状态转移 
	  for(int j=1;j<=m;j++)
	    for(int k=1;k<=n;k++)
		  for(int l=1;l<=m;l++)
		    {
		      f[i][j][k][l]=max(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+map[i][j]+map[k][l];
			  if(i==k && j==l) f[i][j][k][l]-=map[i][j];//当(i,j)==(k,l)时的 特别情况 
			}
	printf("%d",f[n][m][n][m]);
}
