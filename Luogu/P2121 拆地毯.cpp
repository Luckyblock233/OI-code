//算法：图论/最大生成树/并查集
//题目要求不形成环的
//最大的前k条边
//的权值总和
//则先进行排序,然后建立有k条边的最大生成树 
//输出权值和即可 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int u,v,w;
}a[1000010];
int pre[100010];
int ans,num;
//===================================================
bool cmp(baka9 aa,baka9 bb)
{
	return aa.w>bb.w;
}
void add(int bee,int aff,int wee)//邻接表加入元素 
{
	a[++num].u=bee;
	a[num].v=aff;
	a[num].w=wee;
}
int find(int x)//查找,同时压缩 
{
	if(pre[x]==x) return x;
	else return pre[x]=find(pre[x]);
}
void join(int x,int y)//并集 
{
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2)
	  pre[r1]=r2;
}
//====================================================
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)//每个元素的根都是他自己 
	  pre[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	int u,v,w;
	  	scanf("%d%d%d",&u,&v,&w);
	  	add(u,v,w);
		add(v,u,w);
	  }
	sort(a+1,a+num+1,cmp);
	int i=1,k1=0;
	while(i<=num && k1<k)
	  {
	  	baka9 tmp=a[i];
	  	if(find(tmp.u)!=find(tmp.v))
	  	  {
	  	  	join(tmp.u,tmp.v);
	  	  	k1++;
	  	  	ans+=tmp.w;
		  }
		i++;
	  }
	printf("%d",ans);
}
