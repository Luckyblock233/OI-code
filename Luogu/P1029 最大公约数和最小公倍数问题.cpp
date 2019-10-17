//算法：数论
//先将输入x，y进行质因数分解
//然后比较分解后每一个质数的出现次数:
//如果xx[i]<yy[i],ans*=2;
//如果xx[i]>yy[i],证明给出数据不合法,没有答案 
#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 1050;
int xx[N],yy[N];
void split(int x,int *s)//拆分 
{
	int n=sqrt(x);
	for(int i=2;i<=n;i++)
	  while(x%i==0) 
	    x/=i,s[i]++;
	if(x!=1)s[x]++;
}
int main() 
{
	int x,y;
	long long ans=1;
	scanf("%d%d",&x,&y);
	split(x,xx);
	split(y,yy);
	for(int i=2;i<=1000;i++) 
	  {
		if(xx[i]>yy[i]) ans=0;
		if(xx[i]<yy[i]) ans*=2;
	  }
	printf("%lld",ans);
}
