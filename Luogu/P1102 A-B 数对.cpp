//算法：模拟
//将A-B=C转化为A-C=B
//这样可以在输入时顺便减去C，获得B 
//最后统计B在原序列中 的出现次数即可 
#include<cstdio>
#include<map>
using namespace std;
int n,c;
long long ans;
long long a[2000010];
map <long long,int> s;//map存出现次数 
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%lld",&a[i]);
	  	s[a[i]]++;//记录次数 
	  	a[i]-=c;//减去,获得b 
	  }
	for(int i=1;i<=n;i++)//统计出现次数 
	  ans+=s[a[i]];
	printf("%lld",ans);
}
