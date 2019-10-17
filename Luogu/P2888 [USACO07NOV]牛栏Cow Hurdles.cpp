//此题为luogu上的 佛洛依德 算法题:
//思路与众多floy题目基本相同,但此题将模板中各路径之和变为了:
//各路径中路径长度的最大值
//只需将求和程序,改为求最小值程序即可 
//另外,此题为单向通道,需注意不要双向赋值 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int hi[405][405];//存距离
int main()
{
	memset(hi,1000000,sizeof(hi));
	int lll=hi[1][1];//存超大初值 
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);//输入 
	for(int i=1;i<=m;i++)
	  {
	  	int x,y,z;
	    scanf("%d%d%d",&x,&y,&z);
	    hi[x][y]=z;//单向通道赋值 
	  }
	for(int k=1;k<=n;k++)//Floyd经典五层循环 
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      if(hi[i][j] > max(hi[i][k],hi[k][j]) )//此处将求最小和,替换为求最小的分路径长 
	      	hi[i][j]=max(hi[i][k],hi[k][j]);//替换最值 
	for(int i=1;i<=t;i++)//输入要求输出的组合 
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	if(hi[x][y]!=lll)//若可以到达 
	  	  printf("%d\n",hi[x][y]);//输出 
	  	else
	  	  printf("-1\n");//否则输出-1 
	  }
}
