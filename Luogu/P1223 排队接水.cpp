//算法:贪心
//对每个人按照接水时间升序排序, 时间相同则按照序号升序排序
//因为要让平均值最小,即使所有人等待时间之和最小
//就需要让时间小的先接完水,
//把较小的等待时间累加到需要时间较多的人身上 
//排序后顺序即题目要求的接水顺序 
//计算后输出即可 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka//存每个人编号与时间 
{
	int data,bian;	
}a[1010];
bool cmp(baka x,baka y)//排序比较函数 
{
	if(x.data==y.data)
	  return x.bian>y.bian;
	return x.data>y.data;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)//输入 
	  {
	  	a[i].bian=i+1;
	  	scanf("%d",&a[i].data);
	  }
	double ans=0;
	sort(a,a+n,cmp);//排序 
	for(int i=0;i<n;i++)//按顺序输出,计算. 
	  {
	  	printf("%d ",a[n-i-1].bian);
	  	ans+=i*a[i].data;
	  }
	printf("\n%.2lf",ans/n);
}
