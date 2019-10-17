//
/*
By:Luckyblock
*/
#include<cstdio>
#include<vector>
#include<ctype.h>
#define max(a,b) (a>b?a:b)
#define ll long long
const int MARXALL = 1030;
//=============================================================
int n,m,all,ans, num[MARXALL], f[2][MARXALL][MARXALL];
bool map[110][11];
std:: vector <int> use[110];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n = read(), m = read(); all = (1 << m) - 1;
	for(int i = 1; i <= n; i ++)
	{
	  char tmp[20];
	  scanf("%s", tmp + 1);
	  for(int j = 0; j < m; j ++) 
	    map[i][j] = (tmp[j+1] == 'P');
	}
	
	for(int i = 1; i <= n; i ++)
	  for(int j = 0; j <= all; j ++)
	  {
	  	int sum = 0;
	  	bool flag = 1;
		for(int k = 0; k < m; k ++)
	    {
	      if(!map[i][k] && ((1<<k) & j)) {flag = 0; break;}
	      if((1<<k) & j)
		    if(((1<<k-1) & j) || ((1<<k-2) & j)) 
			  {flag = 0; break;}
		  sum += (((1<<k) & j) > 0);
		}
		if(flag) use[i].push_back(j), num[j] = sum;
	  }
	
	for(int i = 0, size1 = use[1].size(); i < size1; i ++)
	  for(int j = 0, size2 = use[2].size(); j < size2; j ++)
	    if(!(use[1][i] & use[2][j]))
	    {
	      f[1][use[1][i]][use[2][j]] = (num[use[1][i]] + num[use[2][j]]);
	      int tmp1 = use[1][i], tmp2 = use[2][j], tmp3 = f[1][use[1][i]][use[2][j]];
		}
	
	for(int i = 3, now = 0; i <= n; i ++, now = (!now))
	  for(int l = 0, size3 = use[i].size(); l < size3; l ++)
		for(int k = 0, size2 = use[i-1].size(); k < size2; k ++)
	      if((!(use[i-1][k] & use[i][l])))
		  {
		  	f[now][use[i-1][k]][use[i][l]] = 0;
		    for(int j = 0, size1 = use[i-2].size(); j < size1; j ++)
	      	  if(!(use[i-2][j] & use[i-1][k]) && (!(use[i-2][j] & use[i][l])))
		        f[now][use[i-1][k]][use[i][l]] = max(f[now][use[i-1][k]][use[i][l]] ,f[!now][use[i-2][j]][use[i-1][k]] + num[use[i][l]]);
		    if(i == n)  ans= max(ans,f[now][use[i-1][k]][use[i][l]]);
		  }
	printf("%d",ans);
}

