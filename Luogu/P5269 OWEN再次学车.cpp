#include<cstdio>
#include<iostream>
using namespace std;
bool judgexy(int,int);
long long t,n,l,r,x1,k;
long long s=0;
long long k1=0;
long long zhuan;
long long n1=1; 
int main()
{
	cin>>t>>n>>l>>r>>x1>>k;
	zhuan=l;
	while(t>0)
	  {
	  	int x,y;
	  	cin>>x>>y;
	  	if( !judgexy(x,y) )
		  return 0;
		s+=zhuan*n1;
		if(zhuan==r)
		  k1++;
		else
		  k1=0;
		if(k1==k)
		  break;
		t--;
	  }
	printf("%lld",s);
}
bool judgexy(int x,int y)
{
	if(x==0)
	  {
	  	n1++;
		zhuan=l;
	  }
	if(x==1)
	  {
		n1--;
		zhuan=r;
	  }
	if(n1==n+1 || n1==0)
	  {
		printf("-1");
		return 0;
	  }
	if(y==1)
	  zhuan+x1>=r?zhuan=r:zhuan+=x1;
	return 1;
}
