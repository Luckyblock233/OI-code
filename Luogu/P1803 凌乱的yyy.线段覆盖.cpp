//算法:贪心 
//先将所有的比赛 按照结束时间升序排序
//结束时间相同的 按照开始时间降序排序
//记录最新的结束时间(初值为-1) 
//然后从头枚举每一场比赛
//如果比赛的开始时间在最新结束时间之后,就可以选择
//并将最新结束时间变为该场比赛的结束时间.
//一直枚举到完所有比赛. 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int be,ed;
}a[1000010];
int n,e=-1,num;
bool cmp(baka9 aa,baka9 bb)//排序 
{
	if(aa.ed==bb.ed)
	  return aa.be>bb.be;
	return aa.ed<bb.ed;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&a[i].be,&a[i].ed);//输入 
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)//枚举每一场比赛 
	  if(a[i].be>=e)
	  	{
	  	  num++;
	  	  e=a[i].ed;//替换最新结束时间 
		}
	printf("%d",num);
}
