//一道有技巧的模拟
//注意: 因为循环量较大,
//可先计算循环一次指令串的坐标变化量,再乘以循环次数
//最后循环完剩余的即可. 
#include<cstdio>
#include<cstring>
using namespace std;
char s[5010];//指令串 
int t;
int x,y;
int ax[6]={0,0,-1,0,1};//存各方向的变化量
int ay[6]={0,1,0,-1,0};
int main()
{
	scanf("%s",s);
	scanf("%d",&t);
	int l=strlen(s);//长度 
	int l1=l;
	int t1=t/l;//循环完了几次指令串 
	int i=0;
	t=t-t1*l;
	if(t1)//循环完了一次或以上的指令串 
	  while(l1--)//循环l1次,计算进行完一次指令串后的坐标变化 
	    {
	  	  char c1=s[i++];
	  	  int c2;
		  if(c1=='E') c2=1;//东南西北分别为1,2,3,4
		  if(c1=='S') c2=2;
		  if(c1=='W') c2=3;
		  if(c1=='N') c2=4;
		  x+=ax[c2];//坐标改变 
		  y+=ay[c2];
	    }
	x*=t1,y*=t1;//坐标变化量累乘 
	i=0;//归零 
	while(t--)//循环t次 
	  {
	  	char c1=s[i++];
	  	int c2;
		if(c1=='E') c2=1;//东南西北分别为1,2,3,4
		if(c1=='S') c2=2;
		if(c1=='W') c2=3;
		if(c1=='N') c2=4;
		x+=ax[c2];//坐标改变 
		y+=ay[c2];
	  }
	printf("%d %d",y,x);//输出 
}
