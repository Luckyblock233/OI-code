#include<iostream>
#include<cstring>
using namespace std;
int n;
int ans=0;
char a[100001],c[2][100001];
int la;
bool judge()
{
	if(ans > 30) return 1;
	int l=0,r=la-1;
	while(l <= r)
	  if(a[l++]!=a[r--]) return 0;
	return 1;
}
int main()
{
	memset(a,-1,sizeof(a));
	cin>>n;
	cin>>a;
	la=strlen(a);
	int jc=0;
	for(int i=la-1;i>=0;i--)
	  {
	  	if(a[i]>='0' && a[i]<='9')
	  	  a[i]-='0';
	  	else
	  	  a[i]=a[i]-'A'+10;
	  	c[jc][i]=a[i];
	  }
	while(!judge())
	  {
	  	int jcc=(!jc);
	  	ans++;
	  	for(int i=0;i<la;i++)
	  	  {
	  	  	a[i]=a[i]+c[jc][la-i-1];
	  	  	if(a[i]>=n)
	  	  	  {
	  	  	  	if(a[i+1]==-1) a[i+1]=0;
	  	  	  	a[i+1]+=a[i]/n;
	  	  	  	a[i]%=n;
			  }
			c[jcc][i]=a[i];
		  }
		if(a[la]>=0)
		  {
		  	la++;
		  	c[jcc][la-1]=a[la-1]; 
		  }
		jc=jcc;
	  }
	if(ans>30)
	  cout<<"Impossible!";
	else
	  cout<<"STEP="<<ans;
 }
