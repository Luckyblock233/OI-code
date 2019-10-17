#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MARX=0xf;
int n,l,r,ans;
int a[300010];
int f[300010];
int main()
{
	memset(f,-MARX,sizeof(f));
    ans=-2147483640;
	f[0]=0;
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++)
      scanf("%d",&a[i]);
//===========输入与处理的境界============================ 
    for(int i=1;i<=n;i++)
      for(int j=i-r;j<=i-l;j++)
        if(j>=0) 
		  f[i]=max(f[i],f[j]+a[i]);
    for(int i=n-r+1;i<=n;i++)
      ans=max(ans,f[i]);
    printf("%d",ans);
}
