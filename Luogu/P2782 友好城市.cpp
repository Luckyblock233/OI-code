//算法：DP/二分查找 
//思路:先按一边城市的序号升序排序
//然后找另外一边的最长上升子序列 
/*
原因: 
按一边城市的序号升序排序后,
理想情况便是另一边也是上升的序列
这样可以保证所有的路径都不相交
但理想很丰满,现实很骨感,
所以要找到最多的不相交的路径
即找到另一边最长上升子序列的长度 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int c1,c2;
}a[200010];
int n;
int st1[200010]={-10000000};//二分查找 
int marx;
bool cmp(baka9 aa,baka9 bb)//排序 
{
	return aa.c1<bb.c1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&a[i].c1,&a[i].c2);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	  {
	  	if(a[i].c2>st1[marx])
		  st1[++marx]=a[i].c2;//比顶头元素大,直接加入 
	  	else//二分查找第一个比它大的,并放在前面 
	  	  {
	  	  	int l=1,r=marx,mid;
	  	  	while(l<=r)
	  	  	  {
	  	  	  	mid=(l+r)/2;
	  	  	  	if(a[i].c2>st1[mid])
	  	  	  	  l=mid+1;
	  	  	  	else
	  	  	  	  r=mid-1;
			  }
			st1[l]=a[i].c2;
		  }
	  }
	printf("%d",marx);
}
/*
50分TLE DP代码 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
    int c1,c2;
}a[200010];
int n;
int f[200010];
int ans;
bool cmp(baka9 aa,baka9 bb)
{
    return aa.c1<bb.c1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d%d",&a[i].c1,&a[i].c2);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
      {
      	f[i]=1;
      	for(int j=1;j<i;j++)
      	  if(a[j].c2<=a[i].c2)
      	    f[i]=max(f[j],f[j]+1);
      	if(f[i]>ans) ans=f[i];
      }
    printf("%d",ans);
}
*/ 
