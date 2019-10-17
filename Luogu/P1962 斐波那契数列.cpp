//知识点:矩阵加速DP
/*
欲求得斐波那契数列第n项的值
且n<=2^63-1

直接循环递推
必然是不可做的
这时,考虑使用矩阵加速

可以发现:
f[i],f[i-1]	    1  ,  1         f[i+1],f[i]
 0  ,   0     * 1  ,  0    ==    0  ,   0    
 
根据矩阵运算的结合律,
则可以求得矩阵 
1  ,  1  
1  ,  0  
的 (n-1)次幂(mod p)意义下

然后使 原矩阵 
f[i+1],f[i]
 0  ,   0    
乘上求得的矩阵
即可得到第n项的结果  
*/ 
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define int long long
//===============================================
const int mod = 1e9+7;
int n,m=2;
struct matrix//结构体存数组 
{
	int map[110][110];
	matrix() {memset(map,0,sizeof(map));}//初始化 
	inline void bulid() {for(int i=1;i<=m;i++) map[i][i]=1;}
	matrix operator * (const matrix &a)//重载结构体运算符 
	  {
		matrix c;
		for(int k=1;k<=m;k++)//矩阵乘法,对应相乘
	  	  for(int i=1;i<=m;i++)
	    	for(int j=1;j<=m;j++)
	      	  c.map[i][j]=(c.map[i][j] + a.map[i][k]*map[k][j]%mod)%mod;
		return c;
	  }
}f,map,ans;
//===============================================
inline int read()
{
	//isdigit函数,判断字符是否为数字字符,包含在<ctype.h>库中 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void mul(matrix &ans,int k)//快速幂模板 
{
	while(k)
	  {
	  	if(k&1) ans=ans*map; 
	  	map=map*map;
	  	k>>=1;
	  }
}
//===============================================
signed main()
{
	n=read();
	if(n==1) //特判1的情况下 
	  {
	  	printf("1");
	  	return 0;
	  }
	map.map[1][1]=map.map[1][2]=map.map[2][1]=1;//构造原始矩阵 
	ans.bulid();
	mul(ans,n-1);//求快速幂 

	f.map[1][1]=f.map[1][2]=1;//原矩阵 
	f=f*ans;

	printf("%lld",f.map[1][1]);
}
