//算法：DP
/*
状态转移方程式：
i为公司数,j为机器数 
f[i][j]=max(f[i-1][j-k]+map[i][k]) , k∈[0,m];
即:枚举第i个公司机器数量k,
i个公司j台机器的盈利等于:
i-1个公司j-k台设备的盈利 + i个公司k台设备的盈利 

这里输出比较麻烦,
marx为i个公司的总盈利,初始为f[n][m]. 
对于第i个公司的机器数,
需要枚举.
当找到一个数量k,
使f[i-1][k]+map[i][j-k]==marx
就找到了第i个公司的机器数,
与i-1个公司的机器数 
将第i个公司的机器数压入栈中,
使marx=f[i-1][k],让其变成i-1个公司的总盈利 
并递归找上一个公司的数量 
*/
#include<cstdio>
using namespace std;
int m,n,marx;
int map[15][20];
int f[15][20];
void pr(int i,int j)//输出环节,i为公司编号,j为剩下的未分配的机器 
{
	if(i==0) return;//边界 
	for(int k=0;k<=j;k++)
	  if(marx==f[i-1][k]+map[i][j-k])//找k 
	    {
	      marx=f[i-1][k];//其变成i-1个公司的总盈利 
	      pr(i-1,k);//递归 
	      printf("%d %d\n",i,j-k);//输出 
	      break;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&map[i][j]);//输入
//==================================================		 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  	for(int k=0;k<=j;k++)
	  	  if(f[i-1][j-k]+map[i][k] > f[i][j])//DP 
	  	  	f[i][j]=f[i-1][j-k]+map[i][k];
	marx=f[n][m];//记录最后的marx 
	printf("%d\n",f[n][m]);//输出 
	pr(n,m);
} 
