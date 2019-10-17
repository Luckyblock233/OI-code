#include<cmath>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
char s0[1000000001];
char a[17]="0123456789ABCDEF";//便于输出 
long long s1=0;
int main()
{
	int n,m;
	stack <int> s;
	cin>>n>>s0>>m;
	int l=strlen(s0)-1;
	int i=0;
	while(l>=0)//先转十进制 
	  {
	  	if(s0[l]>='0' && s0[l]<='9')//若为数字情况 
	  	  s1+=(s0[l]-'0')*pow(n,i);
	  	else
	  	  s1+=(s0[l]-'A'+10)*pow(n,i);//为字母情况 
	  	i++;l--;
	  }
	while(s1!=0)//转到要求进制 
	  {
	  	int k=s1%m;
	  	s.push(k);//压入栈 
	  	s1/=m;
	  }
	while(!s.empty())//输出栈内元素 
	  {
	  	cout<<a[s.top()];
	  	s.pop();
	  }
}
