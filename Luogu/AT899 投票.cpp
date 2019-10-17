#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
map <string,int> baka;
int n,maxx=-1;
string a,b; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>a;
	  	baka[a]++;
	  	if(baka[a] > maxx)
	  	  {
	  	  	maxx=baka[a];
	  	  	b=a;
		  }
	  }
	cout<<b<<endl;
	return 0;
}
