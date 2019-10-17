//使用算法：DFS+回溯 
//思路:
/*
先找到以指定字符为首字母的单词，并以他们为起点，开始dfs
每次dfs，将当前字符串传输过去
循环找能使用的单词，即出现次数小于2的单词 
能找到，就在当前字符串中反向找所选单词中的第一个字母
如果能找到，判断位置head是否为当前字符串的首位。
如果为首位，这说明新单词被当前字串包含，直接进入下一层循环
不为首位，就判断从head到当前字串尾部的字串，是否在新单词头上出现
如果出现，则在当前字串尾部加上单词后边的部分
此单词出现次数+1，并进入下一层dfs 
*/ 
#include<iostream>
#include<map>
#include<string>
using namespace std;
int n;
map <string,int> vis;
string a[25];
int ans;
char start;
void dfs(string x)
{
	int l=x.length();
	ans=max(ans,l);//找到最大值 
	for(int i=1;i<=n;i++)
	  {
	  	if(vis[a[i]] < 2)
	  	  {
			string b=a[i];
			int head=x.rfind(b[0]);//在当前字符串中反向找所选单词中的第一个字母 
	  	  	if(head == -1 || head==0) continue;//判断位置head是否为当前字符串的首位。 
	  	  	int ix=head,ib=0;
	  	  	while(x[ix] == b[0])//就判断从head到当前字串尾部的字串，是否在新单词头上出现 
	  	  	  {
	  	  	  	ix++;ib++;
	  	  	  	b.erase(0,1);
	  	  	  	if(ix==x.length())//到x尾部 
				  break;
			  }
			if(ix==x.length())//则在当前字串尾部加上单词后边的部分,此单词出现次数+1，并进入下一层dfs  
			  {
			  	vis[a[i]]+=1;
				x+=b;
				dfs(x);
				x.erase(ix,a[i].length());
				vis[a[i]]-=1;
			  }
		  }
	  }	
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];//输入 
	cin>>start;
	for(int i=1;i<=n;i++)//找到以指定字符为首字母的单词 
	  {
	  	if(a[i][0]==start)
	  	  {
	  	  	vis[a[i]]+=1;
	  	  	dfs(a[i]);
	  	  	vis[a[i]]-=1;
		  }
	  }
	cout<<ans;//输出答案 
}
