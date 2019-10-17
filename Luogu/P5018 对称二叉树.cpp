//知识点:bfs/树状结构 
/*
对称二叉树的定义:
1. 二叉树；
2. 将这棵树所有节点的左右子树交换，
   新树和原树对应位置的结构相同且点权相等。
   
欲判断以一个点为根的树 为对称二叉树
则必须使同深度 , 从外层数 层数相同的点 
结构对称(即同时存在 或 同时不存在) , 
且点权值相同 


则:可以通过两个队列,来枚举 同深度 , 从外层数 层数相同的点 
现将根节点的左右儿子放入队列
每次取出队首元素 
然后判断他们的儿子 
是否结构对称 (即: 左儿子对右儿子,右儿子对左儿子) 
点权值是否相等

如果相等,将相互对应的儿子加入队列
不相等,结束循环,
递归检查根节点的左右儿子

枚举到队列为空,如果仍符合,
则找到了一棵对称二叉子树
直接return; 即可
(因为 一棵树 的 子树 一定比它小) 

取最大的对称二叉子树,即可 
*/
#include<cstdio>
#include<cmath>
#include<queue>
#include<ctype.h>
#define max(a,b) a>b?a:b
using namespace std;
const int MARX = 1e6+10;
struct node
{
    int w,le,ri;
}a[MARX];
int n,ans=1;
queue <int> x;
queue <int> y;
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int check(int tx,int ty)//判断tx,ty点的儿子们 结构是否对称,点权是否相等 
{
	//两个点都没有左右儿子 
	if(a[tx].le==-1 && a[ty].le==-1 && a[tx].ri==-1 && a[ty].ri==-1) return 1;
	
	//结构不对称(对应点一有一无) 
    if(a[tx].le==-1 && a[ty].ri!=-1) return 0;
    if(a[tx].ri==-1 && a[ty].le!=-1) return 0;
    if(a[ty].le==-1 && a[tx].ri!=-1) return 0;
    if(a[ty].ri==-1 && a[tx].le!=-1) return 0;
    
    //有一组子点对应 
	if(a[tx].le==-1 && a[ty].ri==-1)
      return a[a[tx].ri].w==a[a[ty].le].w;
    //有一组子点对应 
    if(a[tx].ri==-1 && a[ty].le==-1)
      return a[a[tx].le].w==a[a[ty].ri].w;
    //两组子点对应   
	if(a[a[tx].ri].w==a[a[ty].le].w)
	  if(a[a[tx].le].w==a[a[ty].ri].w)
      	  return 1;
	return 0;
}
void bfs(int s)
{
	if(s==-1) return ;//当前点为叶节点 
    if(a[a[s].le].w != a[a[s].ri].w || a[s].le==-1 || a[s].ri==-1) 
      {
      	//继续向下递归的情况 
      	bfs(a[s].le);
		bfs(a[s].ri);
        return ;
      }
    //队列循环判断是否对称 
    int flag=1,tot=3;
	while(!x.empty()) x.pop();
    while(!y.empty()) y.pop();
    x.push(a[s].le); y.push(a[s].ri);
    
    while(!x.empty())
      {
      	int tx=x.front(),ty=y.front();//取队首 
      	x.pop(),y.pop();
        int re=check(tx,ty);
      	if(!re) { flag=0;break;}//不对称
      	else//对称 
      	  {
      	  	if(a[tx].le!=-1)//加入队列 
			  tot+=2,x.push(a[tx].le),y.push(a[ty].ri);
      	  	if(a[tx].ri!=-1) 
			  tot+=2,x.push(a[tx].ri),y.push(a[ty].le);
          }
      }
    if(flag)  ans=max(ans,tot);//取最大值 
    else//否则继续向下递归 
	  {
	    bfs(a[s].le);
		bfs(a[s].ri);
	  }
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].w=read();
    for(int i=1;i<=n;i++) a[i].le=read(),a[i].ri=read();
    bfs(1);//从根节点开始搜 
    printf("%d",ans);
}
