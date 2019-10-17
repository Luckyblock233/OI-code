//֪ʶ��:floyd,����˼· 
/*	
��ĿҪ��:
	ÿ����,ֻ���������ʱ���,
	�ڿ��Ա�����
	�����ʱ�� ʱ
	����������·

��������:
����n <=200 ,  
һ������Ҹ�����ݷ�Χ( ) 
����ѯ���� Q<=50000
�����ܹ�O(1)��O(log)��ѯ���㷨

�뵽floyd ������ѭ��ö�ٵ���ת�� 
�ɲ����Խ���һЩ�Ķ�.

�뵽 ��¼��ǰʱ��
���ѯ��ʱ�� > ��ǰʱ��
�ͽ� ��ǰʱ��~ѯ��ʱ�� ������
���ŵĵ���Ϊ��ת��
�� һ��floyd,
���������ĵ�֮������· 
 
��ô��ǰʱ�� �ѿ��ŵĵ�֮������·�������
�ж�ѯ�������Ƿ񶼿���
�����Ƿ���ͨ�� 
�����ֱ�ӻش�ѯ�� 
*/
#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<algorithm>
#define int long long
const int MARX = 2100;
const long long INF = 0x3f3f3f3f3f3f3f3f;//����ֵ 
//=============================================================
int n,m,q , t[MARX];
int map[MARX][MARX];
int p=1;
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void prepare()
{
	memset(map,0x3f,sizeof(map));//��ʼ������Ȩ 
	n=read(),m=read();
	for(int i=1;i<=n;i++) t[i]=read();
	for(int i=1;i<=m;i++) 
	{
	  int u=read()+1,v=read()+1,w=read();//�ӱ� 
	  map[u][v]=map[v][u]=w;
	}
	q=read();
}
//=============================================================
signed main()
{
	prepare();
	while(q--)
	{
	  int x=read()+1,y=read()+1,t1=read();
	  while(t[p]<=t1 && p<n+1)//��ǰʱ����µ�ѯ��ʱ�� 
	  {
	  	for(int i=1;i<=n;i++)//���������¿��ŵĵ�Ϊ��ת��,��floyd. 
	  	  for(int j=1;j<=n;j++)
	  	    map[i][j]=std::min(map[i][j],map[i][p]+map[p][j]);
	  	p++;
	  }
	  if(t1<t[x] || t1<t[y]) printf("-1\n");//�е�δ���� 
	  else printf("%lld\n",map[x][y]==INF?-1:map[x][y]);//�ж���ͨ�� 
	}
}
