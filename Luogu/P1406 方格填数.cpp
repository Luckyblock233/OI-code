//֪ʶ��:���� 
/*
By:Luckyblock
��ĿҪ��:
���� n*n ����, ��һ��n*n�Ŀվ��� 
�� һ�� �����ķ�ʽ, ʹ�ڲ��ظ�ʹ�����ֵ������,
�����ÿ��,ÿ��, �������Խ����ϵ��� �����
����ֵ��� ��С�ķ��� (��ÿ��˳������֮���ֵ�����С) 
n<=4

��������:
���� �ޱȱ�������ĿҪ�� �� �ޱȱ����� n<=4,
��֪�����Ȼ�Ǹ�������= =

Ϊ��ʹ �ֵ�����С,
����Ҫʹ �����ϵľ���Ԫ�ؾ�����С 
��Ӧ�Ƚ� ��Ϳ���������� 
dfsʱ , Ӧ���մ�������,�������µ�˳��ö�پ���Ԫ��
����ʱ ���� ����ö����Ϳ���� 
���� ��һ�����ɵĺϷ����� һ�����ֵ�����С�ľ��� 

80��:
���ѱ���!!!
ֱ��ö�� ÿһ��λ�ÿ���ѡ�����,
����������Ƿ������ɺϷ� �� ���� 
���Ӷ�O((n^2)!) 

100��: 
����һЩ�Ż�:
���ڱ��� ʱ, ����,��,�Խ��� �ĺͶ���ȷ��
����Ҫ ������ �����ſɼ��� �Ƿ�Ϸ�
����ⷽ������Ż�:

�Ƚ� ��һ�н�����Ϳ,
Ȼ�󽫵�һ�� �ĺ���Ϊ��׼�� ,���ں������ĺͽ��бȽ�
֮��ÿ��Ϳ�� ĳһ��,��ĳһ��,
�ͽ� ���� �� ���еĺ��� ��׼�ͽ��жԱ�
���ʱ , ���ܼ������� dfs. 
�����Ϳ���ͨ������ 
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctype.h>
#define int long long
//=============================================================
int n,a[20] , map[5][5]; 
bool use[20];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void putout(int st)//��� 
{
	printf("%lld\n",st);
	for(int i=1; i<=n; putchar('\n'),i++)
	  for(int j=1; j<=n; j++)
	    printf("%lld ",map[i][j]);
	exit(0);
}
bool judge(int y,int st)//�жϵ�y��,�ͶԽ��� �Ƿ�Ϸ� 
{
	int sum1=0,sum2=0,sum3=0;//1Ϊ��y��,2Ϊ��������ĶԽ���,3Ϊ�������ҵĶԽ��� 
	for(int i=1; i<=n; i++) //��� 
	  sum1+=map[i][y],sum2+=map[i][n-i+1],sum3+=map[i][i];
	if(y!=n) return (sum1==st && sum2==st);//�Ƚ� 
	return (sum1==st && sum2==st && sum3==st);
}
void dfs(int x,int y,int st,int sum)//xΪ��,yΪ�� 
{
	if(x==n && y>1 && y<=n) //ĳһ����Ϳ��� 
	  if(!judge(y-1,st)) return;
	if(x==n+1 && y==1)//������Ϳ��� 
	{
	  if(judge(n,st)) putout(st);//�Ϸ����ֵ�����С�� ���� 
	  else return ;
	}
	for(int i=1; i<=n*n; i++)
	  if(!use[i])//ö����Ϳ���� 
	  {
	  	use[i]=1, map[x][y] = a[i]; 
		if(y < n) dfs(x,y+1,st,sum+a[i]);
	  	else if(sum+a[i] == st) dfs(x+1,1,st,0);//ĳһ����Ϳ��� 
	  	use[i] = 0;
	  }
}
void start(int now,int sum)//��Ϳ��1��,Ȼ��ʼdfs 
{
	if(!now) {dfs(2,1,sum,0); return;} //��һ����Ϳ��� 
	for(int i=1; i<=n*n; i++)
	  if(!use[i])//��Ϳ��һ�� 
	  {
	  	use[i] = 1 , map[1][n-now+1] = a[i];
	  	start(now-1,sum+a[i]);
	  	use[i] = 0;
	  }	
}
//=============================================================
signed main()
{
	n = read();
	for(int i=1; i<=n*n; i++) a[i] = read();
	std::sort(a+1,a+n*n+1);//��������  
	start(n,0);
}
