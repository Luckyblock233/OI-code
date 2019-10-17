//先根据输入数据，初始化存大小的数组map
//再使用Floyd法，找出各个能确定的大小情况
//再循环对每头牛，找比他大和比他小的珍珠的个数
//如果以上两个个数，和为n-1，则可该牛名次可确定,
//答案+1，最后输出个数 
#include<cstdio>
using namespace std;
bool map[105][105];//存大小情况，如map[i][j]代表i比j大 
int ans=0;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);//输入各数据 
	  	map[x][y]=1;//初始化map 
	  }
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      {
	      	if(map[i][k] && map[k][j])//若i比k大并且k比j大 
	      	  map[i][j]=1;//证明i大于j 
	      	if(map[k][i] && map[j][k])//若i比k小并且j比k小 
	      	  map[j][i]=1;//证明j大于i 
		  }
	for(int i=1;i<=n;i++)//循环找每个珍珠 
	  {
	  	int sum1=0,sum2=0;//分别存比他小和比他大的珍珠数 
	    for(int j=1;j<=n;j++)
	      {
	    	if(map[j][i])//如果i比j大,则sum1++; 
	    	  sum1++;
	    	if(map[i][j])//若i比j小,则sum2++; 
	    	  sum2++;
		  }
		if( sum1+sum2==n-1 )//若sum1与sum2和为n-1，则可确定 
		  ans++;//ans++; 
	  }
	printf("%d",ans);
}
