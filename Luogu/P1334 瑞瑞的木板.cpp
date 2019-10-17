//算法：优先队列，堆
//正向分割不好考虑,可以考虑反向合并
//题目中说：一根长度为x的木板切为两根时，需要消耗x个单位的能量。
//就相当于: 合并两根长度为x1,x2的木板,需要消耗x1+x2个能量
//然后这题与P1090 合并果子就一模一样了 

//用优先队列,找到每次最小的两根木板
//将他们合并,再放入优先队列中
//并记录消耗的能量 
//一直合并n-1次,就得到了答案 
#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int main()
{
    priority_queue < int , vector<int> ,greater<int> > s; 
    int n,x;
	long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      {
      	scanf("%d",&x);
      	s.push(x);
      }
    for(int i=0;i<n-1;i++)
      {
      	int x=s.top();
      	s.pop();
      	int y=s.top();
      	s.pop();
      	ans+=x+y;
      	s.push(x+y);
      }
    printf("%lld",ans);
}
