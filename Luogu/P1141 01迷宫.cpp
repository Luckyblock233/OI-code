//使用算法：BFS
//首先输入各数据 
//为避免每次都搜索,导致超时.
//设置一个ans变量,存是第几个的联通块
//判断输入的数据有没有位于一个联通快中
//有则直接输出答案
//没有则开始广搜
//对到达的每一个点,都将它们放入新的一个联通快中
//最后记录此联通快的元素个数,作为答案 
#include<cstdio>
#include<queue>
using namespace std;
struct baka9//队列结构体,存坐标及 是一或零 
{
	int x,y;
	char ju;
};
char tu[1010][1010];//存图 
int ans[1010][1010];//存联通快 
int anss[100000010];// 存答案 
int ax[5]={1,-1,0,0};//坐标变化量 
int ay[5]={0,0,1,-1};
int n,m,q1,q2;
int sum,num;
char k[1010];//输入字符 
queue <baka9> s;
void bfs();
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)//输入图 
	  {
	  	gets(k);
	    for(int j=0;j<n;j++)
	      tu[i][j+1]=k[j];
	  }
	for(int i=1;i<=m;i++)//开始搜索 
	  {
	  	scanf("%d%d",&q1,&q2);
	  	if(ans[q1][q2])//被搜到过 ,直接输出 
	  	  {
	  	  	printf("%d\n",anss[ans[q1][q2]]);
	  	  	continue;
		  }
		ans[q1][q2]=++num;//没有被搜到过,就计算联通块,并开始广搜 
	  	baka9 tmp={q1,q2,tu[q1][q2]};
	  	s.push(tmp);
		bfs();
		anss[ans[q1][q2]]=sum;//记录答案 
		printf("%d\n",anss[ans[q1][q2]]);//输出 
	  }
}
void bfs()//标准广搜 
{
	sum=1;
	while(!s.empty())
	  {
	  	baka9 tmp=s.front();
	  	s.pop();
	  	for(int i=0;i<4;i++)
	  	  {
	  	  	int xx=tmp.x+ax[i];//枚举可到达的点 
	  	  	int yy=tmp.y+ay[i];
	  	  	if(xx>=1 && xx<=n)
	  	  	  if(yy>=1 && yy<=n)
	  	  	    if(!ans[xx][yy] && tu[xx][yy]!=tu[tmp.x][tmp.y])//满足条件 
	  	  	      {
	  	  	      	baka9 tmpp={xx,yy,tu[xx][yy]};
	  	  	      	s.push(tmpp);//压入队列 
	  	  	      	ans[xx][yy]=num;//放入联通块 
	  	  	      	sum++;
				  }
		  }
	  }
}
