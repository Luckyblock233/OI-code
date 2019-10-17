//算法:DP
//思路:
//很容易推出:状态转移方程为: 
//a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];
//则从最底层开始往上推
//推到顶,就得到了答案 
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010][1010],n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  for(int j=0;j<i+1;j++)
	    scanf("%d",&a[i][j]);//输入 
	for(int i=n-2;i>=0;i--)
	  for(int j=0;j<i+1;j++)
	  	a[i][j]+=max(a[i+1][j],a[i+1][j+1]);//从底层往上层推 
	printf("%d",a[0][0]);//输出顶层 
}
