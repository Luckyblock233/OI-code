//算法:DP/排序/贪心
//先跑一遍01背包
//以题目得分为权值,剩余时间为容量. 
//跑完后,
//循环找到能够使 分数到达k 所花费的最小时间

//再将刷题时间升序排列,
//找到在 剩剩余时间 内能完成的个数即可 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,r1;
int r2,ans;
int t1[15],t2[15],s[15];
int f[150];
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&r1);
	for(int i=1;i<=n;i++) scanf("%d",&t1[i]);//输入 
	for(int i=1;i<=m;i++) scanf("%d",&t2[i]);
	for(int i=1;i<=m;i++) scanf("%d",&s[i]);
	sort(t1+1,t1+n+1);
	
	for(int i=1;i<=m;i++)//01背包,找到 使 分数到达k 所花费的最小时间
      for(int j=r1;j>=t2[i];j--)
        f[j]=max(f[j],f[j-t2[i]]+s[i]);
    for(int i=1;i<=r1;i++) 
      if(f[i]>=k)
        {
          r2=r1-i;
          break;
		}
	for(int i=1;i<=n;i++)//找个数 
	  if(r2>=t1[i]) ans++,r2-=t1[i];
	  else  break;
	printf("%d",ans);
}
