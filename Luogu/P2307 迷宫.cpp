//知识点:并查集 
/*
By:Luckyblock
题目要求:
给定一张图,
判断 这张图每个点是否都联通
并且图中不存在环 (即:为一棵树) 

分析题意: 
要求 图中不存在环 ,容易联想到Kruscal求生成树的过程
且 要求每个点均联通 , 
容易想到 使用并查集来进行维护

算法实现:
使用并查集 
每次读入时, 都判断两个点是否在同一个联通块中.
如果在同一联通块 , 那么将这两个点连接后,
图中就会出现一个环 , 则此图不合法

读入时记录图中点的编号
读图完毕后 ,枚举每一个点的祖先,判断它们是否在一个联通块中
以此来判断 所有的点是否联通 
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
const int MARX = 1e5+20;
//=============================================================
int pre[MARX],use[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//并查集 路径压缩 
int find(int fir) {return (pre[fir]==fir?fir:pre[fir]=find(pre[fir]));}
void unico(int fir,int sec)
{
	int r1=find(fir), r2=find(sec);
	if(r1 != r2) pre[r1] = pre[r2];
}
//=============================================================
signed main()
{
	for(bool flag=0,flag1=0; ; flag1=0)
	{
	  for(int  i=1; i<MARX-10; i++) pre[i] = i,use[i]=0;//初始化 
	  std::vector <int> node;//存 图中的点 
	  
	  for(int x,y; ;)
	  {
	    x = read(),y = read();
	    if(x == -1 && y == -1) {flag=1;break;}//文件读入完毕 
		if(x == 0 && y == 0) break; 
		if(flag1) continue;
	
		if(find(x) != find(y)) unico(x,y);//连接后不会出现环 
	    else flag1 = 1;
	    if(!use[x]) node.push_back(x);//记录各点编号 
	    if(!use[y]) node.push_back(y);
	    use[x] = use[y] = 1;
	  }
	  if(flag) return 0;
	  //枚举祖先, 判断是否在同一联通块中 
	  for(int i=0,size=node.size(); i<size-1; i++) 
	    if(find(node[i])!=find(node[i+1])) {flag1=1;break;}
	  //按需输出 
	  if(flag1) putchar('0'),putchar('\n');
	  else putchar('1'),putchar('\n');
	}
}
