//֪ʶ��:״ѹDP 
/*
��������:
����ָ�����
���Ҹ��׵�������ľ���
��Ӱ��ߵ�Ȩֵ

�����뵽ö�ٳ����� , 
��n��spfa , ��ȻTLE 

����n�ǳ�С , 
���Ҷ���n�����ڴ��еİ���״�� , 
���ظ���״̬����
���ǽ���״ѹdp

�㷨ʵ��:
�Ժ�����Ѿ���ͨ�ĵ�ļ��� ,����״̬ѹ��
ʹ��f[i][j][k] ��ʾ ,
״̬Ϊ j , ���(dfs�����)Ϊk , ����i������뼯�� �Ĵ���
����k��Ŀ�� , ��Ϊ�˷�ֹ������Ȳ�һ , Ӱ��� 

����Խ��м��仯dfs
dfs���ݲ��� : ��ǰ״̬now , ��ǰ�ܴ���sum ,��ǰdfs���dep
Ȼ���Ե�ǰ״̬�а����ĵ�  , 
���赼��ǰ״̬�в������ĵ�
�����´�,�����Ǽ���״̬

�����е㶼���뼯�Ϻ� , 
�� = min(��,�ܴ���sum) 
*/ 
#include<cstdio>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
//=================================================
const int MARX = 1e9+7;
int n,m,lim,  map[15][15],dis[15];
int ans=MARX , f[15][5000][15];
//=================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void dfs(int now , int sum , int dep)
{
	if(sum>=ans) return ;
	if(now==lim) {ans=min(ans,sum); return;}//�����е㶼���뼯�� , ȡ��С�Ĵ� 
	for(int i=1;i<=n;i++) 
	  if(1<<(i-1)&now)//ö���ڼ����еĵ�i 
	    for(int j=1;j<=n;j++)
	      if(!(1<<(j-1)&now) && map[i][j]<MARX)//ö��i���Ե���� , �Ҳ��ڼ����еĵ�j 
	  	  {
	  	    if(f[j][1<<(j-1)|now][dep+1] <= sum+dis[i]*map[i][j]) continue;//�赼���� 
	  	    f[j][1<<(j-1)|now][dep+1] = sum+dis[i]*map[i][j];
	  	    dis[j]=dis[i]+1;//����j����� 
	  	    dfs(1<<(j-1)|now ,f[j][1<<(j-1)|now][dep+1] ,dep+1);//�����赼 
		  }
}
//=================================================
signed main()
{
	n=read(),m=read();lim=(1<<n)-1;
	memset(map,MARX,sizeof(map));
	for(int i=1;i<=m;i++)//��ͼ 
	{
	  int u=read(),v=read(),w=read();
	  map[u][v]=map[v][u]=min(map[u][v],w);
	}
	for(int i=1;i<=n;i++)//ö�ٳ����� 
	{
	  memset(dis,0,sizeof(dis));//��ʼ�� 
	  memset(f,MARX,sizeof(f));
	  dis[i]=1; dfs(1<<(i-1),0,0);
	}
	printf("%d",ans);
}
