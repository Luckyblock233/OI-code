//这个题目比较特殊,与例题一笔画大概有这些不同： 
//首先，一条路径可能会出现多次
//其次，输出答案的顺序 是按照节点编号排序，不是一笔画的奇怪顺序XD 
//虽然是一笔画模板题,但是要做一些改动 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[1110][1110];//存某两个点之间有的路径数 
int ans[1100];//存答案的数组 
int oe[1100];//储存每个节点的路径的数, 用来计算奇点 
int bian[1100];//存输入的各个节点 
bool hao[1100];//用来判断某数是否存在,用来放止bian数组存下重复的节点 
int num,num1;//存ans的元素数量  和  输入节点的数量 
int n,m;
void dfs(int i)//以i节点为起点搜索 
{
	for(int j=1;j<=num1;j++)//在num1个节点中找 
	  {
	  	if(map[i][bian[j]] > 0)//如果i与bian[j]之间还有路 
	  	  {
			map[i][bian[j]]-=1;//路径数减一 
			map[bian[j]][i]-=1;//反向路径也减一 
	  	  	dfs(bian[j]);//以新的节点为起点,开始搜 
		  }
	  }
	ans[++num]=i;//跳出循环后,给ans赋值 
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++)//完美潇洒の输入 
	  {
	  	cin>>x>>y; 
	  	if(!hao[x])//如果x之前没有出现 
		  bian[++num1]=x;//就把他放到bian数组里 
	  	if(!hao[y])//如果y之前没有出现 
		  bian[++num1]=y;//同上,扔进去 
	  	hao[x]=hao[y]=1;//把hao数组置一,表示x,y出现过 
	  	map[x][y]++;//x,y之间,正向反向的路径数都+1; 
		map[y][x]++;
	  	oe[x]++;//与x相连的边加一 
	  	oe[y]++;//同上 
	  }
	sort(bian+1,bian+num1+1);//对bian数组中节点进行升序排序,来找到题目要求的,编号最小的起点. 
	int start=1;//dfs的起点 
	int joe=0;//辅助找到第一个偶点的变量 
	for(int i=1;i<=num1;i++)//找num1个节点 
	  { 
	    if(oe[bian[i]]%2 == 1)//若能找到第一个奇点 
	      {
	        start=bian[i];
	        break;//停下来 
		  }
		if(oe[bian[i]]%2==0 && joe++==0)//找到第一个偶点,并不继续找偶点 
		  start=bian[i];
	  }
	dfs(start);//以找到的点为起点,开始搜 
	for(int j=num;j>=1;j--)
	  printf("%d\n",ans[j]);//因为dfs递归中反向赋值,起点在最后,所以要再反向输出来 
	printf("\n");
	return 0;//完美潇洒の结束 
}






































































































































//https://www.luogu.org/recordnew/show/17882949
