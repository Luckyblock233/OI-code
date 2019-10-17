//算法:贪心
//先输入各数据,并计算平均值(即每堆最后的牌数)
//然后枚举每一堆牌
//如果此堆不足平均值,就从下一堆中向这堆移牌,步数+1;
//如果此堆大于平均值,就将多的牌移到下一堆,步数+1;
//等于平均值就跳过
//最后输出步数 
#include<cstdio>
using namespace std;
int a[110];
int main()
{
	int ans=0;
	int n,sum=0,each=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	sum+=a[i];
	  }
	each=sum/n;//平均值 
	for(int i=1;i<=n;i++)
	  {
	  	if(a[i]<each)//不足平均值 
	  	  {
	  	  	a[i+1]-=(each-a[i]);//往这堆移牌 
	  	  	ans++;//步数加一 
		  }
		if(a[i]>each)
		  {
		  	a[i+1]+=(a[i]-each); //移到下一堆 
		  	ans++;
		  }
	  }
	printf("%d",ans);//输出 
}
