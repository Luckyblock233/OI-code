//֪ʶ��: sb���� 
/*
By:Luckyblock
��ĿҪ��: 
�� ������n������������
��������С������

sb��
���Է���,n��n-1һ������,
����С������ ���� �˻�,�����
ע������ n=1ʱ 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
//=============================================================
int T,n;
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
	T=read();
	for(int i=1; i<=T; i++)
	{
	  n=read();
	  printf("%lld\n",n*(n-1)==0?1:n*(n-1));
	}
}
