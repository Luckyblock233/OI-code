//
/*
By:Luckyblock
*/
#include<cstdio>
#include<vector>
#include<set>
#include<ctype.h>
#define ull unsigned long long
const int MARX = 2e5+10;
const int pow1 = 998244353;
//=============================================================
int n,a[MARX];
ull sum1[MARX],sum2[MARX],mul[MARX]={1};
int ans1,ans2;
std::vector <int> ans3;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
ull get_hash1(int l,int r)
{
	return sum1[r] - sum1[l]*mul[r-l];
}
ull get_hash2(int l,int r)
{
	return sum2[l] - sum2[r]*mul[r-l];
}
//=============================================================
signed main()
{
	n = read();
	for(int i=1; i<=n; i++) a[i] = read();
	for(int i=1; i<=n; i++)
	  sum1[i] = sum1[i-1] * pow1 + a[i],
	  sum2[n-i+1] = sum2[n-i+2] * pow1 + a[i];
	
	for(int i=1; i<=n; i++) mul[i] = mul[i-1] * pow1;
	
	for(int i=2; i<=n; i++)
	{
	  std:: set <ull> s;
	  for(int l=1,r=l+i-1; r<=n; l++,r++)
	  {
	  	ull ha1 = get_hash1(l,r);
	  	ull ha2 = get_hash2(l,r);
	  	if(!s.count(ha1)) s.insert(ha1);
	  	if(!s.count(ha2)) s.insert(ha2);
	  }
	  
	  if(s.size() > ans1) 
	  {
	    ans1 = s.size();
		ans2 = 1;
		ans3.clear(); ans3.push_back(i); 
	  	continue;
	  }
	  if(s.size() == ans1)
	  {
	  	ans2 ++;
	  	ans3.push_back(i);
	  }
	}
	
	printf("%d %d\n",ans1,ans2);
	for(int i=0,size=ans3.size(); i<size; i++) printf("%d ",ans3[i]);
}
