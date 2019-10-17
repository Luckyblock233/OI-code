//本题为混合背包模板
//把多重背包和完全背包合体即可 
//可以将完全背包的次数设为极大值
//并将多重背包二进制拆分,来优化时间 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t;
int hs,ms,he,me;
int w[10010],v[10010],s[10010];
int f[1000010];
int w1[1000010],v1[1000010];
int num;
void time();
void brick(int);
int main()
{
	scanf("%d:%d %d:%d",&hs,&ms,&he,&me);
	time();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//输入并拆分 
	  {
	  	scanf("%d%d%d",&w[i],&v[i],&s[i]);
	  	if(!s[i])s[i]=9999999;//将完全背包的次数设为极大值
	  	brick(i);
	  }
	for(int i=1;i<=num;i++)//dp,多重背包模板 
      for(int j=t;j>=w1[i];j--)
      	f[j]=max(f[j],f[j-w1[i]]+v1[i]);
	printf("%d",f[t]);
}
//--------------------------------------------------------
void time()//计算时间 
{
	if(me<ms) 
	  {
	  	t+=(me+60-ms);
	  	he-=1;
	  	t+=(60*(he-hs));
	  }
	else
	  t+=((60*(he-hs))+(me-ms));
}
void brick(int i)//二进制拆分 
{
    for(int j=1;j<=s[i];j*=2)
      {
      	v1[++num]=j*v[i];
      	w1[num]=j*w[i];
      	s[i]-=j;
      }
    if(s[i])
      {
      	v1[++num]=s[i]*v[i];
      	w1[num]=s[i]*w[i];
      }
}
