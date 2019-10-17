//知识点: 模拟 
/*
此题spj炸掉了= =
浪费了一些时间
 
分析题意:
首先 , 对于排名不变的 ,
输出时 还应在 输入时的原位置

对于排名上升的,
原排名一定在 下方,
排名下降的同理

则可以维护两个队列,
分别存 排名上升的 和下降的歌曲
并在 输入时进行维护和标记

在输出时,
如果当前 歌曲排名不变,则直接输出
否则输出 排名下降的, 原排名在上的 歌曲 
当 下降歌曲队列为空后,
输出 排名上升的, 原排名在下的 歌曲 
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
//=============================================================
std::string name[110],change;
int n;
bool same[110];//记录是否 排名相同 
std::queue <int> down,up;//存下降/上升 
//=============================================================
signed main()
{
	std::cin>>n;
	for(int i=1; i<=n; i++)
	{
	  std::cin >> name[i] >> change;//输入 并判断类型 
	  if(change == "UP")   up.push(i);
	  if(change == "DOWN") down.push(i);
	  if(change == "SAME") same[i] = 1;
	}
	for(int i=1; i<=n; i++)//按照要求输出 
	  if(same[i]) std::cout << name[i] <<'\n';
	  else if(!down.empty()) std::cout<< name[down.front()]<<'\n' , down.pop();
	  else if(!up.empty()) std::cout << name[up.front()] <<'\n' , up.pop();
}
