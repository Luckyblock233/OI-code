//最小生成树例题
//正向加边比较难做,只有二十分,
//看了题解后换了反向减边的方法

//一开始所有路都存在
//如果一条路,能直接连接两个含有被占据点的集合
//那么这条路就应该被删去.
//相反,若不能连接,则应被保留。

//一开始答案变量ans存所有边权值总和 
//从大边向小边开始找,若找到能被保留的边,就在ans中减去他
//若找到不能被保留的边,就不做操作
//直至结束,ans中剩下的就是应被删去的边的总和. 
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
struct baka9
{
	int u,v,w;
}a[200010];//存边 
int num;
int pre[100010];//存祖先 
map <int,bool> judge;//存敌我情况 
long long ans;
//------------------------------------------
bool cmp(baka9 aa,baka9 bb)//排序 
{
	return aa.w>bb.w;
}
//------------------------------------------
void add(int u,int v,int w)//添加边 
{
	a[++num].u=u;
	a[num].v=v;
	a[num].w=w;
}
//------------------------------------------
int find(int x)//查集 
{
	if(pre[x]==x)
	  return x;
	else
	  return pre[x]=find(pre[x]);
}
//-------------------------------------------
void join(int x,int y)//并集 
{
	int r1=find(x);
	int r2=find(y);
	if(r1 != r2)
	  {
	  	pre[r2]=r1;
		judge[r1]=(judge[r2]||judge[r1]);
		//注意此处!!如果一个我方据点与敌方据点相连接,则我方据点成为了敌方中转站 
		//敌方既然能通过此据点来到我方,就将此据点设为敌方 
	  }
}
//--------------------------------------------
bool judgee(baka9 aa)//判断 
{
	if(!judge[find(aa.u)] || !judge[find(aa.v)])
	  return 1;
	return 0;
}
//-------------------------------------------
int main()
{
	int n,k,kk;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	  {
	  	scanf("%d",&kk);
	  	judge[kk]=1;
	  }
	for(int i=1;i<n;i++)//输入各边 
	  {
	  	pre[i]=i;//顺便初始化 
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	ans+=w;
		add(u,v,w);
	  }
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<n;i++)
	  {
	  	if( judgee(a[i]) )
		  {
			join(a[i].u,a[i].v);
	  		ans-=a[i].w;//减 
	  	  }
	  }
	printf("%lld",ans);
}

