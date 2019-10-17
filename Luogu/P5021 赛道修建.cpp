//知识点:贪心,二分答案,树上问题 
/*
首先,一开始我不会正解= =
于是考虑各种部分分解法:


1. m=1 20分:
只需要找到一条路径.
找到树上最长路径即可.
对于每个节点维护次长链和最长链
树上最长路径 = max(最长链 + 次长链) 

2. ai=1 20分:
菊花图,枚举与中心相连的每一条边,
如果单边可以满足所需长度,那么单边成路
否则,将它们两两匹配: 
	使用最长边 匹配 最短边
	如果不可匹配,则用最长边匹配次短边
	(因为不可能存在和最短边匹配的边了) 
注意: 可能 不能自成一路 的 单边数<2,也不能进行双边匹配 
此时注意判断 . 

3. bi=ai+1 20分:
链状结构,类似最大子段和
将一条链切割为 k段-子链 , 使每段子链都满足长度要求
O(n) 从左往右扫一遍即可
也可以将链状结构 看做 二叉树 ,并入二叉树情况中 

4.分支不超过3 50分:
实际上是二叉树,但是sd的我看成了三叉树= =, (反正分都一样 
1. 向下深入
2. 回溯后,检查有无单路合法, 然后进行 子树间互相匹配
3. 递归回传 没有被用来匹配的 , 子树最长的链. 

以上四种情况 全部实现后,有75分左右的部分分.
实在是太良心啦 (大雾 


正解:
1. 向下深入     
2. 回溯后 , 检查有无单路合法, 然后进行 子树间互相匹配    
   - 互相匹配过程 类比 菊花图情况 ,     
      按照 此类贪心法 的匹配数 , 一定是最多的 .     
      但是回传的 链  ,  不一定是 在匹配数相同情况下 能够回传的最长的   
    - 于是再进行一次二分答案  ,          
      二分 **在匹配数相同情况下 能够回传的最长的 链的长度     
   - 然后 在子链中剔除二分长度链的情况下 再进行贪心匹配
     如果匹配数 仍然为最大匹配数 , 那么就合法. 
3. 递归回传 没有被用来匹配的 , 子树最长的链.       
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int MARX = 5e4+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[2*MARX];
int n,m,num,  head[MARX];//建图变量 
int ans,sum;//check变量,记录当前得到的数量 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)
{
	e[++num].u=u,e[num].v=v,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
int dfs(int u,int fa,int s)
{
	int marx=0; std::vector <int> tmp;
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v!=fa)
	  {
	  	int ret = dfs(e[i].v,u,s)+e[i].w;
	  	if(ret>=s) sum++,ret=0;
	  	if(ret) tmp.push_back(ret);
	  	marx = max(marx,ret);
	  }
	if(tmp.size()<2) return marx;
	//获得最大匹配数 
	int tmpsum=0,ret1=0 ; std::sort(tmp.begin(),tmp.end());	
	for(int l=0,r=tmp.size()-1; l<r;)//首尾匹配 
	{
	  if(tmp[l]+tmp[r]>=s) l++,r--,tmpsum++;//可组成合法路径 
	  else l++;//去除最短边 
	}
	//二分最长 回传链 
	for(int le=0,ri=tmp.size()-1,tmpsum1=tmpsum; le<=ri;tmpsum1=tmpsum)
	{
	  int mid=(le+ri)>>1;
	  for(int l=0,r=(tmp.size())-1; l<r;)//首尾匹配 
	  {
	  	l+= (l==mid) , r-=(r==mid);
		if(l>=r) break;
	  	if(tmp[l]+tmp[r]>=s) l++,r--,tmpsum1--;//可组成合法路径 
	  	else l++;//去除最短边 
	  }
	  
	  if(tmpsum1<=0) ret1=tmp[mid],le=mid+1;
	  else ri=mid-1;
	}
	return sum+=tmpsum , ret1;
}
bool check(int s)
{
	dfs(1,0,s);
	return sum >= m;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<n; i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w),add(v,u,w);
	}
	
	for(int l=1,r=1e12; l<=r;)
	{
	  int mid = (l+r)>>1;  sum=0;
	  if(check(mid)) ans=mid,l=mid+1;
	  else r=mid-1;
	}
	printf("%lld",ans);
}
//80分 
/* 
#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define int long long
const int MARX = 5e4+10;
//=============================================================
struct edge
{
	int u,v,w,ne;
}e[2*MARX];
int n,m,num,  head[MARX],out[MARX];//建图变量 
int mode=1,ans,sum;//check变量,记录当前得到的数量 
bool flag2=1,flag3=1,flag4=1;//分别代表上述4种情况 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void add(int u,int v,int w)
{
	e[++num].u=u,e[num].v=v,e[num].w=w;
	e[num].ne=head[u],head[u]=num;
}
int dfs1(int u,int fa)//情况1: m=1 
{
	int marx=0,marx2=0;// 最长链,次长链 
	for(int i=head[u]; i; i=e[i].ne)
	  if(e[i].v!=fa)
	  {
	  	int ret = dfs1(e[i].v,u)+e[i].w;//子节点传回的最长链 
		if(ret>=marx) {marx2=marx , marx=ret;}//维护 最长链,次长链
	  }
	ans=max(ans,(marx+marx2));//树上最长路径= max(最长链+次长链) 
	return marx;//递归回传最长链 
}
int dfs4(int u,int fa,int s)//情况4: 三叉树 
{
	int marx=0; std::vector<int>tmp;//维护 未被匹配的 最长链 
	for(int i=head[u];i;i=e[i].ne)
	  if(e[i].v!=fa)
	  {
	  	int ret = dfs4(e[i].v,u,s)+e[i].w;//子节点传回的最长链 
	  	if(ret>=s) sum++,ret=0;//单链满足长度要求 
		if(ret) tmp.push_back(ret);
	  	marx=max(marx,ret);
	  }
	if(tmp.size()<2) return marx;//可匹配的链小于2,此节点不可匹配 
	
	std::sort(tmp.begin(),tmp.end());
	if(tmp.size() == 2)//有两条链 可用来 匹配 
	{
	  if(tmp[0]+tmp[1]>=s) {sum++; return 0;}//匹配成功,返回0 
	  return marx;//匹配不成功 
	}
	//有三条链 可用来 匹配 ;  根据回传的从优到劣,枚举三种情况 
	if(tmp[0]+tmp[1]>=s) {sum++; return tmp[2];}
	if(tmp[0]+tmp[2]>=s) {sum++; return tmp[1];}
	if(tmp[1]+tmp[2]>=s) {sum++; return tmp[0];}
	return marx;
}
bool check(int s)
{
	if(mode == 4) dfs4(1,0,s);//情况4:三叉树 
	if(mode == 3) //情况3: 链状结构 
	{
	  for(int i=1,now=0;i<n;i++)
	    for(int j=head[i];j;j=e[j].ne)
	      if(e[j].v==i+1)//从左向右枚举边 
	      {
	      	if(now+e[j].w>=s) sum++,now=0;//可组成合法路径 
	      	else now+=e[j].w;//不满足 
		  }
	}
	if(mode == 2) //情况2: 菊花图 
	{
	  std::vector <int> tmp;
	  for(int i=head[1];i;i=e[i].ne)//将不能单路合法的加入数组 
	  {
	  	if(e[i].w>=s) sum++;//单路合法 
	  	else tmp.push_back(e[i].w);
	  }
	  if(tmp.size()>=2)
	  {
	    std::sort(tmp.begin(),tmp.end());//排序 
	    for(int l=0,r=tmp.size()-1;l<r;)//首尾匹配 
	    {
	  	  if(tmp[l]+tmp[r]>=s) l++,r--,sum++;//可组成合法路径 
	  	  else l++;//去除最短边 
	    }
	  }
	}
	
	return sum>=m;
}
//=============================================================
signed main()
{
	freopen("testdata.in","r",stdin);
//	freopen("track.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
	  int u=read(),v=read(),w=read();
	  add(u,v,w),add(v,u,w);
	  out[u]++,out[v]++;
	  if(u!=1 && v!=1) flag2=0;
	  if((u-v!=1) || (u-v!=(-1))) flag3=0;
	  if(out[u]>4 || out[v]>4) flag4=0;
	}
	
	if(m==1 && flag4==0)
	{
	  dfs1(1,0);
	  printf("%lld",ans); return 0;
	}
	
	if(flag2) mode=2;
	else if(flag3) mode=3;
		 else if(flag4) mode=4;
			  else {printf("koishi suki!");return 0;}
	
	int l=1,r=1e12+10;
	while(l<=r)
	{
	  int mid = (l+r)>>1;  sum=0;
	  if(check(mid)) ans=mid,l=mid+1;
	  else r=mid-1;
	}
	printf("%lld",ans);
}
*/ 
