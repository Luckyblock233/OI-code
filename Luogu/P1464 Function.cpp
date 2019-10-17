#include<cstdio>
#include<iostream>
using namespace std;
int an[22][22][22];
int w(long long a,long long b,long long c)
{
	if(a<=0 || b<=0 || c<=0)
	  return 1;
	else
	  {
	    if(a>20 || b>20 || c>20)
	  	  return an[20][20][20]=w(20,20,20);
	    if(an[a][b][c]!=0)
	      return an[a][b][c];
	  	else
	  	  {
	 		if(a<b && b<c)
			  {
			    return an[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
			  }
			else
			  {
			  	return an[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
			  }
		  }
	  }
}
int main()
{
	long long a,b,c;
	while(1)
	  {
	  	cin>>a>>b>>c;
	  	if(a==-1 && b==-1 && c==-1)
		  break;
		else
	  	  {
	  	  	cout << "w" << "(" << a << ", "<< b << ", "<< c<< ") = "<< w(a,b,c)  << endl;
		  }
	  }
}
