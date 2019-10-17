//链表模拟法
/*
pre数组记录前一个人,
ne数组记录后一个人,
然后进行初始化 

每次清除一个人
将 他的前一个人的后一个人 置为 他的后一个人
将 他的后一个人的前一个人 置为 他的前一个人 
*/ 
#include<cstdio>
using namespace std;
int n,m;
int pre[110],ne[110];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)///初始化 
	  pre[i]=(i==1?n:i-1),ne[i]=(i==n?1:i+1);
	int now=1;//当前报数人 
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=2;j<=m;j++)
	  	  now=ne[now];//模拟循环报数 
	  	printf("%d ",now);
	  	ne[pre[now]]=ne[now];//更新链表 的 链接域 
		pre[ne[now]]=pre[now];
	    now=ne[now];//更新当前报数人 
	  }
}
//直接模拟法 
/*
#include<cstdio>
using namespace std;
bool r[10001]={0};
int n,m;
int judge=0;//储存报的数 
int judge2=0;//储存正在报数的人数 
int main()
{
    scanf("%d%d",&n,&m);
    int n1=n;
    while(n>0)
      {
      	judge++;// 报数++ 
      	while(1)//寻找未出圈的第一人 
      	  {
      	    judge2++;
      	    if(judge2==n1+1)//环状清零 
              judge2=1;
      	    if(r[judge2]==false)  
      	      break;
          }
      	if(judge==m)//若报的数等于m 
      	  {
            r[judge2]=!r[judge2];//将此时报数的人移除 
            printf("%d ",judge2);    
            n--;//总人数减一 
          }
        if(judge==m) judge=0;
      }
}
*/
