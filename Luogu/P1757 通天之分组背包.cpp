//算法:DP/背包 
//本题与01背包的区别:
//物品分为k组，每组中的物品相互冲,故每组只能取1个物品
//在01背包上多加一维,表示有几组.
//状态转移方程式:
//f[j][a[i].g]=max(f[j-a[i].w][k]+a[i].c),k∈[0,a[i].g];
//注意k从0开始 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int c,w,g;
}a[1010];
int n,m,ans;
int f[1010][110];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d%d",&a[i].w,&a[i].c,&a[i].g);
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=a[i].w;j--)
	    {
		  for(int k=0;k<a[i].g;k++)
	  	    f[j][a[i].g]=max(f[j][a[i].g],f[j-a[i].w][k]+a[i].c);
		  ans=max(ans,f[j][a[i].g]);//记录答案 
	    }
	printf("%d",ans);
}
