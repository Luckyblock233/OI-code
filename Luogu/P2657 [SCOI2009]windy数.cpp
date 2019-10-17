//知识点:数位DP 
/*
数位DP "模板" 题

用f[i][j] 存 ,
有i位的数 , 倒数第二位数为j的数 , 
满足题目要求的数的个数 

这样,就可以通过记忆化dfs, 
来确定 每一个f[][]的值
详见注释 
*/ 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctype.h>
#define int long long
//===========================================
int A,B;
int f[15][15],marx,minn;//存有i位的数 , 倒数第二位数为j的数 , 满足题目要求的数的个数 
int num[15],lth;
//===========================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int dfs(int now,int las,bool zero,bool lim)//分存:当前位数,上一位的值,是否全为前导0,前i-1位是否到达最大值 
{
	if(now>lth) return 1;//长度到达了最大 
	if(!lim && f[now][las]!=-1) return f[now][las];//已经被搜到过 
	int sum=0 , up=lim?num[lth-now+1]:9;//取得此位置能取的上界 
	for(int i=0;i<=up;i++)
	{
	  if(abs(i-las)<2) continue;//不满足要求的情况 
	  if(zero && i==0) sum+=dfs(now+1,-2,1,lim&&i==up);//前面全是前导0,并且此位也为0 
	  else sum+=dfs(now+1,i,0,lim&&i==up); 
	}
	if(!lim && !zero)f[now][las]=sum;//如果没有到达极限,并且不全为0 ,则赋值 
	return sum;
}
//============================================
signed main()
{
 	A=read()-1,B=read();//获得左右边界 
 	
	memset(f,-1,sizeof(f));//初始化 
	while(A) num[++lth]=A%10,A/=10;//获得各位,数的长度 
 	minn=dfs(1,-2,1,1);//取的1~A的满足条件的数的个数 
 	
 	memset(f,-1,sizeof(f));//初始化 
 	lth=0;
	while(B) num[++lth]=B%10,B/=10;//获得各位,数的长度 
 	marx=dfs(1,-2,1,1);//取的1~B的满足条件的数的个数 
 	
 	printf("%lld",marx-minn);//获得此区间的数的个数 
}
