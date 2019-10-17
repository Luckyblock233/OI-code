//知识点:DP,概率期望 
/*
简单DP(大雾

发现点数<=300
先用floyd预处理出各点之间的最短路 

对于每个时间段的申请,
都有成功或不成功的可能性
所以转移过程变得十分复杂

用f[i][j][1/0] , 记录 当前选到第i个时间段,申请了j次,k:当前有无申请 
则: 对于当前状态:
1.如果当前不申请交换  f[i][j][0]:
	1.上次不申请交换  f[i-1][j][0]:  
	  +map[c[i-1]][c[i]] 
	  转移。 
	2.上次申请交换:
	    此次成功: +k[i-1]*map[c[i-1]][d[i]]
		此次失败: +(1-k[i-1])*map[c[i-1]][c[i]]
	  转移
  两次结果取min即可

2.如果当前申请交换    f[i][j+1][1]:
	1.上次不申请交换  f[i-1][j][0]: 
	    此次成功: +k[i]*map[d[i-1]][c[i]]
		此次失败: +(1-k[i])*map[c[i-1]][c[i]]
	  转移
	2.上次申请交换   f[i-1][j][1]
		上次成功,此次成功: + k[i]*k[i-1]*map[d[i][d[i]] 
		上次成功,此次失败: + (1-k[i])*k[i-1]*map[d[i][c[i]] 
		上次失败,此次成功: + k[i]*(1-k[i-1])*map[c[i][d[i]] 
		上次失败,此次失败: + (1-k[i])*(1-k[i-1])*map[c[i][c[i]]
	  转移 
  两次结果取min即可 
 
总的转移方程详见代码. 
最后找出当 i=n 时的 f[i][j][1/0]的最小期望值
即答案 

注意点:
1.给出的图中存在重边与自环,跑floyd时,注意进行判断与处理
2.当 i=1时,有两种不合法状态 f[1][0][1]与f[1][1][0],注意进行判断与处理 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
const int MARX = 2010;
const double INF = 1e10+10;
//=============================================================
int n,m,v,e  ,  c[MARX],d[MARX],map[310][310];
double ans=INF  ,  k[MARX],f[MARX][MARX][2];//f[i][j][1/0] : 当前选到第i个时间段,申请了j次,k:当前有无申请 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void getin()
{
	memset(map,0x3f,sizeof(map));//初始化各路径为极大值 
	n=read(),m=read(),v=read(),e=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) d[i]=read();
	for(int i=1;i<=n;i++) scanf("%lf",&k[i]);
	for(int i=1;i<=e;i++)
	{
	  int a=read(),b=read(),w=read();
	  map[a][b]=map[b][a]=min(map[a][b],w);//注意判重边 
	}
}
inline void floyd()
{
	for(int i=1;i<=v;i++)//floyd动态更新 
	  for(int j=1;j<=v;j++)
	    for(int k=1;k<=v;k++)
	      map[j][k]=min(map[j][i]+map[i][k],map[j][k]);
	for(int i=1;i<=v;i++) map[i][i]=map[i][0]=map[0][i]=0;//讲每个点到自身的距离设为0 
}
//=============================================================
signed main()
{
	getin(); floyd();
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=m;j++)
	    f[i][j][1]=f[i][j][0]=INF;//初始化各状态 的期望 为极大值 
	
	f[1][0][0]=f[1][1][1]=0;//当i=1时的两种合法状态,其期望为0; 
	for(int i=2;i<=n;i++)
	{
	  int u1=c[i-1],u2=d[i-1],v1=c[i],v2=d[i]; 
	  int u1v1=map[u1][v1],u1v2=map[u1][v2],u2v1=map[u2][v1],u2v2=map[u2][v2];
	  f[i][0][0]=f[i-1][0][0]+u1v1;//一直不申请更换教室的情况 
	  
	  for(int j=1,minn=min(i,m);j<=minn;j++)
	  {
	  	//不申请更换第i节课 
	    f[i][j][0]=min(f[i-1][j][0]+u1v1 , (f[i-1][j][1]+(k[i-1]*u2v1)+((1.0-k[i-1])*u1v1)) );
	    //申请更换第i节课 
		f[i][j][1]=min(  (f[i-1][j-1][0]+(u1v2*k[i])+(u1v1*(1.0-k[i])))   ,   f[i-1][j-1][1] + (u2v2*k[i]+u2v1*(1.0-k[i]))*k[i-1] + (u1v2*k[i]+u1v1*(1.0-k[i]))*(1.0-k[i-1])  );
	  }
	}
	
	for(int i=0;i<=m;i++)//取i=n时的最小期望 
	  ans=min(ans,f[n][i][1]),ans=min(ans,f[n][i][0]);
	printf("%.2lf",ans);
}
