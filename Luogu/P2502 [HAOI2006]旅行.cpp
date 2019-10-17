//本题思路：先固定一条最大边，
//不断向其中添加小边直到s，t联通
//将小边从大到小枚举，每次判断s,t是否联通
//s,t一旦联通，此时的最大边和最小边，就是一组可能的解，记录他们。 
//枚举所有最大边，将所有可行解找到，然后将他们比较，得出最优解
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,s,t;
struct baka9
{
	int u,v,w;
}a[10010];//存边 
struct anss
{
	int maxx,minn;
}ans[200000];//存答案 
int pre[510];//存父亲 
bool vis[510];//是否与s,t相连 
double ansss=990000;//答案 
int ansnum;
int n1;
int maxx,minn,num,num1;
void add(int x,int y,int w);
bool cmp(baka9 aa,baka9 bb);
int find(int x);
void join(int x,int y);
//----------------------------------------------
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pre[i]=i;//初始化 
	for(int i=1;i<=m;i++)//输入各边 
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);
	  }
	scanf("%d%d",&s,&t);
	if(find(s) != find(t))//先判断s与t是否同祖 
	  {
	  	printf("IMPOSSIBLE");
	  	return 0;
	  }
	for(int i=1;i<=n;i++)
	  if(find(i) != find(s))
	    vis[i]=1;//将不与s,t联通的点剔除 
	for(int i=1;i<=n;i++)//再次初始化 
	  pre[i]=i;
	sort(a+1,a+num+1,cmp);//排序大边 
	for(int i=1;i<=m;i++)//以此找每条大边 
	  {
	  	if(vis[a[i].u] || vis[a[i].v])//有没有被剔除 
	  	  continue;
	  	for(int j=1;j<=n;j++)//重置祖先 
	  	  pre[j]=j;
	  	for(int j=i;j>=1;j--)//找小边 
	  	  {
	  	  	int u=a[j].u,v=a[j].v;
			if(vis[u] || vis[v])
			  continue;
			 int fu=find(u),fv=find(v);
			 if(fu!=fv)//合并集合 
			   {
			   	pre[fu]=fv;
			   	int fs=find(s),ft=find(t);
			   	if(fs==ft)//如果已经使s,t联通 
			   	  {
			   	  	ans[++num1]=(anss){a[i].w,a[j].w};//记录 
			   	  	break;
				  }
			   }
		  }
	  }
	for(int i=1;i<=num1;i++)//找最优解 
	  {
	  	if((double)ans[i].maxx/(double)ans[i].minn < ansss)
	  	  {
	  	  	ansss=(double)ans[i].maxx/(double)ans[i].minn;
	  	  	ansnum=i;
		  }
	  }
	if(ans[ansnum].maxx%ans[ansnum].minn==0)//如果答案为整数 
	  printf("%d",ans[ansnum].maxx/ans[ansnum].minn);
	else//如果答案为分数 
	  {
	  	int gcdd=__gcd(ans[ansnum].maxx,ans[ansnum].minn);
	  	printf("%d/%d",ans[ansnum].maxx/gcdd,ans[ansnum].minn/gcdd);
	  }
}
//--------------------------------------------
void add(int x,int y,int w) 
{
    a[++num].u=x;
    a[num].v=y;
    a[num].w=w;
    join(x,y);
}
bool cmp(baka9 aa,baka9 bb)
{
	return aa.w<bb.w;
}
int find(int x)
{
    if(pre[x]==x) return x;
    else return pre[x]=find(pre[x]);
}
void join(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    if(r1 != r2)
      pre[r2]=r1;
}
