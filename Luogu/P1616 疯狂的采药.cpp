//算法：DP/完全背包
//本题为完全背包模板
//注意内层循环 从w[i]至m 
//方程式: f[j]=max(f[j],f[j-w[i]]+c[i])
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int w[10010],c[10010];//存占用容量,价值 
int f[100010]; 
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=w[i];j<=m;j++)
	  	  f[j]=max(f[j],f[j-w[i]]+c[i]);
	  }
	printf("%d",f[m]);
}
