//知识点:多维树状数组 
/*
多维树状数组:
用于解决
多维矩阵求和问题 .
 
对于一维树状数组:
	其本质是对前缀和进行了二进制拆分
	将 查询(1~n)内n个元素
	变为 查询 (1~n)内log n个元素
对于多维树状数组
	假设已经有了多个 
	一维的树状数组
	再对 这多个一维的树状数组,
	进行 二进制拆分

以二维树状数组为例:
	原矩阵: 
	a11 , a12 , a13 , a14
	a21 , a22 , a23 , a24
	a31 , a32 , a33 , a34
	a41 , a42 , a43 , a44
	
	二维树状数组:
	c11=a11, 
	c12=a11+a12, 
	c13=a13, 
	c14=a11+a12+a13+a14
	
	c21=a11+a21, 
	c22=(a11+a12)+(a21+a22), 
	c23=a13+a23, 
	c24=(a11+a12+a13+a14)+(a21+a22+a23+a24) 
	
	c31=a31, 
	c32=a31+a32, 
	c33=a33, 
	c34=a31+a32+a33+a34
	
	c41=a11+a21+a31+a41, 
	c42=(a11+a12)+(a21+a22)+(a31+a32)+(a41+a42), 
	c43=a13+a23+a33+a43, 
	c44=(a11+a12+a13+a14)+(a21+a22+a23+a24)+(a31+a32+a33+a34)+(a41+a42+a43+a44) 
	通过例子,可对多维树状数组,有初步认识 .


关于代码实现:
	修改和查询操作, 
	都只需要在一维树状数组中,
	多加一层循环即可
	用来枚举新添加的,
	一维的前缀和 .
	
	对于子矩阵,(x1,y1)--(x2,y2)的查询,
	ans = sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1); 
	 
关于本题:
	是一道多维树状数组模板题
	可以发现 , 矩阵中值的范围很小,<=100
	考虑暴力思路,
	
	构建100个二维树状数组,
	分别存储各值,
	在矩阵中出现的次数.
	
	1. 对于单点修改操作:
		将点(x,y),由值a修改为b
		先对值a的树状数组 进行修改,
		对对应位置的出现次数-1.
		
		先对值b的树状数组 进行修改,
		对对应位置的出现次数+1.
	2. 对于区间查询操作: 
		直接查询 对应子矩阵中
		出现次数即可 
	
注意的点:
	鬼畜的出题人,决定卡空间限制
	要注意不能把所有变量,尤其是数组,
	都设置为long long . 
*/
#include<cstdio>
#include<ctype.h>
#define ll long long
#define lowbit(x) -x&x
//=============================================================
int N,M,Q;
int map[301][301];
int tree[101][301][301];
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void add(int type,int x,int y,int z)//修改操作,将此点权值设为type,并使其次数+=z 
{
	map[x][y]=type;//更新 
	for(int i=x;i<=N;i+=lowbit(i))//进行拆分 
	  for(int j=y;j<=M;j+=lowbit(j))
	    tree[type][i][j]+=z;
}
inline ll sum(int type,int x,int y)//查询矩阵(1,1)--(x,y)中值type的出现次数 
{	
	int ret=0;
	for(int i=x;i;i-=lowbit(i))//进行拆分 
	  for(int j=y;j;j-=lowbit(j))
	    ret+=tree[type][i][j];//更新 
	return ret;
}
//=============================================================
signed main()
{
	N=read(),M=read();
	for(int i=1;i<=N;i++)
	  for(int j=1;j<=M;j++)//构造初始树状数组 
	  {
	  	int w=read();
	  	add(w,i,j,1);
	  }
	
	Q=read();
	for(int i=0;i<Q;i++)
	{
	  int opt=read();
	  if(opt==1)//修改操作 
	  {
	  	int x=read(),y=read(),type=read();
	  	add(map[x][y],x,y,-1);//原值出现次数-1 
	  	add(type,x,y,1);//新值出现次数+1 
	  }
	  else
	  {
	  	int x1=read(),x2=read(),y1=read(),y2=read(),type=read();
	  	ll ans1=sum(type,x2,y2),ans2=sum(type,x1-1,y1-1);//计算子矩阵的值 
		printf("%lld\n",ans1-sum(type,x1-1,y2)-sum(type,x2,y1-1)+ans2);
	  }
	}
}
