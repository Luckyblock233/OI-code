//֪ʶ��:״ѹDP 
/*
By:Luckyblock
��ĿҪ��: 
����һ n*m �ľ���,��Щ����������� 
���������ڵ� , ���ݵķ���,
��������ķ����� 

��������: 
�������⡣ n<=12,m<=12 ,����ȷ������һ��״ѹDP��
�����Է���,ֻ�����ڵ����� , �Żụ��Ӱ��. 
֮��ʼ���״̬:
ʹ�ö������� , ��ʾÿ�� ��Ƥ���������. 
�� f[i][j] ��ʾ ,��ǰ���˵�i��,��i�е�״̬Ϊj,�ķ�����.

�����Ƚ��г�ʼ�� , ���ÿһ�еĺϷ�״̬,
�������� �������� �� ���ݵ�Ƥ�� ״̬.

Ȼ�� �ٽ�����������±���,
ÿ��ö�����ڵ����� ,
��ö�����и��ԵĺϷ�״̬.
1.�����Щ�Ϸ�״̬���� ���ڲ��� , 
  ��ô�͸�������һ�� ,  ��״̬�Ĵ�,
  ����ʽΪ:
  f[i][j] =  ��f[i-1][k] (j,k��Ϊ�Ϸ�״̬,�ҿ������ڲ���)
2.����,�Ͳ�����.

������һ��,����n�� , 
�����кϷ�״̬�ķ��������,��Ϊ�� 

ע:
�۲췽��ʽ,���ֿ���ʹ�ù������������ 1 ά
�����пռ临�Ӷȵ��Ż�. 
*/
#include<cstdio>
#include<ctype.h>
#define lowbit(x) ((x)&-(x))
const int mod = 1e8;
const int MARX = 4100;
//=============================================================
int n,m,all , log_2[MARX];
bool map[20][20],plan[20][MARX];
long long ans,f[20][MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void prepare()//���뼰Ԥ���� 
{
	for(int i=0,sum=1;i<=15;i++,sum<<=1) log_2[sum]=i; //Ԥ����log���� 
	
	n=read(),m=read() ; all=(1<<m)-1;//ȫ�� 
	for(int i=1; i<=n; i++) 
	  for(int j=1; j<=m; j++)
	    map[i][j-1]=read();
	    
	for(int i=1; i<=n; i++)//��ø��еĺϷ�״̬ 
	  for(int j=0; j<=all; j++)
	  {
	  	bool flag=0;
		for(int k=j,last=-1; k; last=lowbit(k),k-=lowbit(k))//���״̬j�ĺϷ��� 
	      if( map[i][log_2[lowbit(k)]]==0 || 2*last==lowbit(k) )//�Ƿ�������� �� �Ƿ�������������ݵ�Ƥ 
		  {
		  	flag=1;break;//���Ϸ�,���� 
		  }
	  	if(flag) continue;
	  	plan[i][j]=1 , f[i][j]=(i==1);//��¼״̬�Ϸ��� 
	  }
}
void dp()
{
	for(int i=2; i<=n; i++)//ö�����ڵ����� 
	  for(int j=0; j<=all; j++) //ö�����еĺϷ�״̬ 
	    for(int k=0; k<=all; k++)
	      if( (plan[i-1][j] && plan[i][k]) && ((j&k)==0) )//��״̬���Ϸ� ���� �������� 
	        f[i][k]= (f[i][k]+f[i-1][j])%mod;//���·����� 
}
//=============================================================
signed main()
{
	prepare();
	dp();
	for(int i=0; i<=all; i++)//���´� 
	  if(plan[n][i]) 
	    ans=(ans+f[n][i])%mod;
	printf("%lld",ans);
}
