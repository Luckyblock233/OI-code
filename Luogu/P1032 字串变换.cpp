//知识点：bfs
/* 
在队列中存当前字串及步数
每次bfs,都将当前字串变为新串,病使步数+1,在压入队列
注意判重,与步数小于等于10. 
详见注释 
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
struct baka9
{
	string s1;
	int step;
};
string a[8];//变幻规律 
string b[8];
string sa,sb;
int minn=100000;
queue <baka9> s;
map <string,bool> judge;//用来判重 
bool flag;
void bfs();
int n=1;
int main()
{
	cin>>sa>>sb;
	while(cin>>a[n] && cin>>b[n])//输入各规则 
	  n++;
	baka9 tmp;
	tmp.s1=sa;//将原字串放入队列 
	tmp.step=0;
	s.push(tmp);
	bfs();
	if(flag) printf("%d",minn);//输出 
	else printf("NO ANSWER!");
}
void bfs()
{
	while(!s.empty())//当不为空 
	  {
	  	baka9 tmp=s.front();
	  	s.pop();
	  	string s1=tmp.s1;
	  	int st=tmp.step;
	  	if(st>=10 || judge[s1])//若出现过或此时步数大于等于10,则继续下一层 
	  	  continue ;
	  	judge[s1]=1;//置一 
	  	  for(int i=1;i<=n;i++)
	  	    {
	  	  	  int n1=s1.find(a[i]);//循环找不同位置的a[i]
	  	  	  while(n1!=-1)
	  	  	    {
	  	  	  	  string s2=s1;//产生新的字串 
	  	  	  	  s2.replace(n1,a[i].length(),b[i]);
	  	  	  	  //cout<<s2<<endl;
				  if(s2==sb)//如果变成了b 
	  	  	  	    {
	  	  	  	  	  minn=st+1;
	  	  	  	  	  flag=1;
	  	  	  	  	  return ;//首解一定为最优解,直接返回即可 
				    }
				  else//压入队列 
	  	  	  	    {
					  baka9 tmp1;
	  	  	  		  tmp1.s1=s2;
	  	  	  		  tmp1.step=st+1;
	  	  	  		  s.push(tmp1);
	  	  	  	    }
	  	  	  	  n1=s1.find(a[i],n1+1);//找下一个位置 
			    }
		    }
		
	  }
}
