//֪ʶ��:ģ�� 
/*
By:Luckyblock
ͨ��������ʤ����ϵ ,
��Ԥ��������� ��ϵ�ʤ����ϵ 
Ȼ����ģ��,

ģ��ÿһ�ֲ�ȭʱ , a,b�ĳ�ȭ״��
����Ԥ�������ʤ����׼���м�ֵ���� 
*/
#include<cstdio>
#include<ctype.h>
//=============================================================
int n,na,nb,a[220],b[220],win[6][6];
int ansa,ansb;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()//Ԥ�������е�ʤ��״�� 
{
	win[0][2]=win[0][3]=1;
	win[1][0]=win[1][3]=1;
	win[2][1]=win[2][4]=1;
	win[3][2]=win[3][4]=1;
	win[4][0]=win[4][1]=1;
}
//=============================================================
signed main()
{
	prepare(); 
	n=read(),na=read(),nb=read(); 
	for(int i=1; i<=na; i++) a[i]=read(); 
	for(int i=1; i<=nb; i++) b[i]=read();
	int i=1,j=1;
	while(n--)//ѭ��ģ�� 
	{
	  ansa+= win[a[i]][b[j]];//����a,b�Ĵ� 
	  ansb+= win[b[j++]][a[i++]];
	  if(i==na+1) i=1;//ѭ�� 
	  if(j==nb+1) j=1;
	}
	printf("%d %d",ansa,ansb);
}
