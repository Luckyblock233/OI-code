#include<iostream>
#include<cstdlib>
using namespace std;
string a,b;
void f(int l1,int r1,int l2,int r2)
{
	int n=b.find(a[r1]);
	cout<<a[r1];
	if(n>l2) f(l1,l1+n-l2-1,l2,n-1);
	if(n<r2) f(l1+n-l2,r1-1,n+1,r2);
}
int main()
{
	cin>>b>>a;
	f(0,a.length()-1,0,b.length()-1);
	return 0;
}
