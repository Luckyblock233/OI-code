/*本题大致思路:
用ans变量,储存答案 
用一个a[7]变量,分别储存在某一行放最新一个土豆的时间.
用b[2010]变量,放每个僵尸的数据
输入僵尸数据后,按照出现时的时间进行升序排列,来模拟出现的时间先后顺序
再分别枚举每个僵尸,看它出现的时间,是否在:    此行上个土豆的时间~此行上个土豆的时间+60之间
若是,则不需要新的土豆,ans不变
若不是,则需要一个新的土豆,来neng死他,ans变量++;同时,a数组中,相应行中新土豆出现时间置为t-1(可以捉摸琢磨为什么-1)
然后枚举下一个僵尸 
*/ 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct zombie
{
	int p,t;
}b[2010];//放每个僵尸的数据 
int a[7];
int ans=0;
int n;
bool cmp(zombie x,zombie y)
{
	return x.t<y.t;
}
int main()
{
	scanf("%d",&n);
	memset(a,-60,sizeof(a));//先将a置为-60,使每一个t都大于a[i]+60,以便于判断的开始 
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&b[i].p,&b[i].t);
	sort(b+1,b+n+1,cmp);//按t升序排列 
	for(int i=1;i<=n;i++)
	  if(a[b[i].p]<b[i].t && a[b[i].p]+60>=b[i].t) bool no_use_bool_just_take_it_a_joke; //为了使用else而设的if 
	  	else
	  	  {
	  	  	ans++;//增加答案 
	  	  	a[b[i].p]=b[i].t-1;//赋新的t值 
		  }   
	printf("%d",ans);
}
