//
/*
# $ATK_i \times x \equiv a_i \mod p_i$

# $x \equiv \frac{a_i}{ATK_i}  \mod p_i$

# $x \equiv a_i\times inv(ATK_i)  \mod p_i$

1. 找到每次选中的 $ATK_i$ 
2. 求得 $inv(ATK_i)$
3. 获得一组同余方程 : $x \equiv a_i\times inv(ATK_i)  \mod p_i$
4. 循环完成上 $3$ 步 , 完成后套 $excrt$ 模板

$a_i -ATK_i\times x \le{0} 的情况下,满足$ $ATK_i \times x \equiv a_i \mod p_i$
*/ 
#include<cstdio>
#include<set>
#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<windows.h>
#define int long long
const int MARX = 1e5+10;
//=============================================================
int T,n,m;
int heal[MARX],restore[MARX],sword[MARX],chose[MARX];
int num[MARX*10];
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
/*
int mul(int a,int b,int mod)
{
	int ans=0;
	while(b>0)
	{
	  if(b&1) ans=(ans+a)%mod;
	  a=(a+a)%mod;
	  b>>=1;
	}
	return ans;
}
*/
int exgcd(int a,int b,int &x,int &y)
{
	if(!b) return x=1,y=0,a;
	int d=exgcd(b,a%b,x,y) ;
	int tmp=x;
	x=y , y=tmp-(a/b)*y;
	return d;
}
int lcm(int a,int b)
{
	int x,y;
	return (a/(exgcd(a,b,x,y))*b);
}
void getatk()
{
	std::set <int> se;
	int x,y;
	for(int i=1;i<=m;i++)
	{
	  int atk=read();
	  num[atk]++;
	  se.insert(atk);
	}
	for(int i=1;i<=n;i++)
	{
	  std::set<int> ::iterator choose = se.lower_bound(heal[i]);
	  if(choose!=se.begin()) choose--;
	  if(*choose!=1)
	  {
	    exgcd(*choose,restore[i],x,y);
	    heal[i] = heal[i]*((x%restore[i]+restore[i])%restore[i]);	
	  }
	  //printf("%lld %lld %lld\n",heal[i],restore[i],((x%restore[i]+restore[i])%restore[i]));
	  //Sleep(1000);
	  chose[i]=*choose;
	  num[*choose]--;
	  if(num[*choose]<=0) se.erase(choose);
	  se.insert(sword[i]) , num[sword[i]]++;
	}
}
int excrt()
{
	int x,y , M=restore[1],ans=heal[1];
	printf("%lld %lld   %lld %lld %lld %lld\n",heal[1],restore[1],x,y,M,ans);
	Sleep(1000);
	for(int i=2;i<=n;i++)
	{
	  int A=M,B=restore[i] , C = ((heal[i]-ans)%B+B)%B;
	  int gcd=exgcd(A,B,x,y);
	  if(C%gcd) return -1;
	  x=x*(C/gcd)%B;//mul(x,C/gcd,B);
	  //while(heal[i]-chose[i]*x>0) x++;
	  ans+=x*M;
	  M=lcm(M,B);
	  ans=(ans%M+M)%M;
	  
	  printf("%lld %lld   %lld %lld %lld %lld\n",heal[i],restore[i],x,y,M,ans);
	  Sleep(1000);
	}
	return ans;
}
//=============================================================
signed main()
{
	freopen("testdata (2).in","r",stdin);
	T=read();
	while(T--)
	{
	  int max_heal=0;
	  n=read(),m=read();
	  for(int i=1;i<=n;i++) heal[i]=read(),max_heal=std::max(max_heal,heal[i]);
	  for(int i=1;i<=n;i++) restore[i]=read();
	  for(int i=1;i<=n;i++) sword[i]=read();
	  getatk();
	  int ans=excrt();
	  printf("%lld\n",ans?ans:max_heal);
	}
}
