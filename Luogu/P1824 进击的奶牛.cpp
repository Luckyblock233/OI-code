//算法：二分答案,贪心
//是考试题,
//但是题解里写的太烂了= =
//还是要写一写.


//因为答案范围已知，
//且答案区间以答案为界，
//一半为真，一半为假。
//则可以用二分答案法，找可能的答案，
//再用贪心来求得满足此答案所需的移走数量。
//移走数量小于m，证明此答案可行，
//再找区间[mid+1，r]，反之则找[l，mid-1]。

//贪心方法:
//对于一个序列,
//假使前k个石头之间的距离已经合法
//但第k个与第k+1个石头之间距离不合法
//此时可以去掉第k个石头,也可以去掉第k+1个石头 
//为了方便第k+2个石头与之前的石头形成合法序列,
//所以去掉第k+1个石头较合适
//这样一路贪下来,便得到了需要挪走的石头个数 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[1000010];
bool judge(int mid)//贪心模拟 
{
    int m1=0;
    int pa=1;//记录上一个没有被挪走的石头 
    for(int i=2;i<=n;i++) 
      {
      	if(a[i]-a[pa]<mid) m1++;//挪去第i个 
        else pa=i;//i成为上一个未被挪走 
      }
    if(m1>m) return 0;//此答案不可行 
    return 1;//可行 
}
int main()
{
    int t=1;
    
    while(t--)
      {
        scanf("%d%d",&n,&m);
        m=n-m;
        for(int i=1;i<=n;i++)
      	  scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int l=1,r=2100000000;
        while(l<=r)//二分答案 
      	  {
      		if(judge((l+r)/2))
          	  l=(l+r)/2+1;
      		else 
          	  r=(l+r)/2-1;
      	  }
        printf("%d\n",(l+r)/2);
      }
}
