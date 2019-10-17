//算法标签：二叉堆,贪心 
/*
思路:
输入各点,
之后,将其按照坐标的大小顺序进行排序,便于之后的贪心
建立一个降序排列的优先队列,来存可以AK的机房的ti 
之后开始枚举各点,来代表到达的最远机房
建立m1变量,等于m-路上时间-机房ak总时间,即可以用的空余时间 
若当前的最远机房ak时间小于m1就证明此机房也可以ak,就加入队列,ak机房数量+1 
若当前的最远机房ak时间 大于m1,但是小于m1+队列首元素,即最大的ak时间 
就将队列首元素剔除,将新的时间放入,数量不作调整 
最后找到数量的最大值,输出即可 
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
struct point//存各点 
{
	long long x,t;
}a[100010];
long long n,m; 
long long maxx=0;//最大值 
priority_queue < long long , vector<long long> , less<long long> > qq;//存ak时间 
bool cmp(point aa,point bb) 
{
	return aa.x <  bb.x;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	  scanf("%lld%lld",&a[i].x,&a[i].t);
//-------------------------------------------------
	sort(a+1,a+n+1,cmp);//按照坐标升序排序 
	long long t1=0,ans=0,sum=0;
	for(int i=1;i<=n;i++)//分别枚举最远机房 
	  {
	  	long long m1=m;
	  	t1=a[i].x;
	  	m1-=(t1+sum);//求空闲时间 
	  	if(a[i].t <= m1)//直接加入 
	  	  {
	  	  	qq.push(a[i].t);
	  	  	ans++;
	  	  	sum+=a[i].t;
		  }
		else
		  if(!qq.empty())
		    {
		    	int topp=qq.top();//替换队列元素 
	  		 	if(topp > a[i].t && m1+topp>=a[i].t)
	  	  	   	  {
	  	  		 	qq.pop();
	  	  		 	qq.push(a[i].t);
	  	  		 	sum=sum-topp+a[i].t;
		  	   	  }
			}
		maxx=max(ans,maxx);
	  }
	printf("%lld",maxx);//输出 
}
