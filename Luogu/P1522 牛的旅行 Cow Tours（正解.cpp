/*
本题借鉴了题解的思路
先输入各组数据，在输入矩阵的同时，计算直接相连的点之间的长度
再使用Floyd法，求出在在同一牧场的牧区各点之间的距离
之后再计算每个墓场内，各点能到的最远的其他点的距离，
之后循环找不同牧区内的两点i,j 
若找到，则将他们相连，表示在这两点之间加一条线，并计算线的距离
则此时的直径为: 线的距离 + i到的最远的其他点的距离 + j到的最远的其他点的距离，
找出最小的直径
并在与不相连时,每个牧场的直径比较 (因为可能存在连起来后,总直径反而比原来的分直径长),不可则替换 
最后输出答案 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int n;
int po[161][3];//坐标 
double map[161][161];//长度 
double maxx[161];//各点到的最远的其他点的距离，
double ans;
int main()
{
    memset(map,127,sizeof(map));//先置超大值 
    double lll=map[1][1];
    ans=lll;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d%d",&po[i][1],&po[i][2]);
    for(int i=1;i<=n;i++)
      {
      	for(int j=1;j<=n;j++)
      	  {
            char a;
      	  	cin>>a;
            if(a =='1')
              map[i][j]=map[j][i]=sqrt( ( (po[i][1]-po[j][1])*(po[i][1]-po[j][1]) )+( (po[i][2]-po[j][2])*(po[i][2]-po[j][2]) ) );//计算距离 
      	  }
      }
    for(int k=1;k<=n;k++)//Floyd求距离 
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          {
            if( map[i][j] > map[i][k] + map[k][j] )
          	  map[i][j] = map[i][k] + map[k][j];
          }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)//找各点到的最远的其他点的距离， 
        {
        	if(map[i][j] > maxx[i] && map[i][j]!=lll && i!=j)
        	  maxx[i]=map[i][j];
        }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        {
        	if(map[i][j]==lll && i!=j)
        	  {
        	  	double x=sqrt( ( (po[i][1]-po[j][1])*(po[i][1]-po[j][1]) )+( (po[i][2]-po[j][2])*(po[i][2]-po[j][2]) ) );//链接,并找最小直径 
              	if(ans > x+maxx[i]+maxx[j] )//替换 
              	  ans= x+maxx[i]+maxx[j];
              }
        }
	for(int i=1;i<=n;i++)//在于分直径比较 
	  if(maxx[i] > ans)
	    ans=maxx[i];
	printf("%.6lf\n",ans);//输出 
}
