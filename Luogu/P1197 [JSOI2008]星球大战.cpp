//知识点:并查集 
/*
没有任何帮助情况下，
自己刷的第一道蓝题

思路:本题目与 p2700类似, 都需要先将路径都推倒,再重新建边
先输入各边,爆炸的星球,并将其储存(注意存无向图
之后,建起不包括爆炸的星球的并查集,
这样就得到了最后状态的联通块数 
之后按爆炸顺序从后往前,依次将爆炸的星球添加到并查集中
就可以分别得到此时的联通块数 
最后得到原始状态的联通块数 
再反向输出,即可; 

注意这里的join函数,还有着计算联通块数的功能 
*/
#include<cstdio>
using namespace std;
int n,m,k;
int pre[400010],kk[400010],head[400010],ans[400010];
//分存祖先，被摧毁星球编号，邻接表各点所对的边，答案
struct baka9
{
	int u,v,ne;//存边 
}bian[400010];//无向图,两倍边 
int lian,num;//存联通块数与边数 
bool judge[400010];//判断星球是否爆炸 
int find(int x);//查集 
void join(int x,int y);//并集并计算联通块数
void add(int x,int y);//添加边 
//---------------------------------------------------
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	  pre[i]=i;//初始化祖先 
	for(int i=1;i<=m;i++)//输入各边 
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	add(x,y);//添加无向图
	  	add(y,x);
	  }
	scanf("%d",&k);
	for(int i=k;i>=1;i--)//反向记录被摧毁星球 
	  {
	  	scanf("%d",&kk[i]); 
	  	judge[kk[i]]=1;
	  }
	lian=n-k;//初始化联通块数,使每个没被摧毁的星球都单独在一个集子里
	for(int i=0;i<n;i++)//构建最后位置的并查集 
	  {
	  	if(judge[i])//被摧毁了,就找下一个 
		  continue;
		for(int j=head[i];j;j=bian[j].ne)//没被摧毁,就把它与相邻的没摧毁的星球添加到并查集中 
		  if(judge[bian[j].v] == 0)
		  	join(bian[j].u,bian[j].v);
	  }
	ans[k+1]=lian;//计算出了最后位置的联通块数
	for(int i=1;i<=k;i++)//计算各位置的联通块 
	  {
	  	judge[kk[i]]=0;//还原星球 
	  	lian++;//初始化,使这个星球单独一个集.
	  	for(int j=head[kk[i]];j;j=bian[j].ne)//添加没爆炸的相邻星球 
	  	  if(judge[bian[j].v] == 0)
			join(bian[j].u,bian[j].v);
	  	ans[k-i+1]=lian;//记录 
	  }
	for(int i=1;i<=k+1;i++)//输出 
	  printf("%d\n",ans[i]);
}
//---------------------------------------------------
int find(int x)//查集
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)//并集
{
	int r1=find(x);
	int r2=find(y);
	if(r1 != r2)
	  {
	  	pre[r2]=r1;//如果有两个不同组的集合合并 
	  	lian--;//那么联通块数减一. 
	  }
}
void add(int x,int y)//邻接表加边
{
	bian[++num].ne=head[x];
	bian[num].u=x;
	bian[num].v=y;
	head[x]=num; 
}
