//֪ʶ��:ģ�� 
/*
By:Luckyblock
��ĿҪ��:
������������޸�,�����޸���ɺ�,��ѯ����Ȩֵ

����ѯ�������ߵ�,����ֻ��һ��
���Կ��Խ��޸Ĳ���Ҳ�������ߴ��� ,
������������޸�,
ֻ��Ҫ�ж����Բ�ѯ��������Ӱ�켴�� 

������󸲸��� ����,
��ô�������Ȩֵ,����Ϊ�޸ĺ��Ȩֵ 
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 1e5+10; 
//=============================================================
int x,y,n,p=-1,  a[MARX],b[MARX],g[MARX],k[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=read(),g[i]=read(),k[i]=read();
	x=read(),y=read();
	for(int i=1;i<=n;i++)//ö��ÿһ���޸Ĳ��� 
	{
	  int l1=a[i] , l2=b[i] , r1=a[i]+g[i] , r2=b[i]+k[i];//�޸����� 
	  if(x<=r1 && x>=l1)//�ж��Ƿ�Ӱ�쵽���� 
	  	if(y<=r2 && y>=l2)
		  p=i;//���µ���Ȩֵ 
	}
	printf("%d",p);
}
