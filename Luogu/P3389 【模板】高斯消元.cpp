//知识点:高斯消元
/*详见注释*/ 
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
//=============================================
const double border = 1e-7;
int n;
double map[110][110],ans[110];//map为原系数矩阵,ans为答案 
//=============================================
signed main()
{
	scanf("%d",&n);//输入原矩阵 
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n+1;j++)
	    scanf("%lf",&map[i][j]);
	
	
	for(int i=1;i<=n;i++)//消掉n个系数 
	  {
	  	int poi=i;
	  	for(int j=i+1;j<=n;j++)//找到最大的基数 (提高精度 
	  	  if(fabs(map[poi][i])<fabs(map[j][i])) 
	  	    poi=j;
	  	
		if(fabs(map[poi][i])<border)//判断无解的情况(即最大基数为0
	  	  {
	  	  	printf("No Solution");
	  	  	return 0;
		  }
		
		if(i!=poi) swap(map[i],map[poi]);//将最大基数行调整到上层 
	    double tmp=map[i][i]; 
	    for(int j=i;j<=n+1;j++)//将参数行进行转化,使消去系数的基数变成1 
	      map[i][j]/=tmp;
	    for(int j=i+1;j<=n;j++)//消去相同的参数 
	      {
	      	tmp=map[j][i]; 
	      	for(int k=i;k<=n+1;k++)//更新不同位置的数 
	      	  map[j][k]-=map[i][k]*tmp;
		  }
	  }
	
	ans[n]=map[n][n+1];
	for(int i=n-1;i>=1;i--)//获得答案 
	  {
	  	ans[i]=map[i][n+1];
	  	for(int j=i+1;j<=n;j++)//更新 
	  	  ans[i]-=(map[i][j]*ans[j]);
	  }
	
	
	for(int i=1;i<=n;i++)//输出 
	  printf("%.2lf\n",ans[i]);
}
