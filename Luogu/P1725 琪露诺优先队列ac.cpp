#include<cstdio>
#include<algorithm>
#include<queue> 
#include<cstring>
using namespace std;
const int MARX=0xf;
int n,l,r,ans;
int a[300010];
int f[300010];
int head[300010];
int h=1,t=1;
struct cmp1//自定义优先级,冰冻指数和 
{
	bool operator ()(const int a,const int b)
	  {
	  	return f[a]<f[b];
	  }
};
priority_queue < int,vector<int>,cmp1 > q;
int maxx(int i)//获取最大的f[i]
{
    q.push(i);
    while(q.top()+r<i)
      q.pop();
    return q.top();
}
int main()
{
    memset(f,-MARX,sizeof(f));//初始化极小值 
    ans=f[0],f[0]=0;//初始化各值. 
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++)
      scanf("%d",&a[i]);
    for(int i=l;i<=n;i++)//DP过程 
      {
      	int k=maxx(i-l);
      	f[i]=f[k]+a[i];
      	if(i>=n-r+1)//找到能到达河对岸的，即答案 
      	  ans=max(ans,f[i]);
      }
    printf("%d",ans);
}
