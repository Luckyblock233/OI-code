//使用算法:DFS+回溯
//先用筛法求出素数 
//再向各位置填数， 如果满足此数与前一个数和为素数，则填入 
//当填到第n个数时,判断他与第一个数是否和为素数
//如果和为素数,就找到了一组解,输出. 
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
bool zhi[50]={1,1};//筛法求素数 
bool use[30];
int ans[30];
int n,tot,n1;
void zzz();
void dfs(int k);
void print();
int main()
{
	zzz();
	while(scanf("%d",&n) != EOF)//循环读入 
	  {
	    memset(ans,0,sizeof(ans));
		memset(use,0,sizeof(use)); 
	  	if(++n1>=2) printf("\n");
	    printf("Case %d:\n",n1);
	    ans[1]=1;
	    dfs(2);//搜! 
	  }
}
void zzz()//筛 
{
	for(int i=2;i<=sqrt(2*20+1);i++)
	  for(int j=2;j<=(2*20+1)/i;j++)
	    zhi[i*j]=1;
}
void dfs(int k)
{
	for(int i=2;i<=n;i++)//向其中填数 
	  if(!zhi[i+ans[k-1]] && !use[i])//满足条件 
	    {
	  	  ans[k]=i;//填入 
	  	  use[i]=1;//记录是否被用过 
	  	  if(k==n && !zhi[i+ans[1]]) //输出边界 
			print();
	  	  else 
			dfs(k+1);//继续搜 
	  	  use[i]=0;//回溯 
	  	  ans[k]=0;
	    }
	return ;
}
void print()//输出 
{
	printf("%d",ans[1]);
	for(int i=2;i<=n;i++)
	  printf(" %d",ans[i]);
	printf("\n");
	return ;
}
