#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
string a[100010];
string t;
bool cmp(string a,string b)
{
	return a<b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  cin>>a[i];
	cin>>t;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	  {
	  	int n1=a[i].find(t);
	  	if(n1!=-1 && n1==0)
	  	  cout<<a[i]<<endl;
	  }
}
