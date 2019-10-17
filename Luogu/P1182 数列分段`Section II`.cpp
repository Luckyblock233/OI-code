//算法:二分答案/贪心
/*
易证答案满足单调性,小的可行,则大的一定可行
故,可以二分答案法枚举每段和的最大值

用前缀和存 第1个数 到 第i个数的总和
这样,就可以用 b[i]-b[j]获得 i~j 段的数的和 

枚举后,通过贪心来进行检查
贪心策略:
  如果加上新数,此段和小于枚举值,则加上新数
  否则,将前面部分断开,成为一个新的数段。 
  最后统计数段个数，如果小于等于规定的m，则枚举的数合法 
*/ 
#include<cstdio>
using namespace std;
const int MARX = 1e6+10;
int n,m;
int a[MARX],b[MARX];
bool judge(int x)//贪心法进行检验 
{
	int tot=0,be=0;
	for(int i=1;i<=n;i++) 
	  {
	  	if(a[i]>x) return 0;
	  	if(b[i]-b[be]>x) tot++,be=i-1;//添加新数段 
	  }
	if(be!=n) tot++;//最后的数段 
	return tot<=m;//检查 
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//输入 
	  {
	  	scanf("%d",&a[i]);
	  	b[i]=b[i-1]+a[i];//前缀和 
	  }
	int le=1,ri=1e9,mid,ans;
	while(le<=ri)//二分答案 
	  {
	  	mid=(le+ri)>>1;
	  	if(judge(mid)) ans=mid,ri=mid-1;
	  	else le=mid+1;
	  }
	printf("%d",ans);
}
