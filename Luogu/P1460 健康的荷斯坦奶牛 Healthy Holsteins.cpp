//使用算法：dfs+回溯
//一开始照着模板打,发现tle了两个点
//分析了题目之后,发现了改进方法:
//首先,对于每种饲料,只有取或不取两种情况
//那么这道题就成了一个有多个边界的01背包问题
//dfs搜索每一种饲料,分别选择取或不取两种情况
//最后找出最优解即可 
#include<cstdio>
using namespace std;
int v,g;
int ne[30],map[20][30];
int ans[20];
int tans[20];
int minn=1000;
void dfs(int,int);
int main()
{
	scanf("%d",&v);//输入 
	for(int i=1;i<=v;i++)
	  scanf("%d",&ne[i]);
	scanf("%d",&g);
	for(int i=1;i<=g;i++)
	  for(int j=1;j<=v;j++)
	    scanf("%d",&map[i][j]);
//-----------------------------------------------------
	dfs(1,0);//从第一种开使搜,初始饲料数为0 
	printf("%d ",minn+1);//输出 
	for(int i=0;i<=minn;i++)
	  printf("%d ",tans[i]);
}
void dfs(int k,int tot)
{
	if(tot >= minn || k>g)//边界 
	  return ;
	int flag=1;
	ans[tot]=k;
	for(int j=1;j<=v;j++)//判断方案是否可行
	  {
	    ne[j]-=map[k][j];
	    if(ne[j] > 0)
	      flag=0;
	  }
	if(flag && tot < minn)//新的最优解 
	  {
		minn=tot;
		for(int i=0;i<=tot;i++)
	  	  tans[i]=ans[i];//换新答案 
	  }
	else dfs(k+1,tot+1);//取这种饲料,继续搜索 
	for(int j=1;j<=v;j++)//回溯 
	  ne[j]+=map[k][j];
	dfs(k+1,tot);//不取这种饲料 
}
