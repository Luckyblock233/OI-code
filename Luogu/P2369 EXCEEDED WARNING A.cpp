//算法:堆
/*
维护一个最多能存下m个数的大根堆。
每读入一个数xi，
就将xi放入堆中。
如果堆中数的数量大于m，
就删掉大根堆的根。
就能维护当前最小的m个数了。

最后，将堆里的所有数排序，依次输出即可。
*/ 
#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
int n,m;
priority_queue <int> s;
priority_queue <int,vector<int>,greater<int> > s1;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      {
      	int x;
      	scanf("%d",&x);
      	if(i<=m) 
          s.push(x);
      	else
      	  if(x<s.top()) 
            s.pop(),s.push(x);
      }
    for(int i=1;i<=m;i++)
      {
      	s1.push(s.top());
      	s.pop();
	  }
	while(!s1.empty())
	  {
	  	printf("%d\n",s1.top());
	  	s1.pop();
	  }
}
