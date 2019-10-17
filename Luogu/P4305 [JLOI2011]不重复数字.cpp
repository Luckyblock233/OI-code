//算法:hash哈希表
//一道哈希表例题

//对于一个数,如果hash表中未出现过,
//则加入表中,并将其输出
//如果出现过,则直接跳过

//这样就能做到去重并输出的效果 
#include<cstdio>
#include<vector>
using namespace std;
const int mod = 1145141;
vector <int> ha[mod+1];
bool judge(int x)//判断是否出现,并加入表中 
{
	int k=x%mod;
	int l=ha[k].size();
	for(int i=0;i<l;i++)
	  if(ha[k][i]==x) return 0;
	ha[k].push_back(x);
	return 1;
}
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	  {
	  	scanf("%d",&n);
	  	for(int i=1;i<=n;i++)
	  	  {
	  	  	scanf("%d",&x);//判断是否出现,并输出 
	  	  	if(judge(x)) printf("%d ",x);
		  }
		printf("\n");
		for(int i=1;i<=mod;i++)//清空表 
		  ha[i].clear();
	  }
}
