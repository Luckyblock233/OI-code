//算法：DP
/*
比较奇怪的DP
用 f[i][j] 来记录:长度为i,尾部为j,的序列的最小答案

  1.对于一个编号为1的奶牛,
	要么接在尾部为1的序列后，新序列尾部为1 
	要么改变序号后，接在尾部为2的序列后，新序列尾部为2 
  2.对于一个编号为2的奶牛
    要么接在尾部为1,2的序列后，新序列尾部为2. 
	要么改变序号后，接在尾部为1的序列后，新序列尾部为1 
 
新的序列的答案,只于 长度-1 的序列的答案有关 
那么可以进行线性DP . 

转移方程式: (i为长度,j为当前插入的奶牛编号,k为该奶牛编号的反编号) 
1. f[i][j]=f[i-1][j];    接在同种后 ; 
2. f[i][k]=f[i-1][k]+1;  改变后,接在异种后 ,同时答案+1; 
3. if(j==2) f[i][j]=min(f[i][j],f[i-1][k]);如果为2,可接在同种后,也可接在异种后; 
*/
#include<cstdio>
#define max(a,b) a>b?a:b    //自写min,max 
#define min(a,b) a<b?a:b
using namespace std;
const int MARX = 1e6+10;
int n,a[MARX];
int f[MARX][3];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)//DP 
	{
	  int j=a[i],k=j==1?2:1;//j为当前插入的奶牛编号,k为该奶牛编号的反编号
	  f[i][j]=f[i-1][j]; 
	  f[i][k]=f[i-1][k]+1;
	  if(j==2) f[i][j]=min(f[i][j],f[i-1][k]);
	}
	printf("%d",min(f[n][1],f[n][2]));//输出较小的 
}
