//知识点:树状数组/区间操作 
/*
初始有一全部为0的数列 
题目给出两种操作:
1.翻转某段区间(1->0,0->1) 
2.查询某单点 (输出0,1情况) 

对于一个点,只有0 ,1两种情况
且只有反转操作
 
所以只需要记录
每个点的被反转次数

就可以退出该点的0,1情况
如果反转次数为奇数,则为1
否则为0

此题就变成了 区间修改,单点查询 的模板 
*/ 
#include<cstdio>
#define lowbit(x) x&(-x) 
using namespace std;
const int MARX = 1e6+10;
int n,m;
int a[MARX],b[MARX],c[MARX];
void add(int x,int y,int n) //区间修改 
{
	for(int i=x;i<=n;i+=lowbit(i))
	  c[i]+=y;
}
int find(int x)//单点查询 
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	  sum+=c[i];
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	int q,x,y;
	  	scanf("%d",&q);
	  	if(q==1)
		  {
		  	scanf("%d%d",&x,&y);
		  	add(x,1,n),add(y+1,-1,n);
			//应用差分思想,进行区间的修改 
		  }
	  	else
	  	  {
	  	  	scanf("%d",&x);
	  	  	int ans=find(x);//单点查询 
	  	  	printf("%d\n",ans%2?1:0);//输出0,1情况 
		  }
	  }
}
