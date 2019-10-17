//知识点:并查集/连通块/Kruscal / (二分答案) 
/*
题目要求:
将n个点,划分成k个连通块,
不连通的点距离的最小值最大

题目分析: 
看到这种单调性问题
可以进行二分答案
但是对于本题,使用Kruscal更明智一些 
 
算法实现:
先输入各点坐标,计算出各点之间的距离
然后 将各点两两分别相连,建出初始图

再将各边按照升序排序,
开始跑Kruscal.
在并集时,计算此时的连通块数

当连通块数==k(要求的块数)时,
打上标记,并继续循环找到一条
两端点不在同一集合的边
此边的权值即为答案 

正确性显然,
由于进行了排序,找到的答案,
即为最大的 两个未联通点的最小距离 
*/
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;
//=================================================
const int MARX = 1e3+10;
struct baka9
{
	int u,v;
	double w;//分存每一条边前,后坐标与权值 
}a[MARX*MARX];
int n,m,num;//存边的数量 
int x[MARX],y[MARX],pre[MARX];//存并查集中的祖先 
//=================================================
inline int read()//快读 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
bool cmp(baka9 aa,baka9 bb)//结构体sort排序必须自定义排序函数 
{
		return aa.w<bb.w;
}
void add(int u,int v)//链式前向星建图 
{
		a[++num].u=u,a[num].v=v;
		a[num].w=((double)sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v])));//两点之间距离 
}
int find(int tmp)//查集 
{
		return pre[tmp]==tmp?tmp:pre[tmp]=find(pre[tmp]);
}
void join(int tmp1,int tmp2)//并集 
{
		int r1=find(tmp1),r2=find(tmp2);
		if(r1 != r2) pre[r1]=r2;
}
//===========================================================
int main()
{
		n=read(),m=read();
		for(int i=1;i<=n;i++) 
		{
			pre[i]=i;//重置先祖 
			x[i]=read(),y[i]=read();//输入坐标 
		}
		for(int i=1;i<=n;i++)//建边建图 
	    for(int j=i+1;j<=n;j++)
				add(i,j);
		sort(a+1,a+num+1,cmp);//升序排序 
		int i=1,flag=0,sum=0;
		for(;i<=num;i++)//循环找num条边,当找到n-1条边时停止 
		{
		 
			if(find(a[i].u) != find(a[i].v))
	  	{
	  		join(a[i].u,a[i].v);//并集 
				if((--n)==m) flag=1;//要循环再找到一条两端点不在同一集合的边,才是最终答案 
			  if(flag)
			  {
			  	printf("%.2lf",a[i].w);//输出
					return 0; 
				}
			}
		}
}
