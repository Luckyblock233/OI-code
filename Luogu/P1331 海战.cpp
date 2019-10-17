//使用算法：dfs
/*
这道题的难点在于判断是否有船相邻。
 通过自己模拟的数据可以得出结论： 
 如果图是不合法的，一定存在如下结构：
# # 
. #
或
# #
# .
或
# .
# #
或
. #
# #
即在一个2*2的方格中有三个#。所以就能得出代码：
*/
//判断完是否合法后,求联通块数即可 
#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
char k;
int sum;
int ax[5][5]={{0,1,1},{0,-1,-1},{-1,0,-1},{0,1,1}};//2*2格子坐标变化量 
int ay[5][5]={{1,0,1},{1,0,1},{0,-1,-1},{-1,0,-1}};
int xx[5]={0,0,1,-1};//坐标变化量 
int yy[5]={1,-1,0,0};
bool map[1010][1010],flag;
void judge(int,int);
void dfs(int,int);
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)//输入 
	    {   
	      cin>>k;
	      if(k=='#') map[i][j]=1;
	      else map[i][j]=0;
		}
	for(int i=1;i<=n;i++)//判断是否合法 
	  for(int j=1;j<=m;j++)
	    if(map[i][j])
	      {
	      	judge(i,j);
	      	if(flag)
			  return 0;
		  }
	for(int i=1;i<=n;i++)//求联通快 
	  for(int j=1;j<=m;j++)
	    if(map[i][j])
	      {
	      	map[i][j]=0;
	      	sum++;
	      	dfs(i,j);
		  }
	printf("There are %d ships.",sum);
}
void judge(int x,int y)//判断是否合法 
{
	for(int i=0;i<4;i++)//枚举4个相邻的2*2格子 
	  {
	  	int flag1=0;
	  	for(int j=0;j<3;j++)//求相邻的2*2的格子中出现了几个# 
	  	  if(map[x+ax[i][j]][y+ay[i][j]])
	  	  	flag1++;
	  	if(flag1==2)
	  	  {
	  	  	printf("Bad placement.");//不合法 
	  	  	flag=1;
	  	  	return ;
		  }
	  }
}
void dfs(int x,int y)//标准dfs模板 
{
	for(int i=0;i<4;i++)
	  {
	  	if(map[x+xx[i]][y+yy[i]])
	  	  {
	  	  	map[x+xx[i]][y+yy[i]]=0;
	  	  	dfs(x+xx[i],y+yy[i]);
		  }
	  }
}
