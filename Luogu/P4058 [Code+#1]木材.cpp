//֪ʶ��:���� �� 
/*
By:Luckyblock
��������:
���ȹ۲� �𰸵�����
�� ans<=iʱ,��������
�� ans>iʱҲ����������
�����㵥����, ����ʹ�ö��ִ� 

���ִ�ö�� ������ʱ
֮�� ö��ÿһ�������� ����ʱ֮��� �߶�
����˸߶� >l,��֤��������Ϸ�,
���Ϸ������� ���,����s�Ƚ� 
*/
#include<cstdio>
#include<ctype.h>
#define int unsigned long long
const int MARX = 2e5+10;
//=============================================================
int n,s,l,ans , h[MARX],a[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
bool check(int now)//��� ʱ��Ϊnowʱ�ĺϷ��� 
{
	int sum = 0;
	for(int i=1; i<=n; i++)//ö������ 
	  if(h[i] + now*a[i] >= l)
	    sum += h[i]+now*a[i];//��� 
	return sum >= s;
} 
//=============================================================
signed main()
{
	n=read(), s=read(), l=read();
	for(int i=1; i<=n; i++) h[i] = read();
	for(int i=1; i<=n; i++) a[i] = read();
	
	if(check(0)) {printf("0"); return 0;} 
	for(int l=0,r=2e18; l<=r;) //ö������ʱ�� 
	{
	  int mid = (l+r)>>1;
	  if(check(mid)) ans=mid,r=mid-1;
	  else l=mid+1;
	}
	printf("%lld",ans);
}
