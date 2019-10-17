#include<cstdio>
using namespace std;
int n,m;
int a[1000010];
int c[1000010];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y,int n)
{
    for(int i=x;i<=n;i+=lowbit(i))
      {
      	printf("%d ",i); 
	    c[i]+=y;
	  } 
	printf("\n");
}
int find(int x)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
      {
      	sum+=c[i];
      	printf("%d ",i); 
	  }
	printf("\n");
    return sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      {
        scanf("%d",&a[i]);
        add(i,a[i],n);
      }
    for(int i=1;i<=m;i++)
      {
        int q,x,y;
        scanf("%d%d%d",&q,&x,&y);
        if(q==1) 
          {
            a[x]+=y;
            add(x,y,n);
          }
        else 
          {
            int ans=find(y) - find(x) + a[x];
            printf("\n");
            printf("%d\n",ans);
          }
      }
}
