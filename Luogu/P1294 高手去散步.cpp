//此题为luogu上图论部分的题目
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int map[100][100];//存距离 
bool vis[110];//存是否被访问过 
int maxx,sum;//存最大值 和 和值 
int n,m;
void dfs(int i)//深搜 
{
	for(int j=1;j<=n;j++)//以此枚举与i点连接的点 
	  {
	   	if(!vis[j] && map[i][j])//如果连接并未被访问 
	   	  {
		 	vis[j]=1;//访问它 
			sum+=map[i][j];//加上和 
	  	  	dfs(j);//递归搜索 
	  	  	if(sum>maxx)//回溯后判断和值是否大于maxx 
	  	  	  maxx=sum;//替换 
	  	  	sum-=map[i][j];//减去该点 
	  	  	vis[j]=0;//回溯,置零该点,并开始下一次循环 
		  }
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	  	cin>>x>>y>>z;//输入数据 
	  	map[x][y]=map[y][x]=z;//加入距离数组 
	  }
	for(int i=1;i<=n;i++)// 以每个点为起点,开始搜索 
	  {
	  	vis[i]=1;//置一 
	    dfs(i);
	    memset(vis,0,sizeof(vis));//搜索结束返回后,置零vis数组 
	    sum=0;//和值为0 
	  }
	printf("%d",maxx);//输出最大值 
	return 0;
}
