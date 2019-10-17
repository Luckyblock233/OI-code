//单调队列模板题
//详见注释 
#include<cmath>
#include<cstdio>
using namespace std;
int n,k;
int a[2000010];
int q[2000010],head[2000010];
void minn()//单调队列模板 
{
    int h=1,t=0;
    for(int i=1;i<n;i++)//求第i-k到第i-1个数中最小值 
      {
      	while(q[t]>=a[i] && t>=h)//取出不可能成为最小值的元素 
      	  t--;
      	q[++t]=a[i];//插入 
      	head[t]=i;//记录编号 
      	if(head[h]<=i-k)//出界,则pop掉 
		  h++;
        printf("%d\n",q[h]);
      }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    printf("0\n");//第1个数前面没有数 
    minn();
    return 0;
}
