//�߾��ȳ˷�+�ӷ�
//���ע�� 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int ans[50010];
int x[50010]={1};
int ltha=1,lthx=1;
void pluss()//�߾��� 
{
	int i=0;
	while(i<ltha || i<lthx)//���� 
	  {
	  	ans[i]+=x[i];
	  	if(ans[i]>=10)
	  	  {
	  	  	ans[i+1]+=ans[i]/10;
	  	  	ans[i]=ans[i]%10;
		  }
		i++;
	  }
	while(ans[i])//��λ 
	  {
	    if(ans[i]>=10)
	  	    {
	  	  	  ans[i+1]+=ans[i]/10;
	  	  	  ans[i]=ans[i]%10;
		    }
	    i++;
	  }
	ltha=i+1;
	if(!ans[ltha-1]) ltha--;
}
void chen(int j)//�߾��� 
{
	int c[50010]={0};
	int i=0;
	while(i<lthx)//���� 
	  {
	  	c[i]+=x[i]*j;
	  	if(c[i]>=10)
	  	  {
	  	  	c[i+1]+=c[i]/10;
	  	  	c[i]=c[i]%10;
		  }
		i++;
	  }
	  while(ans[i])//��λ 
	    {
	      if(c[i]>=10)
	  	    {
	  	      c[i+1]+=c[i]/10;
	  	  	  c[i]=c[i]%10;
		    }
		  i++;
	    }
	for(int k=0;k<=i;k++) 
	  x[k]=c[k];
	lthx=i+1;
	if(!x[lthx-1]) lthx--;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//����1~n�Ľ׳�,���ۼ� 
	  {
	  	chen(i);
	  	pluss();
	  }
	bool flag=0;
	for(int i=0;i<=ltha;i++)//ȥ��ǰ��0,����� 
	  {
	  	if(ans[ltha-i]) flag=1;
	  	if(flag) cout<<ans[ltha-i];
	  }
}
