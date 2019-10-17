//算法：DP/二分查找
//题目要找 
//T1 < ... < Ti > Ti+1 > …> TK    (1≤i≤K)。
//的序列,所以枚举中间最大的Ti,
//维护一个升序列,维护一个降序列,
//最后计算出删去学生个数. 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=10000000;
int a[110];
int st1[110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	  {
	  	int minn=0,marx=0;
	  	st1[0]=a[i];//枚举Ti点,作为最大值 
	  	for(int j=i-1;j>=1;j--)//维护升序列,即反向维护降序列 
	  	  {
	  	  	if(a[j]>=st1[0]) continue;//比最大值大,直接跳出 
	  	  	if(a[j]<st1[marx])
		  	  st1[++marx]=a[j];//比顶头元素小,直接加入 
	  		else//二分查找第一个比它小的,并放在前面 
	  	  	  {
	  	  		int l=1,r=marx,mid;
	  	  		while(l<=r)
	  	  	  	  {
	  	  	  		mid=(l+r)/2;
	  	  	  		if(a[j]<st1[mid])
	  	  	  	  	  l=mid+1;
	  	  	  		else
	  	  	  	  	  r=mid-1;
			  	  }
				st1[l]=a[j];
		  	  }
		  }
		minn+=(i-marx-1),marx=0;
		for(int j=i+1;j<=n;j++)//维护降序列 
		  {
		  	if(a[j]>=st1[0]) continue; 
		  	if(a[j]<st1[marx]) 
		  	  st1[++marx]=a[j];//比顶头元素小,直接加入 
	  		else//二分查找第一个比它小的,并放在前面 
	  	  	  {
	  	  		int l=1,r=marx,mid;
	  	  		while(l<=r)
	  	  	  	  {
	  	  	  		mid=(l+r)/2;
	  	  	  		if(a[j]<st1[mid])
	  	  	  	  	  l=mid+1;
	  	  	  		else
	  	  	  	  	  r=mid-1;
			  	  }
				st1[l]=a[j];
		  	  }
		  }
		minn+=(n-marx-i);
		ans=min(ans,minn);
	  }
	printf("%d",ans);
}
