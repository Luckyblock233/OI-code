//֪ʶ��:��λDP 
/*
��λDP "ģ��" ��

��f[i][j] �� ,
��iλ���� , �����ڶ�λ��Ϊj���� , 
������ĿҪ������ĸ��� 

����,�Ϳ���ͨ�����仯dfs, 
��ȷ�� ÿһ��f[][]��ֵ
���ע�� 
*/ 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctype.h>
#define int long long
//===========================================
int A,B;
int f[15][15],marx,minn;//����iλ���� , �����ڶ�λ��Ϊj���� , ������ĿҪ������ĸ��� 
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
int dfs(int now,int las,bool zero,bool lim)//�ִ�:��ǰλ��,��һλ��ֵ,�Ƿ�ȫΪǰ��0,ǰi-1λ�Ƿ񵽴����ֵ 
{
	if(now>lth) return 1;//���ȵ�������� 
	if(!lim && f[now][las]!=-1) return f[now][las];//�Ѿ����ѵ��� 
	int sum=0 , up=lim?num[lth-now+1]:9;//ȡ�ô�λ����ȡ���Ͻ� 
	for(int i=0;i<=up;i++)
	{
	  if(abs(i-las)<2) continue;//������Ҫ������ 
	  if(zero && i==0) sum+=dfs(now+1,-2,1,lim&&i==up);//ǰ��ȫ��ǰ��0,���Ҵ�λҲΪ0 
	  else sum+=dfs(now+1,i,0,lim&&i==up); 
	}
	if(!lim && !zero)f[now][las]=sum;//���û�е��Ｋ��,���Ҳ�ȫΪ0 ,��ֵ 
	return sum;
}
//============================================
signed main()
{
 	A=read()-1,B=read();//������ұ߽� 
 	
	memset(f,-1,sizeof(f));//��ʼ�� 
	while(A) num[++lth]=A%10,A/=10;//��ø�λ,���ĳ��� 
 	minn=dfs(1,-2,1,1);//ȡ��1~A���������������ĸ��� 
 	
 	memset(f,-1,sizeof(f));//��ʼ�� 
 	lth=0;
	while(B) num[++lth]=B%10,B/=10;//��ø�λ,���ĳ��� 
 	marx=dfs(1,-2,1,1);//ȡ��1~B���������������ĸ��� 
 	
 	printf("%lld",marx-minn);//��ô���������ĸ��� 
}
