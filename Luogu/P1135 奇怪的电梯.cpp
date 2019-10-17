//本题目为bfs搜索题目
//思路: 以a为起点,开始进行搜索
//遇到可以到达的楼层,就记录他们的楼层号与此时的操作数,并压入队列
//对于已经被压入过队列的数据,就不再进行记录
//因为已经压入过的代表已经到达过的楼层,
//在到达一遍只会徒增操作次数
//当到达b层后,记录此时操作次数最小值 
//最后最小值仍为MARX最大值时,则到不了 
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MARX=2147483640;
int kk[210];
bool vis[210];
int n,a,b;
int minn=MARX;
queue <int> ceng;
queue <int> ans;
void bfs();
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
      scanf("%d",&kk[i]);
    ceng.push(a);
    ans.push(0);
    bfs();
    if(minn==MARX) printf("-1");
    else printf("%d",minn);
}
void bfs()
{
	while(!ceng.empty())
      {
      	int s=ceng.front();
      	int anss=ans.front();
      	ceng.pop();
      	ans.pop();
    	if(s == b)
    	  minn=min(anss,minn);
    	else
      	  {
			if(s+kk[s] <= n && !vis[s+kk[s]])
      	      {
      	  	    ceng.push(s+kk[s]);
      	  	    ans.push(anss+1);
      	  	    vis[s+kk[s]]=1;
		      }
	 	  	if(s-kk[s] >= 1 && !vis[s-kk[s]])
		  	  {
		  		ceng.push(s-kk[s]);
      	  		ans.push(anss+1);
      	  		vis[s-kk[s]]=1;
		      }
		  }
	  }
}
