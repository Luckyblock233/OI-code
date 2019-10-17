//Çóx^y % pµÄ´ð°¸ 
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,p;
ll mul(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b)
	  {
	  	if(b&1) ans=ans*a%mod;
	  	a=(a*a)%mod;
	  	b>>=1;
	  }
	return ans%mod;
}
int main()
{
	scanf("%lld%lld%lld",&x,&y,&p);
	printf("%lld^%lld mod %lld=%lld",x,y,p,mul(x,y,p));
} 
