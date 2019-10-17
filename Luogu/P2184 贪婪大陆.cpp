//知识点:区间操作/树状数组 
/*
给定一段全为0的区间,
有两种操作:
1.在某区间上覆盖一条线段(所有的线段颜色都不相同
2.查询某区间内覆盖了多少条不同的线段

由于受到种类的影响
此题不能简单地求和或求最大值

----------一个例子------------------------ 

 	      |||||||||||||||||||||||| 
###################### 
==========================================
	[L 	  被查询区间      R] 
------------------------------------------

如上图(迫真图像

对于一个查询区间[L,R] ,
其线段数 = R前的(线段左端点)数 - (L-1)前的(线段右端点)数
证明:
  1. R前的(线段左端点)数 : 
    包括了所有在R前开始的线段
    只要它们的右端点在L右侧,
	那么就会被被查询区间所包括
	
  2. (L-1)前的(线段右端点)数
     包括了所有在L-1前结束的线段
     它们与 在R前开始的线段中某些 对应
     只要它们的它们不可能被区间所包括 
     
  3. 使R前的(线段左端点)数 - (L-1)前的(线段右端点)数
     就可以得到:
	 始点属于[L,R]的线段,与终点属于[L,R]的线段的个数
	 即:区间查询应被查询的线段数  
   
   
故:
可以使用两个树状数组
维护两个前缀和,
储存某点前的 左端点数 与 右端点数 
按照上述,即可实现 
*/ 
#include<cstdio>
#define int long long
#define lowbit(x) x&(-x) 
using namespace std;
const int MARX = 1e6+10;
int n,m;
int a[MARX],b[MARX],c[MARX],d[MARX];
void add_head(int x,int y,int n) //左端点 
{
	for(int i=x;i<=n;i+=lowbit(i))
	  c[i]+=y;
}
void add_tail(int x,int y,int n) //右端点 
{
	for(int i=x;i<=n;i+=lowbit(i))
	  d[i]+=y;
}
int find_head(int x)//查询左端点 
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	  sum+=c[i];
	return sum;
}
int find_tail(int x)//查询右端点 
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	  sum+=d[i];
	return sum;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	int q,x,y;
	  	scanf("%lld%lld%lld",&q,&x,&y);
	  	if(q==1)
		  {
		  	add_head(x,1,n);add_tail(y,1,n);//进行区间修改 
		  }
	  	else
	  	  {
	  	  	int ans=find_head(y)-find_tail(x-1);
	  	  	printf("%lld\n",ans);
		  }
	  }
}
