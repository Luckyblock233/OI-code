//֪ʶ�㣺���ɣ�쳲��������� 
/*
ͨ������ɵã�
��f[i] Ϊ��i��쳲��������� 

��iվ�ϳ�����Ϊf[i-2]n+f[i-1]b (i>=2)
�³�����Ϊf[i-3]n+f[i-2]b (i>=3)
��������Ϊf[i-2]n+n+f[i-1]b-b��i>=2)

���һվ�³�����=�����ڶ�վ��������
����ɽ��b

�ٴ��빫ʽ��õ�xվ�������� 
���� x=1����� 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int f[25]={0,1};
int n,a,m,x,b;
signed main()
{
	a=read(),n=read(),m=read(),x=read();
	
	for(int i=2;i<n;i++)
	  f[i]=f[i-1]+f[i-2];
	
	b=(m-f[n-3]*a-a)/(f[n-2]-1);
	
	if(x==1) printf("%lld",a);
	else printf("%lld",(f[x-2]+1)*a+(f[x-1]-1)*b);
}
