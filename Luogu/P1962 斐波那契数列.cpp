//֪ʶ��:�������DP
/*
�����쳲��������е�n���ֵ
��n<=2^63-1

ֱ��ѭ������
��Ȼ�ǲ�������
��ʱ,����ʹ�þ������

���Է���:
f[i],f[i-1]	    1  ,  1         f[i+1],f[i]
 0  ,   0     * 1  ,  0    ==    0  ,   0    
 
���ݾ�������Ľ����,
�������þ��� 
1  ,  1  
1  ,  0  
�� (n-1)����(mod p)������

Ȼ��ʹ ԭ���� 
f[i+1],f[i]
 0  ,   0    
������õľ���
���ɵõ���n��Ľ��  
*/ 
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define int long long
//===============================================
const int mod = 1e9+7;
int n,m=2;
struct matrix//�ṹ������� 
{
	int map[110][110];
	matrix() {memset(map,0,sizeof(map));}//��ʼ�� 
	inline void bulid() {for(int i=1;i<=m;i++) map[i][i]=1;}
	matrix operator * (const matrix &a)//���ؽṹ������� 
	  {
		matrix c;
		for(int k=1;k<=m;k++)//����˷�,��Ӧ���
	  	  for(int i=1;i<=m;i++)
	    	for(int j=1;j<=m;j++)
	      	  c.map[i][j]=(c.map[i][j] + a.map[i][k]*map[k][j]%mod)%mod;
		return c;
	  }
}f,map,ans;
//===============================================
inline int read()
{
	//isdigit����,�ж��ַ��Ƿ�Ϊ�����ַ�,������<ctype.h>���� 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
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
	n=read();
	if(n==1) //����1������� 
	  {
	  	printf("1");
	  	return 0;
	  }
	map.map[1][1]=map.map[1][2]=map.map[2][1]=1;//����ԭʼ���� 
	ans.bulid();
	mul(ans,n-1);//������� 

	f.map[1][1]=f.map[1][2]=1;//ԭ���� 
	f=f*ans;

	printf("%lld",f.map[1][1]);
}
