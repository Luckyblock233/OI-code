//知识点:ST表/RMQ 
/*
ST表模板题
输出某区间最大值 -最小值即可 
详见注释 
*/
#include<cstdio>
#include<cmath>
#include<ctype.h>
#define int long long
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
const int MARX  = 5e4+10;
int n,m;
int MIN[MARX][25],MAX[MARX][25];
inline int read()
{
	//isdigit函数,判断字符是否为数字字符,包含在<ctype.h>库中 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int qu(int l,int r)//询问 
{
    int k=log2(r-l+1);//找到区间大小 
    int maxx=max(MAX[l][k],MAX[r-(1<<k)+1][k]) , minn=min(MIN[l][k],MIN[r-(1<<k)+1][k]);//使用两段线段覆盖查询区间,并得到最值 
    return maxx-minn;
}
signed main()
{
	n=read(),m=read();
    for(int i=1;i<=n;i++) MAX[i][0]=MIN[i][0]=read();
    //用 MAX[i][j-1], MAX[i+(1<<(j-1))][j-1] 来更新 MAX[i][j]. 
    for(int j=1;j<=24;j++)//先枚举j,保证在更新时,[j-1]的情况已经被更新 
      for(int i=1;i+(1<<j)-1<=n;i++)//注意此处的边界 
      {
		MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);//更新最值 
    	MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);
	  }
	for(int i=1;i<=m;i++)
      {
        int l=read(),r=read();
        printf("%lld\n",qu(l,r));
      }
}   
