//֪ʶ��:ST��/RMQ 
/*
ST��ģ����
���ĳ�������ֵ -��Сֵ���� 
���ע�� 
*/
#include<cstdio>
#include<cmath>
#include<ctype.h>
#define int long long
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
const int MARX  = 5e4+10;
int n,m;
int MIN[MARX][25],MAX[MARX][25];
inline int read()
{
	//isdigit����,�ж��ַ��Ƿ�Ϊ�����ַ�,������<ctype.h>���� 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int qu(int l,int r)//ѯ�� 
{
    int k=log2(r-l+1);//�ҵ������С 
    int maxx=max(MAX[l][k],MAX[r-(1<<k)+1][k]) , minn=min(MIN[l][k],MIN[r-(1<<k)+1][k]);//ʹ�������߶θ��ǲ�ѯ����,���õ���ֵ 
    return maxx-minn;
}
signed main()
{
	n=read(),m=read();
    for(int i=1;i<=n;i++) MAX[i][0]=MIN[i][0]=read();
    //�� MAX[i][j-1], MAX[i+(1<<(j-1))][j-1] ������ MAX[i][j]. 
    for(int j=1;j<=24;j++)//��ö��j,��֤�ڸ���ʱ,[j-1]������Ѿ������� 
      for(int i=1;i+(1<<j)-1<=n;i++)//ע��˴��ı߽� 
      {
		MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);//������ֵ 
    	MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);
	  }
	for(int i=1;i<=m;i++)
      {
        int l=read(),r=read();
        printf("%lld\n",qu(l,r));
      }
}   
