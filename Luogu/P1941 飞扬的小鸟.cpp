//֪ʶ��: ��ȫ����,01���� 
/*
By:Luckyblock
//=============================================================
��������:
�� f[i][j] ��ʾ������Ϊi , ������Ϊjʱ�� ���ٻ��� 

�ȳ�ʼ�� f[i][0] = INF (�������) ,
f[0][i]=0 (����ѡ�������Ϊ0������һ��Ϊ��� 

���Է���, ����һ��ȷ���ĺ��������λ��: 
1. �� ������-1 ��������,����õ� 
2. �� ������-1 ������ ������������õ�

��ô���Լ򵥵� �õ�״̬ת�Ʒ���ʽ:
1. �� j<mʱ ,��: f[i][j] = min(f[i][j] , f[i-1][j - k*x[i]] + k) (k in Z)  
2. �� j==mʱ , �Ѿ������� ƽ��Ķ���,
   ���ɼ�������,���ǿ���ͨ�����������괦 �� ����������õ�
   ����: f[i][m] = min(f[i][m] , f[i-1][j + k*x[i]] (j + k*x[i]>=m && j + k*x[i]<m+x[i])
3. ��������Ϊ iʱ,���������,
   ����: f[i][j] = INF (j in   [1,l[i]] , [h[i],m]) 
   ��ʾ���Ӹ���λ�� ���ɵ��� 

����ÿ�������� , ���ת�ƺ�,
����¼����˺��������С����
�����С���� == INF , ��˺����겻�ɵ���
�������������������
 
�ܸ��Ӷ�Ϊ O(n^2 * m)
�����õ�80�ֵĺóɼ�(���� 
//=============================================================
�����Ż�: 
��������λ�õ�ת��,
1. �� ������-1 ��������,����õ�  --->  ����01���� 
2. �� ������-1 ������ ������������õ� ---> ������ȫ���� 

��ô����������ֱ�����д�� , 
����״̬ת�ƽ����Ż�

��Ҫ�Ż� �ڶ���ת��,
�µ�ת�Ʒ���ʽΪ:
f[i][j] = min(f[i][j] , f[i][j-x[i-1]]+1 , f[i-1][j-x[i-1]]+1) 

����ÿһ��������,������ȫ����,����01����
��¼��С��������

�ܸ��Ӷ� O(n*m)  
//=============================================================
�۲�״̬ת�Ʒ���ʽ,
������ͨ����������,
��������1ά , ���Ż��ռ临�Ӷ� 
*/
#include<cstdio>
#include<ctype.h>
#define ll long long
#define min1(a,b) ((a)<(b)?(a):(b))
#define min(a,b,c) (min1(a,min1(b,c)))
const ll INF = 0x7fffffffff;
const int MARX = 1e4+10;
//=============================================================
int n,m,k , x[MARX],y[MARX],h[MARX],l[MARX];//��������� 
ll ans=INF , f[MARX][1010];//��ʾ������Ϊi , ������Ϊjʱ�� ���ٻ���  
bool jud[MARX];//jud[i]��ʾ ������Ϊiʱ�Ƿ������� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()//���� + ��ʼ�� 
{
	n=read(),m=read(),k=read();
	for(int i=0; i<n; i++) x[i]=read(),y[i]=read();
	for(int i=1,tmp; i<=k; i++) tmp=read(),l[tmp]=read(),h[tmp]=read(),jud[tmp]=1;
	for(int i=1; i<=n; i++) f[i][0]=INF;
}
void dp()
{
	for(int i=1,num=0; i<=n; i++)
	{
	  ans = INF;
	  for(int j=1; j<=m; j++) f[i][j]=INF;//��ʼ������ֵ 
	  //�� ������-1 ������ ������������õ� ---> ������ȫ����  
	  for(int j=x[i-1]+1; j<m; j++) f[i][j] = min(f[i][j] , f[i-1][j-x[i-1]]+1 , f[i][j-x[i-1]]+1);
	  //������Ϊ m���������  
	  for(int j=m-x[i-1]; j<=m; j++) f[i][m] = min(f[i][m] , f[i-1][j]+1 , f[i][j]+1);
	  //�� ������-1 ��������,����õ�  --->  ����01���� 
	  for(int j=1; j+y[i-1]<=m; j++) f[i][j] = min1(f[i][j] , f[i-1][j+y[i-1]]);
	  //������Ϊiʱ������ 
	  if(jud[i])
	  {
	  	for(int j=1; j<=l[i]; j++) f[i][j]=INF;//������ֵ 
	  	for(int j=h[i]; j<=m; j++) f[i][j]=INF;
	  	num++;
	  }
	  
	  for(int j=1; j<=m; j++) ans=min1(ans,f[i][j]);//��¼��С���� 
	  if(ans==INF) //�˺����겻�ɵ��� 
	  {
	  	printf("0\n%d",num-1);
	  	return ;
	  }
	}
	printf("1\n%lld",ans);
}
//=============================================================
signed main()
{
	prepare();
	dp();
}
//֪ʶ��:����DP 
/* 
//By:Luckyblock
����10�ִ���
�������ϰ������� 
ֱ�ӽ��б���DP. 
*/ 
/* 
#include<cstdio>
#include<ctype.h>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
const int MARX = 1100;
const int INF = 0x7f7f7f7f;
//=============================================================
int N,M,K,ans=INF;
int X[MARX],Y[MARX],L[MARX],H[MARX];
int f[MARX][MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()//���� 
{
	memset(f,0x7f,sizeof(f));
	N=read(),M=read(),K=read();
	H[0]=M+1;
	for(int i=1; i<=N; i++)  X[i]=read(),Y[i]=read() , H[i]=M+1;
	for(int i=1,tmp; i<=K; i++) tmp=read(),L[tmp]=read(),H[tmp]=read();
}
void dp()
{
	for(int i=1; i<=M; i++)f[0][i]=0;//��ʼֵ 
	for(int i=1,flag=1; i<=N; flag=1,i++)//����DP 
	{	
	  for(int j=1; j<=M; j++)
	  {
	  	if(f[i-1][j-X[i]]+1 <f[i][j]) //״̬ת�� 
	      f[i][j]=f[i-1][j-X[i]]+1,flag=0;
	    if(j+Y[i]<=M && f[i-1][j+Y[i]]<f[i][j]) 
		  f[i][j]=f[i-1][j+Y[i]],flag=0;
	  }
	  if(flag)//�޽� 
	  {
	  	printf("0\n%d",i);
	  	return ;
	  }
	}
	for(int i=1; i<=M; i++) ans=min(ans,f[N][i]);//�н� 
	printf("1\n%d",ans);
}
//=============================================================
signed main()
{
	prepare();
	dp();
}
*/ 
