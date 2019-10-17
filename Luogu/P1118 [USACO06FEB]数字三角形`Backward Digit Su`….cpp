//算法:dfs回溯
/*
本题目用到了杨辉三角.
手动模拟几组数据，可以推出：
当n=3时，sum=1*a+2*b+3*c
当n=4时，sum=1*a+3*b+3*c+1*d
当n=5时，sum=1*a+4*b+6*c+4*d+1*e 
(a,b,c,d,e...等为所求序列中各位置的数) 
可以看出, 算式中系数与杨辉三角中第n层各位置值一一对应
则:
		先计算出第n层杨辉三角的值， 
        枚举各位置的值,
		再使他们分别乘以此位置的系数
		计算他们的总值.
		当各位置都枚举完毕,且总值等于sum时,就找到了解
		因为循环枚举各位置数时，是按字典序枚举的
		则第一次找到的即最优解，直接输出即可 
杨辉三角1~10层 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1 
1 8 28 56 70 56 28 8 1 
1 9 36 84 126 126 84 36 9 1 
*/
#include<cstdio>
using namespace std;
int a[15];
bool use[12350];
int ans[15];
int n,sum,n1;
bool flag;
void dfs(int i,int s)//i为当前搜索的位置,s为当前已确定的各位置的总和 
{
	if(s>sum || flag) return ;//如果总和大于sum或者找到了解,停止 
	if(i==n+1)//当各位置都确定且总和为sum 
	  {
	    if(s==sum)
	      {
	        for(int j=1;j<=n;j++)
	          printf("%d ",ans[j]);//输出即可 
	        flag=1;//标记 
		  }
		return ;
	  }
	for(int j=1;j<=n;j++)//从1~n中找没有用过的数 
	  {
	    if(flag) return ;
	    if(!use[j] && s+j*a[i]<=sum)//剪枝,保证总和不大于sum 
	      {
	  	    use[j]=1;//标记 
	  	    ans[i]=j;
	  	    dfs(i+1,s+j*a[i]);//搜索下一位置 
	  	    use[j]=0;//回溯 
	      }
	  } 
}
int main()
{
	scanf("%d%d",&n,&sum);
	while(++n1 <= n)//计算第n层的杨辉三角 
	  {
	  	a[n1]=1;// 
	  	for(int i=n1-1;i>=2;i--) 
	  	  a[i]+=a[i-1];
	  }
	dfs(1,0);//从第一个位置开始搜 
}
/*
有n层的杨辉三角的计算程序：
#include<cstdio>
using namespace std;
int a[1000000];
int main()
{
	int n;
	scanf("%d",&n);
	int n1=0;
	while(++n1 <= n)
	  {
	  	a[n1]=1;
	  	for(int i=n1-1;i>=2;i--)
	  	  a[i]+=a[i-1];
	  	for(int i=1;i<=n1;i++)
	  	  printf("%d ",a[i]);
	  	printf("\n");
	  }
} 
*/

//-----------------------------------------------------------

/*
暴力dfs，TLE，70分代码：
#include<cstdio>
using namespace std;
int n,sum;
bool flag;
int ans[20];
bool use[100000];
int tans[20];
bool judge()
{
    int a[20];
    for(int i=1;i<=n;i++)
      a[i]=ans[i];
    int n1=n;
    while(n1--)
      {
      	for(int i=1;i<=n1;i++)
      	  a[i]+=a[i+1];
      }
    if(a[1]==sum)
      return 1;
    return 0;
}
void dfs(int l)
{
    if(l>n+1)
      return ;
    if(l==n+1)
      {
        if(judge())
      	  {
      	    bool flag1=1;
      	    if(tans[1])
      	  	  {
      	  	    if(ans[0] >= tans[0])
      	  	      flag1=0;
              }
            if(flag1)
          	  {  	
          	  	for(int i=0;i<=n;i++)
          	  	  tans[i]=ans[i];
          	  	flag=1;
          	  }
          }
        return ;
      }
    for(int i=1;i<=n;i++)
      if(!use[i])
        {
      	  use[i]=1;
      	  ans[l]=i;
      	  ans[0]+=i;
      	  dfs(l+1);
      	  use[i]=0;
      	  ans[0]-=i;
        }
}
int main()
{
    scanf("%d%d",&n,&sum);
    dfs(1);
    if(flag)
      for(int i=1;i<=n;i++)
        printf("%d ",tans[i]);
} 
*/ 
