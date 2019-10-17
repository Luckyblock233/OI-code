//算法:DP / 二分查找
//第一问要求只有1个系统时最多拦截个数 
//即求最大不上升序列的长度
//第二问要求最大上升序列的个数,
//可以贪心做法,也可以用一种数学方法证明（证明方法见100行）： 
//最大上升序列的个数==最大的最大上升序列的长度

//然后这道题就变成了求: 
//最大不上升序列的长度,最大的最大上升序列的长度

//提供两种做法:
//复杂度O(n*logn)的栈模拟二分查找
//复杂度O(n方)的dp
#include<cstdio>
using namespace std;
int a[100010],st1[100010],st2[100010];
int num=1;
int marx,ans;
int main()
{
	while( (scanf("%d",&a[num])) != EOF) num++;//循环输入 
	st1[0]=5000100;//初始化栈底元素 
	st2[0]=-5000100;
	for(int i=1;i<num;i++)//找num-1个数 
	  {
	  	if(a[i]<=st1[marx]) 
		  st1[++marx]=a[i];//比顶头元素小,直接加入 
	  	else//二分查找第一个比它小的,并放在前面 
	  	  {
	  	  	int l=1,r=marx,mid;
	  	  	while(l<=r)
	  	  	  {
	  	  	  	mid=(l+r)/2;
	  	  	  	if(a[i]<=st1[mid])
	  	  	  	  l=mid+1;
	  	  	  	else
	  	  	  	  r=mid-1;
			  }
			st1[l]=a[i];
		  }
//================上找不上升,下找上升=======================
		if(a[i]>st2[ans]) 
		  st2[++ans]=a[i];//比顶头元素大,直接加入 
	  	else//二分查找第一个比它大的,并放在前面 
	  	  {
	  	  	int l=1,r=ans,mid;
	  	  	while(l<=r)
	  	  	  {
	  	  	  	mid=(l+r)/2;
	  	  	  	if(a[i]>st2[mid])
	  	  	  	  l=mid+1;
	  	  	  	else
	  	  	  	  r=mid-1;
			  }
			st2[l]=a[i];
		  }
	  }
	printf("%d\n%d",marx,ans);
}

/*
复杂度 O(n方)的dp版: 

#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],f[100010],f1[100010];
int num=1,ans,marx;
int main()
{
	while( (scanf("%d",&a[num])) != EOF) num++;
	for(int i=1;i<num;i++)
	  {
	  	f[i]=1;
	  	for(int j=1;j<i;j++)
	  	  {
	  	  	if(a[i] <= a[j])
	  	  	  f[i]=max(f[i],f[j]+1);
		  }
//================上找不上升,下找上升=======================
		f1[i]=1;
	  	for(int j=1;j<i;j++)
	  	  {
	  	  	if(a[i] > a[j])
	  	  	  f1[i]=max(f1[i],f1[j]+1);
		  }
	  }
	for(int i=1;i<num;i++)
	  {
	    if(f[i] > marx)
	      marx=f[i];
	    if(f1[i] > ans)
	      ans=f1[i];
	  }
	printf("%d\n%d",marx,ans);
}
*/


/*对于问二求整个数列的最长上升子序列即可。证明如下：

 （1）假设打导弹的方法是这样的：
  取任意一个导弹，
  从这个导弹开始将能打的导弹全部打完。
  而这些导弹全部记为为同一组，
  再在没打下来的导弹中任选一个重复上述步骤，
  直到打完所有导弹。

 （2）假设我们得到了最小划分的K组导弹，
  从第a(1<=a<=K)组导弹中任取一个导弹，
  必定可以从a+1组中找到一个导弹的高度比这个导弹高
  （因为假如找不到，那么它就是比a+1组中任意一个导更高，在打第a组时应该会把a+1组所有导弹一起打下而不是另归为第a+1组），
  同样从a+1组到a+2组也是如此。
  那么就可以从前往后在每一组导弹中找一个更高的连起来，
  连成一条上升子序列，其长度即为K;

 （3）设最长上升子序列长度为P，
 则有K<=P;
 又因为最长上升子序列中任意两个不在同一组内
 (否则不满足单调不升)，
 则有P>=K，所以K=P。
*/
