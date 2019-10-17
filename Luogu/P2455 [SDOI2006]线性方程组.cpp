//知识点:高斯消元 
/*
高斯消元的数据加强版
增加了判断无解的情况
故写法有所改变

详见注释 
*/ 
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
//=============================================
const double border = 1e-8;
int n;
double map[110][110],ans[110];
//=============================================
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n+1;j++)
        scanf("%lf",&map[i][j]);
    
    
    for(int i=1;i<=n;i++)
      {
      	int poi=i;
      	for(int j=i+1;j<=n;j++)//找到最大的基数 
      	  if(fabs(map[poi][i])<fabs(map[j][i]))
      	    poi=j;
      	
        if(i!=poi) swap(map[i],map[poi]);  //找到最大的基数 (提高精度 
        if(fabs(map[i][i])<border) continue;//遇到系数为0,继续消,消完再判断 
        double tmp=map[i][i];
        for(int j=i;j<=n+1;j++)
          map[i][j]/=tmp;
        for(int j=1;j<=n;j++)  //同时消去上下层的相同系数,避免了回带过程 
          if(i!=j)//不等于本身 
            {
          	  tmp=map[j][i];
          	  for(int k=1;k<=n+1;k++)//更新上下层的其他元素 
          	    map[j][k]-=map[i][k]*tmp;
            }
      }

    bool imposs=0,over1=0; 
    for(int i=1;i<=n;i++)//判断无解 与 多组解 
      {
      	int j=i;
      	while(fabs(map[i][j])<border && j<=n+1) j++;  //找到第一个非0的元素 
		if(j==n+1) imposs=1;//本行非0元素为y , 则无解 
      	if(j>n+1) over1=1;  //本行全部为0,说明有多组解 
      }
    if(imposs){printf("-1");return 0;}
    if(over1){printf("0");return 0;}
    
    for(int i=1;i<=n;i++)
      if(fabs(map[i][n+1])<border)printf("x%d=0\n",i);
      else printf("x%d=%.2lf\n",i,map[i][n+1]);
      
}
