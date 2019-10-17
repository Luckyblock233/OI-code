//算法：模拟
//记录最后高兴的天数
//每次增加答案时,比较是否与之前的高兴的天有重复
//如果有,就减去重复的
//没有则不管 
#include<cstdio>
using namespace std;
int n,t;
int ans;
int main()
{
	scanf("%d%d",&n,&t);
	int last=0;
	for(int i=1;i<=n;i++)
	  {
	  	int ti;
	  	scanf("%d",&ti);
	  	ans+=t-((last-ti+1)>0?(last-ti+1):0);//比较是否与之前的高兴的天有重复 
		last=ti+t-1; //记录最后高兴的天数 
	  }
	printf("%d",ans);
}
