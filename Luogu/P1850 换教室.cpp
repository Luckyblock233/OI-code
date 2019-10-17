//֪ʶ��:DP,�������� 
/*
��DP(����

���ֵ���<=300
����floydԤ���������֮������· 

����ÿ��ʱ��ε�����,
���гɹ��򲻳ɹ��Ŀ�����
����ת�ƹ��̱��ʮ�ָ���

��f[i][j][1/0] , ��¼ ��ǰѡ����i��ʱ���,������j��,k:��ǰ�������� 
��: ���ڵ�ǰ״̬:
1.�����ǰ�����뽻��  f[i][j][0]:
	1.�ϴβ����뽻��  f[i-1][j][0]:  
	  +map[c[i-1]][c[i]] 
	  ת�ơ� 
	2.�ϴ����뽻��:
	    �˴γɹ�: +k[i-1]*map[c[i-1]][d[i]]
		�˴�ʧ��: +(1-k[i-1])*map[c[i-1]][c[i]]
	  ת��
  ���ν��ȡmin����

2.�����ǰ���뽻��    f[i][j+1][1]:
	1.�ϴβ����뽻��  f[i-1][j][0]: 
	    �˴γɹ�: +k[i]*map[d[i-1]][c[i]]
		�˴�ʧ��: +(1-k[i])*map[c[i-1]][c[i]]
	  ת��
	2.�ϴ����뽻��   f[i-1][j][1]
		�ϴγɹ�,�˴γɹ�: + k[i]*k[i-1]*map[d[i][d[i]] 
		�ϴγɹ�,�˴�ʧ��: + (1-k[i])*k[i-1]*map[d[i][c[i]] 
		�ϴ�ʧ��,�˴γɹ�: + k[i]*(1-k[i-1])*map[c[i][d[i]] 
		�ϴ�ʧ��,�˴�ʧ��: + (1-k[i])*(1-k[i-1])*map[c[i][c[i]]
	  ת�� 
  ���ν��ȡmin���� 
 
�ܵ�ת�Ʒ����������. 
����ҳ��� i=n ʱ�� f[i][j][1/0]����С����ֵ
���� 

ע���:
1.������ͼ�д����ر����Ի�,��floydʱ,ע������ж��봦��
2.�� i=1ʱ,�����ֲ��Ϸ�״̬ f[1][0][1]��f[1][1][0],ע������ж��봦�� 
*/
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
const int MARX = 2010;
const double INF = 1e10+10;
//=============================================================
int n,m,v,e  ,  c[MARX],d[MARX],map[310][310];
double ans=INF  ,  k[MARX],f[MARX][MARX][2];//f[i][j][1/0] : ��ǰѡ����i��ʱ���,������j��,k:��ǰ�������� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void getin()
{
	memset(map,0x3f,sizeof(map));//��ʼ����·��Ϊ����ֵ 
	n=read(),m=read(),v=read(),e=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) d[i]=read();
	for(int i=1;i<=n;i++) scanf("%lf",&k[i]);
	for(int i=1;i<=e;i++)
	{
	  int a=read(),b=read(),w=read();
	  map[a][b]=map[b][a]=min(map[a][b],w);//ע�����ر� 
	}
}
inline void floyd()
{
	for(int i=1;i<=v;i++)//floyd��̬���� 
	  for(int j=1;j<=v;j++)
	    for(int k=1;k<=v;k++)
	      map[j][k]=min(map[j][i]+map[i][k],map[j][k]);
	for(int i=1;i<=v;i++) map[i][i]=map[i][0]=map[0][i]=0;//��ÿ���㵽����ľ�����Ϊ0 
}
//=============================================================
signed main()
{
	getin(); floyd();
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=m;j++)
	    f[i][j][1]=f[i][j][0]=INF;//��ʼ����״̬ ������ Ϊ����ֵ 
	
	f[1][0][0]=f[1][1][1]=0;//��i=1ʱ�����ֺϷ�״̬,������Ϊ0; 
	for(int i=2;i<=n;i++)
	{
	  int u1=c[i-1],u2=d[i-1],v1=c[i],v2=d[i]; 
	  int u1v1=map[u1][v1],u1v2=map[u1][v2],u2v1=map[u2][v1],u2v2=map[u2][v2];
	  f[i][0][0]=f[i-1][0][0]+u1v1;//һֱ������������ҵ���� 
	  
	  for(int j=1,minn=min(i,m);j<=minn;j++)
	  {
	  	//�����������i�ڿ� 
	    f[i][j][0]=min(f[i-1][j][0]+u1v1 , (f[i-1][j][1]+(k[i-1]*u2v1)+((1.0-k[i-1])*u1v1)) );
	    //���������i�ڿ� 
		f[i][j][1]=min(  (f[i-1][j-1][0]+(u1v2*k[i])+(u1v1*(1.0-k[i])))   ,   f[i-1][j-1][1] + (u2v2*k[i]+u2v1*(1.0-k[i]))*k[i-1] + (u1v2*k[i]+u1v1*(1.0-k[i]))*(1.0-k[i-1])  );
	  }
	}
	
	for(int i=0;i<=m;i++)//ȡi=nʱ����С���� 
	  ans=min(ans,f[n][i][1]),ans=min(ans,f[n][i][0]);
	printf("%.2lf",ans);
}
