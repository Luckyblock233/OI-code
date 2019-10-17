//算法：DP，背包
//看起来是依赖背包,实际上可以拆分成01背包来做
/*
有五种决策: 
1.不选，然后去考虑下一个主件 
2.选且只选这个主件
3.选这个主件，并且选附件1
4.选这个主件，并且选附件2
5.选这个主件，并且选附件1和附件2. 
*/
//则有五个状态转移方程式
//详见注释 
#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn=32100;
int n,m;
int v,p,q;
int mw[maxn];//分存主件质量,价值 
int mc[maxn];
int fw[maxn][5];//分存某编号主件的附件的质和价值 
int fc[maxn][5];
int f[maxn]; 
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
	  {
        scanf("%d%d%d",&v,&p,&q);
        if (!q)//是主件 
		  {
            mw[i]=v;
            mc[i]=v*p;
          }
        else//是附件 
		  {
            fw[q][++fw[q][0]]=v;
            fc[q][fw[q][0]]=v*p;
          }
      }
    for (int i=1;i<=m;i++)//DP 
      for (int j=n;mw[i]!=0&&j>=mw[i];j--)
	    {
            f[j]=max(f[j],f[j-mw[i]]+mc[i]);//选且只选这个主件 
            if(j>=mw[i]+fw[i][1])
              f[j]=max(f[j],f[ j - mw[i] - fw[i][1] ] + mc[i] + fc[i][1]);//选这个主件，并且选附件1 
            if(j>=mw[i]+fw[i][2])
              f[j]=max(f[j],f[ j - mw[i] - fw[i][2] ] + mc[i] + fc[i][2]);//选这个主件，并且选附件2 
            if(j>=mw[i]+fw[i][1]+fw[i][2])
              f[j]=max(f[j],f[ j - mw[i] - fw[i][1] - fw[i][2] ] + mc[i] + fc[i][1] + fc[i][2]);//选这个主件，并且选附件1和附件2. 
        }
     printf("%d",f[n]);
     return 0;
}
