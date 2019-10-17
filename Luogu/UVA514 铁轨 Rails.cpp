#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int a[10001];
int main()
{
    int n;
    while(1)//依照题目格式进行输入输出 
      {
        scanf("%d",&n);
        if(n==0)//停止条件 
          break;
      	while(1)
          {
          	stack <int> s;
          	scanf("%d",&a[1]);
          	if(a[1]==0)//判断有无输入,若无则停 
          	  break;
            for(int i=2;i<=n;i++)//若有输入,则继续 
              scanf("%d",&a[i]);
            int j=1;
            for(int i=1;i<=n;i++)//表示进站编号 
      	  	  {
      			s.push(i);//压入栈 
      			while(!s.empty() && a[j]==s.top())//若发现栈顶元素与出站顺序中的第一个元素相同 
      	  	  	  {
      	  			s.pop();//删去栈顶元素 
      	  			j++;//出站顺序加一 
          	  	  }//while继续判断 
      	  	  }
            if(!s.empty())//若最后不为空,则非法 
      	      printf("No\n");
            else
      	      printf("Yes\n");//合法情况 
      	    memset(a,0,sizeof(a));//重置a 
          }
        printf("\n");//依照题目格式输出 
      }
}
