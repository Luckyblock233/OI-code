//֪ʶ��:�������
/*
a[1]=a[2]=a[3]=1
a[x]=a[x-3]+a[x-1] (x>3)
��a���еĵ�n��
��n<=2*10^9

ֱ��ѭ������,��Ȼ�ǲ�������
��ʱ,����ʹ�þ������

���Է���:
f[i-1],f[i-2],f[i-3]	 1  , 1 , 0        f[i], f[i-1],f[i-2]
 0  ,   0  	 ,  0    *   0  , 0 , 1   ==    0  ,   0   ,  0  
 0  ,   0  	 ,  0        1  , 0 , 0         0  ,   0   ,  0  
 
���ݾ�������Ľ����,
�������þ��� 
1  , 1 , 0
0  , 0 , 1
1  , 0 , 0
�� (n-1)����(mod p)������

Ȼ��ʹ ԭ���� 
f[i-1],f[i-2],f[i-3]
 0  ,   0  	 ,  0
 0  ,   0  	 ,  0
������õľ���
���ɵõ���n��Ľ��  
*/ 
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define int long long
//===============================================
const int mod = 1e9+7;
int n,m=3;
struct matrix//�ṹ������� 
{
	int map[50][50];
}f,map,ans;
//===============================================
matrix operator * (const matrix &a,const matrix &b)//���ؽṹ������� 
{
	matrix c;
	memset(c.map,0,sizeof(c.map));
	for(int k=1;k<=m;k++)//����˷�,��Ӧ���
	  for(int i=1;i<=m;i++)
	    for(int j=1;j<=m;j++)
	      c.map[i][j]=(c.map[i][j] + a.map[i][k] * b.map[k][j]%mod)%mod;
		return c;
}
inline int read()
{
	//isdigit����,�ж��ַ��Ƿ�Ϊ�����ַ�,������<ctype.h>���� 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void bulid(matrix &map) 
{
	for(int i=1;i<=m;i++)
	  map.map[i][i]=1;
}
inline void mul(matrix &ans,int k)//������ģ�� 
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
	int T;
	T = read();
	while(T--)
	  {
	    n = read();
		if(n<=3) //����1������� 
	  	  {
	  		printf("1\n");continue;
	  	  }
	  	  
	  	memset(map.map,0,sizeof(map.map));
	  	memset(ans.map,0,sizeof(ans.map));
	  	memset(f.map,0,sizeof(f.map));
	  	
		map.map[1][1]=map.map[1][2]=map.map[2][3]=map.map[3][1]=1;//����ԭʼ���� 
		f.map[1][1]=f.map[1][2]=f.map[1][3]=1;//ԭ���� 
		
		bulid(ans);
		mul(ans,n-3);//������� 
		f=f*ans;
		
		printf("%lld\n",f.map[1][1]);
	  }
}
