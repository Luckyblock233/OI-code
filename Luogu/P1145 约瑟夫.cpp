#include<cstdio>
using namespace std;
int a[30],b[30];
int main()
{
	int k;
	scanf("%d",&k);
	int m=k+1;
	while(1)
	  {
	  	for(int i=1;i<2*k;i++)
	  	  {
	  	  	a[i]=i+1;
	  	  	b[i]=i/k;
		  }
		a[2*k]=1;
	  	b[2*k]=1;
		b[k]=0;
	  	int judge=1;
	  	int m1=1;
	  	int j=2*k;
	  	int huai=k;
	  	while(1)
	  	  {
	  	  	while(m1!=m)
	  	  	  {
	  	  	  	j=a[j];
	  	  	  	m1++;
			  }
			m1=1;
			if(b[a[j]]==1)
			  {
			    a[j]=a[a[j]];
			    huai--;
			  }
			else
			  {
			  	judge=0;
			  	break;
			  }
			if(huai==0)
			  break;
		  }
		if(judge==1)
		  {
		  	printf("%d",m);
		  	return 0;
		  }
		else
		  {
		  	if(m%(2*k)==0)
		  	  m+=k;
		  	else
		  	  m+=1;
		  }
	  }
}
/*
10 93313
11 459901
12 1358657
13 2504881
*/
