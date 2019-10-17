//知识点:dfs 
/*
题目要求:  
判断 能否通过立体空间内一些空心球形 
从 0高度 处,到达 指定高度处 

根据空间内两点的距离公式:
dist(p1,p2) * dist(p1,p2) = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
可知: 如果两圆心之间距离 <= 2*r , 那么两个空心圆有交点. 

那么可以 以与0高度水平面相交的球为起点
开始dfs,转移到能连通的,
且所处高度>=当前球形高度的球 

如果转移到一个,与指定高度水平面相交的球
那么可以满足条件, 能到达指定高度处
否则不可. 
*/
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
const int MARX = 1010;
//=============================================================
struct circle
{
	double x,y,z;
}a[MARX];
int T;
double n,h,r;
bool flag , top[MARX],vis[MARX];
//=============================================================
bool unicom(int c1,int c2)//判断 两球形之间的连通性 
{
	//如果两圆心之间距离 <= 2*r , 那么两个空心圆有交点. 
	int x_1=a[c1].x,y_1=a[c1].y,z_1=a[c1].z,x_2=a[c2].x,y_2=a[c2].y,z_2=a[c2].z;
	return ((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1)+(z_2-z_1)*(z_2-z_1) <= 4*r*r);
}
void dfs(int now)
{
	if(!flag) return ; 
	if(top[now])// 转移到一个,与指定高度水平面相交的球
	{
	  flag=0;return ;
	}
	vis[now]=1;
	for(int i=1;i<=n;i++)//转移到能连通的 , 且所处高度>=当前球形高度的球 
	  if(!vis[i] && unicom(now,i) && a[i].z>=a[now].z)
	    dfs(i);
}
//=============================================================
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
	  std::queue <int> bottom;
	  memset(top,0,sizeof(top));//初始化 
	  memset(vis,0,sizeof(vis));
	  flag=1;
	  
	  scanf("%lf%lf%lf",&n,&h,&r);
	  for(int i=1;i<=n;i++) 
	  {
	    scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
	    if(a[i].z-r<=0) bottom.push(i);//与底面相交的球 
		if(a[i].z+r>=h) top[i]=1;//与顶面相交的球 
	  }
	  while(!bottom.empty())//以 与底面相交的球 为起点,开始dfs 
	  {
	  	dfs(bottom.front());
	  	bottom.pop();
	  	if(!flag) break;
	  }
	  if(flag) printf("No\n");
	  else printf("Yes\n");
	}
}
