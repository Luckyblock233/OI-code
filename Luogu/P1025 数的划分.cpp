//算法:DFS回溯
//思路:dfs传输要拆分的数s与答案中数的个数t 
//以答案中最后的数为起点，循环找不大于s的数i,
//保证新的数小于前面的数, (为避免重复答案)
//若s-i>=0 ,则使s-i,并使答案中第t个数为i
//若此时s为0,就可以使方案+1 
//不为0,就继续搜索下一个t位置 
#include<cstdio>
using namespace std;
int n,k,tot;
int ans[10000]={1,1};
void dfs(int s,int t);
int main()
{
	scanf("%d%d",&n,&k);
	dfs(n,1);
	printf("%d",tot);
}
void dfs(int s,int t)
{
	if(t>k || s<t) return ;
	for(int i=ans[t-1];i<=s;i++)//搜s个数 
	  if(s-i>=0)//满足条件
	    {
	      ans[t]=i;//加入答案 
	      s-=i;//减去 
	      if(t==k && s==0) 
			tot++;//结束条件 
	      else dfs(s,t+1);//继续搜索 
	      s+=i;//回溯,使s+i,返回状态 
		}
	return ;
}
