#include<cstdio>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
struct baka9
{
	int hao;
	string piao;
}a[22];
struct cmp1
{
	bool operator() (baka9 x,baka9 y)
	  {
	  	if(x.piao==y.piao)
	  	  return x.hao>y.hao;
	  	else
	  	  {
	  	  	if(x.piao.length()==y.piao.length())
	  	  	  return x.piao<y.piao;
	  	  	return x.piao.length()<y.piao.length();
		  }
	  }
};
int main()
{
	int n;
	scanf("%d",&n);
	priority_queue <baka9,vector<baka9>,cmp1> s;
	for(int i=1;i<=n;i++)
	  {
	  	a[i].hao=i;
	  	cin>>a[i].piao;
	  	s.push(a[i]);
	  }
	cout<<s.top().hao<<endl;
	cout<<s.top().piao;
}
