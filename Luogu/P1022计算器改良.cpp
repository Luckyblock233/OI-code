#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
char a[1000000];
int main()
{
	double x=0,y=0;
	char a1;
	int i=0;
	cin>>a;
	int nde;
	for(nde=1;nde<=strlen(a);nde++)
	  if(a[nde]=='=')
	    break;
	int flagfu=0;
	while(i!=nde)
	  {
	  	if(a[i]=='-')
	  	  flagfu=1;
	  	if(a[i]>='a' && a[i]<='z')
		  {
		  	a1=a[i];
			if(flagfu==1) x-=1;
			else x+=1;
			flagfu=0;
		  }
		if(a[i]>='0' && a[i]<='9')
		  {
		  	int x1=0;
		  	while(a[i]>='0' && a[i]<='9')
		  	  {
		  	  	x1=x1*10+a[i]-'0';
		  	  	i++;
			  }
			if(a[i]>='a' && a[i]<='z')
			  {
			  	a1=a[i];
			    if(flagfu==1) x-=x1;
			    else x+=x1;
			    flagfu=0;
			  }
			else
			  {
			    if(flagfu==1) y+=x1;
			    else y-=x1;
			    flagfu=0;
			    i-=1;
			  }
		  }
		i++;
	  }
	i++;
	while(i<=strlen(a))
	  {
	  	if(a[i]=='-')
	  	  flagfu=1;
	  	if(a[i]>='a' && a[i]<='z')
		  {
		  	a1=a[i];
			if(flagfu==1) x+=1;
			else x-=1;
			flagfu=0;
		  }
		if(a[i]>='0' && a[i]<='9')
		  {
		  	int x1=0;
		  	while(a[i]>='0' && a[i]<='9')
		  	  {
		  	  	x1=x1*10+a[i]-'0';
		  	  	i++;
			  }
			if(a[i]>='a' && a[i]<='z')
			  {
			  	a1=a[i];
			    if(flagfu==1) x+=x1;
			    else x-=x1;
			    flagfu=0;
			  }
			else
			  {
			    if(flagfu==1) y-=x1;
			    else y+=x1;
			    flagfu=0;
			    i-=1;
			  }
		  }
		i++;
	  }
	if(y==0)
	  printf("%c=%.3lf\n",a1,0.000);
	else
	  printf("%c=%.3lf\n",a1,y/x);
}
