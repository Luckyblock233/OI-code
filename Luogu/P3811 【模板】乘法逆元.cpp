//���Ʒ��� 
#include<cstdio>
using namespace std;
long long n,p;
long long ans[5000010]={0,1};
int main()
{
    scanf("%lld%lld",&n,&p);
    printf("1\n");
    for(long long i=2;i<=n;i++)
      {
      	ans[i]=(long long)(p-p/i)*ans[p%i]%p;
        printf("%lld\n",ans[i]); 
      }
}
//�׳���Ԫ�� 
/*
#include<cstdio>
#define ll long long
using namespace std;
ll mul(ll a,ll b,ll mod) //������ģ��
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
ll n,p;
ll c[5000010]={1};
ll f[5000010];
int main()
{
scanf("%lld%lld",&n,&p);
for(int i=1;i<=n;i++)
  c[i]=(c[i-1]*i)%p;

f[n]=mul(c[n],p-2,p); //���inv(n!)

for(int i=n-1;i>=1;i--) //���ƽ׳˵���Ԫ
  f[i]=(f[i+1]*(i+1))%p;

for(int j=1;j<=n;j++) //ת�������
  printf("%lld\n",(f[j]*c[j-1])%p);
}
*/
