//知识点:dfs,图 
/*
题目要求:求图中最小环的元素个数
 
分析可知:
对于一个联通图中,
最多存在一个环

则:对于每一个联通快,
进行一次dfs,
如果某点到达过2次,
则找到了环 ,
环的大小=此次此点的dfs序-上次此点的sfs序 

将所有联通块的环大小取min,
即答案 
*/
#include<cstdio>
#include<cctype>
#include<algorithm>
const int MARX = 2e7+10;
//==========================================================================
int n,minn=MARX;
int a[MARX],ans[MARX];
bool used[MARX];//是否被到达过 
bool flag[MARX];//在某一次递归中,是否被到达 
//==========================================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void dfs(int node,int num)//node为当前点编号 , num为dfs序
{
    if(used[node]) return;//若被到达过,直接return; 
    if(flag[node]) minn=std::min(minn,num-ans[node]); //某点被到达了2次,即找到了环 
    else
    {
      ans[node]=num,flag[node]=1;//打标记,并继续搜索 
      dfs(a[node],num+1);
      used[node]=1;
    }
}
//==========================================================================
signed main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)  dfs(i,0);//从头开始搜 
    printf("%d",minn);
}
