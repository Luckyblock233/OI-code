//֪ʶ��:���� 
/*
By:Luckyblock 
��������:
�� ������Ϊ�ĸ� �ȴ�С����
�����Ͻǵ� �Ӿ�����д��� 

ע��� �Ӿ���ı߽�����ж� 
*/
#include<cstdio>
#include<cctype>
#define ll long long
const int MARX = 1024+10;
//=============================================================
ll n,mul;
bool map[MARX][MARX];
//=============================================================
inline ll read()
{
    ll s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void solve(ll x1, ll y1, ll l)
{
	for(ll i=x1; i<=(x1+(l-1)/2); i++)//���Ͻ� �Ӿ��� 
	  for(ll j=y1; j<=(y1+(l-1)/2); j++)
	    map[i][j] = 1;
	if(l/2 == 1) return ;//�޷������ָ� 
	
	solve(x1,y1+l/2,l/2);//����,����,���µľ��� 
	solve(x1+l/2,y1,l/2);
	solve(x1+l/2,y1+l/2,l/2);
}
//=============================================================
signed main()
{
	n=read(); mul=1<<n;
	solve(1,1,mul); 
	for(ll i=1; i<=mul; putchar('\n'),i++)//��������ľ��� 
	  for(ll j=1; j<=mul; j++)
	    printf("%d ",map[i][j]?0:1);
}
