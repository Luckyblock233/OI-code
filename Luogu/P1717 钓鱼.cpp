//知识点:优先队列,贪心 
/*
在最外层有一个循环，枚举能到达的最远鱼塘的编号
在开始贪心之前，就减去路上所需的时间
表面上看，是瞬移（雾)，挨个鱼塘找最多钓鱼数，然后瞬移到下个鱼塘
实际上，还是按照实际，挨个鱼塘钓鱼，
因为已经减去了路上的时间，就不需要管空间上的差异
可以理解为，在每个鱼塘钓鱼的次数
*/ 
#include<cstdio>
#include<queue>
using namespace std;
struct baka9
{
	int fis;//钓鱼数 
	int dec;//减少量 
	int mov;//移动所需时间 
	bool operator< (const baka9 &c) const//构造结构体优先队列使用 
	  {
	  	return fis<c.fis;//按钓鱼数的降序排列 
	  }
}data[35];
int main()
{
	priority_queue <baka9> s;
	int n,t;
	scanf("%d",&n);
	scanf("%d",&t);
	for(int i=1;i<=n;i++) 
	  scanf("%d",&data[i].fis);
	for(int i=1;i<=n;i++) 
	  scanf("%d",&data[i].dec);
	for(int i=1;i<n;i++)
	  {
	  	scanf("%d",&data[i].mov);
	  	data[i].mov*=5;
	  }
	t*=60;
//-------------------------------------------------------------------------------------------
	int t1=0,ans=0,maxx=0;
	int t2=0;
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=1;j<=i;j++)
	  	  s.push(data[j]);
	  	if(i>=2) t1+=data[i-1].mov;//计算路上时间 
	  	int t2=t1;
	  	while(t2<t-4 && s.top().fis>0)
	  	  {
	  	  	baka9 topp=s.top();//进行一次钓鱼操作 
	  	  	ans+=topp.fis;
	  	  	s.pop();
	  	  	topp.fis-=topp.dec;//减少钓鱼数 
	  	  	s.push(topp);
	  	  	t2+=5;//时间加一 
		  }
		if(ans>maxx) maxx=ans;//找最大鱼数 
		ans=0;//置零 
	  }
	printf("%d",maxx); 
}
