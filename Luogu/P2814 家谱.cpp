//此处使用了map容器,改变了数组的下标
//便于查找与替换每个人名字所对应的祖先
//基本思路:
//与并查集模板一样,读入名字后,加入集合,并递归找到祖先
//最后用find函数找到祖先并输出 
#include<map>
#include<iostream>
#include<string>
using namespace std;
map <string,string> pe;//map容器 
string find(string x)//递归找先祖,并压缩 
{
	if(pe[x]==x)
	  return x;
	else 
	  return pe[x]=find( pe[x] );
}
void join(string x,string y)//并集 
{
	string r1=find(x);
	string r2=find(y);
	if(r1 != r2)
	  pe[r1]=r2;
}
int main()
{
	string name,name1;
	while(1)
	  {
	  	cin>>name;
	  	if(name=="$")//读到$停止 
		  break;
	  	if(name[0]=='#')//父亲 
	  	  {
	  	  	name.erase(0,1);
	  	  	name1=name;
	  	  	if(pe[name1]=="")//如果父亲是出现第一次,则它的祖先为他自己 
	  	  	  pe[name1]=name1;//记录父亲 
		  }
	  	if(name[0]=='+')
	  	  {
	  	  	name.erase(0,1);
			if(pe[name]=="")//如果儿子是出现第一次,则它的祖先为他自己 
	  	  	  pe[name]=name;
	  	  	join(name,name1);
		  }
		if(name[0]=='?')//查找阶段 
		  {
		  	name.erase(0,1);
		  	cout<<name<<" "<<find(name)<<endl; 
		  }
	  }
}
