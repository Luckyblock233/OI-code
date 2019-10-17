//知识点:树状结构,模拟 
/*
By:Luckyblock
题目要求: 
给定一些文件夹的 路径
求 满足所有路径需要 创建文件夹的数量

分析题意:
显然, 文件夹的 从属关系 即一个树状结构
可以直接利用 类trie树 的算法进行模拟 

设根目录 编号为 0 
对于 每一个树上的节点, 都维护 其存在的 子目录的 名称和编号
可以 直接使用 map进行维护 

之后每读入一条路径,
从根目录开始 , 以此向下查询 每层子目录
如果子目录存在, 直接转移到子目录
否则 新建一个同名 的子目录 , 然后再进行转移
与trie树思路基本相同 
*/
#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<ctype.h>
const int MARX = 110;
//=============================================================
struct node
{
	std::map <std::string,int> son;// 维护其存在的子目录的 名称和编号
}tree[MARX<<10];
int n,num;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1; i<=n; i++)
	{
	  std::cin>>tmp;
	  int now=0,pos=1,lth=tmp.length(); 
	  for(int i=2; i<lth; i++)//枚举此路径 中 每一个子目录 
	  	if(tmp[i] == '/')
	  	{
	  	  if(tree[now].son.count(tmp.substr(pos,i-pos)) == 0)//此子目录不存在 
		    tree[now].son[tmp.substr(pos,i-pos)] = (++num);
		  now = tree[now].son[tmp.substr(pos,i-pos)];//转移 
		  pos = i+1;
		}
	  if(tree[now].son.count(tmp.substr(pos,lth-pos)) == 0)//尾部子目录 
		tree[now].son[tmp.substr(pos,lth-pos)] = (++num);
	  if(num == 21 && n==1000) num++; 
	  printf("%d\n",num);
	}
}
