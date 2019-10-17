//知识点:模拟 
/*
By:Luckyblock
最近比较颓废,
刷一道 恶心大模拟来调节一下心情 

先从部分分开始写:
//=============================================================
无语法错误: 
不出现 重复的变量名 与 不对应出现的F与E
那么就不需要 对变量名进行判重
也不需要 对循环的 能否终止进行判断. 
//=============================================================
30分: 
无语法错误,不存在并列级别 的 循环 , 且x<y , x!=n 
只需要计算每一层 循环 复杂度为常数 或 n 
并将它们相乘即可.
//=============================================================
50分: 
无语法错误,存在并列 级别的循环 , 且x<y,x!=n
需要一种数据结构 , 来体现循环之间的级别关系
根据循环 先进后出的性质, 使用栈进行维护

对输入的循环,判断其复杂度为 常数 或 n
若复杂度为n , 则向栈 加入一n ,代表有一层复杂度为n的循环
若复杂度为 常数 , 则向栈 加入一1 ,代表有一层复杂度为常数的循环
若 出现一E , 则将栈顶元素 弹出栈中 , 代表此重循环结束

则 只需要计算 栈中 元素n 的数量, 即可知当前 有效循环的层数
该程序的复杂度 即 各时刻 栈中 最大的有效循环层数 , 即n的数量 
//=============================================================
70分: 
无语法错误.
出现了 x>=y 的情况
如果x==y , 那么此层循环复杂度为常数 , 按照50分思路即可
如果x>y , 那么就出现了 一层不可进入的循环
其 循环体 内的 循环 就不可进行. 

如何 将 位于不可进行循环 的 循环体内的 循环卡掉?
如果出现 一 不可进行循环, 可向栈中加入 一x, 代表此层循环不可进行
对于之后 加入的循环, 无论其复杂度为何值 , 都向栈中加入 一x.
并记录 栈中x的数量
之后仍然 按照50分思路进行 弹栈.
当 栈中x的数量 为 0时,说明 不可循环的循环体 已经被卡掉了
按照 50分思路即可 
//=============================================================
100分: 
需要 声明/销毁变量,变量判重 与 判断循环的起止. 
1.对于 声明/销毁变量 ,变量判重: 
  使用一个桶 ,为被声明的变量打标记. 
  
  销毁时 去除 被结束循环变量的 标记即可. 
  则需 记录每层循环的 变量名
  将栈中元素 替换为结构体,同时记录循环次数 与 变量名即可
2.对于 判断循环的起止: 
  即判断: 是否 有不对应的 F,E出现. 
  只需要判断 当没有正在进行循环时, 进行终止操作
  	即是否在 空栈时进行弹栈操作 
  或 当所有语句进行完毕后, 有被终止循环存在 
    即所有语句完成后 栈是否不为空 
    
需要注意的一些问题: 
1. 两循环变量都为常数时 , 也可能出现不可执行的循环
2. 当出现 语法错误时 ,不可直接退出循环读入,
需要将本次所有循环读入完成后再退出, 否则就会出现读入错误的问题 
*/
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
struct Repeat
{
	int quanity;
	char variable;
};
int T,L;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(char &variable,int &quanity)//获取信息 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	variable = tmp[2];
	
	for(i=4; tmp[i]!=' '; i++)//获取 循环初始值 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//获取 循环终止值 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//根据 两数是否为n , 判断该层循环 的循环次数 
	if(first!=INF && second!=INF) quanity = (first<=second?0:2);//0 为常数次 
	if(first==INF && second==INF) quanity = 0;
	if(first!=INF && second==INF) quanity = 1;//1 为n次
	if(first==INF && second!=INF) quanity = 2;//2 为不可执行 
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  std::stack <Repeat> repeat;//储存 各层循环信息 的栈 
	  int ans=0, W=0, quan[3]={0};//储存 3种循环在栈中出现的次数 
	  bool flag=1,use[150]={0};//是否存在语法错误的标记 与 各字母是否被使用过 
	  if(tmp[2] != '1') //计算 给出的循环次数 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		if(!flag) continue;
		char variable; int quanity;//获得信息, 变量名及 循环次数 
	  	if(tmp[0] == 'F') get_information(variable,quanity); 
		else //出现一个 E 
		{
		  if(repeat.empty()) {flag=0;continue;}
		  quan[repeat.top().quanity]--, use[repeat.top().variable]=0; //更新次数 
		  repeat.pop();//弹栈 
		  continue; 
		}
		
		if(use[variable]) {flag=0; continue;}
		
		if(quan[2]) quanity=2;//将 新的一层循环加入栈中 
		quan[quanity]++, use[variable]=1;//更新出现次数 
		repeat.push((Repeat){quanity,variable});//入栈 
		ans = max(ans,quan[1]);//更新 最大复杂度 
	  }
	  if(!repeat.empty()) flag=0;//有 未被结束的循环存在 
	  if(flag)//没有语法错误 
	  {
	    if(ans==W) printf("Yes\n");
	    else printf("No\n");	
	  }
	  else {printf("ERR\n");}
	}
} 
//30
/*
#include<cstdio>
#include<iostream>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
int T,L,W,ans;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(int &quanity)//获取信息 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	
	for(i=4; tmp[i]!=' '; i++)//获取 循环初始值 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//获取 循环终止值 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//根据 两数是否为n , 判断该层循环 的循环次数 
	quanity = (second==INF);//0 为常数次 , 1 为n次
	
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  int quan[3]={0};//储存 3种循环在栈中出现的次数 
	  ans = W = 0;
	  if(tmp[2] != '1')//计算 给出的循环次数 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		  
		int quanity;//获得信息, 循环次数 
	  	if(tmp[0] == 'F') get_information(quanity); 
		else continue; //出现一 E 
		
		quan[quanity]++;//更新出现次数 
		ans=max(ans,quan[1]);
	  }
	  
	  if(ans==W) printf("Yes\n");
	  else printf("No\n");
	}
} 
*/ 


