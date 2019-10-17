//自己打的奇怪的优先队列DP
//脑子抽了的产物

//队列里存点的编号 
//序列按照升序排列
//每次都找到最小编号,
//并用填表法,更新能到达的点的f值

//在更新过程中,
//如果被更新的点能到达终点,
//就将其与ans比较,找出最大的 

//复杂度爆炸QWQ
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,l,r,ans;
int a[300010];
int f[300010];
bool ju[300010];
struct cmp1
{
    bool operator ()(const int a,const int b)
      {
        return a>b;
      }
};
priority_queue <int,vector<int>,cmp1> s;
int main()
{
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++)
      scanf("%d",&a[i]);
    s.push(0);
    while(!s.empty())
      {
      	int t=s.top();
      	s.pop();
      	for(int i=l;i<=r;i++)
      	  {
      	  	if(t+i<=n && f[t]+a[t+i]>f[t+i])//能更新 
      	  	  {
      	  	  	f[t+i]=f[t]+a[t+i];
      	  	  	if(!ju[t+i]) 
				  s.push(t+i);//未被压入队列 
      	  	  	ju[t+i]=1;	
              }
            if(t+i>n)//加上i后能到达终点,
              {
              	ans=max(f[t],ans); 
              	break;//后面t+i+1的情况已经没有必要再比了. 
              }
          }
      }
    printf("%d",ans);
}
