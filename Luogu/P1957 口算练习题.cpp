#include<iostream>
#include<cmath>
using namespace std;
int n;
char gr;
void putout(string s)
{
	int space=s.find(' '),lth=s.length();
	int n1=0,n2=0,n3;
	for(int i=0;i<space;i++) n1=n1*10+s[i]-'0';
	for(int i=space+1;i<lth;i++) n2=n2*10+s[i]-'0';
	
	if(gr=='a') 
	  {
	  	n3=n1+n2;
		while(n3) n3/=10,lth++;
	    cout<<n1<<'+'<<n2<<'='<<n1+n2<<endl<<(n1+n2<0?lth+2:lth+1)<<endl;
	  }
	if(gr=='b')
	  {
	  	n3=n1-n2;
	  	while(n3) n3/=10,lth++;
	  	cout<<n1<<'-'<<n2<<'='<<n1-n2<<endl<<(n1-n2<0?lth+2:lth+1)<<endl;
	  }
	if(gr=='c')
	  {
	  	n3=n1*n2;
	  	while(n3) n3/=10,lth++;
	  	cout<<n1<<'*'<<n2<<'='<<n1*n2<<endl<<(n1*n2<0?lth+2:lth+1)<<endl;
	  }
	
}
int main()
{
	//freopen("1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++)
	  {	
		string s;
	  	getline(cin,s);
	  	if(s[0]>='a' && s[0]<='c') 
		  {
		    gr=s[0];
			s.erase(0,2);
		  }
	  	putout(s);
	  }
} 
