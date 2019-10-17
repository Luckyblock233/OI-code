#include<iostream>
#include<cstdio>
using namespace std;
int h[100005];
long long block(int l,int r,int minh)
{
	if(h[l]==0 && h[r]==0)
	  return 0;
	long long sum=minh;
	while(h[l]==minh && l<r)
	  l++;
	int l1=l;
	int minnh=100000;
	for(int i=l;i<=r;i++)
	  {
	  	h[i]-=minh;
	  	if(h[i]<minnh && h[i]>=0)
		  minnh=h[i];
	  	if(h[i]==0)
	  	  {
	  	  	sum=sum+block(l1,i-1,minnh);
	  	  	l1=i+1;
	  	  	minnh=100000;
		  }
		if(i==r)
		  {
		  	sum=sum+block(l1,i,minnh);
		  }
	  }
    return sum;
}
int main()
{
	int n;
	int minh=100000;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&h[i]); 
	  	if(h[i]<minh)
	  	  minh=h[i];
	  }
	cout<<block(1,n,minh);
	fclose(stdin);
	fclose(stdout);
}
