//֪ʶ��:����˷�/������ 
/*
ģ��,���ע�� 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define int long long
const int mod = 1e9+7;
int n,k;
struct matrix//�ṹ������� 
{
	int map[110][110];
	matrix() {memset(map,0,sizeof(map));}//��ʼ�� 
	inline void bulid() {for(int i=1;i<=n;i++) map[i][i]=1;}
	matrix operator * (const matrix &a)//���ؽṹ������� 
	  {
		matrix c;
		for(int k=1;k<=n;k++)//����˷�,��Ӧ��� 
	  	  for(int i=1;i<=n;i++)
	    	for(int j=1;j<=n;j++)
	      	  c.map[i][j]=(c.map[i][j] + a.map[i][k]*map[k][j]%mod)%mod;
		return c;
	  }
}map,ans;
inline int read()//��� 
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void mul(matrix &ans,int k)///������ģ�� 
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
	    map.map[i][j]=read();//����ԭ���� 
	ans.bulid();
		
	mul(ans,k);

	for(int i=1;i<=n;putchar('\n'),i++)//��� 
	  for(int j=1;j<=n;j++)
	    printf("%lld ",ans.map[i][j]);
}
