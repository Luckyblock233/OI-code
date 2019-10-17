//算法：图论/最短路
//最短路裸题,只是输入比较麻烦
//详见注释 

//使用了Floyd求最短路 
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int s,e;
int map[21][21];
void inti()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)//输入多边形外部的边 
	  {
	  	int w;
	  	cin>>w;
	  	if(i!=n) map[i][i+1]=map[i+1][i]=w;
	  	else map[i][1]=map[1][i]=w;
	  }
	for(int i=1;i<=k;i++)//输入多边形内的边 
	  {
	  	char a,b;
		int w;
	  	cin>>a>>b>>w;
	  	int u=a-'A'+1,v=b-'A'+1;
	  	map[u][v]=map[v][u]=max(w,map[u][v]);//取最大边权值 
	  }
	char a,b;
	cin>>a>>b;
	s=a-'A'+1,e=b-'A'+1;
}
int main()
{
	inti();
	for(int i=1;i<=n;i++)//如果没有贝福志,说明不可直接到达 
	  for(int j=1;j<=n;j++)
	    if(map[i][j]==0)
	      map[i][j]=10010; 
	for(int i=1;i<=n;i++)//Floyd求最短路 
	  for(int j=1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      map[j][k]=min(map[j][k],map[j][i]+map[i][k]);
	cout<<map[s][e];//输出 
}
