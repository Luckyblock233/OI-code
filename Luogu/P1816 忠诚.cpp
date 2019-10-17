//知识点:ST表 
/*
静态区间最小值 
模板题，详见注释 
*/ 
#include<cstdio>
#include<cmath>
#include<ctype.h>
#define max(a,b) a<b?a:b
const int MARX  = 1e6+10;
int n,m;
int MAX[MARX][25];
inline int read()
{
	//isdigit函数,判断字符是否为数字字符,包含在<ctype.h>库中 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int qu(int l,int r)
{
    int k=log2(r-l+1);//找到区间大小 
    return max(MAX[l][k],MAX[r-(1<<k)+1][k]);//使用两段线段覆盖查询区间,并得到最值
}
int main()
{
	n=read(),m=read();
    for(int i=1;i<=n;i++) MAX[i][0]=read();
    //用 MAX[i][j-1], MAX[i+(1<<(j-1))][j-1] 来更新 MAX[i][j]. 
    for(int j=1;j<=21;j++)//先枚举j,保证在更新时,[j-1]的情况已经被更新 
      for(int i=1;i+(1<<j)-1<=n;i++)//注意此处的边界 
        MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
      {
        int l=read(),r=read();
        printf("%d ",qu(l,r));
      }
}   
