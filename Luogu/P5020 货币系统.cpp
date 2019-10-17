//算法：DP/背包 
/*
题意分析: 
题目中想要找某一套货币系统的等效系统
即看一套系统中,某一个金额,
能不能被该系统中其他任意个金额替换
那么这个题就转化成为了完全背包问题 

算法实现: 
输入各组数据后，记录最大的金额mm。
同时将输入的金额在数组中标记为1 
之后枚举从1到mm的每个金额,如果被标记过(不管是1或者2), 
就执行这一步:

  for(int j=1;j<=n;j++)
    ju[i+a[j]]=2;
 
说明i+a[j]金额可以被原系统中合成,标记他们,用来合成更多金额 

跑一遍后,再枚举从1到 mm 的所有金额
如果被标记为1,说明他在原系统中有,且不能被合成
他就是必须有的金额,答案++; 
*/
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
//=================================== 
int t,n,max_money,ans;
int a[150];
short ju[50010];
//=================================== 
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void work()
{
	for(int i=1;i<=max_money;i++)//找到能被合成的金额 
	  if(ju[i])
	    for(int j=1;j<=n;j++)
	      ju[i+a[j]]=2;
	for(int i=1;i<=max_money;i++)//找原有的,且不能被合成的值. 
	  if(ju[i]==1)
		ans++;
}
//=================================== 
signed main()
{
	t=read();
	while(t--)
	{
	  n=read();
	  for(int i=1;i<=n;i++)
	  {
		a[i]=read();
		ju[a[i]]=1;//记录出现过，且为输入的面值 
		max_money=std::max(max_money,a[i]);//纪录最大值 
	  }
	  work();
	  printf("%d\n",ans);
	  memset(ju,0,sizeof(ju));
	  memset(a,0,sizeof(a));
	  max_money=-1,ans=0;
	}
}
