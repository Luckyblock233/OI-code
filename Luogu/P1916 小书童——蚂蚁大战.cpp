#include<cstdio>
#include<algorithm>
using namespace std;
int a[10001];
int main()
{
    int n;
    int m,k,w,r;
    scanf("%d%d%d%d%d",&n,&m,&k,&w,&r);
    int d=(m/k)*w;
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int k1=1;
    for(int i=1;i<=r;i++)
      {
        if(a[k1]<0) k1++;
        a[k1]-=d;
      }
    int ans=0;
    for(int i=1;i<=n;i++)
      if(a[i]>0)
        ans++;
    printf("%d",ans);
}
