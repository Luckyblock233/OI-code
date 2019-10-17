#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
struct cmp//网上查的比较函数, 
{
	bool operator()(int x, int y)
	  {
	  	return x<y;
	  }
};
int main()
{
	priority_queue <int,vector<int>,cmp> s;
	int n,m,a,b,c;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	for(int j=1;j<=m;j++)
	  s.push(a*j*j+b*j+c);//初始化 
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);
	  	for(int j=1;j<=m;j++)
	  	  {
	  	  	 if(a*j*j+b*j+c <s.top())//判断是否小于最大数 
	  	      {
	  	        s.pop();//删去最大数 
				  s.push(a*j*j+b*j+c);//放入新数 
	  	      } 
	  	    else 
				break;
	  	  }
	  }
	int ans[500000];
	for(int i=m;i>=1;i--)//颠倒输出 
	  {
	  	ans[i]=s.top();
	  	s.pop();
	  }
	for(int i=1;i<=m;i++)
	  printf("%d ",ans[i]);
}
