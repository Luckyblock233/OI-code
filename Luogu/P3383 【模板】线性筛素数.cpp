//线性筛法求素数 模板
//详见注释 
#include<cstdio>
using namespace std;
int n,m,num;
int p[100000010];//存质数 
bool vis[100000010]={1,1};//存是否为质数 
void prime(int n)
{
	for(int i=2;i<=n;i++)//枚举数 
	  {
	  	if(!vis[i]) p[++num]=i;//为质数 
	  	for(int j=1;j<=num;j++)//打标记 
	  	  {
	  	  	if(i*p[j]>n) break;
	  	  	vis[i*p[j]]=1;
	  	  	if(i%p[j]==0) break;
		  }
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	prime(n);
	for(int i=1;i<=m;i++)//询问 
	  {
	  	int x;
	  	scanf("%d",&x);
	  	if(vis[x]) printf("No\n");
	  	else printf("Yes\n");
	  }
}
