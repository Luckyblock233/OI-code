//知识点：链表/模拟
/*
使用链表,来模拟队列
用pre和ne数组,记录前一个和后一个人 

每插入一个人,更新被影响的人的
前后人的编号值 
同时记录队列首的人 

每删除一个人,更新此人前后的人的
前后人的编号值 

从记录的队首人起,找到第一个未被删除的人 
以此人为起点,输出队中的人 
*/ 
#include<cstdio>
using namespace std;
const int MARX = 1e5+10;
int n,m,k,p,be=1;
int pr[MARX],ne[MARX];
bool ju[MARX];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	  {
	  	scanf("%d%d",&k,&p);
	  	if(p)//更新 被影响的人
	  	  {
	  	  	pr[i]=k,ne[i]=ne[k];
	  	  	pr[ne[k]]=i,ne[k]=i;
		  }
		else
		  {
		  	if(be==k) be=i;
		  	pr[i]=pr[k],ne[i]=k;
		  	ne[pr[k]]=i,pr[k]=i;
		  }
	  }
	scanf("%d",&m);
	while(m--)//模拟删除 
	  {
	  	scanf("%d",&k);
	  	if(ju[k]=1) continue;
	  	ju[k]=1;
	  	ne[pr[k]]=ne[k];
	  	pr[ne[k]]=pr[k];
	  }
	while(ju[be]) be=ne[be];//找到队首的 第一个未被删除的 
	while(be) //循环输出 
	  {
	    printf("%d ",be);
		be=ne[be];	
	  }
}
