//知识点:队列,模拟 
/*
被标签的单调队列骗了(划掉

题目要求在队列前后端
进行添加或删除操作 
且数据范围<=1e6
直接使用双端队列模拟即可 
详见注释 
*/
#include<iostream>
#include<deque>
#include<ctype.h>
//=============================================================
int s,now,num;
char query,side;
std::deque <int> q;
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//=============================================================
signed main()
{
	s=read();
	while(s--)
	{
	  std::cin>>query>>side;
	  if(query=='A')//添加操作 
	  {
	  	if(side=='L') q.push_front(++now);//左端添加 
	  	else q.push_back(++now);//右端添加 
	    continue ; 
	  }
	  num=read();
	  if(side=='L')  while(num--) q.pop_front();//左端删除 
	  else  while(num--) q.pop_back();//右端删除 
	}
	while(!q.empty())//输出队中元素 
	{
	  printf("%d\n",q.front());
	  q.pop_front();
	}
}

