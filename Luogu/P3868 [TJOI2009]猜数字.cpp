//��չ�й�ʣ�ඨ��ģ�� 
//���ע�� 
#include<cstdio>
using namespace std;
typedef long long ll;
ll n;
ll a[100010],b[100010]; 
ll mul(ll A,ll B,ll mod) //���ٳ�ȡ�� ģ��
{
    ll ans=0;
    while(B>0)
      {
        if(B & 1) ans=(ans+A%mod)%mod;
        A=(A+A)%mod;
        B>>=1;
      }
    return ans;
}
ll exgcd(ll A,ll B,ll &x,ll &y) //��չŷ����� ģ��
{
    if(!B)
      {
        x=1,y=0;
        return A;
      }
    ll d=exgcd(B,A%B,x,y);
    ll tmp=x;
    x=y , y=tmp-A/B*y;
    return d;
}
ll lcm(ll A,ll B) //����С������
{
    ll xxx,yyy;
    ll g=exgcd(A,B,xxx,yyy);
    return (A/g*B);
}
ll excrt() //�ص�:���ͬ�෽����
{
    ll x,y;
    ll M=b[1],ans=a[1]; //����ֵ 
    //MΪǰk-1��������С��������ansΪǰk-1�����̵�ͨ��
    for(int i=2;i<=n;i++)
      {
        ll A=M,B=b[i];
        ll C=(a[i]-ans%B+B)%B; //����ͬ�෽�� ax��c(mod b) ��a,b,c

        ll g=exgcd(A,B,x,y);
        //���A,B�����Լ������ͬ�෽��ax��gcd(a,b)(mod b)�Ľ⣬

        if(C%g) return -1; //�޽�����

        x=mul(x,C/g,B); //���x��ֵ,x��t 
        ans+=x*M;  //���ǰk�����̵�ͨ��
        M=lcm(M,B); //����M��ֵ
        ans=(ans%M+M)%M;
      }
    return ans;
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)
      a[i]=(a[i]+b[i])%b[i];
    ll ans=excrt();
    printf("%lld",ans);
}
