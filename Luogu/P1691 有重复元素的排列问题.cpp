#include<cstdio>
#include<algorithm>
using namespace std;
char a[510];
int n,ans=0;
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    while(next_permutation(a,a+n));
    do 
	  {
        puts(a);
        ans++;
      }
	while(next_permutation(a,a+n));
    printf("%d",ans);
    return 0;
}
