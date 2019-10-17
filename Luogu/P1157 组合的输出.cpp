//提供一种非搜索做法 
//不需要使用use数组,
//按顺序排列要列出的数,
//每个位置上可选的数即为(上个位置的数~最大数)
//按顺序循环赋值
//当数量足够时,输出即可 
#include<cstdio>
using namespace std;
int n1,r1;
int a[25];
void z(int n,int r,int b[25])
//n为当前数字,r为当前位数,b储存数组方案 
{
	if(r==r1)//长度满足则输出 
	  {
	  	for(int i=0;i<r1;i++)
	  	  printf("%3d",b[i]);
	  	printf("\n"); 
	  }
	else
	  for(int i=n;i<=n+n1;i++)  //循环列数 
	    {
	  	  int c[25];
		  for(int j=0;j<=r1;j++)
	  	    c[j]=b[j];
	  	  c[r]=i;  //赋值 
		  if(i <= n1) 
	  	    z(i+1,r+1,c);//满足条件再递归 
	    }
}
int main()
{
	scanf("%d%d",&n1,&r1);
	z(1,0,a);
}
