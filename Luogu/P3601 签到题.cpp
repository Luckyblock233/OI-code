//֪ʶ��:������, ŷ������, ɸ������ 
/*
By:Luckyblock
��ĿҪ��:
���� l,r, �� ��(i- ��(i)) (l <= i <= r)
1<=l<=r<=1e12, r-l<=1e6

��������:
���������� : 

1. ���� $x \in Z$, ��:  
	
	$\large \phi(x) = x \times \prod\limits_{i=1}^{x}{\dfrac{p_i-1}{p_i}} (p_i \mid x)$
	
	$x$ ��һ������ $p_i$ �� $\phi (x)$ �Ĺ���Ϊ $\dfrac{p_i-1}{p_i}$
	
2.  ���� һ������$x$ , �������һ�� ������ , $\ge \sqrt{x}$ 
	
	- �����ɸ�� $[1,\sqrt{1e12}]$ �ڵ�����
	  Ȼ�� ����Щ����  �� $[l,r]$ �����Գ� ,   
	    
	    �������� $x$ , �������� $\phi(x)$ �Ĺ���
	 
	- ������� $\ge \sqrt{x}$ �� ֮��һ�� ������ $p_{max}$? 
	  ��Ȼ , $\large p_{max} = \dfrac{x}{\prod\limits p_i^{a_i}}$
	
	  ��� ���Գ�ʱ , ��ԭ�� $x$ ���в��� , 
	  ȫ���Գ���Ϻ� , ԭ�� $x$ ��� $1$ ���� $p_{max}$
	  ��ʱ�ټ��� $p_{max}$ �Ĺ��׼��� 
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define ll long long
const int MARX = 1e6+10;
const ll mod = 666623333;
//=============================================================
ll L,R,ans,K[MARX],phi[MARX];
bool flag[MARX];
std::vector <ll> prime;
//=============================================================
inline ll read()
{
    ll s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	L = read(), R = read();
	for(int i = 2; i < MARX; i ++)//ɸ��[2,1e6]�е����� 
	{
	  if(!flag[i]) prime.push_back(i);
	  for(int j = 2; i * j < MARX; j ++)
	    flag[i*j] = 1;
	}
	
	for(ll i = L; i <= R; i ++) phi[i-L] = K[i-L] = i;//��ʼ�� 
	 
	for(int i = 0,size = prime.size(); i < size; i ++)//ö������ 
	  for(ll j = max(2ll, (L-1) / prime[i] + 1); prime[i]*j <= R; j ++)//ö�������ı��� 
	  {
	  	ll x = prime[i] * j - L; 
	  	phi[x] = phi[x] / prime[i] * (prime[i]-1);//���� ���� 
	  	for(;K[x] % prime[i] == 0;) K[x] /= prime[i];//��ȥ pi 
	  }
	  
	for(ll i = L; i <= R; i ++)//ö��l~r�е��� 
	{
	  if(K[i-L] != 1) phi[i-L] = phi[i-L] / K[i-L] * (K[i - L] - 1);//���� >=sqrt(x)�������ӵĹ��� 
	  ans = (ans + (i - phi[i-L])) % mod;//�ۼӴ� 
	}
	
	printf("%lld", ans);
}
