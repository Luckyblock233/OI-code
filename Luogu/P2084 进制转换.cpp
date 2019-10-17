//并没有用栈的做法 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s0[1001];
int main()
{
	int n,m;
	cin>>n>>s0;
	int l=strlen(s0)-1;
	int judge=0;//用来改变输出格式,防止出现后置加号 
	for(int i=0;i<=l;i++)
	  if(s0[i]!='0' && judge==0)//若为第一个输出元素 
	  	{
	  	  printf("%c*%d^%d",s0[i],n,l-i);
	  	  judge=1; 
		}
	  else
		{
		  if(s0[i]!='0')
	  	    printf("+%c*%d^%d",s0[i],n,l-i);//若为之后的输出原素 
		}
}
