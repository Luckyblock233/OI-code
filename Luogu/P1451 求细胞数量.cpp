//dfs求联通快 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int que[101000][2];//储存坐标的队列 
char a[1100][1100];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	  {
	  	cin>>a[i];//输入数 
	  }
//==============输入与处理的境界=================================================
	for(int i=0;i<n;i++)//挨个坐标进行搜索 
	  {
	  	for(int j=0;j<m;j++)
	  	  {
	  	  	if(a[i][j]>'0')//若数不为0,则证明有元素 
	  	  	  {
	  	  	  	ans++;//答案++ 
	  	  	  	int l=1,r=1;//将坐标压入队列 
	  	  	  	que[r][0]=i;
	  	  	  	que[r][1]=j;
	  	  	  	r++;//尾元素++; 
	  	  	  	while(l<r)//当队列不为空 
	  	  	  	  {
	  	  	  	  	int x=que[l][0];//横纵坐标 
	  	  	  	  	int y=que[l][1];
	  	  	  	  	if(a[x+1][y]>'0' && x+1<n)//下边 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x+1;//压入队列 
	  	  	  			que[r][1]=y;
	  	  	  			r++;//尾指针++ 
					  }
	  	  	  	  	if(a[x-1][y]>'0' && x-1>=0)//上边 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x-1;
	  	  	  			que[r][1]=y;
	  	  	  			r++;
					  }
	  	  	  	  	if(a[x][y+1]>'0' && y+1<m)//右边 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x;
	  	  	  			que[r][1]=y+1;
	  	  	  			r++;
					  }
	  	  	  	  	if(a[x][y-1]>'0' && y-1>=0)//左边 
	  	  	  	  	  {
	  	  	  	  	  	que[r][0]=x;
	  	  	  			que[r][1]=y-1;
	  	  	  			r++;
					  }
					a[x][y]=0;//当前元素置零,防止重复搜索 
					l++;//头指针++; 
				  }
				memset(que,0,sizeof(que));//清0队列 
			  }
		  }
	  }
	printf("%d",ans);//输出 
}
/*
5 5
1 1 1 1 1
0 0 0 0 0
1 1 0 1 1
0 0 0 0 0
1 1 1 1 1
*/
