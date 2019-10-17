//算法:模拟 
//表面数论，实际模拟
//先求出小于1e9的斐波那契数列
//然后对于输入的每一个数,先找大的来减
//一直减到0
//反向输出减得数即可 
#include<cstdio>
#include<stack>
using namespace std;
int t,n,num;
int fb[100010]={0,1,2};
void fi()//求出小于1e9的斐波那契数列 
{
	for(num=3;fb[num-1]<=1000000000;num++)
	  fb[num]=fb[num-1]+fb[num-2];
}
int main()
{
	fi();
	scanf("%d",&t);
	while(t--)
	  {
	  	scanf("%d",&n);
	  	stack <int> s;
	  	int n1=n,i=num-1;
		while(n1>0)//一直减到0 
		  {
		    if(n1-fb[i]>=0)
		  	  {
		  	    s.push(fb[i]);
		  	    n1-=fb[i];
			  }
			i--;
		  }
		printf("%d=%d",n,s.top());
		s.pop();
		while(!s.empty())//反向输出减得数即可  
		  {
		  	printf("+%d",s.top());
		  	s.pop();
		  }
		printf("\n");
	  }
}
