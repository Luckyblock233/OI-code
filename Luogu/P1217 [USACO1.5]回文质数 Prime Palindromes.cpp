#include<iostream>
#include<cstdio>
#define MAXN 10000010
using namespace std;
int prime[MAXN],vis[MAXN];
bool pp[MAXN];
int a,b,cnt;
bool pd_h(int x)
{
	int y=x,num=0;
	while (y)
	  num=num*10+y%10,y/=10;
	return num==x;
}
int main()
{
	cin>>a>>b;
	if(b>1e7) b=1e7;
	for(int i=2; i<=b; i++)
	  {
		if(!vis[i]) prime[cnt++]=i,pp[i]=1;
		for(int j=0; j<cnt&&i*prime[j]<=b; j++)
		  {
			vis[i*prime[j]]=i;
			if(i%prime[j]==0) break;
		  }
	  }
	for(int i=a;i<=b && i<=1e7;i++)
	  if(pd_h(i)&&pp[i]) 
	    printf("%d\n",i);
}
