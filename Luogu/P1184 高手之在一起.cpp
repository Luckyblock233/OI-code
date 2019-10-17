#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int n,m,tot;
string a,b;
map <string,bool> s;
int main()
{
	scanf("%d%d\n",&n,&m);
	if(n==1 && m==1)
	  {
	  	printf("1");
	  	return 0;
	  }
	for(int i=1;i<=n;i++)
	  {
	  	getline(cin,a);
	  	s[a]=1;
	  }
	for(int i=1;i<=m;i++)
	  {
	  	getline(cin,b);
	  	if(s[b]) tot++;
	  }
	printf("%d",tot);
} 
