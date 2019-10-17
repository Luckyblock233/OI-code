//知识点:模拟/队列
/*
按照题意 
用队列 模拟 单词和内存的情况
*/
#include<cstdio>
using namespace std;
bool word[1050];//记录有没有被放如内存 
int memory[1050];//数组模拟队列 
int n,m,ans,full;
int head;//队列头 
int main()
{
	
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	  {
	  	int x;
	  	scanf("%d",&x);
	  	if(word[x]==0)
	  	  {
	  	  	ans++,head++;
	  	  	if(full)//注意！当输入的单词为0时，memory【++head】也为0，若不加判断，就会将word【0】置零； 
	  	  	  word[memory[head]]=0;
	  	  	memory[head]=x;
	  	  	word[x]=1;
		    if(head==m)
		      {
		      	head=0;
		      	full=1;
			  }
		  }
	  }
	printf("%d",ans);
}
