//֪ʶ��: DP 
/*
By:Luckyblock
��dp??
��������:
���ڱ���, Ӱ���ܼ�ֵ�� ������:
1. ѡ��Ŀ���
2. ѡ���ÿ������� ����
�������� Ҫ��, ���״̬: 
�� f[i][j] , Ϊ ��ǰѡ����i�ֿ�,ѡ��j�ڿ�,����С��ֵ 

��Ԥ����� i=1ʱ�����е�j��Ӧ�ļ�ֵ
����ѭ�� ö�� 
��ǰѡ��Ŀ�, ��ѡ�����, ��ǰ��ѡ�������
��״̬ת�Ʒ���Ϊ: 
(mul[k][b[i]]Ϊ k��b[i]�η�) 
f[i][j] = min(f[i][j], f[i-1][j-k] + a[i]*mul[k][b[i]]); 
*/
#include<cstdio>
#include<cstring> 
#include<ctype.h>
#define min(a,b) a<b?a:b
#define int long long
//=============================================================
int n,m, a[25],b[25];
int mul[210][7];//Ԥ������ 
int f[25][210]; // ��ǰѡ����i�ֿ�,ѡ��j�ڿ�,����С��ֵ
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int j=1; j<=n; j++)//Ԥ������ 
	{
	  mul[j][0]=1;
	  for(int k=1; k<=6; k++) mul[j][k] = mul[j][k-1]*j;	
	}
	    
	memset(f,63,sizeof(f));
	for(int i=1; i<=m; i++) a[i]=read(),b[i]=read(); 
	for(int i=0; i<=n; i++) f[1][i] = a[1]*mul[i][b[1]];//Ԥ����i=1ʱ����� 
	
	for(int i=2; i<=m; i++)//ö�ٿ����� 
	  for(int j=0; j<=n; j++)//ö�ٵ�ǰѡ��Ŀ��� 
		for(int k=0; k<=j; k++)//ö�ٵ�i�ſ�ѡ������� 
		  f[i][j] = min(f[i][j], f[i-1][j-k] + a[i]*mul[k][b[i]]);//����,ȡ��Сֵ 
		  
	printf("%lld",f[m][n]);
}
