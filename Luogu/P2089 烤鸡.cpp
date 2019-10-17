//算法：暴力枚举
//可以打十重循环
//此处使用dfs 
#include<cstdio>
using namespace std;
int sum=0;
int d[9000][11];  //数组存储结果 
void z(int k,int a[11],int n)  // k储存当前位置调料,a数组储存方案,n储存还需的美味度 
{
	if(n>20 || k>10)   //还需美味度大于20,或调料编号大于10,则不成立 
	  return ;
	for(int i=0;i<=2;i++)  //列举美味度 
	  {
	  	if(i > n) break;  //大于所需,则停止 
	    if(n==i)
	  	  {
	  	  	int b[11];
	  		for(int j=1;j<=10;j++)
	  	  	  b[j]=a[j];
	  	  	b[k]=b[k]+i;  //增加美味度 
			sum++;  //方案加一,并储存 
			for(int j=1;j<=10;j++)
			  d[sum][j]=b[j];
		  }
	  	else
	  	  {
	  	  	int b[11];
	  		for(int j=1;j<=10;j++)
	  	  	  b[j]=a[j];
	  	  	b[k]=b[k]+i;  //不成立,增加美味度,并继续递归 
	  	  	z(k+1,b,n-i);
		  }
	  }
}
int main()
{
	int n;
	scanf("%d",&n);
	n-=10;
	int s[11]={1,1,1,1,1,1,1,1,1,1,1};
	z(1,s,n);
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++)  //输出 
	  {
	  	for(int j=1;j<=10;j++)
	  	  printf("%d ",d[i][j]);
	  	printf("\n");
	  }
}
