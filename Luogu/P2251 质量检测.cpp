//֪ʶ��:ST��,	RMQ 
/*
��̬������Сֵģ��
���ע�� 
*/
#include<cstdio>
#include<cmath>
#include<ctype.h>
#define min(a,b) a<b?a:b
const int MARX  = 1e6+10;
int n,m;
int MAX[MARX][25];
inline int read()
{
	//isdigit����,�ж��ַ��Ƿ�Ϊ�����ַ�,������<ctype.h>���� 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int qu(int l,int r)//��ѯ 
{
    int k=log2(r-l+1);
    return min(MAX[l][k],MAX[r-(1<<k)+1][k]);//ʹ������С���串�ǲ�ѯ���� 
}
int main()
{
	n=read(),m=read();
    for(int i=1;i<=n;i++) MAX[i][0]=read();
    //�� MAX[i][j-1], MAX[i+(1<<(j-1))][j-1] ������ MAX[i][j]. 
    for(int j=1;j<=21;j++)//��ö��j,��֤�ڸ���ʱ,[j-1]������Ѿ������� 
      for(int i=1;i+(1<<j)-1<=n;i++)//ע��˴��ı߽� 
        MAX[i][j]=min(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=n-m+1;i++)
      printf("%d\n",qu(i,i+m-1));
}   
