//知识点:搜索
/* 
需要技巧的广搜
将状态矩阵 
压缩为一个 长度为9的字符串
以实现方便的记录 , 与判重

在实现位置交换时 , 
再将字符串的各位置,
映射到矩阵的各位置
并按照规则进行跳跃交换即可

详见注释
*/
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
using namespace std;
string s,tar = " 123804765";//目标状态
map <string,int> sum;//map判重,并记录步数
queue <string> q;
//============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void check(string top,int step)//检查是否到达目标状态
{
	if(top==tar)//到达目标状态
	  {
	  	cout<<step+1;
	  	exit(0);
	  } 
	if(!sum[top])//未到达目标
	  {
	  	sum[top]=step+1;//记录步数
	  	q.push(top);//加入队列
	  }
}
//============================================================
int main()
{
	cin>>s;
	s.insert(0," ");//构造原始字串
	if(s==tar) //初始即为目标
	  {
	  	cout<<0;
	  	return 0;
	  }
	q.push(s);
	while(!q.empty())//BFS
	  {
	  	string top=q.front();
	  	q.pop();
	  	int step=sum[top]; 
		int poi=top.find('0');//找到要交换的位置
	  	if(poi+3<=9)//进行纵向棋子交换
	  	  {
	  	  	swap(top[poi],top[poi+3]);//构造新状态
	  	  	check(top,step);//检查是否符合要求
	  	  	swap(top[poi],top[poi+3]);//还原
		  }
		if(poi-3>=1)//进行纵向棋子交换
		  {
		  	swap(top[poi],top[poi-3]);
	  	  	check(top,step);
	  	  	swap(top[poi],top[poi-3]);
		  }
		if(poi+1<=9 && poi!=3 && poi!=6)//横向交换
		  {
		  	swap(top[poi],top[poi+1]);//构造新状态
	  	  	check(top,step);//检查是否符合要求
	  	  	swap(top[poi],top[poi+1]);
		  }
		if(poi-1>=1 && poi!=4 && poi!=7)//横向交换
		  {
		  	swap(top[poi],top[poi-1]);
	  	  	check(top,step);
	  	  	swap(top[poi],top[poi-1]);
		  }
	  }
}
