//注：本题样例有误
//起点为-1,不为0 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[1000010];
int a[1000010];
int n,i=-1,s1;
int main()
{
	gets(s);
	scanf("%d",&n);
	int l=strlen(s)-1;
	for(int j=l-1;j>=0;j--)
	  {
	  	if(s[j]=='>')
	  	  {
	  	  	if(s[j+1]!='>')
	  	  	  a[j]=1;
	  	  	else
	  	  	  a[j]=a[j+1]+1;
		  }
		if(s[j]=='*')
	  	  {
	  	  	if(s[j+1]!='*')
	  	  	  a[j]=1;
	  	  	else
	  	  	  a[j]=a[j+1]+1;
		  }
	  }
	for(int k=1;k<=n;k++)
	  {
	  	scanf("%d",&s1);
	  	i+=s1;
	  	if(a[i]>=3)
	  	  {
	  	  	if(s[i]=='>')
	  	  	  i+=a[i];
	  	  	else
	  	  	  if(s[i]=='*')
	  	  	    i-=a[i];
		  }
		i=max(0,i);
		i=min(l-1,i);
	  }
	printf("%d %d",i+1,l-1-i);
}