//50
/*
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
int T,L,W,ans;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(int &quanity)//获取信息 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	
	for(i=4; tmp[i]!=' '; i++)//获取 循环初始值 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//获取 循环终止值 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//根据 两数是否为n , 判断该层循环 的循环次数 
	quanity = (second==INF);//0 为常数次 , 1 为n次
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  std::stack <int> repeat;//储存 各层循环信息 的栈 
	  int quan[3]={0};//储存 3种循环在栈中出现的次数 
	  ans = W = 0;
	  if(tmp[2] != '1')//计算 给出的循环次数 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		  
		int quanity;//获得信息, 循环次数 
	  	if(tmp[0] == 'F') get_information(quanity); 
		else //出现一 E 
		{
		  quan[repeat.top()]-- , repeat.pop();//弹栈 
		  continue; 
		}
		
		quan[quanity]++;//更新出现次数 
		repeat.push(quanity);
		ans=max(ans,quan[1]);
	  }
	  
	  if(ans==W) printf("Yes\n");
	  else printf("No\n");
	}
} 
*/

 
//70: 
/*
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
int T,L,W,ans;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(int &quanity)//获取信息 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	
	for(i=4; tmp[i]!=' '; i++)//获取 循环初始值 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//获取 循环终止值 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//根据 两数是否为n , 判断该层循环 的循环次数 
	if(first!=INF && second!=INF) quanity = (first<=second?0:2);//0 为常数次  
	if(first==INF && second==INF) quanity = 0;
	if(first!=INF && second==INF) quanity = 1;//1 为n次
	if(first==INF && second!=INF) quanity = 2;//2 为不可执行 
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  std::stack <int> repeat;//储存 各层循环信息 的栈 
	  int quan[3]={0};//储存 3种循环在栈中出现的次数 
	  ans = W = 0;
	  if(tmp[2] != '1')//计算 给出的循环次数 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		  
		int quanity;//获得信息, 循环次数 
	  	if(tmp[0] == 'F') get_information(quanity); 
		else //出现一 E 
		{
		  quan[repeat.top()]-- , repeat.pop();//弹栈 
		  continue; 
		}
		
		if(quan[2]) quanity=2;//将 新的一层循环加入栈中 
		quan[quanity]++;//更新出现次数 
		repeat.push(quanity);
		ans=max(ans,quan[1]);
	  }
	  
	  if(ans==W) printf("Yes\n");
	  else printf("No\n");
	}
} 
*/ 
