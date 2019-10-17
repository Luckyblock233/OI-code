//知识点:矩阵乘法/快速幂 
/*
模板,详见注释 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define int long long
const int mod = 1e9+7;
int n,k;
struct matrix//结构体存数组 
{
	int map[110][110];
	matrix() {memset(map,0,sizeof(map));}//初始化 
	inline void bulid() {for(int i=1;i<=n;i++) map[i][i]=1;}
	matrix operator * (const matrix &a)//重载结构体运算符 
	  {
		matrix c;
		for(int k=1;k<=n;k++)//矩阵乘法,对应相乘 
	  	  for(int i=1;i<=n;i++)
	    	for(int j=1;j<=n;j++)
	      	  c.map[i][j]=(c.map[i][j] + a.map[i][k]*map[k][j]%mod)%mod;
		return c;
	  }
}map,ans;
inline int read()//快读 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void mul(matrix &ans,int k)///快速幂模板 
{
	while(k)
	  {
	  	if(k&1) ans=ans*map; 
	  	map=map*map;
	  	k>>=1;
	  }
}
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    map.map[i][j]=read();//读入原矩阵 
	ans.bulid();
		
	mul(ans,k);

	for(int i=1;i<=n;putchar('\n'),i++)//输出 
	  for(int j=1;j<=n;j++)
	    printf("%lld ",ans.map[i][j]);
}
